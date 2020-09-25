#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n,m;
vector<int>G[N];
int d[N];
int x[N],y[N];
int fa[N];
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
	else return false;
}
vector<pair<int,int> >res;
void kruskal()
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		if(merge(x[i],y[i])) G[x[i]].push_back(y[i]),G[y[i]].push_back(x[i]);
		else res.push_back(make_pair(x[i],y[i])),d[x[i]]++;
	return;
}
void dfs(int u,int father)
{
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
		if(d[v]&1) res.push_back(make_pair(v,u)),d[v]++;
		else res.push_back(make_pair(u,v)),d[u]++;
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&x[i],&y[i]);
	if(m&1)
	{
		printf("-1");
		return 0;
	}
	kruskal();
	dfs(1,0);
	for(auto [u,v]:res)
		printf("%d %d\n",u,v);
	return 0;
}
