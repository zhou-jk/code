#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
const int MOD=998244353;
int n,a,b;
long long k;
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
void init(int n=300000)
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
int main()
{
    init();
    scanf("%d%d%d%lld",&n,&a,&b,&k);
    int ans=0;
    for(int i=0;i<=n;i++)
        if((k-1LL*i*a)%b==0&&(k-1LL*i*a)/b>=0&&(k-1LL*i*a)/b<=n)
        {
            int j=(k-1LL*i*a)/b;
            ans=(ans+1LL*C(n,i)*C(n,j))%MOD;
        }
    printf("%d",ans);
    return 0;
}