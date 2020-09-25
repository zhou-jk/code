#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=200005;
long long s;
int main()
{
	scanf("%lld",&s);
	long long x1,y1,x2,y2,x3,y3;
	x1=0,y1=0;
	x2=y3=ceil(sqrt(s));
	long long t=x2*y3-s;
	if(t==0) y2=x3=0;
	for(long long i=1;i<=sqrt(t);i++)
		if(t%i==0)
		{
			if(i<=1e9&&t/i<=1e9) y2=i,x3=t/i;
		}
	printf("%lld %lld %lld %lld %lld %lld",x1,y1,x2,y2,x3,y3);
	return 0;
}
