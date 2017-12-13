#include "mainwindow.h"
#include <QApplication>
#include "viewv.h"
#include "pole.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Viewv v;
    v.setName("Policka");
    v.addArray(0,"START",NULL,NULL,Pole::None);
    v.addArray(1,"Mediter-Ranean Avenue",60,"brown",Pole::Land);
    v.addArray(2,"Community chest",NULL,NULL,Pole::Finance);
    v.addArray(3,"Baltic Avenue",60,"brown",Pole::Land);
    v.addArray(4,"INCOME TAX",200,NULL,Pole::Special);
    v.addArray(5,"Reading railroad",200,NULL,Pole::Station);
    v.addArray(6,"Oriental Avenue",100,"light blue",Pole::Land);
    v.addArray(7,"CHANCE",NULL,NULL,Pole::Chance);
    v.addArray(8,"Vermont Avenue",100,"light blue",Pole::Land);
    v.addArray(9,"Connecticut Avenue",120,"light blue",Pole::Land);
    v.addArray(10,"JAIL",NULL,NULL,Pole::Special);
    v.addArray(11,"St.Charles place",140,"purple",Pole::Land);
    v.addArray(12,"Electric Company",150,NULL,Pole::Utility);
    v.addArray(13,"States Avenue",140,"purple",Pole::Land);
    v.addArray(14,"Virginia Avenue",160,"purple",Pole::Land);
    v.addArray(15,"Pennsylvania railroad",200,NULL,Pole::Station);
    v.addArray(16,"St. James place",180,"orange",Pole::Land);
    v.addArray(17,"Community chest",NULL,NULL,Pole::Finance);
    v.addArray(18,"Tennessee Avenue",180,"orange",Pole::Land);
    v.addArray(19,"New York",200,"orange",Pole::Land);
    v.addArray(20,"FREE PARKING",NULL,NULL,Pole::None);
    v.addArray(21,"Kentucky Avenue",220,"red",Pole::Land);
    v.addArray(22,"CHANCE",NULL,NULL,Pole::Chance);
    v.addArray(23,"Indiana Avenue",220,"red",Pole::Land);
    v.addArray(24,"Illinois Avenue",240,"red",Pole::Land);
    v.addArray(25,"B.&O. railroad",200,NULL,Pole::Station);
    v.addArray(26,"Atlantic Avenue",260,"yellow",Pole::Land);
    v.addArray(27,"Ventnor Avenue",260,"yellow",Pole::Land);
    v.addArray(28,"Water Works",150,NULL,Pole::Utility);
    v.addArray(29,"Marvin Gardens",280,"yellow",Pole::Land);
    v.addArray(30,"GO TO JAIL",NULL,NULL,Pole::Special);
    v.addArray(31,"Pacific Avenue",300,"green",Pole::Land);
    v.addArray(32,"North Carolina Avenue",300,"green",Pole::Land);
    v.addArray(33,"Community chest",NULL,NULL,Pole::Finance);
    v.addArray(34,"Pennsylvania Avenue",320,"green",Pole::Land);
    v.addArray(35,"Short line",200,NULL,Pole::Station);
    v.addArray(36,"CHANCE",NULL,NULL,Pole::Chance);
    v.addArray(37,"Park Place",350,"blue",Pole::Land);
    v.addArray(38,"LUXURY TAX",NULL,NULL,Pole::Special);
    v.addArray(39,"Boardwalk",400,"blue",Pole::Land);
    v.printArray();

    return a.exec();
}
