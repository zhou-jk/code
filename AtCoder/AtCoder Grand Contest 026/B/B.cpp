#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int T;
long long a,b,c,d;
void solve()
{
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if(a<b||d<b)
    {
        printf("No\n");
        return;
    }
    long long t=__gcd(b,d);
    long long x=(a-b+t)/t*t;
    if(a-b<x&&x<a-c) printf("No\n");
    else printf("Yes\n");
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}