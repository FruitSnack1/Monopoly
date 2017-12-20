#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showMaximized();
    player = new Player(0);
    QPixmap pim("../client/backgroung.jpg");
    scene.addPixmap(pim.scaled(900, 900));
    player->setPosition(0);
    scene.addItem(player);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setFixedSize(904,904);
    ui->graphicsView->setGeometry(10,10,10,10);
    ui->widget->setGeometry(950,10,10,10);
    ui->widget->setFixedSize(300,300);
    spojeni = new QTcpSocket(this);
    connect(spojeni, &QTcpSocket::connected, this, &MainWindow::connectioncreated);
    spojeni->connectToHost(QHostAddress("127.0.0.1"), 4899);
    connect(spojeni, &QTcpSocket::readyRead, this, &MainWindow::gotMessage);
    qDebug()<<"Client start";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gotMessage()
{
    qDebug() << "New message";
    QDataStream stream;
    stream.setDevice(spojeni);
    stream.setVersion(QDataStream::Qt_5_0);
    stream.startTransaction();
    QString slovo;
    stream >> slovo;
    qDebug() << slovo;
    ui->textBrowser->setText(ui->textBrowser->toPlainText()+slovo+"\n");
    player->setPosition((player->getPosition() + slovo.toInt())%40);
}



void MainWindow::connectioncreated()
{
    qDebug() << "Connection established";
}


void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"pes";
    QByteArray block;
    QDataStream output(&block, QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_0);
    output << QString(ui->lineEdit->text());
    spojeni->write(block);

}
