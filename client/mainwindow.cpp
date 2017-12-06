#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showMaximized();
    View *view = new View();
    Player *player = new Player();
    QPixmap pim("../client/backgroung.jpg");
    scene.addPixmap(pim.scaled(900, 900));
    player->setPosition(0);
    scene.addItem(player);
    this->setCentralWidget(view);
    view->setScene(&scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
