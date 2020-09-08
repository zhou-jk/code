#include<iostream>
#include<cstdio>
using namespace std;
const int N=5005;
const int MOD=1000000007;
int n,m;
long long dp[N][N];
long long sum[N][N];
long long Pw[N],inP[N];
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%MOD;
		a=a*a%MOD,b>>=1;
	}
	return res;
}
void init(int n=5000)
{
	Pw[0]=1;
	for(int i=1;i<=n;i++)
		Pw[i]=Pw[i-1]*2%MOD;
	inP[n]=ksm(Pw[n],MOD-2);
	for(int i=n;i>=1;i--)
		inP[i-1]=inP[i]*2%MOD;
	return;
}
int main()
{
	init();
	scanf("%d%d",&n,&m);
	for(int j=1;j<=m;j++)
		dp[0][j]=1,sum[0][j]=(sum[0][j-1]+dp[0][j]*j%MOD*inP[j]%MOD)%MOD;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=dp[i-1][j]*(j+1)%MOD;
			dp[i][j]=(dp[i][j]+sum[i-1][j-1]*Pw[j-1]%MOD)%MOD;
			sum[i][j]=(sum[i][j-1]+dp[i][j]*j%MOD*inP[j]%MOD)%MOD;
		}
	printf("%lld",dp[n][m]);
	return 0;
}

