#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
const int N=200005;
const long long INF=4557430888798830399;
int n,Q;
vector<tuple<int,int,int>>G[N];
long long f[N],g[N];
int pg[N];
void dfs1(int u,int father)
{
    for(auto [v,a,b]:G[u])
    {
        if(v==father) continue;
        dfs1(v,u);
        f[u]+=f[v]+b;
    }
    pg[u]=u;
    for(auto [v,a,b]:G[u])
    {
        if(v==father) continue;
        if(g[v]+a+b+f[u]-f[v]-b>g[u]) pg[u]=pg[v],g[u]=g[v]+a+b+f[u]-f[v]-b;
    }
    return;
}
long long rf[N],rg[N];
long long ans[N];
int s,t;
void dfs2(int u,int father,long long pref)
{
    rf[u]=pref+f[u];
    for(auto [v,a,b]:G[u])
    {
        if(v==father) continue;
        dfs2(v,u,rf[u]-f[v]-b+a);
    }
    ans[1]=max(ans[1],rf[u]);
    long long mx=-INF;
    rg[u]=g[u]+pref;
    int mxg=0;
    int us=u,ut=pg[u];
    for(auto [v,a,b]:G[u])
    {
        if(v==father) continue;
        if(pref+mx+g[v]+a+b+f[u]-f[v]-b>rg[u]) us=pg[v],ut=mxg,rg[u]=pref+mx+g[v]+a+b+f[u]-f[v]-b;
        if(g[v]+a+b-f[v]-b>mx) mxg=pg[v],mx=g[v]+a+b-f[v]-b;
    }
    if(rg[u]>ans[2]) s=us,t=ut,ans[2]=rg[u];
    return;
}
int dfn[N],siz[N],Index;
long long sum[N];
int w[N];
int fa[N];
void dfs3(int u,int father)
{
    dfn[u]=++Index;
    w[Index]=u;
    siz[u]=1;
    fa[u]=father;
    for(auto [v,a,b]:G[u])
    {
        if(v==father) continue;
        sum[v]=sum[u]+a;
        dfs3(v,u);
        siz[u]+=siz[v];
    }
    return;
}
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        pair<long long,int> mx;
        long long tag;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].mx=max(tree[i*2].mx,tree[i*2+1].mx);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tag=0;
        if(l==r)
        {
            tree[i].mx={sum[w[l]],w[l]};
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void add(int i,long long v)
    {
        tree[i].mx.first+=v;
        tree[i].tag+=v;
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].tag) return;
        add(i*2,tree[i].tag);
        add(i*2+1,tree[i].tag);
        tree[i].tag=0;
        return;
    }
    void modify(int i,int l,int r,long long v)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[i*2].r) modify(i*2,l,r,v);
        if(r>=tree[i*2+1].l) modify(i*2+1,l,r,v);
        push_up(i);
        return;
    }
    pair<long long,int> query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].mx;
        push_down(i);
        pair<long long,int> res={-INF,-1};
        if(l<=tree[i*2].r) res=max(res,query(i*2,l,r));
        if(r>=tree[i*2+1].l) res=max(res,query(i*2+1,l,r));
        return res;
    }
}T;
bool vis[N];
void add(int u)
{
    while(u&&!vis[u])
    {
        T.modify(1,dfn[u],dfn[u]+siz[u]-1,-(sum[u]-sum[fa[u]]));
        vis[u]=true;
        u=fa[u];
    }
    return;
}
int main()
{
    scanf("%d",&n);
    long long sum=0;
    for(int i=1;i<n;i++)
    {
        int x,y,a,b;
        scanf("%d%d%d%d",&x,&y,&a,&b);
        G[x].emplace_back(y,a,b);
        G[y].emplace_back(x,b,a);
        sum+=a+b;
    }
    dfs1(1,0);
    dfs2(1,0,0);
    dfs3(s,0);
    T.build(1,1,n);
    add(t);
    for(int i=3;i<=n;i++)
    {
        pair<long long,int> p=T.query(1,1,n);
        ans[i]=ans[i-1]+p.first;
        add(p.second);
    }
    for(int i=1;i<=n;i++)
        ans[i]=sum-ans[i];
    scanf("%d",&Q);
    while(Q--)
    {
        int x;
        scanf("%d",&x);
        printf("%lld\n",ans[x]);
    }
    return 0;
}