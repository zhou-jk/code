#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
const int MOD=1000000007;
int n,h,d;
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
long long fac,sum;
long long s[N],f[N];
int main()
{
	scanf("%d%d%d",&n,&h,&d);
	fac=1;
	for(int i=1;i<=n;i++)
		fac=fac*i%MOD,sum=(sum+fac)%MOD;
	s[0]=f[0]=1;
	for(int i=1;i<=h+1;i++)
	{
		long long p=(s[i-1]-(i-d-1>=0?s[i-d-1]:0)+MOD)%MOD;
		f[i]=p*sum%MOD;
		s[i]=(s[i-1]+f[i])%MOD;
	}
	printf("%lld",f[h]*fac%MOD*ksm(sum,MOD-2)%MOD);
	return 0;
}
