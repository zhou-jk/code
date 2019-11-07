#include<iostream>
#include<cstdio>
using namespace std;
int n,m,dp[51][51][51][51],e[51][51],a,b,c;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&e[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=n;k++)
				for(int l=j+1;l<=m;l++)
					dp[i][j][k][l]=max(max(dp[i][j-1][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k][l-1],dp[i-1][j][k-1][l]))+e[i][j]+e[k][l];
	printf("%d",dp[n][m-1][n-1][m]);
	return 0;
}