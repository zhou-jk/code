#include<bits/stdc++.h>
using namespace std;
constexpr int N=305;
constexpr int M=1000005;
constexpr long long INF=1e18;
constexpr int BASE=13331,MOD=998244353;
int n,m,q;
long long a[N];
vector<long long>p[M];
long long f[N][N];
vector<pair<long long,long long>>b[M];
long long sum[N],dis[N][N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    vector<int>pos;
    for(int i=1;i<=n;i++)
        pos.emplace_back(a[i]%m);
    sort(pos.begin(),pos.end());
    pos.erase(unique(pos.begin(),pos.end()),pos.end());
    for(int i=1;i<=n;i++)
        p[a[i]%m].emplace_back(a[i]/m);
    for(int t:pos)
    {
        int len=(int)p[t].size();
        if(len==0) continue;
        p[t].emplace_back(0);
        sort(p[t].begin(),p[t].end());
        sum[0]=0;
        for(int i=1;i<=len;i++)
            sum[i]=sum[i-1]+p[t][i];
        for(int l=1;l<=len;l++)
            for(int r=l;r<=len;r++)
            {
                int mid=(l+r)/2;
                dis[l][r]=(sum[r]-sum[mid]-p[t][mid]*(r-mid))+(p[t][mid]*(mid-l+1)-(sum[mid]-sum[l-1]));
            }
        for(int i=0;i<=len;i++)
            for(int j=0;j<=len;j++)
                f[i][j]=INF;
        f[0][0]=0;
        for(int i=1;i<=len;i++)
            for(int j=1;j<=len;j++)
            {
                for(int k=1;k<=j;k++)
                    f[i][j]=min(f[i][j],f[i-1][k-1]+dis[k][j]);
            }
        b[t].clear();
        for(int i=1;i<=len;i++)
            b[t].emplace_back(i,f[i][len]);
    }
    vector<long long>dp(n+1,INF);
    dp[0]=0;
    for(int t:pos)
    {
        if(b[t].empty()) continue;
        vector<long long>ndp(n+1,INF);
        for(auto [v,w]:b[t])
            for(int j=n;j>=v;j--)
                ndp[j]=min(ndp[j],dp[j-v]+w);
        dp=move(ndp);
    }
    cin>>q;
    int ans=0;
    while(q--)
    {
        long long k;
        cin>>k;
        int res=lower_bound(dp.begin(),dp.end(),k,greater<long long>())-dp.begin();
        ans=((long long)ans*BASE+res)%MOD;
    }
    cout<<ans<<"\n";
    for(int t:pos)
        p[t].clear(),b[t].clear();
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