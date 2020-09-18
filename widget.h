#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include<playwithai.h>
#include<playwithaijin.h>
#include<gamemodel.h>
#include<playbyperson.h>
#include<playbypersonjin.h>
#include<aitoai.h>
class Widget : public QWidget
{
    Q_OBJECT

public:
   Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPushButton b1;   //定义切换页面的按钮
    QPushButton b2;
    QPushButton b3;
    QPushButton b4;
    QPushButton b5;
    QPushButton b6;
    playbyperson *w1;  //定义新的窗口
    playwithai *w2;
    playbypersonjin *w3;
    playwithaijin *w4;
    aitoai *w5;
};


#endif // MAINWIDGET_H
