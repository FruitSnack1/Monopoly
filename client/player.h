#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QJsonObject>
#include <QList>

class Player : public QGraphicsItem
{
public:
    Player();

    QString getName() const;
    void setName(const QString &value);

    int getPosition() const;
    void setPosition(int value);

    int getMoney() const;
    void setMoney(int value);

    void addLand(const int index);
    bool delLand(const int index);

    QJsonObject toJsonObject() const;

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    QString name;
    int position;
    int money;
    QList<int > lands;
};

#endif // PLAYER_H
