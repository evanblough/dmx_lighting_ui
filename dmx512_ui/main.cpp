#include "mainwindow.h"

#include <QApplication>
#include <QPalette>
#include <QColor>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#define PORT 8080


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QColor light(192,255,44);
    QColor mid(84,201,87);
    QColor dark(27,38,20);
    QColor text(206,250,207);
    QPalette color_scheme(light,dark,light,dark,mid,text,dark);
    int temp_conn = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    if(temp_conn < 0){printf("Fuck\n"); return -1;}
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    if (connect(temp_conn, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    w.remote_sock = temp_conn;
    w.setPalette(color_scheme);
    w.show();
    return a.exec();
}
