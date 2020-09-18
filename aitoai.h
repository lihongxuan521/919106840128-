#ifndef AITOAI_H
#define AITOAI_H
#include <QWidget>                      //包含主页面
#include<QPushButton>                   //为定义按钮
#include<gamemodel.h>                   //为使用gamemodel里说明的函数
class aitoai : public QWidget
{
    Q_OBJECT
public:
    explicit aitoai(QWidget *parent = nullptr);    //新界面重绘背景
    void sendslot();                               //发送信号的函数
    void anewplay();                               //开启一轮新的游戏
    GameModel *game;                               //游戏指针
    GameType game_type;                            //存储游戏类型
    int clickzhong,clickheng;                      //储存鼠标点击点的信息
    bool selectpos = false;                        //是否能够下棋的函数

    void initAIGame();                             //开始AI游戏
    void mouseMoveEvent(QMouseEvent *event);       //鼠标移动函数
    void mouseReleaseEvent(QMouseEvent *event);    //鼠标释放函数
    void AItime();                                 //AI的回合
    void AI2time();                                //AI2的回合
signals:
    void mysignal();                              //发送信号所需
public slots:
private:
    QPushButton back;                              //定义返回主页面的按钮
    QPushButton startnew;                          //定义开始新游戏的按钮
    void paintEvent(QPaintEvent *event);           //绘制窗口所需
};


#endif // AITOAI_H
