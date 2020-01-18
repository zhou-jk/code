#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1061109567;
int n,m,q;
struct Node
{  
    int u,v,w;
}e[50001];
struct Edge
{
    int to,next,val;
}edge[100005];
int cnt,head[10001];
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
bool cmp(Node x,Node y)
{
    return x.w>y.w;
}
int fa[10001];
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
void kruskal()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++)
        if(merge(e[i].u,e[i].v))
        {
            add_edge(e[i].u,e[i].v,e[i].w);
            add_edge(e[i].v,e[i].u,e[i].w);
        }
    return;
}

int dep[10001],f[10001][21],dis[10001][21];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    f[u][0]=father;
    for(int i=1;(1<<i)<=n;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    
    for(int i=1;(1<<i)<=n;i++)
        dis[u][i]=min(dis[u][i-1],dis[f[u][i-1]][i-1]);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dis[v][0]=edge[i].val;
        dfs(v,u);
    }
    return ;
}
int query(int x,int y)
{
    int ans=INF;
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=log2(n);i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y]) ans=min(ans,dis[x][i]),x=f[x][i];
        if(x==y) return ans;
	}
	for(int i=log2(n);i>=0;i--)
		if(f[x][i]!=f[y][i]) ans=min(ans,min(dis[x][i],dis[y][i])),x=f[x][i],y=f[y][i];
    ans=min(ans,min(dis[x][0],dis[y][0]));
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    kruskal();
    memset(dis,63,sizeof(dis));
    for(int i=1;i<=n;i++)
        if(!dep[i]) dfs(i,0);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
	{
        int x,y;
        scanf("%d%d",&x,&y);
        if(getf(x)!=getf(y)) printf("-1\n");
        else printf("%d\n",query(x,y));
    }
    return 0;
} 