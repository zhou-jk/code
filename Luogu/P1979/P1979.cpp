#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1061109567;
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int n,m,Q;
int e[31][31],step[31][31],dis[5001];
bool book[5001];
inline int count(int x,int y)
{
    return (x-1)*m*4+(y-1)*4;
}
struct Edge
{
    int to,val,next;
}edge[40001];
int head[5001],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
struct Node
{
    int x,y;
};
void bfs(int ex,int ey,int sx,int sy,int z)
{
    memset(step,-1,sizeof(step));
    step[sx][sy]=1,step[ex][ey]=0;
    queue<Node>q;
    q.push((Node){ex,ey});
    while(!q.empty())
    {
        Node u=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            Node t;
            t.x=u.x+dir[i][0],t.y=u.y+dir[i][1];
            if(!e[t.x][t.y]||step[t.x][t.y]!=-1) continue;
            step[t.x][t.y]=step[u.x][u.y]+1;
            q.push(t);
        }
    }
    if(z==4) return;
    int id=count(sx,sy);
    for(int i=0;i<4;i++)
    {
        int x=sx+dir[i][0],y=sy+dir[i][1];
        if(step[x][y]==-1) continue;
        add_edge(id+z,id+i,step[x][y]);
    }
    add_edge(id+z,count(ex,ey)+(z+2)%4,1);
    return;
}
void spfa(int sx,int sy)
{
    queue<int>q;
    memset(dis,63,sizeof(dis));
    memset(book,false,sizeof(book));
    int id=count(sx,sy);
    for(int i=0;i<4;i++)
    {
        int x=sx+dir[i][0],y=sy+dir[i][1];
        if(step[x][y]==-1) continue;
        book[id+i]=true;
        dis[id+i]=step[x][y];
        q.push(id+i);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        book[u]=false;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                if(!book[v])
                {
                    book[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&e[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(e[i][j])
                for(int k=0;k<4;k++)
                {
                    int x=i+dir[k][0],y=j+dir[k][1];
                    if(!e[x][y]) continue;
                    bfs(x,y,i,j,k);
                }
    while(Q--)
    {
        int ex,ey,sx,sy,tx,ty;
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        if(sx==tx&&sy==ty)
        {
            printf("0\n");
            continue;
        }
        bfs(ex,ey,sx,sy,4);
        spfa(sx,sy);
        int id=count(tx,ty),ans=INF;
        for(int i=0;i<4;i++)
            ans=min(ans,dis[id+i]);
        if(ans>=INF) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}