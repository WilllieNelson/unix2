#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTextEdit>

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
    QString server_ip;
    int port;

//    void testappend();

private slots:
    void on_pushButton_connect_clicked();

    void on_pushButton_send_clicked();

    void readyRead();


    //void send_recv(int i, int sockfd, char c_name[])
//    void on_lineEdit_message_returnPressed();
//    void on_lineEdit_cname_returnPressed();

  //  QString success_m ;


private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
