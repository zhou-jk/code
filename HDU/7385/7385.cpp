#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000007;
int qpow(int a,int b)
{
    while(b<0) b+=MOD-1;
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
const int N=1000005;
int fac[N];
void init(int n=1000000)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=(long long)fac[i-1]*i%MOD;
    return;
}
int n,k;
void solve()
{
    cin>>n>>k;
    int ans=(long long)fac[n]*fac[k]%MOD*qpow(k,n-k-1)%MOD;
    cout<<ans<<"\n";
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