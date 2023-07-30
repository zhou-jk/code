#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=505,K=100005;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
const int INF=1061109567;
const long long LINF=4557430888798830399;
int n,m,k;
int a,b,c;
int d[N][N];
int x[K],y[K];
void bfs()
{
    for(int i=0;i<=n;i++)
        fill(d[i],d[i]+m+1,INF);
    queue<pair<int,int>>q;
    for(int i=1;i<=k;i++)
        d[x[i]][y[i]]=0,q.emplace(x[i],y[i]);
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=x+dir[i][0],ty=y+dir[i][1];
            if(tx<0||tx>n||ty<0||ty>m) continue;
            if(d[tx][ty]>d[x][y]+1)
            {
                d[tx][ty]=d[x][y]+1;
                q.emplace(tx,ty);
            }
        }
    }
    return;
}
int id[4][N][N],tot;
vector<pair<int,long long>>G[N*N*3];
long long dijkstra(int s,int t)
{
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    static long long dis[N*N*3];
    static bool vis[N*N*3];
    fill(dis+1,dis+tot+1,LINF);
    dis[s]=0;
    q.emplace(dis[s],s);
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto [v,w]:G[u])
            if(!vis[v]&&dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.emplace(dis[v],v);
            }
    }
    return dis[t];
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
        scanf("%d%d",&x[i],&y[i]);
    bfs();
    for(int l=1;l<=3;l++)
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                id[l][i][j]=++tot;
    for(int x=0;x<=n;x++)
        for(int y=0;y<=m;y++)
        {
            for(int i=0;i<4;i++)
            {
                int tx=x+dir[i][0],ty=y+dir[i][1];
                if(tx<0||tx>n||ty<0||ty>m) continue;
                G[id[1][x][y]].emplace_back(id[1][tx][ty],c);
            }
            G[id[1][x][y]].emplace_back(id[2][x][y],b);
            G[id[1][x][y]].emplace_back(id[3][x][y],b);
        }
    for(int x=0;x<=n;x++)
        for(int y=0;y<=m;y++)
        {
            for(int i=0;i<2;i++)
            {
                int tx=x+dir[i][0],ty=y+dir[i][1];
                if(tx<0||tx>n||ty<0||ty>m) continue;
                G[id[2][x][y]].emplace_back(id[2][tx][ty],a);
            }
            G[id[2][x][y]].emplace_back(id[1][x][y],(long long)d[x][y]*c);
        }
    for(int x=0;x<=n;x++)
        for(int y=0;y<=m;y++)
        {
            for(int i=2;i<4;i++)
            {
                int tx=x+dir[i][0],ty=y+dir[i][1];
                if(tx<0||tx>n||ty<0||ty>m) continue;
                G[id[3][x][y]].emplace_back(id[3][tx][ty],a);
            }
            G[id[3][x][y]].emplace_back(id[1][x][y],(long long)d[x][y]*c);
        }
    long long ans=dijkstra(id[1][x[1]][y[1]],id[1][x[k]][y[k]]);
    printf("%lld",ans);
    return 0;
}