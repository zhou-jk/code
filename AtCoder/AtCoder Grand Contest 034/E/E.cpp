#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=2005;
const int INF=1061109567;
int n;
int a[N];
vector<int>G[N];
long long Min[N],Max[N];
int siz[N];
int son[N];
void dfs1(int u,int father)
{
	siz[u]=0;
	if(a[u]) siz[u]++;
	Max[u]=0;
	son[u]=0;
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		Max[u]+=Max[v]+siz[v];
		if(Max[v]>Max[son[u]]) son[u]=v;
	}
	return;
}
void dfs2(int u,int father)
{
	if(!son[u])
	{
		Min[u]=0;
		return;
	}
	dfs2(son[u],u);
	int mi=Min[son[u]]+siz[son[u]],mx=Max[son[u]]+siz[son[u]];
	if(mi-(Max[u]-mx)>=0) Min[u]=mi-(Max[u]-mx);
	else Min[u]=Max[u]&1;
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%1d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	Max[0]=-1;
	long long ans=INF;
	for(int u=1;u<=n;u++)
	{
		dfs1(u,0);
		dfs2(u,0);
		if(Min[u]==0) ans=min(ans,Max[u]/2);
	}
	if(ans>=INF) printf("-1");
	else printf("%lld",ans);
	return 0;
}
