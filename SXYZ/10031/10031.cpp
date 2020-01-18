#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const double eps=1e-4;
int n,m;
int a[N],b[N];
double V[N];
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
int dis[N],dep[N],son[N],len[N];
void dfs1(int u,int father)
{
	dis[u]=dep[u]=dep[father]+1;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father) continue;
		dfs1(v,u);
		if(dis[v]>dis[son[u]]) son[u]=v;
	}
	if(son[u]) dis[u]=dis[son[u]];
	len[u]=dis[u]-dep[u]+1;
	return;
}
double tmp[N],*f[N],*now=tmp;
void dfs2(int u,int father)
{
	if(!son[u]) return;
	f[son[u]]=f[u]+1;
	dfs2(son[u],u);
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father||v==son[u]) continue;
		f[v]=now,now+=len[v];
		dfs2(v,u);
	}
	return;
}
double ans;
void dfs(int u,int father)
{
	V[u]+=V[father];
	f[u][0]=V[u];
	if(!son[u]) return;
	dfs(son[u],u);
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father||v==son[u]) continue;
		dfs(v,u);
		for(int j=0;j<len[v];j++)
			if(m-j-1>=0&&len[u]>m-j-1) ans=min(ans,f[u][m-j-1]+f[v][j]-V[u]-V[father]);
		for(int j=0;j<len[v];j++)
			f[u][j+1]=min(f[u][j+1],f[v][j]);
	}
	if(len[u]>m) ans=min(ans,f[u][m]-V[father]);
	return;
}
bool check(double x)
{
	ans=1e18;
	for(int i=1;i<=n;i++)
		V[i]=a[i]-x*b[i],tmp[i]=1e18;
	dfs(1,0);
	return ans<=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	dfs1(1,0);
	f[1]=now,now+=dis[1];
	dfs2(1,1);
	double l=0,r=1e9;
	while(r-l>=eps)
	{
		double mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(l>=4e8) printf("-1");
	else printf("%.2lf",l);
	return 0;
}
