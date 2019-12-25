#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const long long INF=123456789123456789;
int n,m;
struct Edge
{
    int to,val,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v,int w)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int fa[N],dep[N],size[N],son[N];
long long dis[N];
void dfs1(int u,int father)
{
    fa[u]=father;
    dep[u]=dep[father]+1;
    size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dis[v]=dis[u]+edge[i].val;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[son[u]]<size[v]) son[u]=v;
    }
    return;
}
int top[N],dfn[N],Index;
int w[N];
void dfs2(int u,int father)
{
    top[u]=father;
    dfn[u]=++Index;
    w[Index]=u;
    if(!son[u]) return;
    dfs2(son[u],father);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
    return;
}
long long f(long long x,long long k,long long b)
{
    return k*x+b;
}
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        long long k,b;
        long long Min;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].Min=min(tree[i].Min,min(tree[i*2].Min,tree[i*2+1].Min));
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].k=0,tree[i].b=INF;
        tree[i].Min=INF;
        if(l==r) return;
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        return;
    }
    void modify(int i,long long k,long long b)
    {
        int mid=(tree[i].l+tree[i].r)/2;
        long long lt=f(dis[w[tree[i].l]],tree[i].k,tree[i].b),rt=f(dis[w[tree[i].r]],tree[i].k,tree[i].b);
        long long lp=f(dis[w[tree[i].l]],k,b),rp=f(dis[w[tree[i].r]],k,b);
        if(lp>=lt&&rp>=rt) return;
        if(lp<=lt&&rp<=rt)
        {
            tree[i].k=k,tree[i].b=b;
            tree[i].Min=min(tree[i].Min,min(lp,rp));
            return;
        }
        double x=(double)(tree[i].b-b)/(k-tree[i].k);
        if(x<=dis[w[mid]])
        {
            if(lp>lt) modify(i*2,tree[i].k,tree[i].b),tree[i].k=k,tree[i].b=b;
            else modify(i*2,k,b);
        }
        else 
        {
            if(lp>lt) modify(i*2+1,k,b);
            else modify(i*2+1,tree[i].k,tree[i].b),tree[i].k=k,tree[i].b=b;
        }
        tree[i].Min=min(tree[i].Min,min(f(dis[w[tree[i].l]],k,b),f(dis[w[tree[i].r]],k,b)));
        push_up(i);
        return;
    }
    void update(int i,int l,int r,long long k,long long b)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            modify(i,k,b);
            return;
        }
        if(l<=tree[i*2].r) update(i*2,l,r,k,b);
        if(r>=tree[i*2+1].l) update(i*2+1,l,r,k,b);
        push_up(i);
        return;
    }
    long long query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Min;
        long long res=min(f(dis[w[max(l,tree[i].l)]],tree[i].k,tree[i].b),f(dis[w[min(tree[i].r,r)]],tree[i].k,tree[i].b));
        if(tree[i].b==INF) res=INF;
        if(l<=tree[i*2].r) res=min(res,query(i*2,l,r));
        if(r>=tree[i*2+1].l) res=min(res,query(i*2+1,l,r));
        return res;
    }
}T;
int lca(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    return u;
}
long long query(int u,int v)
{
    long long res=INF;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=min(res,T.query(1,dfn[top[u]],dfn[u]));
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    res=min(res,T.query(1,dfn[u],dfn[v]));
    return res;
}
void update(int u,int v,long long k,long long b)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        T.update(1,dfn[top[u]],dfn[u],k,b);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    T.update(1,dfn[u],dfn[v],k,b);
    return;
}
void solve(int u,int v,long long a,long long b)
{
    int LCA=lca(u,v);
    update(u,LCA,-a,a*dis[u]+b);
    update(v,LCA,a,a*(dis[u]-2*dis[LCA])+b);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    dfs1(1,0);
    dfs2(1,1);
    T.build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op,s,t,a,b;
        scanf("%d%d%d",&op,&s,&t);
        if(op==1)
        {
            scanf("%d%d",&a,&b);
            solve(s,t,a,b);
        }
        else printf("%lld\n",query(s,t));
    }
    return 0;
}