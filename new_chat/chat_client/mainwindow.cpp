#include "mainwindow.h"
#include "ui_mainwindow.h"

#define BUFSIZE 2000

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// Push button connected save username and make new connection
void MainWindow::on_pushButton_connect_clicked()
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
//    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    socket->connectToHost("localhost", 5000);
    username =  ui->lineEdit_cname->text();
}
//Send message to server, add username  before the message
void MainWindow::on_pushButton_send_clicked()
{
    QString message = ui->lineEdit_message->text().trimmed();
    message = username + ":" + message;
    socket->write(QString(message).toUtf8());
    ui->lineEdit_message->clear();
    ui->lineEdit_message->setFocus();

}

void MainWindow::readyRead()
{
    char recv_buf[BUFSIZE];
    int nbyte_recvd;
    QString inmessage;
    while(socket->canReadLine())
    {
        inmessage = QString::fromUtf8(socket->readLine()).trimmed();
        qDebug() << inmessage;
        ui->chatBox->append(inmessage);
    }
//    nbyte_recvd = recv(0,recv_buf,BUFSIZE,0);
//      qDebug() << recv_buf;
//     inmessage = QString::fromUtf8(recv_buff).trimmed();
//    qDebug() << inmessage;
//    ui->chatBox->append(inmessage);
}
