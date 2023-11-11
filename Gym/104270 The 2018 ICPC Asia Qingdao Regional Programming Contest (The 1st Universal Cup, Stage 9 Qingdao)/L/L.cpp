#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=1000000007;
const int INV2=500000004;
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(long long)res*a%MOD;
        a=(long long)a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int a)
{
    return qpow(a,MOD-2);
}
int fac[N+N],ifac[N+N];
void init(int n=200000)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=(long long)fac[i-1]*i%MOD;
    ifac[n]=qpow(fac[n],MOD-2);
    for(int i=n;i>=1;i--)
        ifac[i-1]=(long long)ifac[i]*i%MOD;
    return;
}
int C(int n,int m)
{
    if(m>n) return 0;
    if(m==0||m==n) return 1;
    return (long long)fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int n;
long long m;
void solve()
{
    cin>>n>>m;
    if(m==0) cout<<1<<"\n";
    else if(m>n) cout<<0<<"\n";
    else if(m==n)
    {
        int ans=(long long)fac[n-1]*INV2%MOD;
        cout<<ans<<"\n";
    }
    else
    {
        int ans=0;
        int pre=1;
        for(int i=1;i<=n-m;i++)
        {
            pre=(long long)pre*(2*i-1)%MOD;
            ans=(ans+(long long)C(n,n-m-i)*fac[m-i]%MOD*C(m-1,i-1)%MOD*C(m+i,2*i)%MOD*pre)%MOD;
        }
        cout<<ans<<"\n";
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}