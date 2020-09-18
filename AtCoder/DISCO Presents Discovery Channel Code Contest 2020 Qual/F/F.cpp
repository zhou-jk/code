#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000007;
int n,m,t;
int g,h;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
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
	scanf("%d%d%d",&n,&m,&t);
	g=n/gcd(n,t),h=m/gcd(m,t);
	long long res=1;
	res=(res+ksm(2,g)-1)%MOD;
	res=(res+ksm(2,h)-1)%MOD;
	res=(res+ksm(2,gcd(g,h))-2)%MOD;
	res=ksm(res,1LL*(n/g)*(m/h))%MOD;
	printf("%lld",res);
	return 0;
}
