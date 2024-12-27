/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label1;
    QLabel *label2;
    QWidget *widget;
    QPushButton *AddButton;
    QWidget *widget2;
    QWidget *widget3;
    QLabel *totalExpensesLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(450, 463);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 30, 51, 51));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 25px; \n"
"    background-color: #ffa500; \n"
"    color: white;\n"
"    font-weight: bold; \n"
"    border: 2px solid #cc8400; \n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #cc8400; \n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #ff7f00;\n"
"}\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 170, 71, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #28a745;\n"
"    color: white;\n"
"    font-weight: bold; \n"
"    border: 2px solid #218838; \n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #218838;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1e7e34; \n"
"}\n"
""));
        label1 = new QLabel(centralwidget);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(170, 80, 91, 21));
        label1->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 10pt;     \n"
"    text-align: center;   \n"
"    color: black;        \n"
"}\n"
""));
        label2 = new QLabel(centralwidget);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(30, 200, 71, 21));
        label2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 10pt;     \n"
"    text-align: center;   \n"
"    color: black;        \n"
"}\n"
""));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 100, 451, 51));
        widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: #ffa500;\n"
"}"));
        AddButton = new QPushButton(widget);
        AddButton->setObjectName("AddButton");
        AddButton->setGeometry(QRect(200, 10, 31, 31));
        AddButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 10px;\n"
"    background-color: #28a745;\n"
"    color: white;\n"
"    font-weight: bold; \n"
"    border: 2px solid #218838; \n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #218838;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #1e7e34; \n"
"}\n"
""));
        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(0, 0, 451, 21));
        widget2->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: #ffa500;\n"
"}"));
        widget3 = new QWidget(centralwidget);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(0, 400, 451, 21));
        widget3->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: #28a745;\n"
"}"));
        totalExpensesLabel = new QLabel(centralwidget);
        totalExpensesLabel->setObjectName("totalExpensesLabel");
        totalExpensesLabel->setGeometry(QRect(28, 50, 101, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 450, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Wallet", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Food", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">0</p></body></html>", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        totalExpensesLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
