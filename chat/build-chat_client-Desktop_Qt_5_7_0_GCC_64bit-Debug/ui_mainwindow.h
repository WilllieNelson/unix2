/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_IP;
    QLabel *label_sport;
    QLabel *label_cport;
    QLabel *label_cname;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_IP;
    QLineEdit *lineEdit_sport;
    QLineEdit *lineEdit_cport;
    QLineEdit *lineEdit_cname;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 81, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 210, 101, 23));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 50, 111, 151));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_IP = new QLabel(widget);
        label_IP->setObjectName(QStringLiteral("label_IP"));

        verticalLayout->addWidget(label_IP);

        label_sport = new QLabel(widget);
        label_sport->setObjectName(QStringLiteral("label_sport"));

        verticalLayout->addWidget(label_sport);

        label_cport = new QLabel(widget);
        label_cport->setObjectName(QStringLiteral("label_cport"));

        verticalLayout->addWidget(label_cport);

        label_cname = new QLabel(widget);
        label_cname->setObjectName(QStringLiteral("label_cname"));

        verticalLayout->addWidget(label_cname);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(186, 40, 171, 171));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_IP = new QLineEdit(widget1);
        lineEdit_IP->setObjectName(QStringLiteral("lineEdit_IP"));

        verticalLayout_2->addWidget(lineEdit_IP);

        lineEdit_sport = new QLineEdit(widget1);
        lineEdit_sport->setObjectName(QStringLiteral("lineEdit_sport"));

        verticalLayout_2->addWidget(lineEdit_sport);

        lineEdit_cport = new QLineEdit(widget1);
        lineEdit_cport->setObjectName(QStringLiteral("lineEdit_cport"));

        verticalLayout_2->addWidget(lineEdit_cport);

        lineEdit_cname = new QLineEdit(widget1);
        lineEdit_cname->setObjectName(QStringLiteral("lineEdit_cname"));

        verticalLayout_2->addWidget(lineEdit_cname);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Login</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        label_IP->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Server IP</p></body></html>", 0));
        label_sport->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Server port</p></body></html>", 0));
        label_cport->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Client port</p></body></html>", 0));
        label_cname->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Name</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
