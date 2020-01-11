#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
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
int len[N],son[N],tmp[N],*f[N],*now=tmp;
void dfs(int u,int father)
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father) continue;
		dfs(v,u);
		if(len[v]>len[son[u]]) son[u]=v;
	}
	len[u]=len[son[u]]+1;
	return;
}
int ans[N];
void dp(int u,int father)
{
	f[u][0]=1;
	if(!son[u]) return;
	f[son[u]]=f[u]+1;
	dp(son[u],u);
	ans[u]=ans[son[u]]+1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father||v==son[u]) continue;
		f[v]=now;
		now+=len[v];
		dp(v,u);
		for(int j=1;j<=len[v];j++)
		{
			f[u][j]+=f[v][j-1];
			if(f[u][j]>f[u][ans[u]]) ans[u]=j;
			else if(f[u][j]==f[u][ans[u]]&&j<ans[u]) ans[u]=j; 
		}
	}
	if(f[u][ans[u]]==1) ans[u]=0;
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
	dfs(1,0);
	f[1]=now;
	now+=len[1];
	dp(1,0);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}
