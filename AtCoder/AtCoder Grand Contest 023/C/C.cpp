#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
const int MOD=1000000007;
int n;
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
int fac[N],inv[N];
void init(int n=1000000)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=1LL*fac[i-1]*i%MOD;
    inv[n]=ksm(fac[n],MOD-2);
    for(int i=n;i>=1;i--)
        inv[i-1]=1LL*inv[i]*i%MOD;
    return;
}
int C(int n,int m)
{
    if(m>n) return 0;
    else return 1LL*fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int f[N];
int main()
{
    init();
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
        f[i]=1LL*C(i-1,n-i-1)*fac[i]%MOD*fac[n-i-1]%MOD;
    for(int i=n-1;i>=1;i--)
        f[i]=(1LL*f[i]-f[i-1]+MOD)%MOD;
    int ans=0;
    for(int i=1;i<=n-1;i++)
        ans=(ans+1LL*f[i]*i)%MOD;
    printf("%d",ans);
    return 0;
}