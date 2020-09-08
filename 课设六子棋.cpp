#include<iostream>
#include<cstring>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;
const int mapsize=20;
int m,n,t1x,t1y,t2x,t2y,model,ci=0,xianhou;
int scoremap[mapsize][mapsize];
char map[mapsize][mapsize];
char c;
bool ifwin(int x,int y){
	if(x<15&&
	map[x][y]==map[x+1][y]&&
	map[x][y]==map[x+2][y]&&
	map[x][y]==map[x+3][y]&&
	map[x][y]==map[x+4][y]&&
	map[x][y]==map[x+5][y])
	return true;               //从左到右横 
	if(x>4&&
	map[x][y]==map[x-1][y]&&
	map[x][y]==map[x-2][y]&&
	map[x][y]==map[x-3][y]&&
	map[x][y]==map[x-4][y]&&
	map[x][y]==map[x-5][y])
	return true;              //从右到左横 
	if(y<15&&
	map[x][y]==map[x][y+1]&&
	map[x][y]==map[x][y+2]&&
	map[x][y]==map[x][y+3]&&
	map[x][y]==map[x][y+4]&&
	map[x][y]==map[x][y+5])
	return true;              //从上向下竖
	if(y>4&&
	map[x][y]==map[x][y-1]&&
	map[x][y]==map[x][y-2]&&
	map[x][y]==map[x][y-3]&&
	map[x][y]==map[x][y-4]&&
	map[x][y]==map[x][y-5])
	return true;             //从下向上竖 
	if(y<15&&x<15&& 
	map[x][y]==map[x+1][y+1]&&
	map[x][y]==map[x+2][y+2]&&
	map[x][y]==map[x+3][y+3]&&
	map[x][y]==map[x+4][y+4]&&
	map[x][y]==map[x+5][y+5])
	return true;            //从左上到右下 
	if(y>4&&x>4&&
	map[x][y]==map[x-1][y-1]&&
	map[x][y]==map[x-2][y-2]&&
	map[x][y]==map[x-3][y-3]&&
	map[x][y]==map[x-4][y-4]&&
	map[x][y]==map[x-5][y-5])
	return true;            //从右下到左上
	if(y<15&&x>4&& 
	map[x][y]==map[x-1][y+1]&&
	map[x][y]==map[x-2][y+2]&&
	map[x][y]==map[x-3][y+3]&&
	map[x][y]==map[x-4][y+4]&&
	map[x][y]==map[x-5][y+5])
	return true;            //从左下到右上
	if(y>4&&x<15&&
	map[x][y]==map[x+1][y-1]&&
	map[x][y]==map[x+2][y-2]&&
	map[x][y]==map[x+3][y-3]&&
	map[x][y]==map[x+4][y-4]&&
	map[x][y]==map[x+5][y-5])
	return true;
	return false;          
	          	         	 
}
bool iflegal(int x,int y){
	if(map[x][y]!='-'||x<0||y<0||x>19||y>19)
	return false;
	return true;          //判断棋子是否合法 
}
void updategamemap(int x, int y,int player){
	if(player==1)
	map[x][y]='x';        //x为黑子 
	else
	map[x][y]='o';        //o为白子 
}
void printmap(){
    cout<<"     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19"<<endl;
	for(int i=0;i<mapsize;i++)
	{if(i<10)
	cout<<"  "<<i;
	else
	cout<<" "<<i;
	for(int j=0;j<mapsize;j++)
	 cout<<"  "<<map[i][j];
	 cout<<endl;}         //打印地图 
	
}
bool ifhuiqi(int x,int y){
if(x==-1&&y==-1)
return true;
return false;                  //输入-1，-1悔棋，撤回一个回合（只能悔棋一次） 
}
void player1time(){   ci++;
    cout<<"第"<<ci<<"回合"<<endl; 
    cout<<"玩家1下棋:"<<endl;   
	cin>>m>>n;
	if(ifhuiqi(m,n)&&ci>1)
	{cout<<"悔棋成功,重新输入"<<endl;
	 map[t1x][t1y]='-';
	 map[t2x][t2y]='-';
	 printmap();
	 cin>>m>>n;
	}
	while(!iflegal(m,n))  //输入玩家一下的棋子位置，判断是否合法，不合法重新输入 
	{cout<<"棋子位置不合理，请重新下棋"<<endl; 
    cin>>m>>n;}
    if(ifhuiqi(m,n)&&ci>1)
	{cout<<"悔棋成功，重新输入"<<endl;
	 map[t1x][t1y]='-';
	 map[t2x][t2y]='-';
	 printmap();
	 cin>>m>>n;
	}
	t1x=m;t1y=n;
}
bool ifjinshou(int i,int j){
    int kong;                      //判断所下棋子是否禁手 
 	int lianzi=0, lianzi4=0,lianzi5=0;
 			for(int x=1;x<=6;x++)
 			{
 			if(m-x>=0)
			{
			if(map[m-x][n]=='x')               //向上方向的连子数 
 			lianzi++;
 			if(map[m-x][n]=='-')
 			kong++;
 			if(kong==2)                   //如果遇到两个空格跳过 
 			break;
 			if(map[m-x][n]=='o')             //遇到白棋跳过 
 			break;
				 }
			 
 	 	     }
 	 	     kong=0;          //清空 
 	 	    for(int x=1;x<=6;x++)
 			{
 			if(m+x<mapsize)
			 {
			 if(map[m+x][n]=='x')               //向下方向的连子数 
 			lianzi++;
 			if(map[m+x][n]=='-')
 			kong++;
 			if(kong==2)                   //如果遇到两个空格跳过 
 			break;
 			if(map[m+x][n]=='o')             //遇到白棋跳过 
 			break;
				 }
				 } 
 			kong=0;                       //清空
			if(lianzi==3)
			lianzi4++;
			if(lianzi==4)
			lianzi5++;
			lianzi=0;                    //清空   
			for(int x=1;x<=6;x++)
 			{
 			if(n-x>=0)
			 {
			 if(map[m][n-x]=='x')          //向左方向的连子数 
 			lianzi++;
 			if(map[m][n-x]=='-')
 			kong++;
 			if(kong==2)                 //如果遇到两个空格跳过 
 			break;
 			if(map[m][n-x]=='o')        //遇到白棋跳过 
 			break;
				 }
			 
 	 	     }
 	 	     kong=0;                      //清空 
 	 	    for(int x=1;x<=6;x++)
 			{
 			if(n+x<mapsize)
			 {
			 if(map[m][n+x]=='x')           //向右方向的连子数 
 			lianzi++;
 			if(map[m][n+x]=='-')
 			kong++;
 			if(kong==2)                   //如果遇到两个空格跳过 
 			break;
 			if(map[m][n+x]=='o')          //遇到白棋跳过 
 			break;
				 }
				 } 
 			kong=0;                       //清空
			if(lianzi==3)
			lianzi4++;
			if(lianzi==4)
			lianzi5++;
			lianzi=0;                    //清空 
			if(lianzi4==2||lianzi5==2)   //出现44或者55禁手 
			return true;
			for(int x=1;x<=6;x++)
 			{
 			if(m-x>=0&&n-x>=0)
			 {
			 if(map[m-x][n-x]=='x')               //向左上方向的连子数 
 			lianzi++;
 			if(map[m-x][n-x]=='-')
 			kong++;
 			if(kong==2)                   //如果遇到两个空格跳过 
 			break;
 			if(map[m-x][n-x]=='o')             //遇到白棋跳过 
 			break;
				 }
			 
 	 	     }
 	 	     kong=0;          //清空 
			 for(int x=1;x<=6;x++)
 			{
 			if(n+x<mapsize&&m+x<mapsize)
			 {
			 if(map[m+x][n+x]=='x')           //向右下方向的连子数 
 			lianzi++;
 			if(map[m+x][n+x]=='-')
 			kong++;
 			if(kong==2)                   //如果遇到两个空格跳过 
 			break;
 			if(map[m+x][n+x]=='o')          //遇到白棋跳过 
 			break;
				 }
				 } 
 			kong=0;                       //清空
			if(lianzi==3)
			lianzi4++;
			if(lianzi==4)
			lianzi5++;
			lianzi=0;                    //清空 
			if(lianzi4==2||lianzi5==2)   //出现44或者55禁手 
			return true;  
 			for(int x=1;x<=6;x++)
 			{
 			if(m+x<mapsize&&n-x>=0)
			 {
			 if(map[m+x][n-x]=='x')          //向左下方向的连子数 
 			lianzi++;
 			if(map[m+x][n-x]=='-')
 			kong++;
 			if(kong==2)                 //如果遇到两个空格跳过 
 			break;
 			if(map[m+x][n-x]=='o')        //遇到白棋跳过 
 			break;
				 }
			 
 	 	     }
 	 	     kong=0;                      //清空 
 	 	    for(int x=1;x<=6;x++)
 			{
 			if(m-x>=0&&n+x<mapsize)
			 {
			 if(map[m-x][n+x]=='x')           //向右上方向的连子数 
 			lianzi++;
 			if(map[m-x][n+x]=='-') kong++;
 			if(kong==2)                   //如果遇到两个空格跳过 
 			break;
 			if(map[m-x][n+x]=='o')          //遇到白棋跳过 
 			break;
				 }
				 } 
 			kong=0;                       //清空
			if(lianzi==3)
			lianzi4++;
			if(lianzi==4)
			lianzi5++;
			lianzi=0;                    //清空 
			if(lianzi4==2||lianzi5==2)   //出现44或者55禁手 
			return true;
		    return false;
	 
}
void player2time(){   cout<<"玩家2下棋:"<<endl;
	cin>>m>>n;
	if(ifhuiqi(m,n)&&ci>1)
	{cout<<"悔棋成功，重新输入"<<endl;
	 map[t1x][t1y]='-';
	 map[t2x][t2y]='-';
	 printmap();
	 cin>>m>>n;
	}
	while(!iflegal(m,n)) //输入玩家二下的棋子位置，判断是否合法，不合法重新输入
	{cout<<"棋子位置不合理，请重新下棋"<<endl;
    cin>>m>>n;}
    if(ifhuiqi(m,n)&&ci>1)
	{cout<<"悔棋成功，重新输入"<<endl;
	 map[t1x][t1y]='-';
	 map[t2x][t2y]='-';
	 printmap();
	 cin>>m>>n;
	}
	t2x=m;t2y=n;
}
bool if_no_winner(){
	for(int i=0;i<mapsize;i++)
	for(int j=0;j<mapsize;j++)
	{if(map[i][j]=='-')
	return false;}
	return true; 
	
}
void AIplayscore(char c){              //c为敌方棋子种类 
	int playernum=0;
	int AInum=0;
	int blanknum=0;
    char d;
    if(c=='x')
    d='o';
    else
    d='x';
	memset(scoremap,0,sizeof(scoremap));//清空分数地图 
	for(int i=0;i<mapsize;i++)          //计算评分 
	{for(int j=0;j<mapsize;j++)
	{if(i>=0&&j>=0&&map[i][j]=='-')         //保证下棋的地方是空的 
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
	 		if(i+x*m>=0&&i+x*m<mapsize&&
			   j+y*m>=0&&j+y*m<mapsize&&   //当存在满足条件的敌方棋子时 
			   map[i+x*m][j+y*m]==c)
			   {playernum++;                  //计算这个方向上的敌方棋子数量 
			   }
			else if(i+x*m>=0&&i+x*m<mapsize&&
			   j+y*m>=0&&j+y*m<mapsize&&   //当存在满足条件的空白棋子时 
			   map[i+x*m][j+y*m]=='-')
			   {blanknum++;                //空白棋子数量加一，跳出循环 
			   break;
				}
			else
			   break;	                  //超过边界 
		  }
		for(int m=1;m<=5;m++)              //每个方向延伸5个棋子 
	 	{
	 		if(i-x*m>=0&&i-x*m<mapsize&&
			   j-y*m>=0&&j-y*m<mapsize&&   //当存在满足条件的敌方棋子时（为上面的相反方向） 
			   map[i-x*m][j-y*m]==c)
			   {playernum++;                  //计算这个方向上的敌方棋子数量 
			   }
			else if(i-x*m>=0&&i-x*m<mapsize&&
			   j-y*m>=0&&j-y*m<mapsize&&   //当存在满足条件的空白棋子时 
			   map[i-x*m][j-y*m]=='-')
			   {blanknum++;                //空白棋子数量加一，跳出循环 
			   break;
				}
			else
			   break;	                  //超过边界 
		  }
		if(playernum==1)                  //出现一个棋子时，积分加10 
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
		  scoremap[i][j]+=9500;
		  else if(blanknum==2)            //当周围没有棋子阻挡时 
		  scoremap[i][j]+=10000;                        
		   }
		else if(playernum==5)
		  scoremap[i][j]+=100000;          //当出现五连时，优先级第二高，这时无五子相连堵住  
		 blanknum=0;                       //清空处理        
		                                   // 现在对己方情况进行评分 
		for(int m=1;m<=5;m++)              //每个方向延伸5个棋子 
	 	{
	 		if(i+x*m>=0&&i+x*m<mapsize&&
			   j+y*m>=0&&j+y*m<mapsize&&   //当存在满足条件的己方棋子时 
			   map[i+x*m][j+y*m]==d)
			   {AInum++;                  //计算这个方向上的己方棋子数量 
			   }
			else if(i+x*m>=0&&i+x*m<mapsize&&
			   j+y*m>=0&&j+y*m<mapsize&&   //当存在满足条件的空白棋子时 
			   map[i+x*m][j+y*m]=='-')
			   {blanknum++;                //空白棋子数量加一，跳出循环 
			   break;
				}
			else
			   break;	                  //超过边界 
		  }                            
		for(int m=1;m<=5;m++)              //每个方向延伸5个棋子 
	 	{
	 		if(i-x*m>=0&&i-x*m<mapsize&&
			   j-y*m>=0&&j-y*m<mapsize&&   //当存在满足条件的自己棋子时（为上面的相反方向） 
			   map[i-x*m][j-y*m]==d)
			   {AInum++;                  //计算这个方向上的敌方棋子数量 
			   }
			else if(i-x*m>=0&&i-x*m<mapsize&&
			   j-y*m>=0&&j-y*m<mapsize&&   //当存在满足条件的空白棋子时 
			   map[i-x*m][j-y*m]=='-')
			   {blanknum++;                //空白棋子数量加一，跳出循环 
			   break;
				}
			else
			   break;	                  //超过边界 
		  }
		if(AInum==1)                  //出现一个棋子时，积分加10 
		  scoremap[i][j]+=10;
		else if(AInum==2)             //出现两个棋子时，分两种情况 
		  {if(blanknum==1)                //当周围有一个阻挡的棋子时 
		  scoremap[i][j]+=30;
		  else if(blanknum==2)            //当周围没有棋子阻挡时 
		  scoremap[i][j]+=40;                        
		   }
		else if(AInum==3)             //出现三个棋子时，分两种情况 
		  {if(blanknum==1)                //当周围有一个阻挡的棋子时 
		  scoremap[i][j]+=60;
		  else if(blanknum==2)            //当周围没有棋子阻挡时 
		  scoremap[i][j]+=110;                        
		   }
		else if(AInum==4)             //出现四个棋子时，分两种情况 
		  {if(blanknum==1)                //当周围有一个阻挡的棋子时 
		  scoremap[i][j]+=9600;
		  else if(blanknum==2)            //当周围没有棋子阻挡时 
		  scoremap[i][j]+=11000;                        
		   }
		else if(AInum>=5)
		  scoremap[i][j]+=150000;        //当出现五连时，最高优先级，此时下棋直接获胜  
		 blanknum=0;                     //清空处理      
		   
		  
	 }
	}
	}
	}
	}
	
}
void AIplaytime(){
	if(c=='o')
	cout<<"第"<<ci+1<<"回合"<<endl;
    ci++;
	cout<<"电脑回合:"<<endl; 
	AIplayscore(c);                      //计算每个位置的分数
	if(model==5&&xianhou==2)
	{
	for(int i=0;i<mapsize;i++)           
	for(int j=0;j<mapsize;j++)           //当为人机对战的禁手模式并且电脑先手时 
	{
        if(ifjinshou(i,j))
        scoremap[i][j]=-100;
	}
	}
	int maxscore=0;                     //算出最大值 
	for(int i=0;i<mapsize;i++)           
	for(int j=0;j<mapsize;j++)
	{
		if(scoremap[i][j]>maxscore)
		maxscore=scoremap[i][j];
	 } 
	int flag=0;                         //最大值的个数 
	int an[400],bn[400];                  //存放最大值的位置的数组 
	for(int i=0;i<mapsize;i++)
	for(int j=0;j<mapsize;j++)
	{ 
		if(scoremap[i][j]==maxscore)
		{an[flag]=i;bn[flag]=j;flag++;} 
		
	 }   
	int number;                           
	srand((unsigned)time(0));
	number=rand()%flag;	                 //number=0到flag-1的随即数，随机取一个最大数值 
	if(c=='x')
	map[an[number]][bn[number]]='o';
	else
	map[an[number]][bn[number]]='x';
	t1x=an[number];m=an[number];t1y=bn[number];n=bn[number];
	Sleep(2000);
	printmap();	
}
void AI2playtime(){
	cout<<"电脑2回合:"<<endl;
	AIplayscore('x');                      //计算每个位置的分数
	int maxscore=0;                     //算出最大值 
	for(int i=0;i<mapsize;i++)           
	for(int j=0;j<mapsize;j++)
	{
		if(scoremap[i][j]>=maxscore)
		maxscore=scoremap[i][j];
	 } 
	int flag=0;                         //最大值的个数 
	int an[20],bn[20];                  //存放最大值的位置 
	for(int i=0;i<mapsize;i++)
	for(int j=0;j<mapsize;j++)
	{
		if(scoremap[i][j]==maxscore)
		{an[flag]=i;bn[flag]=j;flag++;} 
		
	 }   
	int number;
	srand((unsigned)time(0));
	number=rand()%flag;	
	map[an[number]][bn[number]]='o';
	m=an[number];n=bn[number];
    Sleep(2000);
	printmap();	
}
void playerwithAItime(){
	
	cout<<"请玩家下棋："<<endl; 
	cin>>m>>n;
	if(ifhuiqi(m,n)&&ci>1)
	{cout<<"悔棋成功，重新输入"<<endl;
	 map[t1x][t1y]='-';
	 map[t2x][t2y]='-';
	 printmap();
	 cin>>m>>n;
	}
	while(!iflegal(m,n)) //输入玩家下的棋子位置，判断是否合法，不合法重新输入
	{cout<<"棋子位置不合理，请重新下棋"<<endl;
    cin>>m>>n;}
    if(ifhuiqi(m,n)&&ci>1)
	{cout<<"悔棋成功，重新输入"<<endl;
	 map[t1x][t1y]='-';
	 map[t2x][t2y]='-';
	 printmap();
	 cin>>m>>n;
	}
	t2x=m;t2y=n;
}
int playstart(){
	cout<<"开始游戏" <<endl;
	cout<<"1.人人对战"<<endl;
	cout<<"2.人机对战"<<endl;
	cout<<"3.机机对战"<<endl; 
	cout<<"4.人人禁手"<<endl;
    cout<<"5.人机禁手"<<endl;
	cout<<"6.退出游戏"<<endl; 
	cin>>model; 
}
void model1(){
	while(1)
	 {  player1time();
		updategamemap(m,n,1);
		printmap();
		if(ifwin(m,n))
		{cout<<"玩家1获胜，游戏结束!"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
        player2time();
		updategamemap(m,n,2);
		printmap();
		if(ifwin(m,n))
		{cout<<"玩家2获胜，游戏结束！"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
		if(if_no_winner())
		 {cout<<"和棋!";
		memset(map,'-',sizeof(map));//地图初始化
		break;}
      }
}
void model2(){
	  cout<<"1.先手"<<endl; 
	  cout<<"2.后手"<<endl;
	  cin>>xianhou; 
	  if(xianhou==1)   
	{
		while(1)
	 {  cout<<"第"<<ci+1<<"回合"<<endl;
	    playerwithAItime();
		updategamemap(m,n,1);
		c='x';
		printmap();
		if(ifwin(m,n))
		{cout<<"玩家获胜，游戏结束！"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;} 
		AIplaytime();
		if(ifwin(m,n))
		{cout<<"电脑获胜，游戏结束!"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
		if(if_no_winner())
		 {cout<<"和棋!";
		memset(map,'-',sizeof(map));//地图初始化
		break;}
         }
	}
		  if(xianhou==2)   
	{
		while(1)
	 {  c='o';
		AIplaytime();
		if(ifwin(m,n))
		{cout<<"电脑获胜，游戏结束!"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
		playerwithAItime();
		updategamemap(m,n,2);
		printmap();
		if(ifwin(m,n))
		{cout<<"玩家获胜，游戏结束！"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;} 
		if(if_no_winner())
		 {cout<<"和棋!";
		memset(map,'-',sizeof(map));//地图初始化
		break;}
         }
	}
	
	
}
void model3(){
	    c='o';
	    while(1){
	    AIplaytime();
	    if(ifwin(m,n))
		{cout<<"电脑1获胜，游戏结束!"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
		AI2playtime();
		if(ifwin(m,n))
		{cout<<"电脑2获胜，游戏结束!"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
		if(if_no_winner())
		 {cout<<"和棋!";
		memset(map,'-',sizeof(map));//地图初始化
		break;}
         }
	    	
		
}
void model4(){
	while(1)
	 {  player1time();
		updategamemap(m,n,1);
		printmap();
		if(ifjinshou(m,n))
		{cout<<"玩家1禁手违规,玩家2获胜，游戏结束!"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
		if(ifwin(m,n))
		{cout<<"玩家1获胜，游戏结束!"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
        player2time();
		updategamemap(m,n,2);
		printmap();
		if(ifwin(m,n))
		{cout<<"玩家2获胜，游戏结束！"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
		if(if_no_winner())
		 {cout<<"和棋!";
		memset(map,'-',sizeof(map));//地图初始化
		break;}
      }
}
void model5(){
	int xianhou;
	  cout<<"1.先手"<<endl; 
	  cout<<"2.后手"<<endl;
	  cin>>xianhou; 
	  if(xianhou==1)   
	{
		while(1)
	 {  cout<<"第"<<ci+1<<"回合"<<endl;
	    playerwithAItime();
		updategamemap(m,n,1);
		c='x';
		printmap();
		if(ifjinshou(m,n))
		{cout<<"玩家1禁手违规,电脑获胜，游戏结束!"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
		if(ifwin(m,n))
		{cout<<"玩家获胜，游戏结束！"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;} 
		AIplaytime();
		if(ifwin(m,n))
		{cout<<"电脑获胜，游戏结束!"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
		if(if_no_winner())
		 {cout<<"和棋!";
		memset(map,'-',sizeof(map));//地图初始化
		break;}
         }
	}
		  if(xianhou==2)   
	{
		while(1)
	 {  c='o';
		AIplaytime();	
		if(ifwin(m,n))
		{cout<<"电脑获胜，游戏结束!"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;}
		playerwithAItime();
		updategamemap(m,n,2);
		printmap();
		if(ifwin(m,n))
		{cout<<"玩家获胜，游戏结束！"<<endl;
		memset(map,'-',sizeof(map));//地图初始化
		break;} 
		if(if_no_winner())
		 {cout<<"和棋!";
		memset(map,'-',sizeof(map));//地图初始化
		break;}
         }
	}
	
	
}
int main(){
	memset(map,'-',sizeof(map));//地图初始化 
	playstart();                //开始游戏的输入 

	
	while(1){
	if(model==1)                 //根据相应model数值跳转到相应函数  
	model1();       
	if(model==2)     
	model2();
	if(model==3)
	model3();
	if(model==4)
	model4();
	if(model==5)
	model5();
	if(model==6)
	{cout<<"谢谢您的参与！"<<endl; 
	break;} 
	Sleep(1000);	            //选择游戏类型 
	ci=0; 
	playstart(); 	
	}
}

