#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long x;
void solve()
{
    cin>>x;
    int n=__lg(x);
    x-=(1ll<<n);
    int cur=1e9;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        if((x>>i)&1) res.emplace_back(cur-i);
        res.emplace_back(i);
    }
    int k=res.size();
    cout<<k<<"\n";
    for(int u:res)
        cout<<u<<" ";
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