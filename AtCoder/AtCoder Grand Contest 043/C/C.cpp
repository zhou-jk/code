#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
const int MOD=998244353;
int n,m;
long long ksm(long long a,long long b)
{
	a%=MOD,b%=(MOD-1);
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%MOD;
		a=a*a%MOD,b>>=1;
	}
	return res;
}
vector<int>G[N];
int sg[N];
int dfs(int u)
{
	if(sg[u]!=-1) return sg[u];
	static int vis[N];
	for(int v:G[u])
	{
		dfs(v);
		vis[sg[v]]=true;
	}
	for(int i=0;;i++)
		if(!vis[i])
		{
			sg[u]=i;
			break;
		}
	for(int v:G[u])
		vis[sg[v]]=false;
	return sg[u];
}
vector<long long> getsg()
{
	for(int i=1;i<=n;i++)
		G[i].clear();
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		G[x].push_back(y);
	}
	memset(sg,-1,sizeof(sg));
	for(int i=n;i>=1;i--)
		dfs(i);
	int Max=*max_element(sg+1,sg+n+1);
	vector<long long>res;
	res.resize(Max+1);
	for(int i=1;i<=n;i++)
		res[sg[i]]=(res[sg[i]]+ksm(1e18,i))%MOD;
	return res;
}
int main()
{
	scanf("%d",&n);
	vector<long long>x=getsg(),y=getsg(),z=getsg();
	long long ans=0;
	for(int i=0;i<x.size();i++)
		for(int j=0;j<y.size();j++)
		{
			int k=i^j;
			if(k>=z.size()) continue;
			ans=(ans+x[i]*y[j]%MOD*z[k]%MOD)%MOD;
		}
	printf("%lld",ans);
	return 0;
}
