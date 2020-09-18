#include "gamemodel.h"
#include<time.h>
#include<stdlib.h>
void GameModel::updatemap(int i, int j){
if(whoisplay)
        map[i][j]=1;   //如果是黑色方下棋，落黑子
else
        map[i][j]=-1;  //如果是白色方下棋，落白子

  whoisplay=!whoisplay;//交换选手
}
void GameModel::startgame(GameType type)
{
    gametype=type;
    map.clear();              //清理棋盘

        for(int i=0;i<MAPsize;i++)
        {
            std::vector<int>lineboard;
            for(int j=0;j<MAPsize;j++)
                lineboard.push_back(0);  //用0填充棋盘上所有位置，使得棋盘上左右位置都能够下棋
            map.push_back(lineboard);
        }
        for(int i=MAPsize;i<MAPsize+2;i++)//用9填充棋盘上底栏的位置，初始化。防止鼠标点击底栏空白位置时系统异常终止
        {
            std::vector<int>lineboard;
            for(int j=0;j<MAPsize;j++)
                lineboard.push_back(9);
            map.push_back(lineboard);
        }
    whoisplay=true;         //先让黑方下棋

}
void GameModel::persontime(int i, int j)
{
    updatemap(i,j);        //人人游戏时，直接更新地图
}


void GameModel::AItime(int &clickzhong,int &clickheng)
{
    AIplayscore();
    //计算每个落子的评分
    int maxScore = 0;
        std::vector<std::pair<int, int>> maxPoints;        //定义一个最大数组

        for (int i = 0; i < MAPsize; i++)
            for (int j = 0; j < MAPsize; j++)
            {
                // 前提是这个坐标是空的
                if (map[i][j] == 0)
                {
                    if (scoremap[i][j] > maxScore)          // 找最大的数对应的坐标
                    {
                        maxPoints.clear();                  //清空
                        maxScore = scoremap[i][j];          //更换最大数的值
                        maxPoints.push_back(std::make_pair(i, j));
                    }
                    else if (scoremap[i][j] == maxScore)     // 如果有多个最大的数，都存起来
                        maxPoints.push_back(std::make_pair(i, j));
                }
            }

        // 随机落子，如果有多个点的话
        srand((unsigned)time(0));
        int index = rand() % maxPoints.size();
        std::pair<int,int> piontpair=maxPoints.at(index);
        clickzhong=piontpair.first;
        clickheng=piontpair.second;
        updatemap(clickzhong,clickheng);
}

