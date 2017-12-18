#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showMaximized();
    Player *player = new Player(0);
    QPixmap pim("../client/backgroung.jpg");
    scene.addPixmap(pim.scaled(900, 900));
    player->setPosition(20);
    scene.addItem(player);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setFixedSize(904,904);
    ui->graphicsView->setGeometry(10,10,10,10);
}

MainWindow::~MainWindow()
{
    delete ui;
}
