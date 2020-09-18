#ifndef PLAYWITHAI_H
#define PLAYWITHAI_H
#include <QWidget>
#include<QPushButton>
#include<gamemodel.h>
class playwithai : public QWidget
{
    Q_OBJECT
public:
    explicit playwithai(QWidget *parent = nullptr);
    void sendslot();
    void anewplay();
    GameModel *game;
    GameType game_type;

    int clickzhong,clickheng;
    bool selectpos = false;

    void initGame();
    void initAIGame();
    void AItime();
    void Persontime();
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void initPVEGame();
signals:
    void mysignal();
public slots:
private:
    QPushButton back;
    QPushButton startnew;
    void paintEvent(QPaintEvent *event);//绘制窗口所需
};

#endif // PLAYWITHAI_H
