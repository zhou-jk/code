#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
int h[100001],fa[100001];
int num;
long long ans;
bool book[100001];
struct Node
{
    int u,v,w;
}e[2000001];
struct Edge
{
    int to,val,next;
}edge[2000001];
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
int getf(int v)
{
    if(v==fa[v]) return v;
    fa[v]=getf(fa[v]);
    return fa[v];
}
bool merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2)
    {
        fa[f2]=f1;
        return true;
    }
    return false;
}
bool cmp(Node a,Node b)
{
    if(h[a.v]!=h[b.v]) return h[a.v]>h[b.v];
    else return a.w<b.w;
}
void bfs()
{
    queue<int>q;
    q.push(1);
    cnt=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(book[u]) continue;
        book[u]=true;
        num++;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(h[v]<h[u])
            {
                cnt++,e[cnt].u=u,e[cnt].v=v,e[cnt].w=edge[i].val;
                if(book[v]) continue;
                q.push(v);
            }
            else if(h[v]==h[u])
            {
                if(book[v]) continue;
                cnt++,e[cnt].u=u,e[cnt].v=v,e[cnt].w=edge[i].val;
                q.push(v);
            }
        }
    }
    return;
}
void kruskal()
{
    sort(e+1,e+cnt+1,cmp);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=cnt;i++)
        if(merge(e[i].u,e[i].v)) ans+=e[i].w;
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    bfs();
    kruskal();
    printf("%d %lld",num,ans);
    return 0;
}