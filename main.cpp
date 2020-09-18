#include "widget.h"
#include <QApplication>
#include<QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.setWindowTitle("瑄瑄牌六子棋小游戏");//主窗口的标题

    w.show();

    return a.exec();
}
