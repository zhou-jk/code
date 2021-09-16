#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
const int N=205,M=50005;
const int INF=1061109567;
int n,m;
struct Edge
{
    int u,v,c,d;
}e[M];
void dijkstra(vector<tuple<int,int,int>> *G,int *dis,bool *book,int s)
{
    fill(dis+1,dis+n+1,INF);
    dis[s]=0;
    static bool vis[N];
    fill(vis+1,vis+n+1,false);
    static int pre[N];
    pre[s]=0;
    for(int k=1;k<=n;k++)
    {
        int u=0;
        for(int i=1;i<=n;i++)
            if(!vis[i])
            {
                if(u==0||dis[i]<dis[u]) u=i;
            }
        if(u==0||dis[u]>=INF) continue;
        vis[u]=true;
        for(auto [v,w,id]:G[u])
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pre[v]=id;
            }
    }
    fill(book+1,book+m+1,false);
    for(int i=1;i<=n;i++)
        if(i!=s) book[pre[i]]=true;
    return;
}
vector<tuple<int,int,int>> G[N],GT[N];
int dis1[N],disn[N];
bool book1[M],bookn[M];
int dist1[N],distn[N];
bool bookt1[M],booktn[M];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].c,&e[i].d);
    for(int i=1;i<=m;i++)
        G[e[i].u].emplace_back(e[i].v,e[i].c,i),GT[e[i].v].emplace_back(e[i].u,e[i].c,i);
    dijkstra(G,dis1,book1,1);
    dijkstra(G,disn,bookn,n);
    dijkstra(GT,dist1,bookt1,1);
    dijkstra(GT,distn,booktn,n);
    int ans=dis1[n]+disn[1];
    for(int k=1;k<=m;k++)
    {
        auto [u,v,c,d]=e[k];
        int d1,dn;
        int dv,du;
        if(book1[k])
        {
            static int dis[N];
            static bool book[M];
            static vector<tuple<int,int,int>> GN[N];
            for(int i=1;i<=n;i++)
                GN[i].clear();
            for(int i=1;i<=m;i++)
                if(i!=k) GN[e[i].u].emplace_back(e[i].v,e[i].c,i);
            dijkstra(GN,dis,book,1);
            dn=dis[n],dv=dis[v];
        }
        else dn=dis1[n],dv=dis1[v];
        if(booktn[k])
        {
            static int dis[N];
            static bool book[M];
            static vector<tuple<int,int,int>> GN[N];
            for(int i=1;i<=n;i++)
                GN[i].clear();
            for(int i=1;i<=m;i++)
                if(i!=k) GN[e[i].v].emplace_back(e[i].u,e[i].c,i);
            dijkstra(GN,dis,book,n);
            du=dis[u];
        }
        else du=distn[u];
        dn=min(dn,dv+du+c);
        if(bookn[k])
        {
            static int dis[N];
            static bool book[M];
            static vector<tuple<int,int,int>> GN[N];
            for(int i=1;i<=n;i++)
                GN[i].clear();
            for(int i=1;i<=m;i++)
                if(i!=k) GN[e[i].u].emplace_back(e[i].v,e[i].c,i);
            dijkstra(GN,dis,book,n);
            d1=dis[1],dv=dis[v];
        }
        else d1=disn[1],dv=disn[v];
        if(bookt1[k])
        {
            static int dis[N];
            static bool book[M];
            static vector<tuple<int,int,int>> GN[N];
            for(int i=1;i<=n;i++)
                GN[i].clear();
            for(int i=1;i<=m;i++)
                if(i!=k) GN[e[i].v].emplace_back(e[i].u,e[i].c,i);
            dijkstra(GN,dis,book,1);
            du=dis[u];
        }
        else du=dist1[u];
        d1=min(d1,dv+du+c);
        ans=min((long long)ans,(long long)d1+dn+d);
    }
    if(ans>=INF) printf("-1");
    else printf("%d",ans);
    return 0;
}