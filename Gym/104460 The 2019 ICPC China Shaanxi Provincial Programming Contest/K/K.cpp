#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=100005;
const long long INF=4557430888798830399;
int n,m,k;
int e[N];
int d[N];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
vector<pair<int,int>>G[N];
long long dis[N];
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
        cin>>e[i];
    for(int i=1;i<=n;i++)
        cin>>d[i];
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        G[x].emplace_back(y,z);
        G[y].emplace_back(x,z);
    }
    fill(dis+1,dis+n+1,INF);
    for(int i=1;i<=k;i++)
        d[e[i]]=0,dis[e[i]]=0;
    for(int i=1;i<=k;i++)
        q.emplace(dis[e[i]],e[i]);
    while(!q.empty())
    {
        int u=q.top().second;
        long long val=q.top().first;
        q.pop();
        d[u]--;
        if(d[u]!=-1) continue;
        dis[u]=val;
        for(auto [v,w]:G[u])
            if(d[v]>=0) q.emplace(dis[u]+w,v);
    }
    if(dis[1]>=INF) cout<<-1<<"\n";
    else cout<<dis[1]<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}