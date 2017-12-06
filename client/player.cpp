#include "player.h"
#include <QPainter>
#include <QJsonArray>

Player::Player()
{

}

QRectF Player::boundingRect() const
{
    return QRect(0,0, 40,40);
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(boundingRect());
}

QString Player::getName() const
{
    return name;
}

void Player::setName(const QString &value)
{
    name = value;
}

int Player::getPosition() const
{
    return position;
}

void Player::setPosition(int value)
{
    position = value;
}

int Player::getMoney() const
{
    return money;
}


void Player::setMoney(int value)
{
    money = value;
}

void Player::addLand(const int index)
{
    lands.append(index);
}

bool Player::delLand(const int index)
{
    if(lands.removeOne(index))
        return true;
    else
        return false;
}


QJsonObject Player::toJsonObject() const
{
    QJsonObject o;
    o["name"] = getName();
    o["position"] = getPosition();
    o["money"] = getMoney();
    QJsonArray a;
    for (int i = 0; i < lands.length(); ++i) {
        a.append(lands[i]);
    }
    o["lands"] = a;
    return o;
}

