#ifndef PLAYBYPERSON_H
#define PLAYBYPERSON_H
#include <QWidget>
#include<QPushButton>
#include<gamemodel.h>

class playbyperson : public QWidget
{     Q_OBJECT
public:
    explicit playbyperson(QWidget *parent = nullptr);//新界面重绘地图
    void sendslot();
       GameModel *game;                             //游戏指针
       GameType game_type;                          //存储游戏类型
       int clickzhong,clickheng;
        bool selectpos = false;
       void initGame();
       void mouseMoveEvent(QMouseEvent *event);
       void mouseReleaseEvent(QMouseEvent *event);
       void Persontime();
         void anewplay();
   signals:
       void mysignal();
   public slots:
   private:
       QPushButton back;
       QPushButton startnew;
      void paintEvent(QPaintEvent *event);//绘制窗口所需
   };

#endif // PLAYBYPERSON_H
