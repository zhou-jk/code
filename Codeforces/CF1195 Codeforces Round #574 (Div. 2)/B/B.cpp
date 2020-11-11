#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	printf("%lld",n-(-3+((long long)sqrt(4*(2*n+2*k)+9)))/2);
	return 0;
}
