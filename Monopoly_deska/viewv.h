#ifndef VIEWV_H
#define VIEWV_H
#include <QGraphicsView>
#include "pole.h"
#include <QDebug>
#include <QFile>



class Viewv : public QGraphicsView
{
public:
    Viewv();
    Viewv(QGraphicsScene *scene);

    void addArray(Pole p);
    void addArray(int index, QString name, int price, QString color, Pole::Type type);
    void printArray();
    void save();

    QString getName() const;
    void setName(const QString &value);

private:

    int width;
    int height;

    QList<Pole> policko;
    QString name;

};

#endif // VIEWV_H
