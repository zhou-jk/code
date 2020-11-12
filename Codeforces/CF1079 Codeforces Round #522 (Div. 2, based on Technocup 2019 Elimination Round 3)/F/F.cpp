#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=300005;
const int MOD=998244353;
int n;
vector<int>G[N];
long long f[N][3];
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
void dfs(int u,int father)
{
	f[u][0]=f[u][1]=1;
	f[u][2]=0;
	long long sum=1;
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
		f[u][0]=f[u][0]*(f[v][0]+f[v][2])%MOD;
		f[u][1]=f[u][1]*(f[v][0]+f[v][2]*2)%MOD;
		sum=sum*(2*f[v][2]+f[v][0])%MOD;  
	}
	for(int v:G[u])
	{
		if(v==father) continue;
		f[u][2]=(f[u][2]+sum*ksm(2*f[v][2]%MOD+f[v][0],MOD-2)%MOD*f[v][1])%MOD;
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
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}
	dfs(1,0);
	printf("%lld",(f[1][0]+f[1][2])%MOD);
	return 0;
}
