#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005,K=25;
const int MOD=1000000007;
int n,k;
int a[K];
long long C[N][N];
void init(int n=1000)
{
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=n;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	return;
}
long long dp[K][N];
int main()
{
	init();
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	dp[0][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			for(int l=0;l<=min(j,a[i]);l++)
				dp[i][j]=(dp[i][j]+dp[i-1][j-l]*C[n-(j-l)][l]%MOD*C[n-l][a[i]-l]%MOD)%MOD;
	printf("%lld",dp[k][n]);
	return 0;
}
