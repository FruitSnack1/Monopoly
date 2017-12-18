#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include "server.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void onMessageWrite();
    //server ser;
private  slots:
    void newClient();
    void isReady();
    void on_pushButton_clicked();
   // void giveNumber(server *sender);

private:
    Ui::MainWindow *ui;
    QTcpServer tcpserver;
    int ClientCount=2;
    int ClientATM=0;
    QList<QTcpSocket *>clients;
};

#endif // MAINWINDOW_H
