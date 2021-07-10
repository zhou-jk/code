#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
const int MOD=1000000007;
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=1LL*res*a%MOD;
        a=1LL*a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return ksm(x,MOD-2);
}
int n;
int fac[N],ifac[N];
void init(int n=1000000)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=1LL*fac[i-1]*i%MOD;
    ifac[n]=getinv(fac[n]);
    for(int i=n;i>=1;i--)
        ifac[i-1]=1LL*ifac[i]*i%MOD;
    return;
}
int C(int n,int m)
{
    if(m>n) return 0;
    else return 1LL*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int main()
{
    init();
    scanf("%d",&n);
    int ans=0;
    for(int i=2;i<=n;i+=2)
        ans=(ans+2LL*fac[i]*(C(i,n-i)+C(i-1,n-i-1)))%MOD;
    printf("%d",ans);
    return 0;
}