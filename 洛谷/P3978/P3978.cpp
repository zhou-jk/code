#include<iostream>
#include<cstdio>
using namespace std;
long long n;
int main()
{
	scanf("%lld",&n);
	printf("%.9lf",(double)n*(n+1)/(2*(2*n-1)));
	return 0;
}
