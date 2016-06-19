#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include "mainwindow.h"

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = 0);
    ~client();
    int sockfd, fdmax, i;
    fd_set master; // declare master file descriptor
    fd_set read_fds; // declare read socket descriptors
    struct sockaddr_in server_addr, my_addr;
    void connectto_server(int *sockfd, struct sockaddr_in *server_addr, struct sockaddr_in *my_addr, char *s_port, char *c_port, char *ip);
   // void set_clear(int sockfd, fd_set *read_fds, fd_set *master);
   // void send_recv(int i, int sockfd, char c_name[]);
  //  void transf_msg(char *send_buf, char c_name[]);

private:
    Ui::client *ui;
};

#endif // CLIENT_H
