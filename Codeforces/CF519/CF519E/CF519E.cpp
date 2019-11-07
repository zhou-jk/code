#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
struct Edge
{
    int to,next;
}edge[200001];
int head[100001],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int size[100001],dep[100001];
int f[100001][17];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    f[u][0]=father;
    size[u]=1;
    for(int i=1;(1<<i)<=n;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
        size[u]+=size[v];
    }
    return;
}
int find(int u,int step)
{
    for(int i=log2(n);i>=0;i--)
        if(dep[u]-(1<<i)>=step) u=f[u][i];
    return u;
}
int query(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    int u=x,v=y,lca=0;
    for(int i=log2(n);i>=0;i--)
        if(dep[f[u][i]]>=dep[v]) u=f[u][i];
    if(u==v) lca=u;
    else
    {
        for(int i=log2(n);i>=0;i--)
            if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
        lca=f[u][0];
    }
    int dis=dep[x]+dep[y]-2*dep[lca];
    if(dis%2!=0) return 0;
    if(lca==y) return size[find(x,(dep[x]+dep[y])/2)]-size[find(x,(dep[x]+dep[y])/2+1)];
    else if(dep[x]==dep[y]) return n-size[find(x,dep[lca]+1)]-size[find(y,dep[lca]+1)];        
    else return size[find(x,dep[x]-dis/2)]-size[find(x,dep[x]-dis/2+1)];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs(1,0);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y) printf("%d\n",n);
        else printf("%d\n",query(x,y));
    }
    return 0;
}