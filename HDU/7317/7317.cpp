#pragma GCC optimize("Ofast")
#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;
int n;
void solve()
{
    cin>>n;
    double ans1=2.0*(n-1)/n,ans2=n==2?1:2;
    cout<<fixed<<setprecision(9)<<ans1<<" "<<ans2<<"\n";
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