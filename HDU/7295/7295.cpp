#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
int n;
string s;
void solve()
{
    cin>>s;
    n=s.size();
    int ans=0;
    for(int i=0,j=0;i<n;i=j)
    {
        while(j<n&&s[i]==s[j]) j++;
        ans+=j-i-1;
    }
    cout<<ans<<"\n";
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