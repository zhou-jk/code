#include<iostream>
#include<cstdio>
using namespace std;
int x,y,k;
void solve()
{
    cin>>x>>y>>k;
    if(y<x) cout<<x<<"\n";
    else cout<<y+max(0,y-x-k)<<"\n";
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
