#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000001;
const int MOD=998244353;
int n;
long long fac[N],inv[N];
long long ans,res;
long long C(int n,int m)
{
    if(n<m) return 0;
    if(m==0) return 1;
    return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
long long ksm(long long a,long long b)
{
    a%=MOD;
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%MOD;
    inv[n]=ksm(fac[n],MOD-2);
    for(int i=n-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
    for(int i=1;i<=n;i++)
    {
        long long a=C(n,i)*ksm(MOD-1,i+1)%MOD;
        long long x=ksm(3,((long long)n*(n-i)+i)%(MOD-1));
        ans=(ans+a*x%MOD)%MOD;
    }
    ans=ans*2%MOD;
    for(int i=0;i<n;i++)
    {
        long long t=MOD-ksm(3,i);
        long long x=(ksm(t+1,n)-ksm(t,n)+MOD)%MOD;
        long long a=C(n,i)*ksm(MOD-1,i+1)%MOD;
        res=(res+a*x%MOD)%MOD;
    }
    res=res*3%MOD;
    printf("%lld",(ans+res)%MOD);
    return 0;
}