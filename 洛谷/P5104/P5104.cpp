#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000007;
int w;
long long n,k;
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
long long getinv(long long a)
{
    return ksm(a,MOD-2);
}
int main()
{
    scanf("%d%lld%lld",&w,&n,&k);
    printf("%lld",w*getinv(ksm(2,k))%MOD);
    return 0;
}