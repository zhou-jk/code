#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
void solve()
{
    cin>>n;
    vector<int>p;
    int l=0,r=1e9;
    for(int i=1;i<=n;i++)
    {
        int a,x;
        cin>>a>>x;
        if(a==1) l=max(l,x);
        else if(a==2) r=min(r,x);
        else p.emplace_back(x);
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    int ans=max(r-l+1,0);
    for(int x:p)
        if(l<=x&&x<=r) ans--;
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