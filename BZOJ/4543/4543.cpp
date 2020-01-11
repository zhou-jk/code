#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
struct Edge
{
	int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
	return;
}
int dep[N],son[N],len[N];
void dfs1(int u,int father)
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father) continue;
		dfs1(v,u);
		len[u]=max(len[u],len[v]);
		if(len[v]>len[son[u]]) son[u]=v;
	}
	len[u]=len[son[u]]+1;
	return;
}
long long *f[N],*g[N];
long long tmp[N<<2],*id=tmp;
long long ans;
void dfs(int u,int father)
{
	f[u][0]=1;
	if(!son[u]) return;
	f[son[u]]=f[u]+1;
	g[son[u]]=g[u]-1;
	dfs(son[u],u);
	ans+=g[u][0];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father||v==son[u]) continue;
		f[v]=id;id+=len[v]<<1;
		g[v]=id;id+=len[v]<<1;
		dfs(v,u);
		for(int j=0;j<len[v];j++)
		{
			if(j) ans+=f[u][j-1]*g[v][j];
			ans+=g[u][j+1]*f[v][j];
		}
		for(int j=0;j<len[v];j++)
		{
			g[u][j+1]+=f[u][j+1]*f[v][j];
			if(j) g[u][j-1]+=g[v][j];
			f[u][j+1]+=f[v][j];
		}
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	dfs1(1,0);
	f[1]=id;id+=len[1]<<1;
	g[1]=id;id+=len[1]<<1;
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
