#ifndef CHAT_CLIENT_H
#define CHAT_CLIENT_H

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
class chat_client;
}

class chat_client : public QDialog
{
    Q_OBJECT

public:
    explicit chat_client(QWidget *parent = 0);
    ~chat_client();
    int sockfd, fdmax, i;
    fd_set master; // declare master file descriptor
    fd_set read_fds; // declare read socket descriptors
    struct sockaddr_in server_addr, my_addr;
    void connectto_server(int *sockfd, struct sockaddr_in *server_addr, struct sockaddr_in *my_addr, char *s_port, char *c_port, char *ip);

private:
    Ui::chat_client *ui;
};

#endif // CHAT_CLIENT_H
