#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
const long long INF=4557430888798830399;
int n;
void solve()
{
    cin>>n;
    long long r=INF,d=0;
    vector<pair<long long,long long>>seg;
    for(int i=1;i<=n;i++)
    {
        int t,k,x;
        cin>>t>>k>>x;
        long long ql=max(0LL,(2*x+(long long)k*(1-k))/(2*k)),qr=(2*x+(long long)k*(k-1)+2*k-1)/(2*k);
        if(t==1) r=min(r,ql),d=max(d,qr);
        else seg.emplace_back(ql,qr);
    }
    seg.emplace_back(0,0);
    sort(seg.begin(),seg.end());
    if(seg.empty()||r>seg.back().first)
    {
        cout<<-1<<"\n";
        return;
    }
    vector<int>stk;
    for(int i=0;i<(int)seg.size();i++)
    {
        while(!stk.empty()&&seg[stk.back()].second>=seg[i].second) stk.pop_back();
        stk.emplace_back(i);
    }
    long long ans=0;
    for(int i=1;i<(int)stk.size();i++)
    {
        long long u=seg[stk[i]].second-1,l=seg[stk[i-1]].first+1;
        if(d<=u&&l<=r) ans+=(min(r,seg[stk[i]].first)-l+1)*(u-d+1);
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