#include<iostream>
#include<cstdio>
using namespace std;
long long n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	printf("%lld",(k+n-1)/n);
	return 0;
}
