#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000003;
int Q;
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
long long fac[MOD],inv[MOD];
void init(int n=1000002)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%MOD;
	return;
}
void solve()
{
	int x,d,n;
	scanf("%d%d%d",&x,&d,&n);
	if(d==0)
	{
		printf("%lld\n",ksm(x,n));
		return;
	}
	x=x*ksm(d,MOD-2)%MOD;
	if(x==0||x+n-1>=MOD)
	{
		printf("0\n");
		return;
	}
	long long ans=fac[x+n-1]*inv[x-1]%MOD;
	printf("%lld\n",ans*ksm(d,n)%MOD);
	return;
}
int main()
{
	init();
	scanf("%d",&Q);
	while(Q--)
		solve();
	return 0;
}
