#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;
int n,m,T;
struct Edge
{
    int next,to,dis;
}edge[600001],e[600001];
int h[300001],Cnt;
int head[300001],cnt;
void add_edge(int u,int v,int w)
{
	Cnt++;
    e[Cnt].next=h[u];
    e[Cnt].to=v;
    e[Cnt].dis=w;
    h[u]=Cnt;
	return;
}
void add(int u,int v,int w)
{
	cnt++;
    edge[cnt].to=v;
    edge[cnt].dis=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
	return;
}
bool book[300001];
stack<int>s;
int dfn[300001],low[300001],Index;
int a[300001],belong[300001],size[300001],tot;
void tarjan(int u,int father)
{
    dfn[u]=low[u]=++Index;
	s.push(u);
	book[u]=true;
    for(int i=h[u];i;i=e[i].next)
	{
        int v=e[i].to;
        if(v==father) continue;
        if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}
        else if(book[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
	{
		tot++;
        while(s.top()!=u)
		{
            size[tot]++;
            belong[s.top()]=tot;
			book[s.top()]=false;
            s.pop();
        }
		belong[u]=tot;
		book[u]=false;
        size[tot]++;
		s.pop();
    }
	return;
}
int dep[300001],dis[300001];
int f[300001][19];
void dfs(int u,int father)
{
	f[u][0]=father;
    dep[u]=dep[father]+1;
	for(int i=1;(1<<i)<=n;i++)
		f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].next)
	{
        int v=edge[i].to;
        if(v==father) continue;
        dis[v]=dis[u]+edge[i].dis+a[v];
        dfs(v,u);
    }
	return;
}
int query(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=log2(n);i>=0;i--)
	{
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
    for(int i=log2(n);i>=0;i--)
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main()
{
	scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
	{
        int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,z);
    }
    for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i,0);
    for(int u=1;u<=n;u++)
	{
        for(int i=h[u];i;i=e[i].next)
		{
            int v=e[i].to;
            if(belong[u]!=belong[v]) add(belong[u],belong[v],e[i].dis);
            else a[belong[u]]+=e[i].dis;
        }
    }
    dis[belong[1]]=a[belong[1]];
    dfs(belong[1],0);
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
	{
        int x,y;
		scanf("%d%d",&x,&y);
        x=belong[x];
		y=belong[y];
        for()
        int lca=query(x,y);
        if(dis[x]+dis[y]-2*dis[lca]+a[lca]>0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
