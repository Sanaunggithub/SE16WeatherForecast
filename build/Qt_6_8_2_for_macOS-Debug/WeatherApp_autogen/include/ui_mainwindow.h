/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *highTemp;
    QLabel *wind;
    QLabel *lowTemp;
    QLabel *humiditylabel;
    QGroupBox *groupBox_2;
    QLabel *monday;
    QLabel *tuesday;
    QLabel *wedenesday;
    QLabel *thursday;
    QLabel *friday;
    QLabel *saturday;
    QLabel *sunday;
    QLabel *sunny;
    QLabel *rainy;
    QLabel *thunder;
    QLabel *cloudy;
    QLabel *snowy;
    QLabel *foggy;
    QLabel *humidity;
    QLabel *dayone;
    QLabel *dayonetemp;
    QLabel *daythreetemp;
    QLabel *daytwotemp;
    QLabel *dayseventemp;
    QLabel *dayfivetemp;
    QLabel *dayfourtemp;
    QLabel *daysixtemp;
    QLabel *daytwo;
    QLabel *daythree;
    QLabel *dayfour;
    QLabel *dayfive;
    QLabel *dayseven;
    QLabel *daysix;
    QLabel *city;
    QLabel *citysearchlabel;
    QLineEdit *lineEdit;
    QPushButton *enterbutton;
    QLabel *applicationLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(760, 650);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(85, 170, 255)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 230, 700, 170));
        groupBox->setStyleSheet(QString::fromUtf8("background-color:#F0F5FA;\n"
"border-radius: 15px; \n"
" box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);"));
        highTemp = new QLabel(groupBox);
        highTemp->setObjectName("highTemp");
        highTemp->setGeometry(QRect(0, 50, 350, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        highTemp->setFont(font);
        highTemp->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        highTemp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        wind = new QLabel(groupBox);
        wind->setObjectName("wind");
        wind->setGeometry(QRect(0, 110, 350, 21));
        wind->setFont(font);
        wind->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        wind->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lowTemp = new QLabel(groupBox);
        lowTemp->setObjectName("lowTemp");
        lowTemp->setGeometry(QRect(350, 50, 350, 21));
        lowTemp->setFont(font);
        lowTemp->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        lowTemp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        humiditylabel = new QLabel(groupBox);
        humiditylabel->setObjectName("humiditylabel");
        humiditylabel->setGeometry(QRect(350, 110, 350, 21));
        humiditylabel->setFont(font);
        humiditylabel->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        humiditylabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(30, 420, 700, 170));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color:#F0F5FA;\n"
"border-radius: 15px; \n"
" box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);"));
        monday = new QLabel(groupBox_2);
        monday->setObjectName("monday");
        monday->setGeometry(QRect(0, 20, 100, 21));
        monday->setStyleSheet(QString::fromUtf8("font: 700  10pt \"Segoe UI\";\n"
"background-color: #F0F5FA;\n"
"color: rgb(0, 0, 0);"));
        monday->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tuesday = new QLabel(groupBox_2);
        tuesday->setObjectName("tuesday");
        tuesday->setGeometry(QRect(100, 20, 100, 21));
        tuesday->setStyleSheet(QString::fromUtf8("font: 700  10pt \"Segoe UI\";\n"
"background-color: #F0F5FA;\n"
"color: rgb(0, 0, 0);"));
        tuesday->setAlignment(Qt::AlignmentFlag::AlignCenter);
        wedenesday = new QLabel(groupBox_2);
        wedenesday->setObjectName("wedenesday");
        wedenesday->setGeometry(QRect(200, 20, 100, 21));
        wedenesday->setStyleSheet(QString::fromUtf8("font: 700  10pt \"Segoe UI\";\n"
"background-color: #F0F5FA;\n"
"color: rgb(0, 0, 0);"));
        wedenesday->setAlignment(Qt::AlignmentFlag::AlignCenter);
        thursday = new QLabel(groupBox_2);
        thursday->setObjectName("thursday");
        thursday->setGeometry(QRect(300, 20, 100, 21));
        thursday->setStyleSheet(QString::fromUtf8("font: 700  10pt \"Segoe UI\";\n"
"background-color: #F0F5FA;\n"
"color: rgb(0, 0, 0);"));
        thursday->setAlignment(Qt::AlignmentFlag::AlignCenter);
        friday = new QLabel(groupBox_2);
        friday->setObjectName("friday");
        friday->setGeometry(QRect(400, 20, 100, 21));
        friday->setStyleSheet(QString::fromUtf8("font: 700  10pt \"Segoe UI\";\n"
"background-color: #F0F5FA;\n"
"color: rgb(0, 0, 0);"));
        friday->setAlignment(Qt::AlignmentFlag::AlignCenter);
        saturday = new QLabel(groupBox_2);
        saturday->setObjectName("saturday");
        saturday->setGeometry(QRect(500, 20, 100, 21));
        saturday->setStyleSheet(QString::fromUtf8("font: 700  10pt \"Segoe UI\";\n"
"background-color: #F0F5FA;\n"
"color: rgb(0, 0, 0);"));
        saturday->setAlignment(Qt::AlignmentFlag::AlignCenter);
        sunday = new QLabel(groupBox_2);
        sunday->setObjectName("sunday");
        sunday->setGeometry(QRect(600, 20, 100, 21));
        sunday->setStyleSheet(QString::fromUtf8("font: 700  10pt \"Segoe UI\";\n"
"background-color: #F0F5FA;\n"
"color: rgb(0, 0, 0);"));
        sunday->setAlignment(Qt::AlignmentFlag::AlignCenter);
        sunny = new QLabel(groupBox_2);
        sunny->setObjectName("sunny");
        sunny->setGeometry(QRect(25, 50, 50, 50));
        sunny->setPixmap(QPixmap(QString::fromUtf8("sunny.png")));
        sunny->setScaledContents(true);
        sunny->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rainy = new QLabel(groupBox_2);
        rainy->setObjectName("rainy");
        rainy->setGeometry(QRect(125, 50, 50, 50));
        rainy->setPixmap(QPixmap(QString::fromUtf8("rainy.png")));
        rainy->setScaledContents(true);
        rainy->setAlignment(Qt::AlignmentFlag::AlignCenter);
        thunder = new QLabel(groupBox_2);
        thunder->setObjectName("thunder");
        thunder->setGeometry(QRect(225, 50, 50, 50));
        thunder->setPixmap(QPixmap(QString::fromUtf8("thunder.png")));
        thunder->setScaledContents(true);
        thunder->setAlignment(Qt::AlignmentFlag::AlignCenter);
        cloudy = new QLabel(groupBox_2);
        cloudy->setObjectName("cloudy");
        cloudy->setGeometry(QRect(325, 50, 50, 50));
        cloudy->setPixmap(QPixmap(QString::fromUtf8("cloudy.png")));
        cloudy->setScaledContents(true);
        cloudy->setAlignment(Qt::AlignmentFlag::AlignCenter);
        snowy = new QLabel(groupBox_2);
        snowy->setObjectName("snowy");
        snowy->setGeometry(QRect(425, 50, 50, 50));
        snowy->setPixmap(QPixmap(QString::fromUtf8("snowy.png")));
        snowy->setScaledContents(true);
        snowy->setAlignment(Qt::AlignmentFlag::AlignCenter);
        foggy = new QLabel(groupBox_2);
        foggy->setObjectName("foggy");
        foggy->setGeometry(QRect(525, 50, 50, 50));
        foggy->setPixmap(QPixmap(QString::fromUtf8("foggy.png")));
        foggy->setScaledContents(true);
        foggy->setAlignment(Qt::AlignmentFlag::AlignCenter);
        humidity = new QLabel(groupBox_2);
        humidity->setObjectName("humidity");
        humidity->setGeometry(QRect(625, 50, 50, 50));
        humidity->setPixmap(QPixmap(QString::fromUtf8("humidity.png")));
        humidity->setScaledContents(true);
        humidity->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dayone = new QLabel(groupBox_2);
        dayone->setObjectName("dayone");
        dayone->setGeometry(QRect(0, 130, 100, 25));
        dayone->setFont(font);
        dayone->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        dayone->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dayonetemp = new QLabel(groupBox_2);
        dayonetemp->setObjectName("dayonetemp");
        dayonetemp->setGeometry(QRect(0, 110, 100, 25));
        dayonetemp->setFont(font);
        dayonetemp->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        dayonetemp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        daythreetemp = new QLabel(groupBox_2);
        daythreetemp->setObjectName("daythreetemp");
        daythreetemp->setGeometry(QRect(200, 110, 100, 25));
        daythreetemp->setFont(font);
        daythreetemp->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        daythreetemp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        daytwotemp = new QLabel(groupBox_2);
        daytwotemp->setObjectName("daytwotemp");
        daytwotemp->setGeometry(QRect(100, 110, 100, 25));
        daytwotemp->setFont(font);
        daytwotemp->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        daytwotemp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dayseventemp = new QLabel(groupBox_2);
        dayseventemp->setObjectName("dayseventemp");
        dayseventemp->setGeometry(QRect(600, 110, 100, 25));
        dayseventemp->setFont(font);
        dayseventemp->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        dayseventemp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dayfivetemp = new QLabel(groupBox_2);
        dayfivetemp->setObjectName("dayfivetemp");
        dayfivetemp->setGeometry(QRect(400, 110, 100, 25));
        dayfivetemp->setFont(font);
        dayfivetemp->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        dayfivetemp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dayfourtemp = new QLabel(groupBox_2);
        dayfourtemp->setObjectName("dayfourtemp");
        dayfourtemp->setGeometry(QRect(300, 110, 100, 25));
        dayfourtemp->setFont(font);
        dayfourtemp->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        dayfourtemp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        daysixtemp = new QLabel(groupBox_2);
        daysixtemp->setObjectName("daysixtemp");
        daysixtemp->setGeometry(QRect(500, 110, 100, 25));
        daysixtemp->setFont(font);
        daysixtemp->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        daysixtemp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        daytwo = new QLabel(groupBox_2);
        daytwo->setObjectName("daytwo");
        daytwo->setGeometry(QRect(100, 130, 100, 25));
        daytwo->setFont(font);
        daytwo->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        daytwo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        daythree = new QLabel(groupBox_2);
        daythree->setObjectName("daythree");
        daythree->setGeometry(QRect(200, 130, 100, 25));
        daythree->setFont(font);
        daythree->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        daythree->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dayfour = new QLabel(groupBox_2);
        dayfour->setObjectName("dayfour");
        dayfour->setGeometry(QRect(300, 130, 100, 25));
        dayfour->setFont(font);
        dayfour->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        dayfour->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dayfive = new QLabel(groupBox_2);
        dayfive->setObjectName("dayfive");
        dayfive->setGeometry(QRect(400, 130, 100, 25));
        dayfive->setFont(font);
        dayfive->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        dayfive->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dayseven = new QLabel(groupBox_2);
        dayseven->setObjectName("dayseven");
        dayseven->setGeometry(QRect(600, 130, 100, 25));
        dayseven->setFont(font);
        dayseven->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        dayseven->setAlignment(Qt::AlignmentFlag::AlignCenter);
        daysix = new QLabel(groupBox_2);
        daysix->setObjectName("daysix");
        daysix->setGeometry(QRect(500, 130, 100, 25));
        daysix->setFont(font);
        daysix->setStyleSheet(QString::fromUtf8("font: 700 italic  12pt \"Segoe UI\";\n"
"color: black;\n"
""));
        daysix->setAlignment(Qt::AlignmentFlag::AlignCenter);
        monday->raise();
        tuesday->raise();
        wedenesday->raise();
        thursday->raise();
        friday->raise();
        saturday->raise();
        sunday->raise();
        rainy->raise();
        thunder->raise();
        cloudy->raise();
        snowy->raise();
        foggy->raise();
        humidity->raise();
        dayone->raise();
        dayonetemp->raise();
        daythreetemp->raise();
        daytwotemp->raise();
        dayseventemp->raise();
        dayfivetemp->raise();
        dayfourtemp->raise();
        daysixtemp->raise();
        daytwo->raise();
        daythree->raise();
        dayfour->raise();
        dayfive->raise();
        dayseven->raise();
        daysix->raise();
        sunny->raise();
        city = new QLabel(centralwidget);
        city->setObjectName("city");
        city->setGeometry(QRect(0, 180, 761, 31));
        city->setStyleSheet(QString::fromUtf8("font: 700 italic  13pt \"Segoe UI\";\n"
"color: black;\n"
""));
        city->setAlignment(Qt::AlignmentFlag::AlignCenter);
        citysearchlabel = new QLabel(centralwidget);
        citysearchlabel->setObjectName("citysearchlabel");
        citysearchlabel->setGeometry(QRect(0, 110, 152, 31));
        citysearchlabel->setStyleSheet(QString::fromUtf8("font: 700  13pt \"Segoe UI\";\n"
"\n"
"color: rgb(0, 0, 0)"));
        citysearchlabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(152, 110, 456, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 255, 255, 51);\n"
