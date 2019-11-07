#include<iostream>
#include<cstdio>
using namespace std;
long long n,k;
long long r,ans;
int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i=r+1)
    {
        if(k<i) break;
        r=min(k/(k/i),n);
        ans+=(k/i)*(i+r)*(r-i+1)/2;
    }
    printf("%lld",n*k-ans);
    return 0;
}