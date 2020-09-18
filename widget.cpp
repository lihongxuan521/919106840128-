#include "widget.h"
#include"QTime"
#include"QPushButton"
#include"QPixmap"
#include"QPalette"
#include"QBitmap"
Widget::Widget(QWidget *parent) :
    QWidget(parent)
{  //设置游戏图标
    this->setWindowIcon(QPixmap(":/new/prefix1/w7tu.jpg"));
    //设置标题
    QPixmap bgImage(":/new/prefix1/wtu.jpg");
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background,bgImage);
    this->setPalette(bgPalette);
    b1.setParent(this);
    b1.setText("人人模式");
    b1.move(90,50);
    b2.setParent(this);
    b2.setText("人机模式");
    b2.move(90,150);
    b3.setParent(this);
    b3.setText("人人禁手模式");
    b3.move(90,250);
    b4.setParent(this);
    b4.setText("人机禁手模式");
    b4.move(90,350);
    b5.setParent(this);
    b5.setText("机机模式");
    b5.move(90,450);
    b6.setParent(this);
    b6.setText("退出游戏");
    b6.move(90,550);
    resize(600,650);
    w1=new playbyperson;
    w2=new playwithai;
    w3=new playbypersonjin;
    w4=new playwithaijin;
    w5=new aitoai;

    connect(&b6,&QPushButton::pressed,this,&Widget::close);//点击b6按钮结束程序执行
    connect(&b1,&QPushButton::released,[=](){              //点击b1按钮跳转界面显示，主页面隐藏
            w1->show();
           this->hide();


        });
        connect(&b2,&QPushButton::released,[=](){

                w2->show();
               this->hide();


            });
        connect(&b3,&QPushButton::released,[=](){

                w3->show();
               this->hide();


            });
        connect(&b4,&QPushButton::released,[=](){

                w4->show();
               this->hide();


            });
        connect(&b5,&QPushButton::released,[=](){

                w5->show();
               this->hide();


            });
        connect(w1,&playbyperson::mysignal,this,[=](){
            w1->hide();  //场景隐藏
            this->show();   //主页出现
        });

        connect(w2,&playwithai::mysignal,this,[=](){
            w2->hide();  //场景隐藏
            this->show();   //主页出现
        });
        connect(w3,&playbypersonjin::mysignal,this,[=](){
                    w3->hide();  //场景隐藏
                    this->show();   //主页出现
                });
        connect(w4,&playwithaijin::mysignal,this,[=](){
                    w4->hide();  //场景隐藏
                    this->show();   //主页出现
                });
        connect(w5,&aitoai::mysignal,this,[=](){
                    w5->hide();  //场景隐藏
                    this->show();   //主页出现
                });

}
Widget::~Widget()
{

}
