#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set window title
    setWindowTitle("SE16 Weather Forecast");

    // Make sure all image labels have scaledContents set to true
    QList<QLabel*> iconLabels = {
        ui->sunny, ui->rainy, ui->thunder,
        ui->cloudy, ui->snowy, ui->foggy, ui->humidity
    };

    for (auto label : iconLabels) {
        label->setScaledContents(true);
        label->setVisible(true);
    }

    // Initialize weather manager
    weatherManager = new WeatherManager(this);
    weatherManager->testApiKey();

    // Connect signals and slots
    connect(weatherManager, &WeatherManager::currentWeatherReceived,
            this, &MainWindow::displayCurrentWeather);
    connect(weatherManager, &WeatherManager::forecastReceived,
            this, &MainWindow::displayForecast);
    connect(weatherManager, &WeatherManager::errorOccurred,
            this, &MainWindow::displayError);

    // Set Bangkok as default location
    weatherManager->getCurrentWeather("Bangkok");
    weatherManager->getForecast("Bangkok");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enterbutton_clicked()
{
    QString city = ui->lineEdit->text().trimmed();
    if (city.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a city name");
        return;
    }

    weatherManager->getCurrentWeather(city);
    weatherManager->getForecast(city);
}

void MainWindow::displayCurrentWeather(const WeatherManager::WeatherData &data)
{
    ui->city->setText(data.cityName);
    ui->highTemp->setText(QString("Highest Temp: %1°C").arg(data.highTemp, 0, 'f', 1));
    ui->lowTemp->setText(QString("Lowest Temp: %1°C").arg(data.lowTemp, 0, 'f', 1));
    ui->wind->setText(QString("Wind: %1 m/s").arg(data.windSpeed, 0, 'f', 1));
    ui->humiditylabel->setText(QString("Humidity: %1%").arg(data.humidity));
}

void MainWindow::displayForecast(const QVector<WeatherManager::ForecastData> &forecast)
{
    QVector<QLabel*> tempLabels = {
        ui->dayonetemp, ui->daytwotemp, ui->daythreetemp,
        ui->dayfourtemp, ui->dayfivetemp, ui->daysixtemp, ui->dayseventemp
    };

    QVector<QLabel*> dateLabels = {
        ui->dayone, ui->daytwo, ui->daythree,
        ui->dayfour, ui->dayfive, ui->daysix, ui->dayseven
    };

    QVector<QLabel*> iconLabels = {
        ui->sunny, ui->rainy, ui->thunder,
        ui->cloudy, ui->snowy, ui->foggy, ui->humidity
    };

    // Make sure all weather icons are visible
    for (auto label : iconLabels) {
        label->setVisible(true);
    }

    // Clear all labels first
    for (int i = 0; i < 7; i++) {
        tempLabels[i]->setText("--°C");
        dateLabels[i]->setText("--/--/----");
        iconLabels[i]->setPixmap(QPixmap());
    }

    // fill the data we have
    int count = qMin(forecast.size(), 7);
    for (int i = 0; i < count; i++) {
        tempLabels[i]->setText(QString("%1°C").arg(forecast[i].temp, 0, 'f', 0));

        // Parse the date string and format it as DD/MM/YYYY
        QDate date = QDate::fromString(forecast[i].date, "dd/MM/yyyy");
        if (date.isValid()) {
            // Show full DD/MM/YYYY format
            dateLabels[i]->setText(date.toString("dd/MM/yyyy"));
        } else {
            // Try alternative format parsing if the first attempt failed
            date = QDate::fromString(forecast[i].date, "yyyy-MM-dd");
            if (date.isValid()) {
                dateLabels[i]->setText(date.toString("dd/MM/yyyy"));
            } else {
                // If all parsing fails, just use the original string
                dateLabels[i]->setText(forecast[i].date);
            }
        }

        // Update icon based on weather condition
        QString iconPath = getWeatherIconPath(forecast[i].weatherIcon);
        iconLabels[i]->setPixmap(QPixmap(iconPath));
    }
}

void MainWindow::displayError(const QString &errorMessage)
{
    QMessageBox::critical(this, "Error", "Failed to fetch weather data: " + errorMessage);
}

QString MainWindow::getWeatherIconPath(const QString &iconCode)
{
    // Map OpenWeather icon codes to our local icons
    if (iconCode.startsWith("01")) {
        return ":/sunny.png"; // Clear sky
    } else if (iconCode.startsWith("02") || iconCode.startsWith("03") || iconCode.startsWith("04")) {
        return ":/cloudy.png"; // Clouds
    } else if (iconCode.startsWith("09") || iconCode.startsWith("10")) {
        return ":/rainy.png"; // Rain
    } else if (iconCode.startsWith("11")) {
        return ":/thunder.png"; // Thunderstorm
    } else if (iconCode.startsWith("13")) {
        return ":/snowy.png"; // Snow
    } else if (iconCode.startsWith("50")) {
        return ":/foggy.png"; // Mist, fog
    }

    return ":/cloudy.png"; // Default
}
