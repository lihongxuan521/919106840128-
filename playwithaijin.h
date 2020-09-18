#ifndef PLAYWITHAIJIN_H
#define PLAYWITHAIJIN_H
#include <QWidget>
#include<QPushButton>
#include<gamemodel.h>
class playwithaijin : public QWidget
{
    Q_OBJECT
public:
    explicit playwithaijin(QWidget *parent = nullptr);
    void sendslot();
    void anewplay();
    GameModel *game;//游戏指针
    GameType game_type;//存储游戏类型

    int clickzhong,clickheng;
    bool selectpos = false;

    void initGame();
    void initAIGame();
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void Persontime();
    void AItime();
    void initPVEGame();
signals:
    void mysignal();
public slots:
private:
    QPushButton back;
    QPushButton startnew;
    void paintEvent(QPaintEvent *event);//绘制窗口所需
};

#endif // PLAYWITHAIJIN_H
