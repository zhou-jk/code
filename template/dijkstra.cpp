#include<iostream>
#include<cstdio>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N=2505;
const long long INF=4557430888798830399;
int n,m;
vector<pair<int,int>>G[N];
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
    int s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].emplace_back(y,z);
        G[y].emplace_back(x,z);
    }
    vector<long long>dis=dijkstra(s);
    printf("%lld",dis[t]);
    return 0;
}