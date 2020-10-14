#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=4005;
const int MOD=998244353;
int n;
char s[N];
int sumr[N],sumb[N];
long long dp[N][N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		sumr[i]=sumr[i-1],sumb[i]=sumb[i-1];
		if(s[i]=='0') sumr[i]+=2;
		else if(s[i]=='1') sumr[i]++,sumb[i]++;
		else sumb[i]+=2;
	}
	for(int i=n+1;i<=n*2;i++)
		sumr[i]=sumr[i-1],sumb[i]=sumb[i-1];
	dp[0][0]=1;
	for(int i=1;i<=n*2;i++)
		for(int j=max(i-sumr[i],0);j<=min(sumb[i],i);j++)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
			if(j-1>=0) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;
		}
	printf("%lld",dp[n*2][sumb[n]]);
	return 0;
}
