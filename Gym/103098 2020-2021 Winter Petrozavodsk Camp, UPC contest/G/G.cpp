#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
#include<functional>
using namespace std;
const int N=100005,C=20;
const int MOD=1000000007;
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=1LL*res*a%MOD;
        a=1LL*a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return qpow(x,MOD-2);
}
int n,m,c;
int p[C];
int a[N];
vector<int>G[N];
int fa[N],dep[N];
int son[N],siz[N];
void dfs1(int u,int father)
{
    fa[u]=father;
    dep[u]=dep[father]+1;
    siz[u]=1;
    son[u]=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs1(v,u);
        if(siz[v]>siz[son[u]]) son[u]=v;
        siz[u]+=siz[v];
    }
    return;
}
int dfn[N],Index;
int b[N];
int top[N];
void dfs2(int u,int topf)
{
    dfn[u]=++Index;
    b[Index]=1<<a[u];
    top[u]=topf;
    if(!son[u]) return;
    dfs2(son[u],topf);
    for(int v:G[u])
    {
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
    return;
}
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int sum;
    }tree[N*4];
    void push_up(int i)
    {
        tree[i].sum=tree[ls].sum^tree[rs].sum;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].sum=b[l];
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,int v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].sum=v;
            return;
        }
        if(u<=tree[ls].r) modify(ls,u,v);
        else modify(rs,u,v);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        int res=0;
        if(l<=tree[ls].r) res^=query(ls,l,r);
        if(r>=tree[rs].l) res^=query(rs,l,r);
        return res;
    }
    #undef ls
    #undef rs
}T;
int query(int x,int y)
{
    int res=0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        res^=T.query(1,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    res^=T.query(1,dfn[x],dfn[y]);
    return res;
}
typedef vector<int> Poly;
Poly operator^(const Poly &F,const Poly &G)
{
    Poly f=F,g=G;
    int m=max(f.size()-1,g.size()-1),n=1;
    while(n<=m) n<<=1;
    f.resize(n),g.resize(n);
    function<void(Poly &)> fwt=[=](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    int l=F[k],r=F[k+len/2];
                    F[k]=(l+r)%MOD;
                    F[k+len/2]=(l-r+MOD)%MOD;
                }
        return;
    };
    fwt(f);
    fwt(g);
    for(int i=0;i<n;i++)
        f[i]=(long long)f[i]*g[i]%MOD;
    function<void(Poly &)> ifwt=[=](Poly &F)
    {
        int n=F.size();
        for(int len=2;len<=n;len<<=1)
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    int l=F[k],r=F[k+len/2];
                    F[k]=(l+r)%MOD;
                    F[k+len/2]=(l-r+MOD)%MOD;
                }
        cerr<<"FFF"<<n<<"\n";
        int invn=getinv(n);
        for(int i=0;i<(int)F.size();i++)
            F[i]=(long long)F[i]*invn%MOD;
        return;
    };
    ifwt(f);
    return f;
}
int d[N],s[N];
int lowbit(int x)
{
    return x&-x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>m>>c>>n;
    for(int i=0;i<c;i++)
        cin>>p[i];
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        for(int j=1;j<=x;j++)
        {
            int y;
            cin>>y;
            d[i]|=1<<y;
        }
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        x++,y++;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs1(1,0);
    dfs2(1,1);
    T.build(1,1,Index);
    for(int i=1;i<=m;i++)
    {
        int u,v,w,y;
        cin>>u>>v>>w>>y;
        u++,v++,w++;
        s[i]=s[i-1]^query(u,v);
        T.modify(1,dfn[w],1<<y);
    }
    vector<int>cnt(1<<c,0);
    for(int i=1;i<=m;i++)
        cnt[d[i]]++;
    vector<int>point(1<<c,0);
    for(int i=0;i<c;i++)
        point[1<<i]=p[i];
    for(int i=1;i<(1<<c);i++)
        point[i]=gcd(point[i^lowbit(i)],point[lowbit(i)]);
    vector<int>res=cnt^point;
    for(int i=1;i<=m;i++)
        cout<<res[s[i]]<<" ";
    return 0;
}