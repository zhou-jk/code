#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
queue<int>q;
int temp;
int x[200001],y[200001];
int n,m,s,t;
struct Edge
{
    int to,next;
}edge[500001];
int cnt,head[10001];
bool book[10001],vis[10001],inq[10001];
int dis[10001];
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void check(int S)
{
    memset(vis,false,sizeof(vis));
    q.push(S);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!vis[v]) q.push(v);
        }
    }
    return;
}
void spfa(int S)
{
    memset(dis,63,sizeof(dis));
    temp=dis[0];
    dis[S]=0;
    q.push(S);
    inq[S]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inq[u]=false;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!book[v]) continue;
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                if(!inq[v])
                {
                    inq[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        add_edge(y[i],x[i]);
    }
    scanf("%d%d",&s,&t);
    check(t);
    memset(head,0,sizeof(head));
    cnt=0;
    for(int i=1;i<=m;i++)
        add_edge(x[i],y[i]);
    for(int u=1;u<=n;u++)
    {
        book[u]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!vis[v])
            {
                book[u]=false;
                break;
            }
        }
    }
    spfa(s);
    if(dis[t]==temp) printf("-1");
    else printf("%d",dis[t]);
    return 0;
}