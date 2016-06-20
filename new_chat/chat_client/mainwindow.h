#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString username;

private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_send_clicked();

    void readyRead();

    //void send_recv(int i, int sockfd, char c_name[])

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
