#include "chat_client.h"
#include "ui_chat_client.h"

chat_client::chat_client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat_client)
{
    ui->setupUi(this);
}

chat_client::~chat_client()
{
    delete ui;
}

chat_client::connectto_server(int *sockfd, struct sockaddr_in *server_addr, struct sockaddr_in *my_addr, char *s_port, char *c_port, char *ip)
{
    if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket");
        exit(1);
    }
    server_addr->sin_family = AF_INET;
    server_addr->sin_port = htons(atoi(s_port));
    server_addr->sin_addr.s_addr = inet_addr(ip);
    memset(server_addr->sin_zero, '\0', sizeof server_addr->sin_zero);

    my_addr->sin_family = AF_INET;
    my_addr->sin_port = htons(atoi(c_port));
    my_addr->sin_addr.s_addr = inet_addr(ip);
    memset(my_addr->sin_zero, '\0', sizeof my_addr->sin_zero);

    if(connect(*sockfd, (struct sockaddr *)server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }
}
