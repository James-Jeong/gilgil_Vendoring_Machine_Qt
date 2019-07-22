#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.disable_button(w.money);

    Widget w2;
    w2.show();
    w2.disable_button(w2.money);

    return a.exec();
}
