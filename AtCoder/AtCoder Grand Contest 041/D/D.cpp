#include<iostream>
#include<cstdio>
using namespace std;
const int N=5005;
int n,k,P;
int w[N];
long long dp[N][N];
int main()
{
	scanf("%d%d",&n,&P);
	k=(n-1)/2;
	for(int i=1,j=1;i<=k+1;i++,j--)
		w[i]=j;
	for(int i=n,j=-1,cnt=1;cnt<=k;cnt++,i--,j--)
	{
		w[i]=j;
		if(n%2==0&&cnt==k) w[i-1]=j;
	}
	dp[1][0]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j-(1-w[i])>=0) dp[i][j]=(dp[i][j]+dp[i][j-(1-w[i])])%P;
		}
	long long ans=0;
	for(int j=0;j<=n;j++)
		ans=(ans+dp[n][j]*(n-j)%P)%P;
	printf("%lld",ans);
	return 0;
}
