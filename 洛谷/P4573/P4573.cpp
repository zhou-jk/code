#include<iostream>
#include<cstdio>
using namespace std;
const int N=15;
int e[N][N][N][N];
int r=1,c=2;
bool visr[N][N],visc[N][N],visn[N][N];
int ans[N][N];
char s[10];
const int idx[10][10]= 
{{0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,1,1,1,2,2,2,3,3,3},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,4,4,4,5,5,5,6,6,6},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9},
{0,7,7,7,8,8,8,9,9,9}};
bool check(int x,int y,int num)
{
	if(e[x][y][x][y-1]==1&&num<=ans[x][y-1]) return false;
	if(e[x][y][x][y-1]==-1&&num>=ans[x][y-1]) return false;
	if(e[x][y][x-1][y]==1&&num<=ans[x-1][y]) return false;
	if(e[x][y][x-1][y]==-1&&num>=ans[x-1][y]) return false;
	return true;
}
void dfs(int x,int y)
{
	if(x>9)
	{
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=9;j++)
				printf("%d ",ans[i][j]);
			printf("\n");
		}
		exit(0);
	}
	for(int i=1;i<=9;i++)
		if(!visr[x][i]&&!visc[y][i]&&!visn[idx[x][y]][i]&&check(x,y,i))
		{
			ans[x][y]=i;
			visr[x][i]=visc[y][i]=visn[idx[x][y]][i]=true;
			if(y==9) dfs(x+1,1);
			else dfs(x,y+1);
			visr[x][i]=visc[y][i]=visn[idx[x][y]][i]=false;
		}
	return;
}
int main()
{
	for(int k=1;k<=3;k++)
	{
		for(int j=1;j<=2;j++)
		{
			for(int i=1;i<=3;i++)
			{
				char ch;
				for(ch=getchar();ch!='<'&&ch!='>'&&ch!='^'&&ch!='v';ch=getchar());
				e[r][c][r][c-1]=(ch=='>'?-1:1);
				for(ch=getchar();ch!='<'&&ch!='>'&&ch!='^'&&ch!='v';ch=getchar());
				e[r][c+1][r][c]=(ch=='>'?-1:1);
				c+=3;
			}
			for(int i=1;i<=9;i++)
			{
				char ch;
				for(ch=getchar();ch!='<'&&ch!='>'&&ch!='^'&&ch!='v';ch=getchar());
				e[r+1][i][r][i]=(ch=='v'?-1:1);
			}
			r++;
			c=2;
		}
		for(int i=1;i<=3;i++)
		{
			char ch;
			for(ch=getchar();ch!='<'&&ch!='>'&&ch!='^'&&ch!='v';ch=getchar());
			e[r][c][r][c-1]=(ch=='>'?-1:1);
			for(ch=getchar();ch!='<'&&ch!='>'&&ch!='^'&&ch!='v';ch=getchar());
			e[r][c+1][r][c]=(ch=='>'?-1:1);
			c+=3;
		}
		r++;
		c=2;
	}
	dfs(1,1);
	return 0;
}