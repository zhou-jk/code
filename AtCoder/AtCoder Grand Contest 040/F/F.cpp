#include<iostream>
#include<cstdio>
using namespace std;
const int N=20000005;
const int MOD=998244353;
int n,A,B;
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
long long Catalan(int n,int m)
{
	return (C(n+m,n)-C(n+m,n+1)+MOD)%MOD;
}
int main()
{
	init();
	scanf("%d%d%d",&n,&A,&B);
	if(B==0)
	{
		printf("1");
		return 0;
	}
	long long ans=0;
	for(int k=0;B+k<n&&k<=A;k++)
		ans=(ans+Catalan(B-1,k)*C(n-B-k-1+A-k,A-k)%MOD)%MOD;
	if(A+B==n) ans=(ans+Catalan(B-1,A))%MOD;
	printf("%lld",ans);
	return 0;
}
