#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
void solve()
{
    cin>>n>>m;
    int ans=(m+n-m)/(n-m+1);
    cout<<m<<" "<<ans<<"\n";
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