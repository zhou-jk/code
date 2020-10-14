#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n;
int a[N];
int dp[N][6];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dp,63,sizeof(dp));
	dp[0][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			for(int k=1;k<=j;k++)
				if(j==1||j==5) dp[i][j]=min(dp[i][j],dp[i-1][k]+a[i]);
				else if(j==2||j==4) dp[i][j]=min(dp[i][j],dp[i-1][k]+(a[i]==0?2:(a[i]%2==1)));
				else if(j==3) dp[i][j]=min(dp[i][j],dp[i-1][k]+(a[i]%2==0));
	printf("%d",min({dp[n][1],dp[n][2],dp[n][3],dp[n][4],dp[n][5]}));
	return 0;
}
