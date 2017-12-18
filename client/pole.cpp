#include "pole.h"

Pole::Pole()
{

}

int Pole::getIndex() const
{
    return index;
}

void Pole::setIndex(int value)
{
    index = value;
}

QString Pole::getName() const
{
    return name;
}

void Pole::setName(const QString &value)
{
    name = value;
}

int Pole::getPrice() const
{
    return price;
}

void Pole::setPrice(int value)
{
    price = value;
}

QString Pole::getColor() const
{
    return color;
}

void Pole::setColor(const QString &value)
{
    color = value;
}

Pole::Type Pole::getType() const
{
    return type;
}

void Pole::setType(const Type &value)
{
    type = value;
}


