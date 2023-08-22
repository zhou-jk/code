#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
int k,n;
void solve()
{
    cin>>k>>n;
    if(n==0)
    {
        cout<<"Alice\n";
        return;
    }
    if(n%(4*k+2)==(k+1)) cout<<"Bob\n";
    else cout<<"Alice\n";
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