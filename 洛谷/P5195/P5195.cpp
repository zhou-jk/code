#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1061109567;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int N=1050;
int w,h;
int bush[N][3],cnt;
int book[N][N];
int dis[N][N][2];
bool vis[N][N];
queue<pair<int,int> >q;
void BFS(int sx,int sy,int op)
{
    dis[sx][sy][op]=0;
    vis[sx][sy]=true;
    q.push(make_pair(sx,sy));
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=x+dir[i][0],ty=y+dir[i][1];
            if(tx<1||tx>h||ty<1||ty>w) continue;
            if(vis[tx][ty]) continue;
            if(book[tx][ty]!=0&&book[tx][ty]!=4) continue;
            dis[tx][ty][op]=dis[x][y][op]+1;
            vis[tx][ty]=true;
            q.push(make_pair(tx,ty));
        }
    }
    return;
}
int main()
{
    scanf("%d%d",&w,&h);
    int sx,sy,ex,ey;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        {
            scanf("%d",&book[i][j]);
            if(book[i][j]==2) sx=i,sy=j;
            if(book[i][j]==3) ex=i,ey=j;
            if(book[i][j]==4) cnt++,bush[cnt][1]=i,bush[cnt][2]=j;
        }
    BFS(sx,sy,0);
    memset(vis,false,sizeof(vis));
    BFS(ex,ey,1);
    int ans=INF;
    for(int i=1;i<=cnt;i++)
        if(dis[bush[i][1]][bush[i][2]][1]!=0&&dis[bush[i][1]][bush[i][2]][0]!=0) ans=min(ans,dis[bush[i][1]][bush[i][2]][1]+dis[bush[i][1]][bush[i][2]][0]);
    printf("%d",ans);
    return 0;

}