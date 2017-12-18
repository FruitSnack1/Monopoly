#ifndef SERVER_H
#define SERVER_H
#include <QWidget>

#include <QTcpSocket>
#include <qDebug>



class server : public QWidget
{
    Q_OBJECT
public:
    server(QTcpSocket *spojeni, QWidget *parent = nullptr);
    QDataStream stream;
    QString zprava;
    QString text;
    QString getZprava() const;
    void setZprava(const QString &value);
   // void sendNumber(int number);

private:
    QTcpSocket *spojeni;
    QString pes;

private slots:
    void clientDisconnected();
    void submitClicked();
    void gotMessage();

signals:
    void messageWrite();

};

#endif // SERVER_H
