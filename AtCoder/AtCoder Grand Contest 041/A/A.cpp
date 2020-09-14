#include<iostream>
#include<cstdio>
using namespace std;
long long n,a,b;
int main()
{
	scanf("%lld%lld%lld",&n,&a,&b);
	if(a>b) swap(a,b);
	if((b-a)%2==0) return printf("%lld",(b-a)/2),0;
	long long ans=min(a,n-b+1);
	printf("%lld",ans+(b-a-1)/2);
	return 0;
}
