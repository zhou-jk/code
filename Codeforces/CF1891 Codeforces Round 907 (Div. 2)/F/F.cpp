#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=500005;
int n,q;
int t[N],v[N],x[N];
vector<int>G[N];
int dfn[N],siz[N],Index;
struct BIT
{
    long long C[N];
    int lowbit(int x)
    {
        return x&-x;
    }
    void clear()
    {
        for(int i=0;i<=n;i++)
            C[i]=0;
        return;
    }
    void add(int x,long long y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    void modify(int l,int r,long long x)
    {
        add(l,x);
        if(r+1<=n) add(r+1,-x);
        return;
    }
    long long query(int x)
    {
        long long res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
}T;
void dfs(int u)
{
    dfn[u]=++Index;
    siz[u]=1;
    for(int v:G[u])
    {
        dfs(v);
        siz[u]+=siz[v];
    }
    return;
}
long long ans[N];
void solve()
{
    cin>>q;
    n=1;
    for(int i=1;i<=q;i++)
    {
        cin>>t[i]>>v[i];
        if(t[i]==1) G[v[i]].emplace_back(++n);
        else if(t[i]==2) cin>>x[i];
    }
    Index=0;
    T.clear();
    dfs(1);
    int cur=n;
    for(int i=q;i>=1;i--)
        if(t[i]==1) ans[cur]=T.query(dfn[cur]),cur--;
        else if(t[i]==2) T.modify(dfn[v[i]],dfn[v[i]]+siz[v[i]]-1,x[i]);
    ans[cur]=T.query(dfn[cur]);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++)
        G[i].clear();
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