"color: rgb(0, 0, 0);"));
        enterbutton = new QPushButton(centralwidget);
        enterbutton->setObjectName("enterbutton");
        enterbutton->setGeometry(QRect(615, 110, 111, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(false);
        enterbutton->setFont(font1);
        enterbutton->setStyleSheet(QString::fromUtf8("font: 700  10pt \"Segoe UI\";\n"
"background-color: #F0F5FA;\n"
"color: black;\n"
"border-radius: 10px; \n"
"box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);\n"
""));
        applicationLabel = new QLabel(centralwidget);
        applicationLabel->setObjectName("applicationLabel");
        applicationLabel->setGeometry(QRect(0, 20, 760, 31));
        applicationLabel->setStyleSheet(QString::fromUtf8("font: 700  13pt \"Segoe UI\";\n"
"text-align:center;\n"
"color: black;"));
        applicationLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        highTemp->setText(QCoreApplication::translate("MainWindow", "Highest Temp:", nullptr));
        wind->setText(QCoreApplication::translate("MainWindow", "Wind:", nullptr));
        lowTemp->setText(QCoreApplication::translate("MainWindow", "Lowest Temp:", nullptr));
        humiditylabel->setText(QCoreApplication::translate("MainWindow", "Humidity:", nullptr));
        groupBox_2->setTitle(QString());
        monday->setText(QCoreApplication::translate("MainWindow", "Mon", nullptr));
        tuesday->setText(QCoreApplication::translate("MainWindow", "Tue", nullptr));
        wedenesday->setText(QCoreApplication::translate("MainWindow", "Wed", nullptr));
        thursday->setText(QCoreApplication::translate("MainWindow", "Thur", nullptr));
        friday->setText(QCoreApplication::translate("MainWindow", "Fri", nullptr));
        saturday->setText(QCoreApplication::translate("MainWindow", "Sat", nullptr));
        sunday->setText(QCoreApplication::translate("MainWindow", "Sun", nullptr));
        sunny->setText(QString());
        rainy->setText(QString());
        thunder->setText(QString());
        cloudy->setText(QString());
        snowy->setText(QString());
        foggy->setText(QString());
        humidity->setText(QString());
        dayone->setText(QCoreApplication::translate("MainWindow", " 03/29", nullptr));
        dayonetemp->setText(QCoreApplication::translate("MainWindow", "35\302\260C", nullptr));
        daythreetemp->setText(QCoreApplication::translate("MainWindow", "27\302\260C", nullptr));
        daytwotemp->setText(QCoreApplication::translate("MainWindow", "28\302\260C", nullptr));
        dayseventemp->setText(QCoreApplication::translate("MainWindow", "27\302\260C", nullptr));
        dayfivetemp->setText(QCoreApplication::translate("MainWindow", "25\302\260C", nullptr));
        dayfourtemp->setText(QCoreApplication::translate("MainWindow", "29\302\260C", nullptr));
        daysixtemp->setText(QCoreApplication::translate("MainWindow", "27\302\260C", nullptr));
        daytwo->setText(QCoreApplication::translate("MainWindow", " 03/30", nullptr));
        daythree->setText(QCoreApplication::translate("MainWindow", " 03/31", nullptr));
        dayfour->setText(QCoreApplication::translate("MainWindow", "04/01", nullptr));
        dayfive->setText(QCoreApplication::translate("MainWindow", "04/02", nullptr));
        dayseven->setText(QCoreApplication::translate("MainWindow", " 04/04", nullptr));
        daysix->setText(QCoreApplication::translate("MainWindow", "  04/03", nullptr));
        city->setText(QCoreApplication::translate("MainWindow", "   Bangkok", nullptr));
        citysearchlabel->setText(QCoreApplication::translate("MainWindow", "  City", nullptr));
        enterbutton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        applicationLabel->setText(QCoreApplication::translate("MainWindow", "     Welcome to our SE16 Weather Forecast Application!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
