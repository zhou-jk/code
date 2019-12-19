#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long a,b;
int main()
{
    scanf("%lld%lld",&a,&b);
    if(a>b) swap(a,b);
    if(a==(long long)((b-a)*(sqrt(5)+1)/2)) printf("0");
    else printf("1");
    return 0;
}