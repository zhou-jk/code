#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
int ans,cnt,flag=1;
int a[501][501];
bool vis[501][501],book[501][501];
int l[501],r[501];
struct node
{
    int x,y,v;
}e[501];
bool cmp(node x,node y)
{
    return x.v>y.v;
}
struct Node
{
    int x,y;
}u,t;
void bfs(int x,int y)
{
    queue<Node>q;
    t.x=x,t.y=y;
    q.push(t);
    memset(vis,false,sizeof(vis));
    vis[t.x][t.y]=true;
    book[t.x][t.y]=true;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            t.x=u.x+dir[i][0],t.y=u.y+dir[i][1];
            if(t.x<1||t.x>n||t.y<1||t.y>m) continue;
            if(vis[t.x][t.y]||a[u.x][u.y]<=a[t.x][t.y]) continue;
            vis[t.x][t.y]=true;
            book[t.x][t.y]=true;
            q.push(t);
        }
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=m;i++)
        e[i].v=a[1][i],e[i].x=1,e[i].y=i;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++)
        if(!book[e[i].x][e[i].y])
        {
            bfs(e[i].x,e[i].y);
            for(int j=1;j<=m;j++)
                if(vis[n][j])
                {
                    l[i]=j;
                    break;
                }
            for(int j=1;j<=m;j++)
                if(vis[n][j]) r[i]=j;
        }
    for(int j=1;j<=m;j++)
        if(!book[n][j]) flag=0,cnt++;
    printf("%d\n",flag);
    if(flag)
    {
        int Max;
        for(int left=1;left<=m;left=Max+1)
        {
            Max=0;
            for(int i=1;i<=m;i++)
                if(l[i]<=left) Max=max(Max,r[i]);
            ans++;
        }
        printf("%d",ans);
    }
    else printf("%d",cnt);
    return 0;
}