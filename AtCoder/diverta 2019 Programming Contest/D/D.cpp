#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n;
bool check(long long x)
{
	long long m=x-1;
	return (m+1)*(n/m)==n;
}
int main()
{
	scanf("%lld",&n);
	long long ans=0;
	for(long long i=2;i<=sqrt(n);i++)
		if(n%i==0)
		{
			if(check(i)) ans+=i-1;
			if(i*i!=n&&check(n/i)) ans+=n/i-1;
		}
	if(n!=1&&check(n)) ans+=n-1;
	printf("%lld",ans);
	return 0;
}
