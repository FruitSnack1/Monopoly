#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    if(!tcpserver.listen(QHostAddress::Any, 4899))
    {
        qWarning() << "Nepodarilo se spustit naslouchani serveru";
    }
    else
    {
        qDebug() << tcpserver.serverPort();
        connect(&tcpserver, &QTcpServer::newConnection, this, &MainWindow::newClient);


    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onMessageWrite()
{

   server *sender =  static_cast<server *>(QObject::sender());
   qDebug()<<sender;
   ui->textBrowser->setText(ui->textBrowser->toPlainText()+sender->getZprava()+"\n");

   QByteArray block;
   QDataStream output(&block, QIODevice::WriteOnly);
   output.setVersion(QDataStream::Qt_5_0);
   output << QString("5");
   for (int x = 0; x < clients.length(); ++x) {
       QTcpSocket *socket = clients.at(x);
       socket->write(block);
       qDebug()<<clients.at(x);

   }



}

void MainWindow::newClient()
{
    QTcpSocket *client = tcpserver.nextPendingConnection();
    qDebug() << "Nove spojeni";
    server *s = new server(client, this);
    clients.append(client);
    connect(s,&server::messageWrite,this, &MainWindow::onMessageWrite);
    ClientATM++;
    if (ClientCount==ClientATM) {
       isReady();
    }

}

void MainWindow::isReady()
{
    QByteArray block;
    QDataStream output(&block, QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_0);
    output << QString("ready");
    for (int x = 0; x < clients.length(); ++x) {
        QTcpSocket *socket = clients.at(x);
        socket->write(block);
    }


}



void MainWindow::on_pushButton_clicked()
{
    QByteArray block;
    QDataStream output(&block, QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_0);
    output << QString(ui->lineEdit->text());
    for (int x = 0; x < clients.length(); ++x) {
        QTcpSocket *socket = clients.at(x);
        socket->write(block);
        qDebug()<<clients.at(x);

    }


}

//void MainWindow::giveNumber(server *sender)
//{
//    QByteArray block;
//    QDataStream output(&block, QIODevice::WriteOnly);
//    output.setVersion(QDataStream::Qt_5_0);
//    output << int(5);
//    sender->sendNumber(5);
//}
