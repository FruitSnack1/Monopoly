#ifndef POLE_H
#define POLE_H
#include <QString>
#include <QList>


class Pole
{
public:
    enum Type {
        None, Chance, Finance, Station, Special, Utility, Land
    };

    Pole();

    int getIndex() const;
    void setIndex(int value);

    QString getName() const;
    void setName(const QString &value);

    int getPrice() const;
    void setPrice(int value);

    QString getColor() const;
    void setColor(const QString &value);

    Type getType() const;
    void setType(const Type &value);



protected:
    QList<Pole> policka;
    Type type;
    int index;
    QString name;
    int price;
    QString color;

};

#endif // POLE_H
