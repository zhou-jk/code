#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1061109567;
struct Edge
{
    int to,val,next;
}edge[200001];
int cur[10001],head[10001],cnt=1;
int n,m,s,t;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dep[10001];
bool bfs()
{
    memset(dep,-1,sizeof(dep));
    queue<int>q;
    q.push(s);
    dep[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]!=-1||edge[i].val<=0) continue;
            dep[v]=dep[u]+1;
            q.push(v);
        }
    }
    return dep[t]!=-1;
}
long long dfs(int u,int flow)
{
    if(u==t) return flow;
    long long used=0;
    for(int i=cur[u];i;i=edge[i].next)
    {
        cur[u]=i;
        int v=edge[i].to;
        if(dep[v]!=dep[u]+1||edge[i].val<=0) continue;
        int now=dfs(v,min(flow,edge[i].val));
        flow-=now;
        edge[i].val-=now;
        edge[i^1].val+=now;
        used+=now;
        if(flow==0) break;
    }
    if(used==0) dep[u]=-1;
    return used;
}
long long dinic()
{
    long long res=0;
    while(bfs())
    {
        memcpy(cur,head,sizeof(head));
        res+=dfs(s,INF);
    }
    return res;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,0);
    }
    printf("%lld",dinic());
    return 0;
}