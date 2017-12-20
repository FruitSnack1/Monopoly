#include "server.h"

server::server(QTcpSocket *spojeni, QWidget *parent) : QWidget::QWidget(parent)
{
    this->spojeni = spojeni;
    connect(spojeni, &QTcpSocket::readyRead, this, &server::gotMessage);
    connect(spojeni, &QTcpSocket::disconnected, this, &server::clientDisconnected);
    stream.setDevice(this->spojeni);
    stream.setVersion(QDataStream::Qt_5_0);
    stream.startTransaction();

}

QString server::getZprava() const
{
    return zprava;
}

void server::setZprava(const QString &value)
{
    zprava = value;
}
//void server::sendNumber(int number)
//{
//    qDebug() << "Chceme odeslat novou zprávu";
//    QByteArray block;
//    QDataStream output(&block, QIODevice::WriteOnly);
//    output.setVersion(QDataStream::Qt_5_0);
//    output << QString(number);
//    spojeni->write(block);
//}
void server::clientDisconnected()
{
    qDebug()<<"pes";
}

void server::submitClicked()
{
    qDebug() << "Chceme odeslat novou zprávu";
    QByteArray block;
    QDataStream output(&block, QIODevice::WriteOnly);
    output.setVersion(QDataStream::Qt_5_0);
//    output << message() << "\r\n";
//    historie->append(message() + "\n");
//    vstup->setText("");
    spojeni->write(block);
}

void server::gotMessage()
{
    QString slovo;
    stream >> slovo;
    qDebug()<<"zprava od klienta";
    qDebug()<< slovo;
    setZprava(slovo);
    qDebug()<<getZprava();
    emit(messageWrite());
    text = slovo;



}
