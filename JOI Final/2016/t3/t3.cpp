#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=100005,M=200005,Q=200005;
const int INF=1061109567;
int n,m,q;
int u[M],v[M],t[M];
vector<pair<int,int>>G[N];
int r[Q];
int dis[N],pre[N];
int ans[Q];
void bfs()
{
    fill(dis+1,dis+n+1,INF);
    fill(pre+1,pre+n+1,INF);
    queue<int>q;
    q.emplace(1);
    dis[1]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto [v,i]:G[u])
        {
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                pre[v]=min(pre[u],t[i]);
                q.emplace(v);
            }
            else if(dis[v]==dis[u]+1&&pre[v]<min(pre[u],t[i])) pre[v]=min(pre[u],t[i]);
        }
    }
    for(int i=1;i<=n;i++)
        if(pre[i]>=1&&pre[i]<=::q) ans[pre[i]]++;
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&u[i],&v[i]);
    fill(t+1,t+m+1,INF);
    for(int i=1;i<=q;i++)
        scanf("%d",&r[i]),t[r[i]]=i;
    for(int i=1;i<=m;i++)
        G[u[i]].emplace_back(v[i],i),G[v[i]].emplace_back(u[i],i);
    bfs();
    for(int i=1;i<=q;i++)
        ans[i]+=ans[i-1];
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    return 0;
}