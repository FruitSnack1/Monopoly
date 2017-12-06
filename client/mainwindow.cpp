#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMainWindow::showMaximized();
    View *view = new View();
    QPixmap pim("../Monopoly/backgroung.jpg");
    scene.addPixmap(pim.scaled(900, 900));
    this->setCentralWidget(view);
    view->setScene(&scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
