#include "playbypersonjin.h"

#include"gamemodel.h"

#include"QPainter"        //画地图所需
#include"QMouseEvent"
#include<math.h>
#include<QMessageBox>
playbypersonjin::playbypersonjin(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    this->setWindowTitle("hello");
    setFixedSize(
                 kongxi*2+(MAPsize-1)*gezisize,
                 kongxi*2+(MAPsize-1)*gezisize+dilan);
    back.setParent(this);
    back.setText("返回主页面");
    back.move(150,size().height()-dilan);
    startnew.setParent(this);
    startnew.setText("重新开始");
    startnew.move(600,size().height()-dilan);
    initGame();

    connect(&back,&QPushButton::clicked,this,&playbypersonjin::sendslot);
    connect(&startnew,&QPushButton::clicked,this,&playbypersonjin::anewplay);

}
void playbypersonjin::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //绘制棋盘
   //painter.setRenderHint(QPainter::Antialiasing,true);//抗锯齿
    QPixmap pix;
    //加载图片
    pix.load(":/new/prefix1/w2tu.jpg");
    //绘制背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    painter.setRenderHint(QPainter::Antialiasing,true);
    for(int i=0;i<MAPsize;i++)
    {
        painter.drawLine(
                    kongxi+gezisize*i,kongxi,
                    kongxi+gezisize*i,size().height()-kongxi-dilan);//竖线
        painter.drawLine(kongxi,kongxi+gezisize*i,
                    size().width()-kongxi,kongxi+gezisize*i);//横线
    }


    //绘制选中点
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);               //定义刷子模式
    //绘制落子标记
    if(clickzhong>0&&clickzhong<MAPsize&&
       clickheng>0&&clickheng<MAPsize&&
            game->map[clickzhong][clickheng]==0)    //在边界范围内且为空
    {
            brush.setColor(Qt::red);              //设置模糊界面为红色
        painter.setBrush(brush);
        painter.drawEllipse(kongxi+gezisize*clickheng-biaoji/2,kongxi+gezisize*clickzhong-biaoji/2,biaoji,biaoji);
    }
    //绘制棋子
    for(int i=0;i<MAPsize;i++)
    {
        for(int j=0;j<MAPsize;j++)
        {
            if(game->map[i][j]==1)
            {//黑子下棋
                brush.setColor(Qt::black);
                painter.setBrush(brush);
                painter.drawEllipse(kongxi+gezisize*j-chessr,kongxi+gezisize*i-chessr,chessr*2,chessr*2);
            }
            else if(game->map[i][j]==-1)
            {//白子下棋
                brush.setColor(Qt::white);
                painter.setBrush(brush);
                painter.drawEllipse(kongxi+gezisize*j-chessr,kongxi+gezisize*i-chessr,chessr*2,chessr*2);
            }
        }
    }
    if(clickheng>=0&&clickheng<MAPsize&&clickzhong>=0&&clickzhong<MAPsize
            &&game->map[clickzhong][clickheng]==1&&game->ifjin(clickzhong,clickheng))
    {
        QMessageBox::StandardButton btend=QMessageBox::information(this,"五子棋对战","黑方禁手，白棋获胜");
        if(btend==QMessageBox::Ok)
        {
            game->startgame(game_type);
            game->gamestatus=playing;
        }
    }
    if(clickheng>=0&&clickheng<MAPsize&&clickzhong>=0&&clickzhong<MAPsize
     &&(game->map[clickzhong][clickheng]==1||game->map[clickzhong][clickheng]==-1))
    {
        if(game->ifwin(clickzhong,clickheng)&&game->gamestatus==playing)
        {
            game->gamestatus=win;
            QString str;
            if(game->map[clickzhong][clickheng]==1)
                str="黑棋";
            else
                str="白棋";
            QMessageBox::StandardButton btend=QMessageBox::information(this,"五子棋对战",str + "胜利");
            if(btend==QMessageBox::Ok)
            {
                game->startgame(game_type);
                game->gamestatus=playing;
            }
        }
    }
    if(game->ifhe())
    {
        QMessageBox::StandardButton btend=QMessageBox::information(this,"五子棋对战","和棋");
        if(btend==QMessageBox::Ok)
        {
            game->startgame(game_type);
            game->gamestatus=playing;
        }
    }

}
void playbypersonjin::initGame()
{
    game=new GameModel;
    game_type=player;
    game->gamestatus=playing;
    game->startgame(game_type);
}
void playbypersonjin::mouseMoveEvent(QMouseEvent *event)
{
    int x=event->x();
    int y=event->y();//通过鼠标移动确定落子
    if(x>=kongxi&&
            x<(size().width()-kongxi)&&
            y>=kongxi&&
            y<(size().height()-kongxi))   //棋盘边缘空隙处不能落子
    {
        int heng=(x-kongxi)/gezisize;        //横坐标的值
        int zhong=(y-kongxi)/gezisize;       //纵坐标的值
        int posx=kongxi+heng*gezisize;       //棋子在窗口的横向位置
        int posy=kongxi+zhong*gezisize;      //棋子在窗口的纵向位置
        clickheng=-1;                     //根据距离选出合适的点的位置
        clickzhong=-1;                     //初始化
        int len=0;
        selectpos=false;

        len=sqrt((x-posx)*(x-posx)+(y-posy)*(y-posy));
        if(len<offset)
        {
            clickheng=heng;
            clickzhong=zhong;
            if(game->map[clickzhong][clickheng]==0){
                selectpos=true;
            }
        }
        len=sqrt((x-posx-gezisize)*(x-posx-gezisize)+(y-posy)*(y-posy));
        if(len<offset)
        {
            clickheng=heng+1;
            clickzhong=zhong;
            if(game->map[clickzhong][clickheng]==0){
                selectpos=true;
            }
        }
        len=sqrt((x-posx)*(x-posx)+(y-posy-gezisize)*(y-posy-gezisize));
        if(len<offset)
        {
            clickheng=heng;
            clickzhong=zhong+1;
            if(game->map[clickzhong][clickheng]==0){
                selectpos=true;
            }
        }
        len=sqrt((x-posx-gezisize)*(x-posx-gezisize)+(y-posy-gezisize)*(y-posy-gezisize));
        if(len<offset)
        {
            clickheng=heng+1;
            clickzhong=zhong+1;
            if(game->map[clickzhong][clickheng]==0){
                selectpos=true;
            }
        }
    }
            update();
}
void playbypersonjin::mouseReleaseEvent(QMouseEvent *event)
{
    if(selectpos==false){
        return;            //如果此处不能下棋 不落子
    }  else{
        selectpos=false;   //如果能下 ，把这步棋变得不能落子
    }
    Persontime();
}
void playbypersonjin::Persontime()
{
    if(clickheng!=-1&&clickzhong!=-1&&game->map[clickzhong][clickheng]==0)
    {
        game->persontime(clickzhong,clickheng);
        update();
    }
}
void playbypersonjin::sendslot(){
    emit mysignal();
}
void playbypersonjin::anewplay(){
    game->gamestatus=dead;
    initGame();

}
