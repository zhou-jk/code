#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
void solve()
{
    cin>>n>>m;
    if(n==1||m==1) cout<<(n+m)/2<<"\n";
    else if(n*m%3==0) cout<<2<<"\n";
    else cout<<1<<"\n";
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