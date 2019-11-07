#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
int n,m;
struct
{
    int to,next;
}edge1[100001];
int head1[100001],cnt1;
void add_edge1(int u,int v)
{
    cnt1++;
    edge1[cnt1].to=v;
    edge1[cnt1].next=head1[u];
    head1[u]=cnt1;
    return;
}
struct
{
    int to,val,next;
}edge[300001];
int head[200001],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dfn[100001],low[100001],Index;
int belong[100001],size[100001],tot;
stack<int>s;
bool book[100001];
void tarjan(int u)
{
    dfn[u]=low[u]=++Index;
    book[u]=true;
    s.push(u);
    for(int i=head1[u];i;i=edge1[i].next)
    {
        int v=edge1[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(book[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        tot++;
        while(s.top()!=u)
        {
            belong[s.top()]=tot;
            size[tot]++;
            book[s.top()]=false;
            s.pop();
        }
        belong[u]=tot;
        size[tot]++;
        book[u]=false;
        s.pop();
    }
    return;
}
queue<int> q;
int dis[200001];
bool vis[200001];
void spfa()
{
    q.push(belong[1]);
    vis[belong[1]]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(dis[v]<dis[u]+edge[i].val)
            {
                dis[v]=dis[u]+edge[i].val;
                if(!vis[v])
                {
                    vis[v]=true;
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
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge1(x,y);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    for(int u=1;u<=n;u++)
        for(int i=head1[u];i;i=edge1[i].next)
        {
            int v=edge1[i].to;
            if(belong[u]!=belong[v])
            {
                add_edge(belong[u],belong[v],size[belong[v]]);
                add_edge(belong[u]+n,belong[v]+n,size[belong[v]]);
                add_edge(belong[v],belong[u]+n,size[belong[u]]);
            }
        }
    spfa();
    printf("%d",dis[belong[1]+n]);
    return 0;
}