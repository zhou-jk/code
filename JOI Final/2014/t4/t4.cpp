#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=100005;
const long long INF=4557430888798830399;
int n,m,x;
int h[N];
vector<pair<int,int>>G[N];
long long dijkstra()
{
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    static long long dis[N];
    static bool vis[N];
    int dh[N];
    fill(vis+1,vis+n+1,false);
    fill(dis+1,dis+n+1,INF);
    dis[1]=0;
    dh[1]=x;
    q.emplace(dis[1],1);
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto [v,w]:G[u])
        {
            if(dh[u]-w>h[v])
            {
                int dw=dh[u]-h[v];
                if(dis[v]>dis[u]+dw)
                {
                    dis[v]=dis[u]+dw;
                    dh[v]=h[v];
                    q.emplace(dis[v],v);
                }
            }
            else if(dh[u]-w<0)
            {
                if(w>h[u]) continue;
                int dw=w-dh[u]+w;
                if(dis[v]>dis[u]+dw)
                {
                    dis[v]=dis[u]+dw;
                    dh[v]=0;
                    q.emplace(dis[v],v);
                }
            }
            else
            {
                int dw=w;
                if(dis[v]>dis[u]+dw)
                {
                    dis[v]=dis[u]+dw;
                    dh[v]=dh[u]-w;
                    q.emplace(dis[v],v);
                }
            }
        }
    }
    return dis[n]+h[n]-dh[n];
}
int main()
{
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].emplace_back(y,z);
        G[y].emplace_back(x,z);
    }
    long long ans=dijkstra();
    if(ans>=INF) printf("-1");
    else printf("%lld",ans);
    return 0;
}