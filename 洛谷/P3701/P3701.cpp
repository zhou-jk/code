#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=1061109567;
queue<int>q;
int n,m,S,T;
int a[101],b[101],cnta,cntb;
string as[101],bs[101];
struct Edge
{
    int to,val,next;
}edge[200001];
int head[301],cur[301],dep[301],cnt=1;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
bool bfs()
{
    memset(dep,-1,sizeof(dep));
    q.push(S);
    dep[S]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dep[v]==-1&&edge[i].val)
            {
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[T]!=-1;
}
int dfs(int u,int flow)
{
    if(u==T) return flow;
    int used=0;
    for(int i=cur[u];i;i=edge[i].next)
    {
        cur[u]=i;
        int v=edge[i].to;
        if(dep[v]==dep[u]+1&&edge[i].val)
        {
            int now=dfs(v,min(flow,edge[i].val));
            used+=now;
            flow-=now;
            edge[i].val-=now;
            edge[i^1].val+=now;
            if(!flow) break;
        }
    }
    return used;
}
int dinic()
{
    int res=0;
    while(bfs())
    {
        memcpy(cur,head,sizeof(head));
        res+=dfs(S,INF);
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    S=0,T=n*2+1;
    for(int i=1;i<=n;i++)
    {
        cin>>as[i];
        if(as[i]=="YYY") cnta++;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>bs[i];
        if(bs[i]=="YYY") cntb++;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(as[i]=="J") a[i]+=cnta;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if(bs[i]=="J") b[i]+=cntb;
    }
    for(int i=1;i<=n;i++)
        add_edge(S,i,a[i]),add_edge(i,S,0);
    for(int i=n+1;i<=n*2;i++)
        add_edge(i,T,b[i-n]),add_edge(T,i,0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(as[i]=="J"&&(bs[j]=="W"||bs[j]=="HK")) add_edge(i,j+n,1),add_edge(j+n,i,0);
            else if(as[i]=="E"&&(bs[j]=="J"||bs[j]=="YYY")) add_edge(i,j+n,1),add_edge(j+n,i,0);
            else if(as[i]=="YYY" && (bs[j]=="J" || bs[j]=="HK")) add_edge(i,j+n,1),add_edge(j+n,i,0);
            else if(as[i]=="HK" && (bs[j]=="W" || bs[j]=="E")) add_edge(i,j+n,1),add_edge(j+n,i,0);
            else if(as[i]=="W" && (bs[j]=="YYY" || bs[j]=="E")) add_edge(i,j+n,1),add_edge(j+n,i,0);
        }
    printf("%d",min(dinic(),m));
    return 0;
}