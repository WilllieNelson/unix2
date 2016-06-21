#include "mainwindow.h"
#include "ui_mainwindow.h"

#define BUFSIZE 2000

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
// Push button connected save username and make new connection
void MainWindow::on_pushButton_connect_clicked()
{
    port = ui->lineEdit_p->text().toInt();
    username =  ui->lineEdit_cname->text();
    server_ip = ui->lineEdit_s->text();
    socket->connectToHost(server_ip, port);

    if(socket->state() == QAbstractSocket::ConnectedState || QAbstractSocket::ConnectingState)
    {
        ui->chatBox->append("Connected Successful");
    }

}
//Send message to server, add username  before the message
void MainWindow::on_pushButton_send_clicked()
{
    QString message = ui->lineEdit_message->text().trimmed();
    message = username + ":" + message;
    socket->write(QString(message).toUtf8());
    ui->chatBox->append(message);
    ui->lineEdit_message->clear();
    ui->lineEdit_message->setFocus();

}
//void MainWindow::testappend()
//{
//    ui->chatBox->append("tesst");
//}
void MainWindow::readyRead()
{
 //   ui->chatBox->append("testready");
    ui->chatBox->append(QString::fromUtf8(socket->readLine()).trimmed());
   // QString inmessage;
//    while(socket->canReadLine())
//    {
//  //      inmessage = QString::fromUtf8(socket->readLine()).trimmed();
//        ui->chatBox->append(QString::fromUtf8(socket->readLine()).trimmed());
//        ui->chatBox->append("LUL");
//    }

}

//void MainWindow::on_lineEdit_message_returnPressed()
//{
//    connect(ui->lineEdit_message, SIGNAL(returnPressed()),ui->pushButton_send,SIGNAL(clicked()));
//}

//void MainWindow::on_lineEdit_cname_returnPressed()
//{
//    connect(ui->lineEdit_cname, SIGNAL(returnPressed()),ui->pushButton_connect,SIGNAL(clicked()));
//}
