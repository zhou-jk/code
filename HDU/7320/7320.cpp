#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
const int N=200005;
const int MOD=998244353;
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(long long)res*a%MOD;
        a=(long long)a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return qpow(x,MOD-2);
}
int fac[N],ifac[N];
void init(int n=200000)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=(long long)fac[i-1]*i%MOD;
    ifac[n]=getinv(fac[n]);
    for(int i=n;i>=1;i--)
        ifac[i-1]=(long long)ifac[i]*i%MOD;
    return;
}
int C(int n,int m)
{
    if(m>n) return 0;
    if(m==0||n==m) return 1;
    return (long long)fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int n;
vector<pair<int,int>>G[N];
stack<int>s[N];
int siz[N];
int f[N],g[N];
int up[N];
void dfs(int u,int father)
{
    siz[u]=1;
    for(auto [v,w]:G[u])
    {
        if(v==father) continue;
        s[w].emplace(v);
        dfs(v,u);
        s[w].pop();
        siz[u]+=siz[v];
        if(s[w].empty()) up[v]=-w,g[w]-=siz[v];
        else up[v]=s[w].top(),f[up[v]]-=siz[v];
    }
    f[u]+=siz[u];
    return;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        G[x].emplace_back(y,z);
        G[y].emplace_back(x,z);
    }
    for(int i=1;i<=n;i++)
        f[i]=0,g[i]=n;
    dfs(1,0);
    int sum=0;
    for(int i=2;i<=n;i++)
        if(up[i]>0) sum=(sum+(long long)f[i]*f[up[i]])%MOD;
        else sum=(sum+(long long)f[i]*g[-up[i]])%MOD;
    int res=0;
    for(int k=2;k<=n;k++)
    {
        int ans=(long long)sum*C(n-2,k-2)%MOD*getinv(C(n,k))%MOD;
        res^=ans;
    }
    cout<<res<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}