#include<iostream>
#include<cstdio>
using namespace std;
int a,b;
void solve()
{
    cin>>a>>b;
    if((a+b)&1) cout<<"Alice\n";
    else cout<<"Bob\n";
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