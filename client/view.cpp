#include "view.h"

View::View()
{

}

View::View(QGraphicsScene *scene){
   setScene(scene);
}

void View::addArray(Pole p)
{
    this->policko.append(p);
}

void View::addArray(int index, QString name, int price, QString color, Pole::Type type)
{
    Pole p;
    p.setName(name);
    p.setIndex(index);
    p.setPrice(price);
    p.setColor(color);
    p.setType(type);
    this->policko.append(p);
}
