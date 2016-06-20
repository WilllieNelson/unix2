#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>


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

//    void testappend();

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
