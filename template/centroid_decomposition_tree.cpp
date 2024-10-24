#include<iostream>
#include<cstdio>
#include<cassert>
#include<vector>
using namespace std;
template<typename T>
struct Fenwick_Tree
{
private:
    size_t n;
    vector<T>C;
public:
    Fenwick_Tree(size_t _n=0):n(_n),C(vector<T>(_n)){}
    size_t size()const
    {
        return n;
    }
    int lowbit(int x)const
    {
        return x&-x;
    }
    void init(size_t _n)
    {
        n=_n;
        C=vector<T>(_n);
        return;
    }
    void add(size_t x,T y)
    {
        x++;
        assert(1<=x&&x<=n);
        for(size_t i=x;i<=n;i+=lowbit(i))
            C[i-1]=C[i-1]+y;
        return;
    }
    T getsum(size_t x)const
    {
        x++;
        assert(1<=x&&x<=n);
        T res=C[x-1];
        for(size_t i=x-lowbit(x);i>0;i-=lowbit(i))
            res=res+C[i-1];
        return res;
    }
    int query(size_t l,size_t r)const
    {
        assert(l<=r);
        T res=getsum(r);
        if(l>0) res=res-getsum(l-1);
        return res;
    }
};
const int N=100005;
int n,m;
vector<int>G[N];
int dep[N];
int dfn[N],Index;
int mn[N][20],lg2[N];
void dfs_lca(int u,int father)
{
    dfn[u]=++Index;
    mn[Index][0]=father;
    dep[u]=dep[father]+1;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs_lca(v,u);
    }
    return;
}
void init_lca()
{
    Index=0;
    dfs_lca(1,0);
    lg2[0]=-1;
    for(int i=1;i<=Index;i++)
        lg2[i]=lg2[i/2]+1;
    for(int j=1;(1<<j)<=Index;j++)
        for(int i=1;i+(1<<j)-1<=Index;i++)
            if(dfn[mn[i][j-1]]<dfn[mn[i+(1<<(j-1))][j-1]]) mn[i][j]=mn[i][j-1];
            else mn[i][j]=mn[i+(1<<(j-1))][j-1];
    return;
}
int lca(int u,int v)
{
    if(u==v) return u;
    u=dfn[u],v=dfn[v];
    if(u>v) swap(u,v);
    u++;
    int d=lg2[v-u+1];
    if(dfn[mn[u][d]]<dfn[mn[v-(1<<d)+1][d]]) return mn[u][d];
    else return mn[v-(1<<d)+1][d];
}
int dis(int u,int v)
{
    return dep[u]+dep[v]-dep[lca(u,v)]*2;
}

int a[N];
int rt,tot;
int siz[N],mx[N];
bool book[N];
void getroot(int u,int father)
{
    siz[u]=1,mx[u]=0;
    for(int v:G[u])
    {
        if(book[v]) continue;
        if(v==father) continue;
        getroot(v,u);
        siz[u]+=siz[v];
        mx[u]=max(mx[u],siz[v]);
    }
    mx[u]=max(mx[u],tot-siz[u]);
    if(!rt||mx[u]<mx[rt]) rt=u;
    return;
}
int fa[N];
Fenwick_Tree<long long>f[N],g[N];
void add(int u,int father,int d)
{
    f[fa[rt]].add(d,a[u]);
    g[rt].add(d,a[u]);
    for(int v:G[u])
    {
        if(v==father) continue;
        if(book[v]) continue;
        add(v,u,d+1);
    }
    return;
}
void dfs(int u)
{
    book[u]=true;
    f[u].add(0,a[u]);
    for(int v:G[u])
    {
        if(book[v]) continue;
        tot=siz[v],rt=0;
        getroot(v,0);
        fa[rt]=u;
        f[rt].init(siz[v]+1),g[rt].init(siz[v]+1);
        add(v,u,1);
        dfs(rt);
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    init_lca();
    rt=0,tot=n;
    getroot(1,0);
    f[rt].init(n),g[rt].init(n);
    fa[rt]=0;
    dfs(rt);
    long long lastans=0;
    while(m--)
    {
        int op;
        scanf("%d",&op);
        if(op==0)
        {
            long long x,k;
            scanf("%lld%lld",&x,&k);
            x^=lastans,k^=lastans;
            long long ans=f[x].query(0,min<int>(k,f[x].size()-1));
            for(int u=fa[x],v=x;u;u=fa[u],v=fa[v])
            {
                int d=dis(u,x);
                if(k>=d) ans+=f[u].query(0,min<int>(k-d,f[u].size()-1))-g[v].query(0,min<int>(k-d,g[v].size()-1));
            }
            printf("%lld\n",ans);
            lastans=ans;
        }
        else if(op==1)
        {
            long long x,y;
            scanf("%lld%lld",&x,&y);
            x^=lastans,y^=lastans;
            for(int u=x;u;u=fa[u])
            {
                f[u].add(dis(x,u),y-a[x]);
                if(fa[u]) g[u].add(dis(x,fa[u]),y-a[x]);
            }
            a[x]=y;
        }
    }
    return 0;
}