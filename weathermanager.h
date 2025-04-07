#ifndef WEATHERMANAGER_H
#define WEATHERMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMap>

class WeatherManager : public QObject
{
    Q_OBJECT
public:
    explicit WeatherManager(QObject *parent = nullptr);

    void getCurrentWeather(const QString &city);
    void getForecast(const QString &city);
    void testApiKey();

    // Struct to hold weather data
    struct WeatherData {
        QString cityName;
        double currentTemp;
        double highTemp;
        double lowTemp;
        int humidity;
        double windSpeed;
        QString weatherDescription;
        QString weatherIcon;
    };

    // Struct to hold forecast data for a day
    struct ForecastData {
        QString date;
        double temp;
        QString weatherIcon;
    };

signals:
    void currentWeatherReceived(const WeatherData &data);
    void forecastReceived(const QVector<ForecastData> &forecast);
    void errorOccurred(const QString &errorMessage);

private slots:
    void onCurrentWeatherReplyFinished();
    void onForecastReplyFinished();
    void onOneCallReplyFinished();

private:
    QNetworkAccessManager *manager;
    const QString apiKey = "33fff3e9d04e77710378b453abae773e"; // API KEY
    const QString baseUrl = "https://api.openweathermap.org/data/2.5/";
};

#endif // WEATHERMANAGER_H
