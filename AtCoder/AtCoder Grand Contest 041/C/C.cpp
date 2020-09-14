#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
const char s3[4][4]=
{
"aa.",
"..a",
"..a"
};
const char s4[5][5]=
{
"aabc",
"ddbc",
"efgg",
"efhh"
};
const char s5[6][6]=
{
"a.bbc",
"add.c",
"eeffg",
"hi..g",
"hi.jj"
};
const char s6[7][7]=
{
"aabbc.",
"d...ce",
"d.f..e",
"..fghh",
"ii.g.k",
".llnnk"
};
const char s7[8][8]=
{
"aabbc..",
".d..cee",
"fd...gg",
"f.h...i",
"..hjj.i",
"kklm...",
"..lmnn."
};
int n,m;
char col[N][N];
int main()
{
	scanf("%d",&n);
	if(n<=2)
	{
		printf("-1");
		return 0;
	}
	if(n==3)
	{
		for(int x=0;x<3;x++)
		{
			for(int y=0;y<3;y++)
				printf("%c",s3[x][y]);
			printf("\n");
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			col[i][j]='.';
	if(n%4==0)
	{
		for(int i=1;i<=n;i+=4)
			for(int x=0;x<4;x++)
				for(int y=0;y<4;y++)
					col[i+x][i+y]=s4[x][y];
	}
	else if(n%4==1)
	{
		m=n-5;
		int i;
		for(i=1;i<=m;i+=4)
			for(int x=0;x<4;x++)
				for(int y=0;y<4;y++)
					col[i+x][i+y]=s4[x][y];
		for(int x=0;x<5;x++)
			for(int y=0;y<5;y++)
				col[i+x][i+y]=s5[x][y];
	}
	else if(n%4==2)
	{
		m=n-6;
		int i;
		for(i=1;i<=m;i+=4)
			for(int x=0;x<4;x++)
				for(int y=0;y<4;y++)
					col[i+x][i+y]=s4[x][y];
		for(int x=0;x<6;x++)
			for(int y=0;y<6;y++)
				col[i+x][i+y]=s6[x][y];
	}
	else if(n%4==3)
	{
		m=n-7;
		int i;
		for(i=1;i<=m;i+=4)
			for(int x=0;x<4;x++)
				for(int y=0;y<4;y++)
					col[i+x][i+y]=s4[x][y];
		for(int x=0;x<7;x++)
			for(int y=0;y<7;y++)
				col[i+x][i+y]=s7[x][y];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%c",col[i][j]);
		printf("\n");
	}
	return 0;
}
