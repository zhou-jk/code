#include<iostream>
#include<cstdio>
using namespace std;
const int N=600005;
const int MOD=1000000007;
int n,m,L,R;
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
void init(int n=600000)
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
long long calc(long long x,int p,int q)
{
	x-=1LL*m*p;
	if(x<0) return 0;
	long long res=0;
	for(int i=0;i<=n-m&&x-1LL*i*q>=0;i++)
		if(i&1) res=(res-C(n-m,i)*C(x-1LL*i*q+n,n)%MOD+MOD)%MOD;
		else res=(res+C(n-m,i)*C(x-1LL*i*q+n,n)%MOD)%MOD;
	res*=C(n,m);
	return res;
}
long long solve(int x)
{
	long long res=0;
	for(int p=0;p<=x;p++)
		res=(res+(calc(x,p,p)-calc(x,p+1,p)+MOD)%MOD)%MOD;
	res=(C(x+n,n)-res+MOD)%MOD;
	return res;
}
int main()
{
	init();
	scanf("%d%d%d%d",&n,&m,&L,&R);
	printf("%lld",(solve(R)-solve(L-1)+MOD)%MOD);
	return 0;
}

