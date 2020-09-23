#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
int n;
char s[N];
int dp[N][3];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=dp[i-1][2]+1;
		if(s[i]!=s[i-1]) dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
		if(i-2>=0) dp[i][2]=dp[i-2][1]+1;
		if(i-2>=0&&(s[i]!=s[i-1]||s[i-1]!=s[i-2])) dp[i][2]=max(dp[i][2],dp[i-2][2]+1);
	}
	printf("%d",max(dp[n][1],dp[n][2]));
	return 0;
}
