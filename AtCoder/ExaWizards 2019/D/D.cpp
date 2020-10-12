#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=205,M=100005;
const int MOD=1000000007;
int n,X;
int a[N];
long long dp[N][M];
int main()
{
	scanf("%d%d",&n,&X);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	dp[0][X]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=X;j++)
		{
			dp[i][j%a[i]]=(dp[i][j%a[i]]+dp[i-1][j])%MOD;
			dp[i][j]=(dp[i][j]+dp[i-1][j]*(n-i)%MOD)%MOD;
		}
	long long ans=0;
	for(int j=0;j<=X;j++)
		ans=(ans+j*dp[n][j]%MOD)%MOD;
	printf("%lld",ans);
	return 0;
}
