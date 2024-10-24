#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
            cout<<char('a'+j-1);
    cout<<"\n";
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