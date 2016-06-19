#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
   //   ip = QString(ui->label_IP->text()).at(0).toAscii();
    QString temp = ui->label_IP->text();
    ip = QString(temp).toStdString()[0];
    temp = ui->label_sport->text();
    s_port = QString(temp).toStdString()[0];
    temp = ui->label_cport->text();
    c_port = QString(temp).toStdString()[0];
    temp = ui->label_cname->text();
    c_name = QString(temp).toStdString()[0];
    this->hide();
    Client client;
    client.setModal(true);
    client.exec();
}
