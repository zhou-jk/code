#include<iostream>
#include<cstdio>
using namespace std;
const int N=5005;
int n,m;
char s[N],t[N];
int dp[N][N];
int main() 
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	scanf("%s",t+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=max(dp[i][j],max(dp[i-1][j]-1,dp[i][j-1]-1)); 
			if(s[i]==t[j]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
			ans=max(ans,dp[i][j]);
		}
	printf("%d",ans);
	return 0;
}
