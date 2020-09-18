#include<iostream>
#include<cstdio>
using namespace std;
const int N=505;
const int MOD=1000000007;
int n,m;
int c[N];
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
long long fac[N],inv[N];
void init(int n=500)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%MOD;
	return;
}
long long C(int n,int m)
{
	if(m>n) return 0;
	else return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
long long f[N][N][N];
int main()
{
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		c[x]++;
	}
	f[m+1][0][0]=1;
	for(int i=m;i>=1;i--)
		for(int j=0;j<=m;j++)
			for(int k=i*j;k<=m;k++)
			{
				long long mul=ksm(k-(i-1)*j,c[i])%MOD;
				for(int l=0;l<=min(j,k/i);l++)
					f[i][j][k]=(f[i][j][k]+f[i+1][j-l][k-i*l]*inv[l]%MOD*mul%MOD)%MOD;
			}
	long long ans=0;
	for(int j=0;j<=m;j++)
		for(int k=j;k<=m;k++)
		{
			long long res=C(m-k+1,j)*fac[j]%MOD*f[1][j][k]%MOD;
			if((m-k)&1) ans=(ans-res+MOD)%MOD;
			else ans=(ans+res)%MOD;
		}
	printf("%lld",ans);
	return 0;
}
