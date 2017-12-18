#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void gotMessage();
    void connectioncreated();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *spojeni;
};

#endif // MAINWINDOW_H
