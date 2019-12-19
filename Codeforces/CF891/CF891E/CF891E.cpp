#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5001;
const int MOD=1000000007;
int n,k;
long long fac[N],ifac[N],inv[N],pw[N];
long long a[N],b[N],c[N];
void init(int n)
{
    fac[0]=ifac[0]=inv[0]=1;
    fac[1]=ifac[1]=inv[1]=1;
    pw[0]=1,pw[1]=n;
    for(int i=2;i<=n;i++)
    {
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
        ifac[i]=ifac[i-1]*inv[i]%MOD;
        pw[i]=pw[i-1]*n%MOD;
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    init(n);
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        ans=ans*a[i]%MOD;
    }
    c[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
            b[j]=c[j]*a[i]%MOD;
        for(int j=0;j<i;j++)
            b[j+1]=(b[j+1]-c[j]+MOD)%MOD;
        memcpy(c,b,sizeof(c));
    }
    long long sum=1,res=1;
    for(int i=0;i<=n;i++)
    {
        c[i]=c[i]*sum%MOD*res%MOD;
        sum=sum*inv[n]%MOD;
        res=res*(k-i)%MOD;
    }
    for(int i=0;i<=n;i++)
        ans=(ans-c[i]+MOD)%MOD;
    printf("%lld",ans);
    return 0;
}