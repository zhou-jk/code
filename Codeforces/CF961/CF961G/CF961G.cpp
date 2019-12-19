#include<iostream>
#include<cstdio>
using namespace std;
const int N=200001,MOD=1000000007;
long long ksm(long long a,long long b)
{
    if(b<0) return 1; 
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
int n,k;
long long fac[N],inv[N];
int main()
{
    scanf("%d%d",&n,&k);
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%MOD;
    inv[n]=ksm(fac[n],MOD-2);
    for(int i=n-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum=(sum+x)%MOD;
    }
    long long ans=0;
    for(int i=0;i<k;i++)
    {
        if(i&1) ans=(ans-inv[i]*inv[k-i-1]%MOD*ksm(k-i,n-2)%MOD*(k-i+n-1)%MOD+MOD)%MOD;
        else ans=(ans+inv[i]*inv[k-i-1]%MOD*ksm(k-i,n-2)%MOD*(k-i+n-1)%MOD+MOD)%MOD;
    }
    printf("%lld",ans*sum%MOD);
    return 0;
}