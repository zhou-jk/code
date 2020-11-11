#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=300005;
const long long INF=4557430888798830399;
int n,m,k;
int a[N];
long long dp[N][10];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dp,-63,sizeof(dp));
	dp[0][0]=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<m&&j<=i;j++)
		{
			if(m==1&&j==0) dp[i][j]=max(dp[i-1][m-1]-k+a[i],0LL);
			else if(j==0) dp[i][j]=max(dp[i-1][m-1]+a[i],0LL);
			else if(j==1) dp[i][j]=dp[i-1][0]-k+a[i];
			else dp[i][j]=dp[i-1][j-1]+a[i];
			ans=max(ans,dp[i][j]);
		}
	printf("%lld",ans);
	return 0;
}
