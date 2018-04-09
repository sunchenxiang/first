#include "dialog.h"
#include <QApplication>
#include"mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    MainWindow q;
    QObject::connect(&q,SIGNAL(showdialog()),&w,SLOT(showw()));
    return a.exec();
}
