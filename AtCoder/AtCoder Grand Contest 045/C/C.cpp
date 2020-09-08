#include<iostream>
#include<cstdio>
using namespace std;
const int N=5005;
const int MOD=1000000007;
int n,a,b;
long long f[N][2];
long long g[N];
long long dp[N][2];
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
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	if(a>b) swap(a,b);
	if(b==1)
	{
		printf("%lld",ksm(2,n));
		return 0;
	}
	f[0][0]=f[0][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
			f[i][1]=(f[i][1]+f[j][0])%MOD;
		for(int j=0;j+a<=i;j++)
			f[i][0]=(f[i][0]+f[j][1])%MOD;
	}
	g[0]=1;
	for(int i=1;i<=n;i++)
		g[i]=(f[i][0]+f[i][1])%MOD;
	long long ans=0;
	for(int i=1;i<n;i++)
	{
		if(i<a) dp[i][0]=(dp[i][0]+1)%MOD;
		for(int j=max(i-a+1,1);j<i;j++)
			dp[i][0]=(dp[i][0]+dp[j][1])%MOD;
		if(i<b) dp[i][1]=(dp[i][1]+g[i-1])%MOD;
		for(int j=max(i-b+1,1);j<i;j++)
			dp[i][1]=(dp[i][1]+dp[j][0]*(i-j==1?1:g[i-j-2])%MOD)%MOD;
		if(i+b-1>=n) ans=(ans+dp[i][0]*g[n-i-1]%MOD)%MOD;
		if(i+a-1>=n) ans=(ans+dp[i][1])%MOD;
	}
	printf("%lld",(ksm(2,n)-ans+MOD)%MOD);
	return 0;
}
