#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
#include <QHostAddress>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    spojeni = new QTcpSocket(this);
    connect(spojeni, &QTcpSocket::connected, this, &MainWindow::connectioncreated);
    spojeni->connectToHost(QHostAddress("127.0.0.1"), 4899);
    connect(spojeni, &QTcpSocket::readyRead, this, &MainWindow::gotMessage);
    qDebug()<<"Client start";
    ui->setupUi(this);
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
}



void MainWindow::connectioncreated()
{
    qDebug() << "Connection established";
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray block;
    QDataStream output(&block, QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_0);
    output << QString(ui->lineEdit->text());
    spojeni->write(block);



}
