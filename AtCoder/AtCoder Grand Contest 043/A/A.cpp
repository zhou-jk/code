#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
int h,w;
char s[N][N];
int dp[N][N];
int main()
{
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++)
		scanf("%s",s[i]+1);
	memset(dp,63,sizeof(dp));
	dp[1][1]=s[1][1]=='#';
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
		{
			if(i>1) dp[i][j]=min(dp[i][j],dp[i-1][j]+(s[i-1][j]!=s[i][j]));
			if(j>1) dp[i][j]=min(dp[i][j],dp[i][j-1]+(s[i][j-1]!=s[i][j]));
		}
	printf("%d",(dp[h][w]+1)/2);
	return 0;
}
