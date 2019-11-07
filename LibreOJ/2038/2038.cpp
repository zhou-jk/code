#include<iostream>
#include<cstdio>
using namespace std;
const int mod=2333;
int T;
long long n,k;
long long c[2334][2334],sum[2334][2334];
void init()
{
    for(int i=0;i<=mod;i++)
    {
        c[i][0]=sum[i][0]=1;
        for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        for(int j=1;j<=mod;j++) sum[i][j]=(sum[i][j-1]+c[i][j])%mod;
    }
    return;
}
long long C(long long n , long long m)
{
    if(n<m) return 0;
    if(n<mod&&m<mod) return c[n][m];
    return C(n/mod,m/mod)*C(n%mod,m%mod)%mod;
}
long long calc(long long n,long long k)
{
    if(k<mod) return sum[n%mod][k%mod];
    return (sum[n%mod][mod-1]*calc(n/mod,k/mod-1)+C(n/mod,k/mod)*calc(n%mod,k%mod))%mod;
}
int main()
{
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&k);
        printf("%lld\n",calc(n,k));
    }
    return 0;
}