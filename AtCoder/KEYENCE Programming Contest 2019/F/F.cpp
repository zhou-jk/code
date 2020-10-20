#include<iostream>
#include<cstdio>
using namespace std;
const int N=20000005;
const int MOD=1000000007;
int h,w,K;
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
void init(int n=20000000)
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
int main()
{
	init();
	scanf("%d%d%d",&h,&w,&K);
	long long ans=0;
	for(int k=1;k<=K;k++)
	{
		long long res=((k+1)*C(h+w,k)%MOD+1LL*h*w%MOD*C(h+w-2,k-2)%MOD)%MOD;
		res=res*fac[k]%MOD*fac[K-k]%MOD*C(h+w-k,K-k)%MOD;
		ans=(ans+res)%MOD;
	}
	printf("%lld",ans);
	return 0;
}
