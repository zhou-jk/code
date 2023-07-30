#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=100005;
const long long INF=4557430888798830399;
int n,m,c;
vector<pair<int,int>>G[N];
long long dis[N];
void dijkstra()
{
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    static bool vis[N];
    fill(dis+1,dis+n+1,INF);
    fill(vis+1,vis+n+1,false);
    dis[1]=0;
    q.emplace(dis[1],1);
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto [v,w]:G[u])
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.emplace(dis[v],v);
            }
    }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&c);
    long long sum=0;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].emplace_back(y,z);
        G[y].emplace_back(x,z);
        sum+=z;
    }
    dijkstra();
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return dis[x]<dis[y];});
    long long ans=sum;
    static bool book[N];
    fill(book+1,book+n+1,false);
    for(int i=1;i<=n;i++)
    {
        int u=id[i];
        book[u]=true;
        for(auto [v,w]:G[u])
            if(book[v]) sum-=w;
        ans=min(ans,(long long)c*dis[u]+sum);
    }
    printf("%lld",ans);
    return 0;
}