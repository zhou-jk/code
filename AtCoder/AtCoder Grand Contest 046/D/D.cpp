#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=305;
const int MOD=998244353;
int n;
char s[N];
long long dp[N][N][N];
bool f[N][N][N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	dp[n][0][0]=1;
	for(int i=n;i>=1;i--)
		for(int c0=0;c0<i;c0++)
			for(int c1=0;c0+c1<i;c1++)
			{
				dp[i-1][c0][c1]=(dp[i-1][c0][c1]+dp[i][c0][c1])%MOD;
				if(s[i]=='0') dp[i][c0][c1+1]=(dp[i][c0][c1+1]+dp[i][c0][c1])%MOD;
				else if(s[i]=='1') dp[i][c0+1][c1]=(dp[i][c0+1][c1]+dp[i][c0][c1])%MOD;
			}
	f[0][0][0]=true;
	for(int i=0;i<=n;i++)
		for(int c0=0;c0<=i;c0++)
			for(int c1=0;c0+c1<=i;c1++)
			{
				if(i+1<=n)
				{
					f[i+1][c0][c1]|=f[i][c0][c1];
					if(s[i+1]=='0'&&c1>0) f[i+1][c0+1][c1-1]|=f[i][c0][c1];
					if(s[i+1]=='1'&&c0>0) f[i+1][c0-1][c1+1]|=f[i][c0][c1];
				}
				if(i+2<=n)
				{
					if(s[i+1]=='0'||s[i+2]=='0') f[i+2][c0+1][c1]|=f[i][c0][c1];
					if(s[i+1]=='1'||s[i+2]=='1') f[i+2][c0][c1+1]|=f[i][c0][c1];
				}
			}
	f[n][0][0]=false;
	long long ans=0;
	for(int i=0;i<=n;i++)
		for(int c0=0;c0<=i;c0++)
			for(int c1=0;c0+c1<=i;c1++)
				if(f[i][c0][c1]) ans=(ans+dp[i][c0][c1])%MOD;
	printf("%lld",ans);
	return 0;
}
