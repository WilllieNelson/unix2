/********************************************************************************
** Form generated from reading UI file 'chat_client.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_CLIENT_H
#define UI_CHAT_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_chat_client
{
public:

    void setupUi(QDialog *chat_client)
    {
        if (chat_client->objectName().isEmpty())
            chat_client->setObjectName(QStringLiteral("chat_client"));
        chat_client->resize(400, 300);

        retranslateUi(chat_client);

        QMetaObject::connectSlotsByName(chat_client);
    } // setupUi

    void retranslateUi(QDialog *chat_client)
    {
        chat_client->setWindowTitle(QApplication::translate("chat_client", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class chat_client: public Ui_chat_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_CLIENT_H
