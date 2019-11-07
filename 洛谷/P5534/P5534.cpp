#include<iostream>
#include<cstdio>
using namespace std;
long long a1,a2,n;
int main()
{
    scanf("%lld%lld%lld", &a1, &a2, &n);
    printf("%lld",n*a1+n*(n-1)/2*(a2 - a1));
    return 0;
}