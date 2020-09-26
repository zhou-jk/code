#include<iostream>
#include<cstdio>
using namespace std;
const int N=3005;
const int MOD=998244353;
int n,X;
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
void init(int n=3000)
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
	return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
long long f(int n)
{
	long long res=0;
	if(2*n<X||(2*n-X)%2==1) res++;
	for(int S=0;S<2*n;S++)
	{
		if(S<X)
		{
			if(S>=n) res=(res+C(n,S-n))%MOD;
		}
		else
		{
			if((S-X)%2==0) continue;
			int num=(S-X+1)/2;
			int reb=n-2*num,ret=S-2*num*2;
			if(reb<=0||ret<=0) continue;
			if(ret>=reb&&ret<=2*reb) res=(res+C(reb,ret-reb))%MOD;
		}
	}
	return res;
}
int main()
{
	init();
	scanf("%d%d",&n,&X);
	long long ans=0;
	for(int i=0;i<=n;i++)
		ans=(ans+C(n,i)*f(n-i)%MOD)%MOD;
	printf("%lld",ans);
	return 0;
}
