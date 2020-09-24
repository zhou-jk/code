#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const int MOD=1000000007;
int n;
int A,B,c;
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
void init(int n=200000)
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
	scanf("%d",&n);
	scanf("%d%d%d",&A,&B,&c);
	int a=1LL*A*ksm(A+B,MOD-2)%MOD,b=1LL*B*ksm(A+B,MOD-2)%MOD;
	long long ans=0;
	for(int i=n;i<n*2;i++)
	{
		long long res=(ksm(a,n)*ksm(b,i-n)%MOD*C(i-1,n-1)%MOD+ksm(b,n)*ksm(a,i-n)%MOD*C(i-1,n-1)%MOD)%MOD*i%MOD;
		ans=(ans+res)%MOD;
	}
	ans=ans*100%MOD*ksm(A+B,MOD-2)%MOD;
	printf("%lld",ans);
	return 0;
}
