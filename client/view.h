#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "pole.h"

class View : public QGraphicsView
{
public:
    View();
    View(QGraphicsScene *scene);
    void addArray(Pole p);
    void addArray(int index, QString name, int price, QString color, Pole::Type type);
    QList<Pole> policko;
};

#endif // VIEW_H
