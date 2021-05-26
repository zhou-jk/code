#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c;
long long k;
int main()
{
    scanf("%d%d%d%lld",&a,&b,&c,&k);
    if(k%2==0) printf("%d",a-b);
    else printf("%d",b-a);
    return 0;
}