#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n,q;
void solve()
{
    cin>>n>>q;
    map<pair<long long,long long>,vector<long long>> cnt1,cnt2;
    for(int i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        while(x>0&&y>0)
        {
            if(x>y)
            {
                cnt1[make_pair(x%y,y)].emplace_back(x);
                x%=y;
            }
            else
            {
                cnt2[make_pair(x,y%x)].emplace_back(y);
                y%=x;
            }
        }
    }
    for(auto &[p,v]:cnt1)
        sort(v.begin(),v.end());
    for(auto &[p,v]:cnt2)
        sort(v.begin(),v.end());
    for(int i=1;i<=q;i++)
    {
        long long a,b;
        cin>>a>>b;
        int ans=0;
        if(a>=b)
        {
            pair<long long,long long> p=make_pair(a%b,b);
            ans+=cnt1[p].size()-(lower_bound(cnt1[p].begin(),cnt1[p].end(),a)-cnt1[p].begin());
        }
        if(a<=b)
        {
            pair<long long,long long> p=make_pair(a,b%a);
            ans+=cnt2[p].size()-(lower_bound(cnt2[p].begin(),cnt2[p].end(),b)-cnt2[p].begin());
        }
        cout<<ans<<"\n";
    }
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