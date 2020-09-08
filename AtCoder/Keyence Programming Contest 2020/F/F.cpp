#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int w,h,k;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
long long solve(int w,int h)
{
	long long res=0;
	for(int d=0;d<h;d++)
		for(int a=1;a<w;a++)
		{
			int R=2*k-a*d+gcd(d,w)-2;
			if(R<0) break;
			int b=min(h-1-d,R/w);
			int tmp=b;
			b++;
			if(b+d<h&&w*b-gcd(w-a,b+d)-gcd(a,b)<=R) tmp++;
			if(d==0) res+=tmp;
			else res+=tmp*2;
		}
	return res*2;
}
int main()
{
	scanf("%d%d%d",&w,&h,&k);
	printf("%lld",solve(w,h)+solve(h,w));
	return 0;
}
