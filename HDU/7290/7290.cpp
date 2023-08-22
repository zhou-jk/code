#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=998244353;
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
void solve()
{
    int n;
    cin>>n;
    int ans=(qpow(2,n-1)-1+MOD)%MOD;
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