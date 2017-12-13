#include "viewv.h"


Viewv::Viewv()
{

}

Viewv::Viewv(QGraphicsScene *scene)
{
    setScene(scene);
    width = 900;
    height = 900;

    this->scene()->addRect(0,0,width,height, QPen(Qt::black),QBrush(QColor(230,230,230)));
}

void Viewv::addArray(Pole p)
{
    this->policko.append(p);
}

void Viewv::addArray(int index, QString name, int price, QString color, Pole::Type type)
{
    Pole p;
    p.setName(name);
    p.setIndex(index);
    p.setPrice(price);
    p.setColor(color);
    p.setType(type);
    this->policko.append(p);
}

void Viewv::printArray()
{
    qDebug()<< getName();
    for (int i = 0; i < policko.count(); ++i) {
        qDebug()<< policko[i].getIndex()<<
                   policko[i].getName()<<
                   policko[i].getPrice()<<
                   policko[i].getColor()<<
                   policko[i].getType();
    }
}

void Viewv::save()
{

}

QString Viewv::getName() const
{
    return name;
}

void Viewv::setName(const QString &value)
{
    name = value;
}





