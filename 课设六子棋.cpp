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
	return true;               //�����Һ� 
	if(x>4&&
	map[x][y]==map[x-1][y]&&
	map[x][y]==map[x-2][y]&&
	map[x][y]==map[x-3][y]&&
	map[x][y]==map[x-4][y]&&
	map[x][y]==map[x-5][y])
	return true;              //���ҵ���� 
	if(y<15&&
	map[x][y]==map[x][y+1]&&
	map[x][y]==map[x][y+2]&&
	map[x][y]==map[x][y+3]&&
	map[x][y]==map[x][y+4]&&
	map[x][y]==map[x][y+5])
	return true;              //����������
	if(y>4&&
	map[x][y]==map[x][y-1]&&
	map[x][y]==map[x][y-2]&&
	map[x][y]==map[x][y-3]&&
	map[x][y]==map[x][y-4]&&
	map[x][y]==map[x][y-5])
	return true;             //���������� 
	if(y<15&&x<15&& 
	map[x][y]==map[x+1][y+1]&&
	map[x][y]==map[x+2][y+2]&&
	map[x][y]==map[x+3][y+3]&&
	map[x][y]==map[x+4][y+4]&&
	map[x][y]==map[x+5][y+5])
	return true;            //�����ϵ����� 
	if(y>4&&x>4&&
	map[x][y]==map[x-1][y-1]&&
	map[x][y]==map[x-2][y-2]&&
	map[x][y]==map[x-3][y-3]&&
	map[x][y]==map[x-4][y-4]&&
	map[x][y]==map[x-5][y-5])
	return true;            //�����µ�����
	if(y<15&&x>4&& 
	map[x][y]==map[x-1][y+1]&&
	map[x][y]==map[x-2][y+2]&&
	map[x][y]==map[x-3][y+3]&&
	map[x][y]==map[x-4][y+4]&&
	map[x][y]==map[x-5][y+5])
	return true;            //�����µ�����
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
	return true;          //�ж������Ƿ�Ϸ� 
}
void updategamemap(int x, int y,int player){
	if(player==1)
	map[x][y]='x';        //xΪ���� 
	else
	map[x][y]='o';        //oΪ���� 
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
	 cout<<endl;}         //��ӡ��ͼ 
	
}
bool ifhuiqi(int x,int y){
if(x==-1&&y==-1)
return true;
return false;                  //����-1��-1���壬����һ���غϣ�ֻ�ܻ���һ�Σ� 
}
void player1time(){   ci++;
    cout<<"��"<<ci<<"�غ�"<<endl; 
    cout<<"���1����:"<<endl;   
	cin>>m>>n;
	if(ifhuiqi(m,n)&&ci>1)
	{cout<<"����ɹ�,��������"<<endl;
	 map[t1x][t1y]='-';
	 map[t2x][t2y]='-';
	 printmap();
	 cin>>m>>n;
	}
	while(!iflegal(m,n))  //�������һ�µ�����λ�ã��ж��Ƿ�Ϸ������Ϸ��������� 
	{cout<<"����λ�ò���������������"<<endl; 
    cin>>m>>n;}
    if(ifhuiqi(m,n)&&ci>1)
	{cout<<"����ɹ�����������"<<endl;
	 map[t1x][t1y]='-';
	 map[t2x][t2y]='-';
	 printmap();
	 cin>>m>>n;
	}
	t1x=m;t1y=n;
}
bool ifjinshou(int i,int j){
    int kong;                      //�ж����������Ƿ���� 
 	int lianzi=0, lianzi4=0,lianzi5=0;
 			for(int x=1;x<=6;x++)
 			{
 			if(m-x>=0)
			{
			if(map[m-x][n]=='x')               //���Ϸ���������� 
 			lianzi++;
 			if(map[m-x][n]=='-')
 			kong++;
 			if(kong==2)                   //������������ո����� 
 			break;
 			if(map[m-x][n]=='o')             //������������ 
 			break;
				 }
			 
 	 	     }
 	 	     kong=0;          //��� 
 	 	    for(int x=1;x<=6;x++)
 			{
 			if(m+x<mapsize)
			 {
			 if(map[m+x][n]=='x')               //���·���������� 
 			lianzi++;
 			if(map[m+x][n]=='-')
 			kong++;
 			if(kong==2)                   //������������ո����� 
 			break;
 			if(map[m+x][n]=='o')             //������������ 
 			break;
				 }
				 } 
 			kong=0;                       //���
			if(lianzi==3)
			lianzi4++;
			if(lianzi==4)
			lianzi5++;
			lianzi=0;                    //���   
			for(int x=1;x<=6;x++)
 			{
 			if(n-x>=0)
			 {
			 if(map[m][n-x]=='x')          //������������� 
 			lianzi++;
 			if(map[m][n-x]=='-')
 			kong++;
 			if(kong==2)                 //������������ո����� 
 			break;
 			if(map[m][n-x]=='o')        //������������ 
 			break;
				 }
			 
 	 	     }
 	 	     kong=0;                      //��� 
 	 	    for(int x=1;x<=6;x++)
 			{
 			if(n+x<mapsize)
			 {
			 if(map[m][n+x]=='x')           //���ҷ���������� 
 			lianzi++;
 			if(map[m][n+x]=='-')
 			kong++;
 			if(kong==2)                   //������������ո����� 
 			break;
 			if(map[m][n+x]=='o')          //������������ 
 			break;
				 }
				 } 
 			kong=0;                       //���
			if(lianzi==3)
			lianzi4++;
			if(lianzi==4)
			lianzi5++;
			lianzi=0;                    //��� 
			if(lianzi4==2||lianzi5==2)   //����44����55���� 
			return true;
			for(int x=1;x<=6;x++)
 			{
 			if(m-x>=0&&n-x>=0)
			 {
			 if(map[m-x][n-x]=='x')               //�����Ϸ���������� 
 			lianzi++;
 			if(map[m-x][n-x]=='-')
 			kong++;
 			if(kong==2)                   //������������ո����� 
 			break;
 			if(map[m-x][n-x]=='o')             //������������ 
 			break;
				 }
			 
 	 	     }
 	 	     kong=0;          //��� 
			 for(int x=1;x<=6;x++)
 			{
 			if(n+x<mapsize&&m+x<mapsize)
			 {
			 if(map[m+x][n+x]=='x')           //�����·���������� 
 			lianzi++;
 			if(map[m+x][n+x]=='-')
 			kong++;
 			if(kong==2)                   //������������ո����� 
 			break;
 			if(map[m+x][n+x]=='o')          //������������ 
 			break;
				 }
				 } 
 			kong=0;                       //���
			if(lianzi==3)
			lianzi4++;
			if(lianzi==4)
			lianzi5++;
			lianzi=0;                    //��� 
			if(lianzi4==2||lianzi5==2)   //����44����55���� 
			return true;  
 			for(int x=1;x<=6;x++)
 			{
 			if(m+x<mapsize&&n-x>=0)
			 {
			 if(map[m+x][n-x]=='x')          //�����·���������� 
 			lianzi++;
 			if(map[m+x][n-x]=='-')
 			kong++;
 			if(kong==2)                 //������������ո����� 
 			break;
 			if(map[m+x][n-x]=='o')        //������������ 
 			break;
				 }
			 
 	 	     }
 	 	     kong=0;                      //��� 
 	 	    for(int x=1;x<=6;x++)
 			{
 			if(m-x>=0&&n+x<mapsize)
			 {
			 if(map[m-x][n+x]=='x')           //�����Ϸ���������� 
 			lianzi++;
 			if(map[m-x][n+x]=='-') kong++;
 			if(kong==2)                   //������������ո����� 
 			break;
 			if(map[m-x][n+x]=='o')          //������������ 
 			break;
				 }
				 } 
 			kong=0;                       //���
			if(lianzi==3)
			lianzi4++;
			if(lianzi==4)
			lianzi5++;
			lianzi=0;                    //��� 
			if(lianzi4==2||lianzi5==2)   //����44����55���� 
			return true;
		    return false;
	 
}
void player2time(){   cout<<"���2����:"<<endl;
	cin>>m>>n;
	if(ifhuiqi(m,n)&&ci>1)
	{cout<<"����ɹ�����������"<<endl;
	 map[t1x][t1y]='-';
	 map[t2x][t2y]='-';
	 printmap();
	 cin>>m>>n;
	}
	while(!iflegal(m,n)) //������Ҷ��µ�����λ�ã��ж��Ƿ�Ϸ������Ϸ���������
	{cout<<"����λ�ò���������������"<<endl;
    cin>>m>>n;}
    if(ifhuiqi(m,n)&&ci>1)
	{cout<<"����ɹ�����������"<<endl;
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
void AIplayscore(char c){              //cΪ�з��������� 
	int playernum=0;
	int AInum=0;
	int blanknum=0;
    char d;
    if(c=='x')
    d='o';
    else
    d='x';
	memset(scoremap,0,sizeof(scoremap));//��շ�����ͼ 
	for(int i=0;i<mapsize;i++)          //�������� 
	{for(int j=0;j<mapsize;j++)
	{if(i>=0&&j>=0&&map[i][j]=='-')         //��֤����ĵط��ǿյ� 
	{
	for(int x=-1;x<=1;x++)
	for(int y=-1;y<=1;y++)                //ݰ����Χ8���ط������� 
	{playernum=0;
	 AInum=0;
	 blanknum=0;                          //�������� 
	 if(!(x==0&&y==0))                        //�õ����겻���� 
	 {                                      //�ȿ��ǵз��ĵ÷� 
	 	for(int m=1;m<=5;m++)              //ÿ����������5������ 
	 	{
	 		if(i+x*m>=0&&i+x*m<mapsize&&
			   j+y*m>=0&&j+y*m<mapsize&&   //���������������ĵз�����ʱ 
			   map[i+x*m][j+y*m]==c)
			   {playernum++;                  //������������ϵĵз��������� 
			   }
			else if(i+x*m>=0&&i+x*m<mapsize&&
			   j+y*m>=0&&j+y*m<mapsize&&   //���������������Ŀհ�����ʱ 
			   map[i+x*m][j+y*m]=='-')
			   {blanknum++;                //�հ�����������һ������ѭ�� 
			   break;
				}
			else
			   break;	                  //�����߽� 
		  }
		for(int m=1;m<=5;m++)              //ÿ����������5������ 
	 	{
	 		if(i-x*m>=0&&i-x*m<mapsize&&
			   j-y*m>=0&&j-y*m<mapsize&&   //���������������ĵз�����ʱ��Ϊ������෴���� 
			   map[i-x*m][j-y*m]==c)
			   {playernum++;                  //������������ϵĵз��������� 
			   }
			else if(i-x*m>=0&&i-x*m<mapsize&&
			   j-y*m>=0&&j-y*m<mapsize&&   //���������������Ŀհ�����ʱ 
			   map[i-x*m][j-y*m]=='-')
			   {blanknum++;                //�հ�����������һ������ѭ�� 
			   break;
				}
			else
			   break;	                  //�����߽� 
		  }
		if(playernum==1)                  //����һ������ʱ�����ּ�10 
		  scoremap[i][j]+=5;
		else if(playernum==2)             //������������ʱ����������� 
		  {if(blanknum==1)                //����Χ��һ���赲������ʱ 
		  scoremap[i][j]+=25;
		  else if(blanknum==2)            //����Χû�������赲ʱ 
		  scoremap[i][j]+=35;                        
		   }
		else if(playernum==3)             //������������ʱ����������� 
		  {if(blanknum==1)                //����Χ��һ���赲������ʱ 
		  scoremap[i][j]+=50;
		  else if(blanknum==2)            //����Χû�������赲ʱ 
		  scoremap[i][j]+=100;                        
		   }
		else if(playernum==4)             //�����ĸ�����ʱ����������� 
		  {if(blanknum==1)                //����Χ��һ���赲������ʱ 
		  scoremap[i][j]+=9500;
		  else if(blanknum==2)            //����Χû�������赲ʱ 
		  scoremap[i][j]+=10000;                        
		   }
		else if(playernum==5)
		  scoremap[i][j]+=100000;          //����������ʱ�����ȼ��ڶ��ߣ���ʱ������������ס  
		 blanknum=0;                       //��մ���        
		                                   // ���ڶԼ�������������� 
		for(int m=1;m<=5;m++)              //ÿ����������5������ 
	 	{
	 		if(i+x*m>=0&&i+x*m<mapsize&&
			   j+y*m>=0&&j+y*m<mapsize&&   //���������������ļ�������ʱ 
			   map[i+x*m][j+y*m]==d)
			   {AInum++;                  //������������ϵļ����������� 
			   }
			else if(i+x*m>=0&&i+x*m<mapsize&&
			   j+y*m>=0&&j+y*m<mapsize&&   //���������������Ŀհ�����ʱ 
			   map[i+x*m][j+y*m]=='-')
			   {blanknum++;                //�հ�����������һ������ѭ�� 
			   break;
				}
			else
			   break;	                  //�����߽� 
		  }                            
		for(int m=1;m<=5;m++)              //ÿ����������5������ 
	 	{
	 		if(i-x*m>=0&&i-x*m<mapsize&&
			   j-y*m>=0&&j-y*m<mapsize&&   //�����������������Լ�����ʱ��Ϊ������෴���� 
			   map[i-x*m][j-y*m]==d)
			   {AInum++;                  //������������ϵĵз��������� 
			   }
			else if(i-x*m>=0&&i-x*m<mapsize&&
			   j-y*m>=0&&j-y*m<mapsize&&   //���������������Ŀհ�����ʱ 
			   map[i-x*m][j-y*m]=='-')
			   {blanknum++;                //�հ�����������һ������ѭ�� 
			   break;
				}
			else
			   break;	                  //�����߽� 
		  }
		if(AInum==1)                  //����һ������ʱ�����ּ�10 
		  scoremap[i][j]+=10;
		else if(AInum==2)             //������������ʱ����������� 
		  {if(blanknum==1)                //����Χ��һ���赲������ʱ 
		  scoremap[i][j]+=30;
		  else if(blanknum==2)            //����Χû�������赲ʱ 
		  scoremap[i][j]+=40;                        
		   }
		else if(AInum==3)             //������������ʱ����������� 
		  {if(blanknum==1)                //����Χ��һ���赲������ʱ 
		  scoremap[i][j]+=60;
		  else if(blanknum==2)            //����Χû�������赲ʱ 
		  scoremap[i][j]+=110;                        
		   }
		else if(AInum==4)             //�����ĸ�����ʱ����������� 
		  {if(blanknum==1)                //����Χ��һ���赲������ʱ 
		  scoremap[i][j]+=9600;
		  else if(blanknum==2)            //����Χû�������赲ʱ 
		  scoremap[i][j]+=11000;                        
		   }
		else if(AInum>=5)
		  scoremap[i][j]+=150000;        //����������ʱ��������ȼ�����ʱ����ֱ�ӻ�ʤ  
		 blanknum=0;                     //��մ���      
		   
		  
	 }
	}
	}
	}
	}
	
}
void AIplaytime(){
	if(c=='o')
	cout<<"��"<<ci+1<<"�غ�"<<endl;
    ci++;
	cout<<"���Իغ�:"<<endl; 
	AIplayscore(c);                      //����ÿ��λ�õķ���
	if(model==5&&xianhou==2)
	{
	for(int i=0;i<mapsize;i++)           
	for(int j=0;j<mapsize;j++)           //��Ϊ�˻���ս�Ľ���ģʽ���ҵ�������ʱ 
	{
        if(ifjinshou(i,j))
        scoremap[i][j]=-100;
	}
	}
	int maxscore=0;                     //������ֵ 
	for(int i=0;i<mapsize;i++)           
	for(int j=0;j<mapsize;j++)
	{
		if(scoremap[i][j]>maxscore)
		maxscore=scoremap[i][j];
	 } 
	int flag=0;                         //���ֵ�ĸ��� 
	int an[400],bn[400];                  //������ֵ��λ�õ����� 
	for(int i=0;i<mapsize;i++)
	for(int j=0;j<mapsize;j++)
	{ 
		if(scoremap[i][j]==maxscore)
		{an[flag]=i;bn[flag]=j;flag++;} 
		
	 }   
	int number;                           
	srand((unsigned)time(0));
	number=rand()%flag;	                 //number=0��flag-1���漴�������ȡһ�������ֵ 
	if(c=='x')
	map[an[number]][bn[number]]='o';
	else
	map[an[number]][bn[number]]='x';
	t1x=an[number];m=an[number];t1y=bn[number];n=bn[number];
	Sleep(2000);
	printmap();	
}
void AI2playtime(){
	cout<<"����2�غ�:"<<endl;
	AIplayscore('x');                      //����ÿ��λ�õķ���
	int maxscore=0;                     //������ֵ 
	for(int i=0;i<mapsize;i++)           
	for(int j=0;j<mapsize;j++)
	{
		if(scoremap[i][j]>=maxscore)
		maxscore=scoremap[i][j];
	 } 
	int flag=0;                         //���ֵ�ĸ��� 
	int an[20],bn[20];                  //������ֵ��λ�� 
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
	
	cout<<"��������壺"<<endl; 
	cin>>m>>n;
	if(ifhuiqi(m,n)&&ci>1)
	{cout<<"����ɹ�����������"<<endl;
	 map[t1x][t1y]='-';
	 map[t2x][t2y]='-';
	 printmap();
	 cin>>m>>n;
	}
	while(!iflegal(m,n)) //��������µ�����λ�ã��ж��Ƿ�Ϸ������Ϸ���������
	{cout<<"����λ�ò���������������"<<endl;
    cin>>m>>n;}
    if(ifhuiqi(m,n)&&ci>1)
	{cout<<"����ɹ�����������"<<endl;
	 map[t1x][t1y]='-';
	 map[t2x][t2y]='-';
	 printmap();
	 cin>>m>>n;
	}
	t2x=m;t2y=n;
}
int playstart(){
	cout<<"��ʼ��Ϸ" <<endl;
	cout<<"1.���˶�ս"<<endl;
	cout<<"2.�˻���ս"<<endl;
	cout<<"3.������ս"<<endl; 
	cout<<"4.���˽���"<<endl;
    cout<<"5.�˻�����"<<endl;
	cout<<"6.�˳���Ϸ"<<endl; 
	cin>>model; 
}
void model1(){
	while(1)
	 {  player1time();
		updategamemap(m,n,1);
		printmap();
		if(ifwin(m,n))
		{cout<<"���1��ʤ����Ϸ����!"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
        player2time();
		updategamemap(m,n,2);
		printmap();
		if(ifwin(m,n))
		{cout<<"���2��ʤ����Ϸ������"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
		if(if_no_winner())
		 {cout<<"����!";
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
      }
}
void model2(){
	  cout<<"1.����"<<endl; 
	  cout<<"2.����"<<endl;
	  cin>>xianhou; 
	  if(xianhou==1)   
	{
		while(1)
	 {  cout<<"��"<<ci+1<<"�غ�"<<endl;
	    playerwithAItime();
		updategamemap(m,n,1);
		c='x';
		printmap();
		if(ifwin(m,n))
		{cout<<"��һ�ʤ����Ϸ������"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;} 
		AIplaytime();
		if(ifwin(m,n))
		{cout<<"���Ի�ʤ����Ϸ����!"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
		if(if_no_winner())
		 {cout<<"����!";
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
         }
	}
		  if(xianhou==2)   
	{
		while(1)
	 {  c='o';
		AIplaytime();
		if(ifwin(m,n))
		{cout<<"���Ի�ʤ����Ϸ����!"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
		playerwithAItime();
		updategamemap(m,n,2);
		printmap();
		if(ifwin(m,n))
		{cout<<"��һ�ʤ����Ϸ������"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;} 
		if(if_no_winner())
		 {cout<<"����!";
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
         }
	}
	
	
}
void model3(){
	    c='o';
	    while(1){
	    AIplaytime();
	    if(ifwin(m,n))
		{cout<<"����1��ʤ����Ϸ����!"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
		AI2playtime();
		if(ifwin(m,n))
		{cout<<"����2��ʤ����Ϸ����!"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
		if(if_no_winner())
		 {cout<<"����!";
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
         }
	    	
		
}
void model4(){
	while(1)
	 {  player1time();
		updategamemap(m,n,1);
		printmap();
		if(ifjinshou(m,n))
		{cout<<"���1����Υ��,���2��ʤ����Ϸ����!"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
		if(ifwin(m,n))
		{cout<<"���1��ʤ����Ϸ����!"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
        player2time();
		updategamemap(m,n,2);
		printmap();
		if(ifwin(m,n))
		{cout<<"���2��ʤ����Ϸ������"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
		if(if_no_winner())
		 {cout<<"����!";
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
      }
}
void model5(){
	int xianhou;
	  cout<<"1.����"<<endl; 
	  cout<<"2.����"<<endl;
	  cin>>xianhou; 
	  if(xianhou==1)   
	{
		while(1)
	 {  cout<<"��"<<ci+1<<"�غ�"<<endl;
	    playerwithAItime();
		updategamemap(m,n,1);
		c='x';
		printmap();
		if(ifjinshou(m,n))
		{cout<<"���1����Υ��,���Ի�ʤ����Ϸ����!"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
		if(ifwin(m,n))
		{cout<<"��һ�ʤ����Ϸ������"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;} 
		AIplaytime();
		if(ifwin(m,n))
		{cout<<"���Ի�ʤ����Ϸ����!"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
		if(if_no_winner())
		 {cout<<"����!";
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
         }
	}
		  if(xianhou==2)   
	{
		while(1)
	 {  c='o';
		AIplaytime();	
		if(ifwin(m,n))
		{cout<<"���Ի�ʤ����Ϸ����!"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
		playerwithAItime();
		updategamemap(m,n,2);
		printmap();
		if(ifwin(m,n))
		{cout<<"��һ�ʤ����Ϸ������"<<endl;
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;} 
		if(if_no_winner())
		 {cout<<"����!";
		memset(map,'-',sizeof(map));//��ͼ��ʼ��
		break;}
         }
	}
	
	
}
int main(){
	memset(map,'-',sizeof(map));//��ͼ��ʼ�� 
	playstart();                //��ʼ��Ϸ������ 

	
	while(1){
	if(model==1)                 //������Ӧmodel��ֵ��ת����Ӧ����  
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
	{cout<<"лл���Ĳ��룡"<<endl; 
	break;} 
	Sleep(1000);	            //ѡ����Ϸ���� 
	ci=0; 
	playstart(); 	
	}
}

