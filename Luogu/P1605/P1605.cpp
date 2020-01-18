#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool e[6][6],book[6][6];
int fx,fy,sx,sy,T,n,m,ans;
void dfs(int x,int y)
{
    if(x==fx&&y==fy)
    {
        ans++;
        return;
    }
    for(int i=0;i<4;i++)
    {
    	int tx=x+dir[i][0],ty=y+dir[i][1];
    	if(tx<1||tx>n||ty<1||ty>m) continue;
    	if(book[tx][ty]||!e[tx][ty]) continue;
    	book[x][y]=true;
    	dfs(tx,ty);
    	book[x][y]=false;
    }
    return;
}
int main()
{
	memset(e,true,sizeof(e));
    scanf("%d%d%d%d%d%d%d",&n,&m,&T,&sx,&sy,&fx,&fy);
    int x,y;
    for(int i=1;i<=T;i++)
    {
        scanf("%d%d",&x,&y);
        e[x][y]=false;
    }
    dfs(sx,sy);
    printf("%d",ans);
    return 0;
} 