#include "4enLinea.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.begining();
    w.show();

    return a.exec();
}
