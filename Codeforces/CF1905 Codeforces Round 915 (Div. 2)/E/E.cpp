#include<iostream>
#include<cstdio>
#include<queue>
#include<unordered_map>
using namespace std;
const int MOD=998244353;
int qpow(int a,long long b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(long long)res*a%MOD;
        a=(long long)a*a%MOD,b>>=1;
    }
    return res;
}
long long n;
unordered_map<long long,pair<int,int>>mp[63];
void solve()
{
    cin>>n;
    int m=__lg(n)+3;
    for(int i=1;i<=m;i++)
        mp[i].clear();
    mp[1][n]=make_pair(1,1);
    long long ans=0;
    for(int i=1;i<=m;i++)
        for(auto [v,o]:mp[i])
        {
            auto [sum,cnt]=o;
            if(v==1)
            {
                ans=(ans+sum)%MOD;
                continue;
            }
            long long l=(v+1)/2,r=v-l;
            ans=(ans+(long long)sum*(qpow(2,l)-1)%MOD*(qpow(2,r)-1))%MOD;
            mp[i+1][l].first=(mp[i+1][l].first+sum*2ll)%MOD;
            mp[i+1][l].second=(mp[i+1][l].second+cnt)%MOD;
            mp[i+1][r].first=(mp[i+1][r].first+sum*2ll+cnt)%MOD;
            mp[i+1][r].second=(mp[i+1][r].second+cnt)%MOD;
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