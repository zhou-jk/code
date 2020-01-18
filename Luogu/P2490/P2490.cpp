#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000007;
const int N=10005;
int n,K,d;
long long C[N][205],dp[18][100005];
int main()
{
	scanf("%d%d%d",&n,&K,&d);
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=200;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	dp[0][0]=1;
	for(int i=0;i<=16;i++)
		for(int j=0;j<=n-K;j++)
			for(int k=0;(1<<i)*k*(d+1)<=n-K&&k*(d+1)<=K/2;k++)
				dp[i+1][j+(1<<i)*k*(d+1)]=(dp[i+1][j+(1<<i)*k*(d+1)]+dp[i][j]*C[K/2][k*(d+1)]%MOD)%MOD;
	long long ans=0;
	for(int i=0;i<=n-K;i++)
		ans=(ans+dp[17][i]*C[n-i-K/2][K/2]%MOD)%MOD;
	printf("%lld",(C[n][K]-ans+MOD)%MOD);
  	return 0;
}
