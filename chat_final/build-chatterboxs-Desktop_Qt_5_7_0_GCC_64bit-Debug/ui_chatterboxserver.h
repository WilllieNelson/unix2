/********************************************************************************
** Form generated from reading UI file 'chatterboxserver.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATTERBOXSERVER_H
#define UI_CHATTERBOXSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatterBoxServer
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatterBoxServer)
    {
        if (ChatterBoxServer->objectName().isEmpty())
            ChatterBoxServer->setObjectName(QStringLiteral("ChatterBoxServer"));
        ChatterBoxServer->resize(400, 300);
        menuBar = new QMenuBar(ChatterBoxServer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ChatterBoxServer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatterBoxServer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ChatterBoxServer->addToolBar(mainToolBar);
        centralWidget = new QWidget(ChatterBoxServer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ChatterBoxServer->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ChatterBoxServer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChatterBoxServer->setStatusBar(statusBar);

        retranslateUi(ChatterBoxServer);

        QMetaObject::connectSlotsByName(ChatterBoxServer);
    } // setupUi

    void retranslateUi(QMainWindow *ChatterBoxServer)
    {
        ChatterBoxServer->setWindowTitle(QApplication::translate("ChatterBoxServer", "ChatterBoxServer", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatterBoxServer: public Ui_ChatterBoxServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATTERBOXSERVER_H
