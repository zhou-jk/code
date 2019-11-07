#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=998244353;
int T;
long long n,m;
long long ksm(long long a,long long b,long long p)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%p;
        a=a*a%p,b>>=1;
    }
    return res;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",ksm(2,(n-1)*(m-1),MOD));
    }
    return 0;
}