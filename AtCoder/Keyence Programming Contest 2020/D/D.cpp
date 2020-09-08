#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=(1<<9)+5,M=100005;
int n,m,Q;
int v[N*N],w[N*N];
long long f[N][M];
bool book[N*N];
long long ans;
void dfs(int u,long long ret,long long sum)
{
	if(ret<0) return;
	if(u<=(1<<9))
	{
		ans=max(ans,sum+f[u][ret]);
		return;
	}
	book[u]=true;
	dfs(u/2,ret-w[u],sum+v[u]);
	book[u]=false;
	dfs(u/2,ret,sum);
	return;
}
void solve()
{
	int u,L;
	scanf("%d%d",&u,&L);
	ans=0;
	dfs(u,L,0);
	printf("%lld\n",ans);
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&v[i],&w[i]);
	m=100000;
	for(int i=1;i<=min(1<<9,n);i++)
	{
		int p=i/2;
		for(int j=0;j<=m;j++)
			if(j>=w[i]) f[i][j]=max(f[p][j],f[p][j-w[i]]+v[i]);
			else f[i][j]=f[p][j];
	}
	scanf("%d",&Q);
	while(Q--)
		solve();
	return 0;
}
