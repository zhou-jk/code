#include<iostream>
#include<cstdio>
using namespace std;
int n;
string s;
void solve()
{
    cin>>n;
    cin>>s;
    if(n>5) cout<<"sleep\n";
    else cout<<s<<"\n";
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