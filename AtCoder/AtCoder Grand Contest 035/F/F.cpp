#include<iostream>
#include<cstdio>
using namespace std;
const int N=500005;
const int MOD=998244353;
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
void init(int n=500000)
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
long long f(int k)
{
	return C(n,k)*C(m,k)%MOD*fac[k]%MOD*ksm(m+1,n-k)%MOD*ksm(n+1,m-k)%MOD;
}
int main()
{
	init();
	scanf("%d%d",&n,&m);
	long long ans=0;
	for(int i=0;i<=min(n,m);i++)
		if(i&1) ans=(ans-f(i)+MOD)%MOD;
		else ans=(ans+f(i))%MOD;
	printf("%lld",ans);
	return 0;
}
