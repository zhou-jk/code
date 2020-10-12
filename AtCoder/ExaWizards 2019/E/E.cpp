#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const int MOD=1000000007;
int n,m;
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
long long inv2[N];
void init(int n=200000)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%MOD;
	inv2[n]=ksm(ksm(2,n),MOD-2);
	for(int i=n;i>=1;i--)
		inv2[i-1]=inv2[i]*2%MOD;
	return;
}
long long C(int n,int m)
{
	if(m>n) return 0;
	else return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
long long f[N],g[N];
int main()
{
	init();
	scanf("%d%d",&n,&m);
	f[0]=0;
	g[0]=1;
	for(int i=1;i<=n+m;i++)
	{
		f[i]=(f[i-1]+C(i-1,m-1)*inv2[i]%MOD)%MOD;
		g[i]=(2*g[i-1]%MOD-(C(i-1,n-1)+C(i-1,m-1))%MOD+MOD)%MOD;
		printf("%lld\n",(f[i-1]+g[i-1]*inv2[i]%MOD)%MOD);
	}
	return 0;
}