void GameModel::AIplayscore()
{
        int playernum=0;              //计算选手一个方向棋子数
        int AInum=0;                  //计算AI自身棋子数
        int blanknum=0;               //计算周围没有棋子的个数
        scoremap.clear();             //初始化分数地图
            for (int i = 0; i < MAPsize; i++)
            {
                std::vector<int> lineScores;
                for (int j = 0; j < MAPsize; j++)
                    lineScores.push_back(0);     //用0填充分数地图
                scoremap.push_back(lineScores);
            }

        for(int i=0;i<MAPsize;i++)          //计算评分
        {for(int j=0;j<MAPsize;j++)
        {if(i>=0&&j>=0&&map[i][j]==0)         //保证下棋的地方是空的
        {
        for(int x=-1;x<=1;x++)
        for(int y=-1;y<=1;y++)                //莅临周围8个地方的棋子
        {playernum=0;
         AInum=0;
         blanknum=0;                          //更新内容
         if(!(x==0&&y==0))                    //该点坐标不考虑
         {                                    //先考虑敌方的得分
            for(int m=1;m<=5;m++)             //每个方向延伸5个棋子
            {
                if(i+x*m>=0&&i+x*m<MAPsize&&
                   j+y*m>=0&&j+y*m<MAPsize&&  //当存在满足条件的敌方棋子时
                   map[i+x*m][j+y*m]==1)
                   {playernum++;              //计算这个方向上的敌方棋子数量
                   }
                else if(i+x*m>=0&&i+x*m<MAPsize&&
                   j+y*m>=0&&j+y*m<MAPsize&&   //当存在满足条件的空白棋子时
                   map[i+x*m][j+y*m]==0)
                   {blanknum++;                //空白棋子数量加一，跳出循环
                   break;
                    }
                else
                   break;	                  //超过边界
              }
            for(int m=1;m<=5;m++)              //每个方向延伸5个棋子
            {
                if(i-x*m>=0&&i-x*m<MAPsize&&
                   j-y*m>=0&&j-y*m<MAPsize&&   //当存在满足条件的敌方棋子时（为上面的相反方向）
                   map[i-x*m][j-y*m]==1)
                   {playernum++;                  //计算这个方向上的敌方棋子数量
                   }
                else if(i-x*m>=0&&i-x*m<MAPsize&&
                   j-y*m>=0&&j-y*m<MAPsize&&   //当存在满足条件的空白棋子时
                   map[i-x*m][j-y*m]==0)
                   {blanknum++;                //空白棋子数量加一，跳出循环
                   break;
                    }
                else
                   break;	                  //超过边界
              }
            if(playernum==1)                  //出现一个棋子时
              scoremap[i][j]+=5;
            else if(playernum==2)             //出现两个棋子时，分两种情况
              {if(blanknum==1)                //当周围有一个阻挡的棋子时
              scoremap[i][j]+=25;
              else if(blanknum==2)            //当周围没有棋子阻挡时
              scoremap[i][j]+=35;
               }
            else if(playernum==3)             //出现三个棋子时，分两种情况
              {if(blanknum==1)                //当周围有一个阻挡的棋子时
              scoremap[i][j]+=50;
              else if(blanknum==2)            //当周围没有棋子阻挡时
              scoremap[i][j]+=100;
            }
            else if(playernum==4)             //出现四个棋子时，分两种情况
              {if(blanknum==1)                //当周围有一个阻挡的棋子时
              scoremap[i][j]+=500;
              else if(blanknum==2)            //当周围没有棋子阻挡时
              scoremap[i][j]+=1000;
               }
            else if(playernum==5)
              scoremap[i][j]+=10000;          //当出现五连时，优先级第二高，这时无五子相连堵住
             AInum=0;
             playernum=0;
             blanknum=0;                       //清空处理
                                               // 现在对己方情况进行评分
            for(int m=1;m<=5;m++)               //每个方向延伸5个棋子
            {
                if(i+x*m>=0&&i+x*m<MAPsize&&
                   j+y*m>=0&&j+y*m<MAPsize&&   //当存在满足条件的己方棋子时
                   map[i+x*m][j+y*m]==-1)
                   {AInum++;                  //计算这个方向上的己方棋子数量
                   }
                else if(i+x*m>=0&&i+x*m<MAPsize&&
                   j+y*m>=0&&j+y*m<MAPsize&&   //当存在满足条件的空白棋子时
                   map[i+x*m][j+y*m]==0)
                   {blanknum++;                //空白棋子数量加一，跳出循环
                   break;
                    }
                else
                   break;	                  //超过边界
              }
            for(int m=1;m<=5;m++)              //每个方向延伸5个棋子
            {
                if(i-x*m>=0&&i-x*m<MAPsize&&
                   j-y*m>=0&&j-y*m<MAPsize&&   //当存在满足条件的自己棋子时（为上面的相反方向）
                   map[i-x*m][j-y*m]==-1)
                   {AInum++;                  //计算这个方向上的敌方棋子数量
                   }
                else if(i-x*m>=0&&i-x*m<MAPsize&&
                   j-y*m>=0&&j-y*m<MAPsize&&   //当存在满足条件的空白棋子时
                   map[i-x*m][j-y*m]==0)
                   {blanknum++;                //空白棋子数量加一，跳出循环
                   break;
                    }
                else
                   break;	                  //超过边界
              }
            if(AInum==1)                      //出现一个棋子时
              scoremap[i][j]+=10;
            else if(AInum==2)                 //出现两个棋子时，分两种情况
              {if(blanknum==1)                //当周围有一个阻挡的棋子时
              scoremap[i][j]+=30;
              else if(blanknum==2)            //当周围没有棋子阻挡时
              scoremap[i][j]+=40;
               }
            else if(AInum==3)                 //出现三个棋子时，分两种情况
              {if(blanknum==1)                //当周围有一个阻挡的棋子时
              scoremap[i][j]+=60;
              else if(blanknum==2)            //当周围没有棋子阻挡时
              scoremap[i][j]+=110;
               }
            else if(AInum==4)                  //出现四个棋子时，分两种情况
              {if(blanknum==1)                //当周围有一个阻挡的棋子时
              scoremap[i][j]+=600;
              else if(blanknum==2)            //当周围没有棋子阻挡时
              scoremap[i][j]+=1100;
               }
            else if(AInum>=5)
              scoremap[i][j]+=16000;         //当出现五连时，最高优先级，此时下棋直接获胜
             blanknum=0;                     //清空处理
             AInum=0;
             playernum=0;

         }
        }
        }
        }
        }
}
void GameModel::AI2time(int &clickzhong,int &clickheng)
{
            AI2playscore();
            //计算AI2每个落子的评分
            int maxScore = 0;
                std::vector<std::pair<int, int>> maxPoints;        //定义一个最大数组

                for (int i = 0; i < MAPsize; i++)
                    for (int j = 0; j < MAPsize; j++)
                    {
                        // 前提是这个坐标是空的
                        if (map[i][j] == 0)
                        {
                            if (scoremap[i][j] > maxScore)          // 找最大的数对应的坐标
                            {
                                maxPoints.clear();                  //清空
                                maxScore = scoremap[i][j];          //更换最大数的值
                                maxPoints.push_back(std::make_pair(i, j));
                            }
                            else if (scoremap[i][j] == maxScore)     // 如果有多个最大的数，都存起来
                                maxPoints.push_back(std::make_pair(i, j));
                        }
                    }

            // 随机落子，如果有多个点的话
           srand((unsigned)time(0));
           int index = rand() % maxPoints.size();
            std::pair<int,int> piontpair=maxPoints.at(index);
            clickzhong=piontpair.first;
            clickheng=piontpair.second;
            updatemap(clickzhong,clickheng);         //地图上为这个点的坐标赋值
}
void GameModel::AI2playscore()
{
        int playernum=0;
        int AInum=0;
        int blanknum=0;
        scoremap.clear();                           //初始化处理，清空分数地图
            for (int i = 0; i < MAPsize; i++)
            {
                std::vector<int> lineScores;
                for (int j = 0; j < MAPsize; j++)
                    lineScores.push_back(0);        //用0填充分数地图
                scoremap.push_back(lineScores);
            }

        for(int i=0;i<MAPsize;i++)          //计算评分
        {for(int j=0;j<MAPsize;j++)
        {if(i>=0&&j>=0&&map[i][j]==0)        //保证下棋的地方是空的
        {
        for(int x=-1;x<=1;x++)
        for(int y=-1;y<=1;y++)                //莅临周围8个地方的棋子
        {playernum=0;
         AInum=0;
         blanknum=0;                          //更新内容
         if(!(x==0&&y==0))                        //该点坐标不考虑
         {                                      //先考虑敌方的得分
            for(int m=1;m<=5;m++)              //每个方向延伸5个棋子
            {
                if(i+x*m>=0&&i+x*m<MAPsize&&
                   j+y*m>=0&&j+y*m<MAPsize&&   //当存在满足条件的敌方棋子时
                   map[i+x*m][j+y*m]==-1)
                   {playernum++;                  //计算敌方棋子数量
                   }
                else if(i+x*m>=0&&i+x*m<MAPsize&&
                   j+y*m>=0&&j+y*m<MAPsize&&   //当存在满足条件的己方棋子时
                   map[i+x*m][j+y*m]==0)
                   {blanknum++;                //空白棋子加加
                   break;
                    }
                else
                   break;
            }	                  //超过边界，跳出循环、

            for(int m=1;m<=5;m++)
            {
                if(i-x*m>=0&&i-x*m<MAPsize&&
                   j-y*m>=0&&j-y*m<MAPsize&&
                   map[i-x*m][j-y*m]==-1)
                   {playernum++;}
                else if(i-x*m>=0&&i-x*m<MAPsize&&
                   j-y*m>=0&&j-y*m<MAPsize&&
                   map[i-x*m][j-y*m]==0)
                   {blanknum++;
                   break;
                    }
                else
                   break;
              }
            if(playernum==1)
              scoremap[i][j]+=10;
            else if(playernum==2)
              {if(blanknum==1)
              scoremap[i][j]+=30;
              else if(blanknum==2)
              scoremap[i][j]+=50;
               }
            else if(playernum==3)
              {if(blanknum==1)
              scoremap[i][j]+=50;
              else if(blanknum==2)
              scoremap[i][j]+=50;
               }
            else if(playernum==4)
              {if(blanknum==1)
              scoremap[i][j]+=60;
              else if(blanknum==2)
              scoremap[i][j]+=60;
               }
            else if(playernum==5)
              scoremap[i][j]+=500;
             blanknum=0;
             playernum=0;
             AInum=0;
            for(int m=1;m<=5;m++)
            {
                if(i+x*m>=0&&i+x*m<MAPsize&&
                   j+y*m>=0&&j+y*m<MAPsize&&
                   map[i+x*m][j+y*m]==1)
                   {AInum++;
                   }
                else if(i+x*m>=0&&i+x*m<MAPsize&&
                   j+y*m>=0&&j+y*m<MAPsize&&
                   map[i+x*m][j+y*m]==0)
                   {blanknum++;
                   break;
                    }
                else
                   break;
              }
            for(int m=1;m<=5;m++)
            {
                if(i-x*m>=0&&i-x*m<MAPsize&&
                   j-y*m>=0&&j-y*m<MAPsize&&
                   map[i-x*m][j-y*m]==1)
                   {AInum++;
                   }
                else if(i-x*m>=0&&i-x*m<MAPsize&&
                   j-y*m>=0&&j-y*m<MAPsize&&
                   map[i-x*m][j-y*m]==0)
                   {blanknum++;
                   break;
                    }
                else
                   break;
              }
            if(AInum==1)
              scoremap[i][j]+=10;
            else if(AInum==2)
              {if(blanknum==1)
              scoremap[i][j]+=10;
              else if(blanknum==2)
              scoremap[i][j]+=20;
               }
            else if(AInum==3)
              {if(blanknum==1)
              scoremap[i][j]+=30;
              else if(blanknum==2)
              scoremap[i][j]+=40;
               }
            else if(AInum==4)
              {if(blanknum==1)
              scoremap[i][j]+=60;
              else if(blanknum==2)
              scoremap[i][j]+=120;
               }
            else if(AInum>=5)
              scoremap[i][j]+=6000;
             blanknum=0;
             AInum=0;
             playernum=0;


         }
        }
        }
        }
        }
}
bool GameModel::ifwin(int x,int y){
    for(int i=0;i<=5;i++)
    {if(x+5-i<20&&x-i>=0&&                       //从右向左依次莅临判断输赢
    map[x-i][y]==map[x+1-i][y]&&
    map[x-i][y]==map[x+2-i][y]&&
    map[x-i][y]==map[x+3-i][y]&&
    map[x-i][y]==map[x+4-i][y]&&
    map[x-i][y]==map[x+5-i][y])
    return true;               //横
    if(y+5-i<20&&y-i>=0&&
    map[x][y-i]==map[x][y+1-i]&&
    map[x][y-i]==map[x][y+2-i]&&
    map[x][y-i]==map[x][y+3-i]&&
    map[x][y-i]==map[x][y+4-i]&&
    map[x][y-i]==map[x][y+5-i])
    return true;              //竖
    if(x-i>0&&y-i>0&&
    y+5-i<20&&x+5-i<20&&
    map[x-i][y-i]==map[x+1-i][y+1-i]&&
    map[x-i][y-i]==map[x+2-i][y+2-i]&&
    map[x-i][y-i]==map[x+3-i][y+3-i]&&
    map[x-i][y-i]==map[x+4-i][y+4-i]&&
    map[x-i][y-i]==map[x+5-i][y+5-i])
    return true;            //左斜
    if(x+5-i<20&&x-i>0&&
    y-5+i>=0&&y+i<=20&&
    map[x-i][y+i]==map[x+1-i][y-1+i]&&
    map[x-i][y+i]==map[x+2-i][y-2+i]&&
    map[x-i][y+i]==map[x+3-i][y-3+i]&&
    map[x-i][y+i]==map[x+4-i][y-4+i]&&
    map[x-i][y+i]==map[x+5-i][y-5+i])
    return true;           }  //右斜
    return false;

}
bool GameModel::ifhe(){
    for(int i=0;i<MAPsize;i++)
    {for(int j=0;j<MAPsize;j++)
        {
            if(map[i][j]==0)
                return false;         //如果棋盘出现了空的地方，没有和棋返回
        }}
    return true;                      //如果棋盘满了那就是和棋了
}
bool GameModel::ifjin(int m, int n){
        int kong;                     //判断所下棋子是否禁手
        int lianzi=0, lianzi4=0,lianzi5=0;//计数
                for(int x=1;x<=6;x++)
                {
                if(m-x>=0)                     //向左
                {
                if(map[m-x][n]==1)            //遇到黑棋连子加加
                lianzi++;
                if(map[m-x][n]==0)
                kong++;
                if(kong==2)                   //遇到两个空棋子，跳出循环
                break;
                if(map[m-x][n]==-1)             //遇到敌方棋子跳出循环
                break;
                     }

                 }
                 kong=0;                       //清空处理
                for(int x=1;x<=6;x++)
                {
                if(m+x<MAPsize)                 //向右
                 {
                 if(map[m+x][n]==1)               //遇到黑棋连子加加
                lianzi++;
                if(map[m+x][n]==0)
                kong++;
                if(kong==2)                   //遇到两个空棋子，跳出循环
                break;
                if(map[m+x][n]==-1)             //遇到敌方棋子跳出循环
                break;
                     }
                     }
                kong=0;                       //清空处理
                if(lianzi==3)                 //如果左右有三个连子
                lianzi4++;                    //下这部棋子会出现4连，4连加1
                if(lianzi==4)                 //如果左右有三个连子
                lianzi5++;                    //下这部棋子会出现5连，5连加1
                lianzi=0;                     //清空这个方向上的连子
                for(int x=1;x<=6;x++)
                {
                if(n-x>=0)                   //向上
                 {
                 if(map[m][n-x]==1)
                lianzi++;
                if(map[m][n-x]==0)
                kong++;
                if(kong==2)
                break;
                if(map[m][n-x]==-1)
                break;
                     }

                 }
                 kong=0;                      //清空
                for(int x=1;x<=6;x++)
                {
                if(n+x<MAPsize)               //向下
                 {
                 if(map[m][n+x]==1)
                lianzi++;
                if(map[m][n+x]==0)
                kong++;
                if(kong==2)
                break;
                if(map[m][n+x]==-1)
                break;
                     }
                     }
                kong=0;                       //清空
                if(lianzi==3)
                lianzi4++;
                if(lianzi==4)
                lianzi5++;
                lianzi=0;
                if(lianzi4==2||lianzi5==2)   //如果出现双四或者双五，下了禁手
                return true;
                for(int x=1;x<=6;x++)
                {
                if(m-x>=0&&n-x>=0)          //左上
                 {
                 if(map[m-x][n-x]==1)
                lianzi++;
                if(map[m-x][n-x]==0)
                kong++;
                if(kong==2)
                break;
                if(map[m-x][n-x]==-1)
                break;
                     }

                 }
                 kong=0;
                 for(int x=1;x<=6;x++)
                {
                if(n+x<MAPsize&&m+x<MAPsize)
                 {
                 if(map[m+x][n+x]==1)           //右下
                lianzi++;
                if(map[m+x][n+x]==0)
                kong++;
                if(kong==2)
                break;
                if(map[m+x][n+x]==-1)
                break;
                     }
                     }
                kong=0;
                if(lianzi==3)
                lianzi4++;
                if(lianzi==4)
                lianzi5++;
                lianzi=0;
                if(lianzi4==2||lianzi5==2)
                return true;
                for(int x=1;x<=6;x++)
                {
                if(m+x<MAPsize&&n-x>=0)
                 {
                 if(map[m+x][n-x]==1)          //右下
                lianzi++;
                if(map[m+x][n-x]==0)
                kong++;
                if(kong==2)
                break;
                if(map[m+x][n-x]==-1)
                break;
                     }

                 }
                 kong=0;
                for(int x=1;x<=6;x++)
                {
                if(m-x>=0&&n+x<MAPsize)
                 {
                 if(map[m-x][n+x]==1)
                lianzi++;
                if(map[m-x][n+x]==0) kong++;
                if(kong==2)
                break;
                if(map[m-x][n+x]==-1)
                break;
                     }
                     }
                kong=0;
                if(lianzi==3)
                lianzi4++;
                if(lianzi==4)
                lianzi5++;
                lianzi=0;
                if(lianzi4==2||lianzi5==2)
                return true;
                return false;                //除了上述清况，下棋都是非禁手
}
