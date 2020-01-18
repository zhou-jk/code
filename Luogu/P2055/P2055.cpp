#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1061109567;
int T,n;
struct Edge
{
    int to,val,next;
}edge[200001];
int head[100001],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int a[100001],b[100001];
int deep[100001];
bool bfs(int s,int t)
{
    queue<int>q;
    memset(deep,-1,sizeof(deep));
    q.push(s);
    deep[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].val<=0||deep[v]!=-1) continue;
            q.push(v);
            deep[v]=deep[u]+1;
        }
    }
    if(deep[t]!=-1) return true;
    else return false;
}
int dfs(int u,int flow,int t)
{
    if(u==t) return flow;
    int w,used=0;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(deep[v]!=deep[u]+1||edge[i].val==0) continue;
        w=dfs(v,min(flow-used,edge[i].val),t);
        edge[i].val-=w;
        edge[i^1].val+=w;
        used+=w;
        if(used==flow) return flow;
    }
    if(used==0) deep[u]=-1;
    return used;
}
int dinic(int s,int t)
{
    int res=0;
    while(bfs(s,t))
        res+=dfs(s,INF,t);
    return res;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(head,0,sizeof(head));
        cnt=1;
        int s=0,t=1000;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==1) add_edge(i+n,t,1),add_edge(t,i+n,0);
        }
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0) tot++;
            else if(b[i]==0) tot++;
            if(a[i]==1&&b[i]==0) add_edge(s,i,1),add_edge(i,s,0),add_edge(i,i+n,1),add_edge(i+n,i,0);
            if(a[i]==0) add_edge(s,i,1),add_edge(i,s,0);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                int x;
                scanf("%d",&x);
                if(x==0) continue;
                add_edge(i,j+n,1),add_edge(j+n,i,0);
            }
        if(tot==dinic(s,t)) printf("^_^\n");
        else printf("T_T\n");
    }
    return 0;
}