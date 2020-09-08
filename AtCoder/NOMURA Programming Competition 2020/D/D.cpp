#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=5005;
const int MOD=1000000007;
int n,k;
int p[N];
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%MOD;
		a=a*a%MOD,b>>=1;
	}
	return res;
}
vector<int>G[N];
bool vis[N];
int cnt,tot;
bool flag;
int a[N],m;
void dfs(int u,int father)
{
	if(vis[u])
	{
		if(!flag) cnt++;
		flag=true;
		return;
	}
	vis[u]=true;
	tot++;
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
	}
	return;
}
long long fac[N];
void init(int n=5000)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	return;
}
long long dp[N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if(p[i]==-1) k++;
		else G[i].push_back(p[i]),G[p[i]].push_back(i);
	}
	for(int u=1;u<=n;u++)
		if(!vis[u])
		{
			flag=false;
			tot=0;
			dfs(u,0);
			if(!flag) a[++m]=tot;
		}
	long long ans=n*ksm(n-1,k)%MOD;
	ans=(ans-cnt*ksm(n-1,k)%MOD+MOD)%MOD;
	dp[0][0]=1;
	for(int i=1;i<=k;i++)
	{
		dp[i][0]=1;
		for(int j=1;j<=i;j++)
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*a[i]%MOD)%MOD;
	}
	init();
	if(k>=1) ans=(ans-(dp[k][1]-k)*ksm(n-1,k-1)%MOD+MOD)%MOD;
	for(int i=2;i<=k;i++)
		ans=(ans-dp[k][i]*fac[i-1]%MOD*ksm(n-1,k-i)%MOD+MOD)%MOD;
	printf("%lld",ans);
	return 0;
}

