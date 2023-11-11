#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=500005;
const long long INF=4557430888798830399;
int n,k;
int c[N];
int dfnc[N];
vector<pair<int,int>>G[N];
int dfn[N],ed[N],Index;
long long dis[N],b[N];
void init(int u,int father)
{
    dfn[u]=++Index;
    for(auto [v,w]:G[u])
    {
        if(v==father) continue;
        dis[v]=dis[u]+w;
        init(v,u);
    }
    ed[u]=Index;
    return;
}
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        long long g,sum,tag;
    }tree[N*4];
    Node merge(const Node &a,const Node &b)
    {
        Node c;
        c.l=a.l,c.r=b.r;
        c.tag=0;
        c.sum=a.sum+b.sum;
        c.g=gcd(a.g,b.g);
        return c;
    }
    void push_up(int i)
    {
        tree[i]=merge(tree[ls],tree[rs]);
        return;
    }
    void add(int i,long long v)
    {
        tree[i].sum+=(tree[i].r-tree[i].l+1)*v;
        tree[i].tag+=v;
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].tag) return;
        add(ls,tree[i].tag);
        add(rs,tree[i].tag);
        tree[i].tag=0;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tag=0;
        if(l==r)
        {
            tree[i].sum=dis[c[l]];
            tree[i].g=b[l];
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,long long v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].g+=v;
            return;
        }
        push_down(i);
        if(u<=tree[ls].r) modify(ls,u,v);
        else modify(rs,u,v);
        push_up(i);
        return;
    }
    void add(int i,int l,int r,long long v)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[ls].r) add(ls,l,r,v);
        if(r>=tree[rs].l) add(rs,l,r,v);
        push_up(i);
        return;
    }
    Node query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i];
        push_down(i);
        if(r<=tree[ls].r) return query(ls,l,r);
        else if(l>=tree[rs].l) return query(rs,l,r);
        else return merge(query(ls,l,r),query(rs,l,r));
    }
    #undef ls
    #undef rs
}T;
long long ans=INF;
void dfs(int u,int father)
{
    auto res=T.query(1,1,k);
    if(res.g<0) res.g=-res.g;
    ans=min(ans,res.sum*2/res.g);
    for(auto [v,w]:G[u])
    {
        if(v==father) continue;
        int l=lower_bound(dfnc+1,dfnc+k+1,dfn[v])-dfnc;
        int r=upper_bound(dfnc+1,dfnc+k+1,ed[v])-dfnc-1;
        if(l<=r)
        {
            T.modify(1,l,-w);
            if(r+1<=k) T.modify(1,r+1,w);
            T.add(1,l,r,-w);
        }
        if(1<=l-1)
        {
            T.modify(1,1,w);
            if(l<=k) T.modify(1,l,-w);
            T.add(1,1,l-1,w);
        }
        if(r+1<=k)
        {
            T.modify(1,r+1,w);
            T.add(1,r+1,k,w);
        }
        dfs(v,u);
        if(l<=r)
        {
            T.modify(1,l,w);
            if(r+1<=k) T.modify(1,r+1,-w);
            T.add(1,l,r,w);
        }
        if(1<=l-1)
        {
            T.modify(1,1,-w);
            if(l<=k) T.modify(1,l,w);
            T.add(1,1,l-1,-w);
        }
        if(r+1<=k)
        {
            T.modify(1,r+1,-w);
            T.add(1,r+1,k,-w);
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        cin>>c[i];
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        G[x].emplace_back(y,z);
        G[y].emplace_back(x,z);
    }
    init(1,0);
    sort(c+1,c+k+1,[=](const int &x,const int &y){return dfn[x]<dfn[y];});
    for(int i=1;i<=k;i++)
        dfnc[i]=dfn[c[i]];
    for(int i=1;i<=k;i++)
        b[i]=dis[c[i]]-dis[c[i-1]];
    T.build(1,1,k);
    if(k==1)
    {
        cout<<0;
        return 0;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}