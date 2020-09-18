#include<iostream>
#include<cstdio>
using namespace std;
const int N=10000005;
const int MOD=998244353;
int n;
long long pw2[N],pw3[N];
long long fac[N],inv[N];
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
void init(int n=10000000)
{
	pw2[0]=1;
	for(int i=1;i<=n;i++)
		pw2[i]=pw2[i-1]*2%MOD;
	pw3[0]=1;
	for(int i=1;i<=n;i++)
		pw3[i]=pw3[i-1]*3%MOD;
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
int main()
{
	init();
	scanf("%d",&n);
	long long ans=pw3[n];
	long long res=0;
	for(int i=n/2+1;i<=n;i++)
		res=(res+C(n,i)*pw2[n-i]%MOD)%MOD;
	for(int i=n/2+1;i<=n;i++)
		res=(res+C(n,i)*pw2[n-i]%MOD)%MOD;
	ans=(ans-res+MOD)%MOD;
	printf("%lld",ans);
	return 0;
}
