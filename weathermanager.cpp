#include "weathermanager.h"
#include <QUrlQuery>
#include <QDateTime>
#include <QDebug>

WeatherManager::WeatherManager(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}

void WeatherManager::getCurrentWeather(const QString &city)
{
    QUrl url(baseUrl + "weather");
    QUrlQuery query;
    query.addQueryItem("q", city);
    query.addQueryItem("appid", apiKey);
    query.addQueryItem("units", "metric");
    url.setQuery(query);

    qDebug() << "Making current weather request to:" << url.toString(QUrl::RemoveQuery)
             << "with city:" << city;

    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, &WeatherManager::onCurrentWeatherReplyFinished);
}

void WeatherManager::getForecast(const QString &city)
{
    QUrl url(baseUrl + "forecast");
    QUrlQuery query;
    query.addQueryItem("q", city);
    query.addQueryItem("appid", apiKey);
    query.addQueryItem("units", "metric");
    url.setQuery(query);

    qDebug() << "Making forecast request to:" << url.toString(QUrl::RemoveQuery)
             << "with city:" << city;

    QNetworkRequest request(url);
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, &WeatherManager::onForecastReplyFinished);
}

void WeatherManager::onCurrentWeatherReplyFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;

    if (reply->error() != QNetworkReply::NoError) {
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (statusCode == 404) {
            // Handle invalid city
            emit errorOccurred("Invalid city");
        } else {
            emit errorOccurred("Error occured. Please try again.");
        }
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (doc.isNull() || !doc.isObject()) {
        emit errorOccurred("Invalid JSON response");
        reply->deleteLater();
        return;
    }

    QJsonObject obj = doc.object();

    WeatherData weatherData;
    weatherData.cityName = obj["name"].toString();

    QJsonObject main = obj["main"].toObject();
    weatherData.currentTemp = main["temp"].toDouble();
    weatherData.highTemp = main["temp_max"].toDouble();
    weatherData.lowTemp = main["temp_min"].toDouble();
    weatherData.humidity = main["humidity"].toInt();

    QJsonObject wind = obj["wind"].toObject();
    weatherData.windSpeed = wind["speed"].toDouble();

    QJsonArray weatherArray = obj["weather"].toArray();
    if (!weatherArray.isEmpty()) {
        QJsonObject weather = weatherArray.first().toObject();
        weatherData.weatherDescription = weather["description"].toString();
        weatherData.weatherIcon = weather["icon"].toString();
    }

    emit currentWeatherReceived(weatherData);
    reply->deleteLater();
}

void WeatherManager::onForecastReplyFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;

    if (reply->error() != QNetworkReply::NoError) {
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (doc.isNull() || !doc.isObject()) {
        emit errorOccurred("Invalid JSON response");
        reply->deleteLater();
        return;
    }

    QJsonObject obj = doc.object();
    QJsonArray list = obj["list"].toArray();

    QVector<ForecastData> forecastList;
    QMap<QString, ForecastData> dailyForecasts; // Use a map to collect one forecast per day

    for (const QJsonValue &value : list) {
        QJsonObject item = value.toObject();
        QDateTime dateTime = QDateTime::fromSecsSinceEpoch(item["dt"].toInt());
        QDate date = dateTime.date();
        QString dateStr = date.toString("dd/MM/yyyy");

        // For each day, save the first forecast we find
        if (!dailyForecasts.contains(dateStr)) {
            ForecastData forecast;
            forecast.date = dateStr;

            QJsonObject main = item["main"].toObject();
            forecast.temp = main["temp"].toDouble();

            QJsonArray weatherArray = item["weather"].toArray();
            if (!weatherArray.isEmpty()) {
                QJsonObject weather = weatherArray.first().toObject();
                forecast.weatherIcon = weather["icon"].toString();
            }

            dailyForecasts[dateStr] = forecast;
        }
    }

    // Generate forecasts for 7 days starting from today
    QDate currentDate = QDate::currentDate();
    for (int i = 0; i < 7; i++) {
        QDate date = currentDate.addDays(i);
        QString dateStr = date.toString("dd/MM/yyyy");

        // If we don't have data for this day from API, create default data
        if (!dailyForecasts.contains(dateStr)) {
            ForecastData forecast;
            forecast.date = dateStr;
            forecast.temp = 25.0; // Default temperature
            forecast.weatherIcon = "01d"; // Default clear sky icon
            dailyForecasts[dateStr] = forecast;
        }

        forecastList.append(dailyForecasts[dateStr]);
    }

    emit forecastReceived(forecastList);
    reply->deleteLater();
}

void WeatherManager::onOneCallReplyFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply) return;

    if (reply->error() != QNetworkReply::NoError) {
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        QString errorDetails = QString("Network Error: %1 (Status Code: %2)\nResponse: %3")
                                   .arg(reply->errorString())
                                   .arg(statusCode)
                                   .arg(QString(reply->readAll()));
        qDebug() << errorDetails;
        emit errorOccurred(errorDetails);
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (doc.isNull() || !doc.isObject()) {
        emit errorOccurred("Invalid JSON response");
        reply->deleteLater();
        return;
    }

    QJsonObject obj = doc.object();
    QJsonArray daily = obj["daily"].toArray();

    QVector<ForecastData> forecastList;

    for (int i = 0; i < qMin(daily.size(), 7); i++) {
        QJsonObject dayData = daily[i].toObject();

        ForecastData forecast;
        QDateTime dateTime = QDateTime::fromSecsSinceEpoch(dayData["dt"].toInt());
        forecast.date = dateTime.date().toString("dd/MM/yyyy");

        QJsonObject temp = dayData["temp"].toObject();
        forecast.temp = temp["day"].toDouble();

        QJsonArray weatherArray = dayData["weather"].toArray();
        if (!weatherArray.isEmpty()) {
            QJsonObject weather = weatherArray.first().toObject();
            forecast.weatherIcon = weather["icon"].toString();
        }

        forecastList.append(forecast);
    }

    // If we don't have 7 days from the API, fill the rest with placeholder data
    QDate lastDate = QDate::currentDate();
    if (!forecastList.isEmpty()) {
        lastDate = QDate::fromString(forecastList.last().date, "dd/MM/yyyy");
    }

    while (forecastList.size() < 7) {
        lastDate = lastDate.addDays(1);
        ForecastData forecast;
        forecast.date = lastDate.toString("dd/MM/yyyy");
        forecast.temp = 25.0; // Default temperature
        forecast.weatherIcon = "01d"; // Default clear sky icon
        forecastList.append(forecast);
    }

    emit forecastReceived(forecastList);
    reply->deleteLater();
}

void WeatherManager::testApiKey()
{
    // Test API key using the simplest endpoint
    QString testUrl = QString("https://api.openweathermap.org/data/2.5/weather?q=London&appid=%1").arg(apiKey);

    qDebug() << "Testing API with URL:" << testUrl;

    QNetworkRequest request((QUrl(testUrl))); // Fixed parentheses issue
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "Test API call failed:" << reply->errorString();
            qDebug() << "Status code:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            qDebug() << "Response:" << reply->readAll();
        } else {
            qDebug() << "Test API call succeeded!";
            QByteArray responseData = reply->readAll();
            qDebug() << "Response:" << responseData.left(100); // Show first 100 chars
        }
        reply->deleteLater();
    });
}
