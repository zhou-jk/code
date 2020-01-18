#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005,M=200;
const int MOD=998244353;
int n;
int a[N];
long long dp[N][M+5][3];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=M;i++)
	{
		if(a[1]==-1||i==a[1]) dp[1][i][0]=1;
		else dp[1][i][0]=0;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=M;j++)
			if(a[i]==-1||j==a[i]) dp[i][j][1]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%MOD;
			else dp[i][j][1]=0;
		long long sum=0;
		for(int j=1;j<=M;j++)
		{
			if(a[i]==-1||j==a[i]) dp[i][j][0]=sum;
			else dp[i][j][0]=0;
			sum=(sum+dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%MOD;
		}
		sum=0;
		for(int j=M;j>=1;j--)
		{
			if(a[i]==-1||j==a[i]) dp[i][j][2]=sum;
			else dp[i][j][2]=0;
			sum=(sum+dp[i-1][j][1]+dp[i-1][j][2])%MOD;
		}
	}
	long long ans=0;
	for(int i=1;i<=M;i++)
		ans=(ans+dp[n][i][1]+dp[n][i][2])%MOD;
	printf("%lld",ans);	 
	return 0;
}
