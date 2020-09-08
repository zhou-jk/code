#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=305;
const int MOD=998244353;
int n,m;
char s[N];
int a[N];
int sum[N];
long long dp[N][N][N];
int main()
{
	scanf("%s%d",s+1,&m);
	n=strlen(s+1);
	s[++n]='0';
	m=min(m,n);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='0') cnt++;
		else a[cnt+1]++;
	for(int i=1;i<=cnt;i++)
		sum[i]=sum[i-1]+a[i];
	dp[0][0][0]=1;
	for(int i=1;i<=cnt;i++)
		for(int j=sum[i];j<=n-cnt;j++)
			for(int k=0;k<=m;k++)
				for(int p=0;p<=min(j,n-sum[i-1]-cnt);p++)
					if(k>=max(p-a[i],0)) dp[i][j][k]=(dp[i][j][k]+dp[i-1][j-p][k-max(p-a[i],0)])%MOD;
	long long ans=0;
	for(int k=0;k<=m;k++)
		ans=(ans+dp[cnt][n-cnt][k])%MOD;
	printf("%lld",ans);
	return 0;
}
