#ifndef PLAYBYPERSONJIN_H
#define PLAYBYPERSONJIN_H
#include <QWidget>
#include<QPushButton>
#include<gamemodel.h>

class playbypersonjin : public QWidget
{     Q_OBJECT
public:
    explicit playbypersonjin(QWidget *parent = nullptr);
    void sendslot();
    void anewplay();
       GameModel *game;//游戏指针
       GameType game_type;//存储游戏类型
       int clickzhong,clickheng;
       bool selectpos = false;
       void initGame();
       void mouseMoveEvent(QMouseEvent *event);
       void mouseReleaseEvent(QMouseEvent *event);
       void Persontime();
   signals:
       void mysignal();
   public slots:
   private:
       QPushButton back;
       QPushButton startnew;
      void paintEvent(QPaintEvent *event);//绘制窗口所需
   };

#endif // PLAYBYPERSONJIN_H
