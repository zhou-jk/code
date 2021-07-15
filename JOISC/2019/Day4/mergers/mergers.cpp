#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=500005;
int n,k;
struct Edge
{
    int to,next;
}edge[N<<2];
int head[N],cnt=1;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dfn[N],low[N],Index;
bool book[N<<2];
void tarjan(int u,int pre)
{
    dfn[u]=low[u]=++Index;
    for(int i=head[u];i;i=edge[i].next)
    {
        if((i^1)==pre) continue;
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v]) book[i]=book[i^1]=true;
        }
        else low[u]=min(low[u],dfn[v]);
    }
    return;
}
vector<int> e[N];
int fa[N],d[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    fa[v]=getf(fa[v]);
    return fa[v];
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2) fa[f2]=f1;
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        e[x].push_back(i);
    }
    for(int i=1;i<=k;i++)
        for(int j=0;j<(int)e[i].size();j++)
            add_edge(e[i][j],e[i][(j+1)%e[i].size()]),add_edge(e[i][(j+1)%e[i].size()],e[i][j]);
    tarjan(1,0);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=edge[i].next)
        {
            if(book[i]) continue;
            int v=edge[i].to;
            merge(u,v);
        }
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(getf(u)==getf(v)||u>=v) continue;
            d[getf(u)]++,d[getf(v)]++;
        }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(getf(i)==i&&d[i]==1) ans++;
    printf("%d",(ans+1)/2);
    return 0;
}