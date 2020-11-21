#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000007;
long long n,k;
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
int main()
{
	scanf("%lld%lld",&n,&k);
	if(n==0)
	{
		printf("0");
		return 0;
	}
	printf("%lld",(n%MOD*ksm(2,k+1)%MOD-ksm(2,k)+1+MOD)%MOD);
	return 0;
}
