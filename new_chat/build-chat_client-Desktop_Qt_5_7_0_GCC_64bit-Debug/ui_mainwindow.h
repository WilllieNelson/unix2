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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_message;
    QPushButton *pushButton_send;
    QPushButton *pushButton_connect;
    QTextBrowser *chatBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_s;
    QLineEdit *lineEdit_s;
    QLabel *label_p;
    QLineEdit *lineEdit_p;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_cname;
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
        lineEdit_message = new QLineEdit(centralWidget);
        lineEdit_message->setObjectName(QStringLiteral("lineEdit_message"));
        lineEdit_message->setGeometry(QRect(0, 210, 291, 31));
        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setGeometry(QRect(300, 210, 101, 31));
        pushButton_send->setAutoDefault(true);
        pushButton_connect = new QPushButton(centralWidget);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(320, 0, 80, 51));
        chatBox = new QTextBrowser(centralWidget);
        chatBox->setObjectName(QStringLiteral("chatBox"));
        chatBox->setGeometry(QRect(0, 50, 401, 161));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(1, 0, 311, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_s = new QLabel(widget);
        label_s->setObjectName(QStringLiteral("label_s"));

        horizontalLayout->addWidget(label_s);

        lineEdit_s = new QLineEdit(widget);
        lineEdit_s->setObjectName(QStringLiteral("lineEdit_s"));

        horizontalLayout->addWidget(lineEdit_s);

        label_p = new QLabel(widget);
        label_p->setObjectName(QStringLiteral("label_p"));

        horizontalLayout->addWidget(label_p);

        lineEdit_p = new QLineEdit(widget);
        lineEdit_p->setObjectName(QStringLiteral("lineEdit_p"));

        horizontalLayout->addWidget(lineEdit_p);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(1, 25, 311, 25));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_cname = new QLabel(widget1);
        label_cname->setObjectName(QStringLiteral("label_cname"));

        horizontalLayout_2->addWidget(label_cname);

        lineEdit_cname = new QLineEdit(widget1);
        lineEdit_cname->setObjectName(QStringLiteral("lineEdit_cname"));

        horizontalLayout_2->addWidget(lineEdit_cname);

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

        pushButton_send->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_send->setText(QApplication::translate("MainWindow", "Send", 0));
        pushButton_connect->setText(QApplication::translate("MainWindow", "Connect", 0));
        label_s->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Server:</p></body></html>", 0));
        label_p->setText(QApplication::translate("MainWindow", "Port:", 0));
        label_cname->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Client name:</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
