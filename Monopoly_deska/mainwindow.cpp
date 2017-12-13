#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "viewv.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Viewv *viewv = new Viewv(&scene);
    this->setCentralWidget(viewv);
}

MainWindow::~MainWindow()
{
    delete ui;
}
