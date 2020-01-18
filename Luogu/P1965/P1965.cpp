#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=100003;
long long m,n;
long long ksm(long long a,long long b,long long mod)
{
    long long res=1;
    a%=mod;
    while(b)
    {
        if(b&1) res=res*a%mod;
        b>>=1,a=a*a%mod;
    }
    return res;
}
int main()
{
    scanf("%lld%lld",&m,&n);
    printf("%lld",(ksm(m,n,mod)%mod-m*ksm(m-1,n-1,mod)%mod+mod)%mod);
    return 0;
}