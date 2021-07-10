#include<iostream>
#include<cstdio>
using namespace std;
const int N=2005;
const int MOD=998244353;
int n,m;
int f[N][N],g[N][N];
int sumf[N][N],sumg[N][N];
int pw2[N];
int main()
{
	scanf("%d%d",&m,&n);
	sumf[0][0]=f[0][0]=1;
	for(int j=1;j<=n;j++)
		sumf[0][j]=(sumf[0][j-1]+f[0][j])%MOD;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			f[i][j]=f[i-1][j];
		for(int j=1;j<=n;j++)
			f[i][j]=(f[i][j]+sumf[i-1][j-1])%MOD;
		sumf[i][0]=f[i][0];
		for(int j=1;j<=n;j++)
			sumf[i][j]=(sumf[i][j-1]+f[i][j])%MOD;
	}
	sumg[0][0]=g[0][0]=1;
	for(int j=1;j<=n;j++)
		sumg[0][j]=(sumg[0][j-1]+g[0][j])%MOD;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			g[i][j]=g[i-1][j];
		for(int j=1;j<=n;j++)
			g[i][j]=(g[i][j]+2LL*sumg[i-1][j-1])%MOD;
		sumg[i][0]=g[i][0];
		for(int j=1;j<=n;j++)
			sumg[i][j]=(sumg[i][j-1]+g[i][j])%MOD;
	}
	for(int i=2;i<=2*m;i++)
		if(i%2==0)
		{
			int cnt1=i>m?i-m-1:m-i+1,cnt2=i>m?m-i/2:(i-1)/2;
			int ans=0;
			ans=(ans+f[cnt1][n])%MOD;
			for(int j=1;j<=n;j++)
				ans=(ans+1LL*g[cnt2][j]%MOD*f[cnt1][n-j])%MOD;
			ans=(ans+1LL*f[cnt1][n-1])%MOD;
			for(int j=1;j<=n-1;j++)
				ans=(ans+1LL*g[cnt2][j]%MOD*f[cnt1][n-1-j])%MOD;
			printf("%d\n",ans);
		}
		else
		{
			int cnt1=i>m?i-m-1:m-i+1,cnt2=i>m?m-i/2:i/2;
			int ans=0;
			ans=(ans+f[cnt1][n])%MOD;
			for(int j=1;j<=n;j++)
				ans=(ans+1LL*g[cnt2][j]%MOD*f[cnt1][n-j])%MOD;
			printf("%d\n",ans);
		}
	return 0;
}