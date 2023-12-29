#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
void solve()
{
    cin>>n>>m;
    cout<<max(n,m)<<"\n";
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