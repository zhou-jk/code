#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const int MOD=998244353;
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
int fac[N],ifac[N];
void init(int n=200000)
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
int n,k;
int sa[N],rk[N];
int main()
{
    init();
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&sa[i]);
    for(int i=1;i<=n;i++)
        rk[sa[i]]=i;
    int cnt=0;
    for(int i=1;i<n;i++)
        if(rk[sa[i]+1]<rk[sa[i+1]+1]) cnt++;
    int ans=0;
    for(int i=0;i<=cnt;i++)
        ans=(ans+1LL*C(cnt,i)*C(k,n-i))%MOD;
    printf("%d",ans);
    return 0;
}