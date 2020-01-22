#include "ImageExplorer.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ImageExplorer w;
    w.show();
    return a.exec();
}
