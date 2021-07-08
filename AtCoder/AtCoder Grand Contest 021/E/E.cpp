#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
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
int fac[N],inv[N];
void init(int n=1000000)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=1LL*fac[i-1]*i%MOD;
    inv[n]=getinv(fac[n]);
    for(int i=n;i>=1;i--)
        inv[i-1]=1LL*inv[i]*i%MOD;
    return;
}
int C(int n,int m)
{
    if(m>n) return 0;
    else return 1LL*fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int n,k;
int main()
{
    init();
    scanf("%d%d",&n,&k);
    if(k<n)
    {
        printf("0");
        return 0;
    }
    int ans=0;
    for(int r=1;r<=k;r++)
    {
        int b=k-r;
        if(r<b) continue;
        if(r>=b+n) ans=(ans+C(k,r))%MOD;
        else
        {
            if(r==b) b--;
            if(2*r-n+1>=0) ans=((long long)ans+C(r+b,r)-C(r+b,2*r-n+1)+MOD)%MOD;
        }
    }
    printf("%d",ans);
    return 0;
}