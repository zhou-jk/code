#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int res[1000001];
struct Edge
{
    int to,next;
}edge[1000001];
int head[1000001],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void dfs(int u,int father)
{
    res[u]=father;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!res[v]) dfs(v,father);
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
        add_edge(y,x);
    }
    for(int i=n;i>0;i--)
        if(!res[i]) dfs(i,i);
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}