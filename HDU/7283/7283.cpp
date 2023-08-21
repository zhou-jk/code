#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,d;
void solve()
{
    cin>>n>>m>>d;
    if((m+n-1)/n>=d) cout<<"Yes\n";
    else cout<<"No\n";
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