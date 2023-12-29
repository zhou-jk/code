#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1000005;
int n;
int p[N];
int suf[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    suf[n+1]=n;
    for(int i=n;i>=1;i--)
        suf[i]=min(suf[i+1],p[i]);
    deque<pair<int,int>>q;
    long long sum=0;
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n&&suf[i+1]==suf[j+1]) j++;
        sum+=(long long)suf[i+1]*(j-i);
        q.emplace_back(suf[i+1],j-i);
    }
    long long ans=sum;
    for(int i=1;i<=n;i++)
    {
        auto [v,c]=q.front();
        q.pop_front();
        sum-=v,c--;
        if(c>0) q.emplace_front(v,c);
        int cnt=0;
        while(!q.empty()&&q.back().first>p[i]) cnt+=q.back().second,sum-=(long long)q.back().first*q.back().second,q.pop_back();
        if(cnt>0)
        {
            sum+=(long long)p[i]*cnt;
            if(!q.empty()&&q.back().first==p[i])
            {
                auto [v,c]=q.back();
                q.pop_back();
                q.emplace_back(v,c+cnt);
            }
            else
                q.emplace_back(p[i],cnt);
        }
        sum+=n;
        if(!q.empty()&&q.back().first==n)
        {
            auto [v,c]=q.back();
            q.pop_back();
            q.emplace_back(v,c+1);
        }
        else
            q.emplace_back(n,1);
        ans=max(ans,sum);
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