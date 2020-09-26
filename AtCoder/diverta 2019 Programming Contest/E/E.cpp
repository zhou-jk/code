#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=500005,M=(1<<20)+5;
const int MOD=1000000007;
int n;
int a[N],s[N];
vector<int>pos[M];
long long dp[N];
long long f[M],g[M];
int sum[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sum[0]=1;
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]^a[i];
		pos[s[i]].push_back(i);
		sum[i]=sum[i-1];
		if(s[i]==0) sum[i]++;
	}
	for(int i=1;i<=n;i++)
		if(s[i])
		{
			dp[i]=1;
			dp[i]=(dp[i]+f[s[i]]*sum[i]%MOD-g[s[i]]+MOD)%MOD;
			f[s[i]]=(f[s[i]]+dp[i])%MOD,g[s[i]]=(g[s[i]]+dp[i]*sum[i]%MOD)%MOD;
		}
		else
		{
			dp[i]=1;
			dp[i]=(dp[i]+f[s[i]])%MOD;
			f[s[i]]=(f[s[i]]+dp[i])%MOD,g[s[i]]=(g[s[i]]+dp[i]*sum[i]%MOD)%MOD;
		}
	long long ans=dp[n];
	if(!s[n]) 
	{
		for(int i=1;i<=n;i++)
			if(s[i]) ans=(ans+dp[i])%MOD;
	}
	printf("%lld",ans);
	return 0;
}
