#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=500005;
const long long INF=4557430888798830399;
int n,k,m;
int a[N];
int s[N];
long long f[N],g[N];
long long dp[N];
deque<int>q;
int pre1[N],suf1[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[0]=a[n+1]=0;
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
        s[i]=str[i-1]-'0';
    pre1[0]=0;
    for(int i=1;i<=n;i++)
    {
        pre1[i]=pre1[i-1];
        if(s[i]==1) pre1[i]=i;
    }
    suf1[n+1]=n+1;
    for(int i=n;i>=1;i--)
    {
        suf1[i]=suf1[i+1];
        if(s[i]==1) suf1[i]=i;
    }
    for(int i=1;i<=n;i++)
        f[i]=g[i]=INF;
    f[0]=0,g[n+1]=0;
    q.clear();
    q.emplace_back(0);
    for(int i=1;i<=n+1;i++)
    {
        while(!q.empty()&&q.front()<max(i-k,pre1[i-1])) q.pop_front();
        if(!q.empty()) f[i]=f[q.front()]+a[i];
        while(!q.empty()&&f[q.back()]>f[i]) q.pop_back();
        q.emplace_back(i);
    }
    q.clear();
    q.emplace_back(n+1);
    for(int i=n;i>=0;i--)
    {
        while(!q.empty()&&q.front()>min(suf1[i+1],i+k)) q.pop_front();
        if(!q.empty()) g[i]=g[q.front()]+a[i];
        while(!q.empty()&&g[q.back()]>g[i]) q.pop_back();
        q.emplace_back(i);
    }
    static long long ff[N];
    for(int i=0;i<=n+1;i++)
        ff[i]=f[i];
    cin>>m;
    while(m--)
    {
        int p,v;
        cin>>p>>v;
        int u=a[p];
        a[p]=v; 
        q.clear();
        for(int i=max(p-k,pre1[p-1]);i<p;i++)
        {
            while(!q.empty()&&q.front()<max(i-k,pre1[i-1])) q.pop_front();
            while(!q.empty()&&ff[q.back()]>ff[i]) q.pop_back();
            q.emplace_back(i);
        }
        for(int i=p;i<=min(suf1[p+1],p+k);i++)
        {
            while(!q.empty()&&q.front()<max(i-k,pre1[i-1])) q.pop_front();
            if(!q.empty()) ff[i]=ff[q.front()]+a[i];
            while(!q.empty()&&ff[q.back()]>ff[i]) q.pop_back();
            q.emplace_back(i);
        }
        long long ans=ff[p]+v+g[p]-u;
        for(int i=p+1;i<=min(suf1[p+1],p+k);i++)
            ans=min(ans,ff[i]+g[i]-a[i]);
        cout<<ans<<"\n";
        for(int i=p;i<=min(suf1[p+1],p+k);i++)
            ff[i]=f[i];
        a[p]=u;
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
