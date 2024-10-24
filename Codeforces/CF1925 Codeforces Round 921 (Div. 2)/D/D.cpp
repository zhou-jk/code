#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000007;
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
int getinv(int x)
{
    return qpow(x,MOD-2);
}
int n,m,k;
void solve()
{
    cin>>n>>m>>k;
    int s=0;
    for(int i=1;i<=m;i++)
    {
        int a,b,f;
        cin>>a>>b>>f;
        s=(s+f)%MOD;
    }
    int p=2ll*getinv((long long)n*(n-1)%MOD)%MOD;
    int ans=0;
    for(int i=1;i<=k;i++)
        ans=(ans+(long long)p*s)%MOD,s=(s+(long long)p*m)%MOD;
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}