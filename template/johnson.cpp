#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N=3005;
const long long INF=4557430888798830399;
int n,m;
vector<pair<int,int>>G[N];
long long h[N];
bool inq[N];
int num[N];
bool spfa(int s)
{
    fill(h,h+n+1,INF);
    h[s]=0;
    fill(num,num+n+1,0);
    fill(inq,inq+n+1,false);
    queue<int>q;
    q.emplace(s);
    inq[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(auto [v,w]:G[u])
            if(h[v]>h[u]+w)
            {
                h[v]=h[u]+w;
                if(!inq[v])
                {
                    q.emplace(v);
                    inq[v]=true;
                    num[v]=num[u]+1;
                    if(num[v]>n) return false;
                }
            }
    }
    return true;
}
vector<long long> dijkstra(int s)
{
    vector<long long>dis(n+1,INF);
    __gnu_pbds::priority_queue<pair<long long,int>,greater<pair<long long,int>>,pairing_heap_tag> q;
    vector<__gnu_pbds::priority_queue<pair<long long,int>,greater<pair<long long,int>>,pairing_heap_tag>::point_iterator> id(n+1,nullptr);
    dis[s]=0;
    static bool vis[N];
    fill(vis+1,vis+n+1,false);
    id[s]=q.push(make_pair(dis[s],s));
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(auto [v,w]:G[u])
        {
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(id[v]==nullptr) id[v]=q.push(make_pair(dis[v],v));
                else q.modify(id[v],make_pair(dis[v],v));
            }
        }
    }
    return dis;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].emplace_back(y,z);
    }
    for(int i=1;i<=n;i++)
        G[0].emplace_back(i,0);
    if(!spfa(0))
    {
        printf("-1");
        return 0;
    }
    for(int u=1;u<=n;u++)
        for(auto &[v,w]:G[u])
            w+=h[u]-h[v];
    for(int i=1;i<=n;i++)
    {
        vector<long long>dis=dijkstra(i);
        for(int j=1;j<=n;j++)
            if(dis[j]<INF) dis[j]+=h[j]-h[i];
        long long ans=0;
        for(int j=1;j<=n;j++)
        {
            if(dis[j]>=INF) ans+=j*1000000000LL;
            else ans+=j*dis[j];
        }
        printf("%lld\n",ans);
    }
    return 0;
}