#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1061109567;
int n,m,s,t;
struct Edge
{
    int to,val,next;
}edge[200001];
int head[10001],cnt=1;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int pre[10001],flow[10001],rec[10001];
queue<int>q;
int bfs(int S,int T)
{
    memset(pre,-1,sizeof(pre));
    pre[S]=S;
    flow[S]=INF;
    q.push(S);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(pre[v]!=-1||edge[i].val<=0) continue;
            rec[v]=i;
            pre[v]=u;
            flow[v]=min(flow[u],edge[i].val);
            q.push(v);
        }
    }
    if(pre[T]!=-1) return flow[T];
    else return -1;
}
int edmonds_karp(int S,int T)
{
    int ans=0;
    while(1)
    {
        int res=bfs(S,T);
        if(res==-1) break;
        ans+=res;
        for(int i=T;i!=S;i=pre[i])
            edge[rec[i]].val-=res,edge[rec[i]^1].val+=res;
    }
    return ans;
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
    printf("%d",edmonds_karp(s,t));
    return 0;
}