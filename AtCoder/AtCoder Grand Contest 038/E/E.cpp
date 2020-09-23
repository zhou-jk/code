#include<iostream>
#include<cstdio>
using namespace std;
const int N=405;
const int MOD=998244353;
int n;
int a[N],b[N];
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
long long fac[N];
void init(int n=400)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%MOD;
    return;
}
long long q[N][N][N];
int sa,sb;
long long c[N][N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]),sa+=a[i],sb+=b[i];
    init();
    q[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        long long p=a[i]*ksm(sa,MOD-2)%MOD,fac=MOD-1;
        for(int l=0;l<b[i];l++,fac=fac*ksm(l,MOD-2)%MOD*p%MOD)
            for(int j=0;j<=sa;j++)
                for(int k=l;k<=sb;k++)
                    q[i][j][k]=(q[i][j][k]+fac*q[i-1][j][k-l]%MOD)%MOD;
        for(int j=a[i];j<=sa;j++)
            for(int k=0;k<=sb;k++)
                q[i][j][k]=(q[i][j][k]+q[i-1][j-a[i]][k])%MOD;
    }
    for(int i=0;i<=sa;i++)
        for(int j=0;j<=sb;j++)
            c[i][j]=(-q[n][i][j]+MOD)%MOD;
    c[sa][0]=(c[sa][0]+1)%MOD;
    long long ans=0;
    for(int i=0;i<=sa;i++)
        for(int j=0;j<=sb;j++)
        {
            long long p=i*ksm(sa,MOD-2)%MOD;
            long long f=ksm(ksm((1-p+MOD)%MOD,MOD-2),j+1)*fac[j]%MOD;
            ans=(ans+c[i][j]*f%MOD)%MOD;
        }
    printf("%lld",ans);
    return 0;
}
