#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,p;
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res*=a;
		a*=a,b>>=1;
	}
	return res;
}
int main()
{
	scanf("%lld%lld",&n,&p);
	long long ans=1;
	for(int i=2;i<=sqrt(p);i++)
		if(p%i==0)
		{
			int cnt=0;
			while(p%i==0) cnt++,p/=i;
			ans*=ksm(i,cnt/n);
		}
	if(p!=1) ans*=ksm(p,1/n);
	printf("%lld",ans);
	return 0;
}
