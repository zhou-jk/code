#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
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
    if(m>n||m<0) return 0;
    else return 1LL*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int n,l,r;
void solve()
{
    scanf("%d%d%d",&n,&l,&r);
    int ans=0;
    for(int d=min(r-1,n-l);d>=1;d--)
    {
        int R=min(r-d,n),L=max(l+d,1);
        if(R==n&&L==1)
        {
            if(n%2==0) ans=(ans+1LL*d*C(n,n/2))%MOD;
            else ans=(ans+1LL*d*(C(n,n/2)+C(n,n/2+1)))%MOD;
            break;
        }
        if(R+1>=L)
        {
            if(n%2==0) ans=(ans+C(R-L+1,n/2-(L-1)))%MOD;
            else ans=(ans+C(R-L+1,n/2-(L-1)))%MOD,ans=(ans+C(R-L+1,n/2+1-(L-1)))%MOD;
        }
    }
    printf("%d\n",ans);
    return;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}