#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c;
void solve()
{
    cin>>a>>b>>c;
    if(abs(b-c)%2==0) cout<<1<<" ";
    else cout<<0<<" ";
    if(abs(a-c)%2==0) cout<<1<<" ";
    else cout<<0<<" ";
    if(abs(a-b)%2==0) cout<<1<<" ";
    else cout<<0<<" ";
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