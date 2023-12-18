#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1000005;
bool isprime[N];
int w[N];
void init(int n=1000000)
{
    fill(isprime+1,isprime+n+1,true);
    isprime[1]=false;
    for(int i=2;i<=n;i++)
        if(isprime[i])
            for(int j=i+i;j<=n;j+=i)
                isprime[j]=false;
    for(int i=2;i<=n;i++)
        if(isprime[i])
            for(int j=i;j<=n;j+=i)
                w[j]++;
    return;
}
int l,r;
int fa[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    else return fa[v]=getf(fa[v]);
}
bool merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2)
    {
        fa[f2]=f1;
        return true;
    }
    else return false;
}
vector<pair<int,int>>edge[32];
void solve()
{
    cin>>l>>r;
    for(int w=1;w<=30;w++)
        edge[w].clear();
    for(int d=1;d<=r;d++)
    {
        int v=0;
        for(int u=(l+d-1)/d*d;u<=r;u+=d)
            if(v==0||w[u]<w[v]) v=u;
        if(v)
            for(int u=(l+d-1)/d*d;u<=r;u+=d)
                if(u!=v) edge[w[u]+w[v]-w[d]].emplace_back(u,v); 
    }
    for(int i=l;i<=r;i++)
        fa[i]=i;
    long long ans=0;
    for(int w=1;w<=30;w++)
        for(auto [u,v]:edge[w])
            if(merge(u,v)) ans+=w;
    cout<<ans<<"\n";
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