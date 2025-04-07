#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "weathermanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enterbutton_clicked();
    void displayCurrentWeather(const WeatherManager::WeatherData &data);
    void displayForecast(const QVector<WeatherManager::ForecastData> &forecast);
    void displayError(const QString &errorMessage);

private:
    Ui::MainWindow *ui;
    WeatherManager *weatherManager;
    QString getWeatherIconPath(const QString &iconCode);
};
#endif // MAINWINDOW_H
