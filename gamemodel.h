#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include<vector>         //六子棋游戏类型//
enum GameType              //游戏类型
{
    AI,
    player
};
enum GameStatus            //游戏状态
{
    playing,               //正在玩
    win,                   //赢棋
    dead                  //死棋
};
const int MAPsize=20;      //棋盘大小
const int kongxi=30;      //棋盘边缘大小
const int chessr=15;       //棋子半径的长度
const int biaoji=7;        //落子标记边长
const int gezisize=40;     //格子大小
const int offset=gezisize*0.4;//鼠标点击的模糊距离上线，小于二分之一的格子大小
const int dilan=50;
const int AIsleeptime=1000;   //AI下棋时的默认思考时间
class GameModel
{
public:
    GameModel(){};
public:
    std::vector<std::vector<int>>map;
    //保存地图，1为黑子，-1为白子，0为空
    std::vector<std::vector<int>>scoremap;
    //AI算法使用，计算各个点的分值
   bool whoisplay;          //判断黑棋还是白棋下
   GameType gametype;       //选择游戏模式
   GameStatus gamestatus;    //选择游戏状态
   void startgame(GameType type);//开始游戏的函数
   void updatemap(int i,int j);  //更新地图的函数
   void persontime(int i,int j); //选手的时间
   void personjintime(int i,int j);//选手禁手的时间
   void AItime(int &clickzhong,int &clickheng); //AI的游戏时间，返回AI选择的点坐标的信息
   void AI2time(int &clickzhong,int &clickheng);//AI2的游戏时间，返回AI2选择的点坐标的信息
   void AIplayscore();                          //AI对各点分析分数的函数
   void AI2playscore();                         //AI2对各点分析分数的函数
   bool ifwin(int m,int n);                     //判断输赢的函数
   bool ifhe();                                 //判断是否和棋的函数
   bool ifjin(int i,int j);                     //判断下的棋是否禁手的函数
};

#endif // GAMEMODEL_H
