#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <deque>
#include <map>
using namespace std;
#define MAXN 15
#define MAXM 15

char c,ch;

struct point{
    int x,y;	
};
deque<point>q;

map<char,int> mp_ch_int;
int mp_int_ch[5];
int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,-1,1};

char cb[16][16];
int direct,predirect;

int score;

bool iscrash;
bool isBean;

int level[6];
char diff_chr;

void color(int x){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);	
} 

void warning(){
	printf("键入错误！\n");	
}

void place_Bean(){
	 while(1){
	 	int tx=(rand()%MAXN)+1;
	 	int ty=(rand()%MAXM)+1;
	 	if(cb[tx][ty]=='.'){
	 		cb[tx][ty]='$';
	 		return;
	 	}
	 }	
}

void init_cb(){
	for(int i=1;i<=MAXN;++i){
		for(int j=1;j<=MAXM;++j){
			cb[i][j]='.';
		}
	}
	mp_ch_int['w']=1;mp_ch_int['s']=2;mp_ch_int['a']=3;mp_ch_int['d']=4;
	mp_int_ch[1]='w';mp_int_ch[2]='s';mp_int_ch[3]='a';mp_ch_int[4]='d';
	place_Bean();
	printf("加载棋盘模块完成\n");
}

void init_level(){
	 level[1]=400;level[2]=300;level[3]=150;level[4]=50;level[5]=20;
	 printf("加载难度模块完成\n");	
} 

void init_snake(){
	 cb[5][5]='@';	
	 q.push_back((point){5,5});
	 printf("加载贪吃蛇初始位置模块完成\n");
} 

void print(){
	for(int i=1;i<=MAXN;++i){
		for(int j=1;j<=MAXM;++j){
			if(cb[i][j]=='.')
		        color(7);
            else if(cb[i][j]=='$')
                color(10);
		    else
		    	color(9);
			printf("%c",cb[i][j]);
		}
		printf("\n");
	}
	color(7);
	printf("Score:%d\n",score);
}

void modify(){
	if(direct==0) return;

	point NOW=q.front();
	int tx=NOW.x+dx[direct];
	int ty=NOW.y+dy[direct];
	point LAST=q.back();
	if(tx<1) tx=MAXN;
	if(tx>MAXN) tx=1;
	if(ty<1) ty=MAXM;
	if(ty>MAXM) ty=1;
	
	point tt={0,0};
	if(q.size()>1){
		q.pop_front();
		tt=q.front();q.push_front(NOW);
	}

	if(cb[tx][ty]=='*' || cb[tx][ty]=='@'){
		if(tt.x==tx && tt.y==ty){
			direct=predirect;
			return;
		}
		printf("Crash!!!\n");
		iscrash=true;
		return;
	}
	isBean=false;
	if(cb[tx][ty]=='$'){
		isBean=true;
		score+=4;
		if(q.size()==1){
			int tmp=(((direct-1)^1)+1);
			q.push_back((point){LAST.x+dx[tmp],LAST.y+dy[tmp]});
			cb[LAST.x+dx[tmp]][LAST.y+dy[tmp]]='*';
		} else{
			point t1=q.back();q.pop_back();
			point t2=q.back();q.push_back(t1);
			if(t1.y==t2.y){
				if(t1.x>t2.x){
					if(t1.x!=MAXN){
                        q.push_back((point){t1.x+1,t1.y});
                        cb[t1.x+1][t1.y]='*';
                    } else{
                    	q.push_back((point){1,t1.y});
                    	cb[1][t1.y]='*';
                    }
				} else{
					if(t1.y!=1){
					    q.push_back((point){t1.x,t1.y-1});
					    cb[t1.x][t1.y-1]='*';
					} else{
		                q.push_back((point){t1.x,MAXM});
		                cb[t1.x][MAXM]='*';
		            }
				}
			} else{
				if(t1.y>t2.y){
					if(t1.y!=MAXM){
					    q.push_back((point){t1.x,t1.y+1});
					    cb[t1.x][t1.y+1]='*';
					} else{
	                    q.push_back((point){t1.x,1});
	                    cb[t1.x][1]='*';
	                }
				} else{
					if(t1.y!=1){
		                q.push_back((point){t1.x,t1.y-1});
		                cb[t1.x][t1.y-1]='*';
		            } else{
                    	q.push_back((point){t1.x,MAXN});
                    	cb[t1.x][MAXN]='*';
                    }
				}
			}
		}
		cb[tx][ty]='.';
	}
	LAST=q.back();
	
	if(q.size()>1) cb[NOW.x][NOW.y]='*';
	cb[LAST.x][LAST.y]='.';cb[tx][ty]='@';
	q.pop_back();q.push_front((point){tx,ty});
	if(isBean) place_Bean();
}

int main(){
	srand(time(NULL));
	HANDLE hOutput;
	COORD coord={0,0};
	hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	
	printf("选择游戏模式（1：单人，2：双人）\n");
	while(1){
		c=getch();
		if(c=='1'||c=='2') break;
		warning();
	}
	if(c=='1'){
		init_cb();
		init_snake();
		init_level();
		printf("w向上,s向下,a向左,d向右。准备好了吗，准备好输入y\n");
		while(1){
			ch=getch();
			if(ch=='y') break;
			warning();
		}
		if(ch=='y'){
			printf("请选择难度等级，1:极易,2:容易,3:普通,4:较难,5:极难\n");
			while(1){
				diff_chr=getch();
				if('1'<=diff_chr && diff_chr<='5'){
				    break;
				}
				warning();
			}
			printf("准备开始游戏\n");
			for(int i=5;i>=1;--i){
				printf("%d...\n",i);
				Sleep(1000); 
			}
			system("cls");
			bool flag=false;
			while(1){
				SetConsoleCursorPosition(hOutput,coord);
		        print();
				flag=false;	
		        if(kbhit()){
		        	flag=true;
					ch=getch();
					if(ch=='w'||ch=='s'||ch=='a'||ch=='d'){
						predirect=direct;
						direct=mp_ch_int[ch];
					}
				}
				modify();
				if(iscrash){
					printf("游戏结束，你本次积分为%d\n",score);
					getchar();getchar();
					return 0;
				}
				if(!flag)Sleep(level[diff_chr-'0']);
				else Sleep(1);	
			}
		}
	} else{
		printf("暂未编写，敬请期待\n");
		//待补充 
	}
}
