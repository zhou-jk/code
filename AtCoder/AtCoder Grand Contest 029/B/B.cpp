#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N=200005;
int n;
int a[N];
unordered_map<int,int>cnt;
int b[N],tot;
vector<int>G[N];
int fa[N];
int ret[N];
int ans;
void dfs(int u,int father)
{
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
		if(ret[v]>0&&ret[u]>0)
		{
			int del=min(ret[v],ret[u]);
			ret[v]-=del,ret[u]-=del,ans+=del;
		}
	}
	if(__builtin_popcount(b[u]+b[u])==1) ans+=ret[u]/2,ret[u]%=2;
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		cnt[a[i]]++,b[++tot]=a[i];
	sort(b+1,b+tot+1);
	tot=unique(b+1,b+tot+1)-b-1;
	for(int i=1;i<=tot;i++)
	{
		int t=log2(b[i])+1;
		int val=(1<<t)-b[i];
		if(!cnt[val]) continue;
		int v=lower_bound(b+1,b+tot+1,val)-b;
		if(i==v) continue;
		G[i].emplace_back(v);
		G[v].emplace_back(i);
		fa[i]=v;
	}
	for(int i=1;i<=tot;i++)
		ret[i]=cnt[b[i]];
	for(int i=1;i<=n;i++)
		if(!fa[i]) dfs(i,0);
	printf("%d",ans);
	return 0;
}