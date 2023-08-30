#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=998244353;
const int INV3=332748118;
int n;
void solve()
{
    cin>>n;
    if(n==1)
    {
        cout<<0<<"\n";
        return;
    }
    int ans=(long long)(2*n-1)*INV3%MOD;
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