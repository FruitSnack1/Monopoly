#include "player.h"
#include <QPainter>
#include <QJsonArray>

Player::Player(const int index)
{
   setIndex(index);
   setPosition(0);
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
    QImage img("../client/players.png");
    img = img.scaled(boundingRect().width()*4,boundingRect().height());
    img =img.copy(QRect(boundingRect().width()*index,0,boundingRect().width(), boundingRect().height()));
    painter->drawImage(QPoint(0,0),img);
}

int Player::getIndex() const
{
    return index;
}

void Player::setIndex(int value)
{
    index = value;
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

    int x;
    int y;
    int list[11] = {840, 745, 672, 599, 524, 451, 376, 303, 229, 154, 60};
    if(value == 0){
        x = 840 - boundingRect().width()/2;
        y = 840 - boundingRect().height()/2;
    }
    if(value > 0 && value < 11){
        x = list[value] - boundingRect().width()/2;
        y = 840 - boundingRect().height()/2;
    }
    if(value > 10 && value < 21){
        x = 60 - boundingRect().width()/2;
        y = list[value-10] - boundingRect().height()/2;
    }
    if(value > 20 && value < 31){
        x = list[30-value] - boundingRect().width()/2;
        y = 60 - boundingRect().height()/2;
    }
    if(value > 30 && value < 40){
        x = 840 - boundingRect().width()/2;
        y = list[40-value] - boundingRect().height()/2;
    }
    this->setPos(x,y);
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

