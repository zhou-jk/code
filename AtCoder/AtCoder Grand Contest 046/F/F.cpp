#include<iostream>
#include<cstdio>
using namespace std;
const int N=205;
int n,k,p;
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p,b>>=1;
	}
	return res;
}
long long fac[N],inv[N];
void init(int n=200)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%p;
	inv[n]=ksm(fac[n],p-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%p;
	return;
}
long long P(int n,int m)
{
	if(m>n) return 0;
	return fac[n]*inv[n-m]%p;
}
long long f[N][N];
long long sum[N][N];
int calc(int n,int m,int k)
{
	f[0][m]=1;
	for(int i=1;i<=m-1;i++)
		f[0][i]=0;
	f[0][0]=-1;
	for(int j=0;j<=m;j++)
	{
		sum[0][j]=j>0?sum[0][j-1]:0;
		sum[0][j]=(sum[0][j]+f[0][j]+p)%p;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			f[i][j]=0;
			if(i-1+j<=k&&n-i+m-j<=k)
			{
				f[i][j]=(f[i][j]+(sum[i-1][m]-(j>0?sum[i-1][j-1]:0)+p)%p)%p;
			}
			sum[i][j]=j>0?sum[i][j-1]:0;
			sum[i][j]=(sum[i][j]+f[i][j])%p;
		}
	return f[n][0];
}
long long solve(int n,int k)
{
	if(n==1) return 1;
	long long res=0;
	for(int deg=2;deg<n;deg++)
		res=(res+calc(deg,n-deg,k))%p;
	return res*fac[n-1]%p;
}
int main()
{
	scanf("%d%d%d",&n,&k,&p);
	init();
	long long ans=0;
	for(int i=0;i<=k;i++)
		ans=(ans+P(n,i)*solve(n-i,k-i)%p)%p;
	printf("%lld",ans);
	return 0;
}
