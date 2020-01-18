#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100001;
const long long INF=4557430888798830399;
int n,m;
struct Edge
{
    int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dep[N],fa[N],f[N][17],son[N],size[N];
long long a[N],w[N];
void dfs1(int u,int father)
{
    size[u]=1;
    dep[u]=dep[father]+1;
    fa[u]=father;
    f[u][0]=father;
    for(int i=1;(1<<i)<=n;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
    }
    return;
}
int top[N],Index,dfn[N];
void dfs2(int u,int father)
{
    top[u]=father;
    dfn[u]=++Index;
    w[Index]=a[u];
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
struct Node
{
    int l,r;
    long long Min,lazy;
}tree[N<<2];
void push_up(int i)
{
    tree[i].Min=min(tree[i*2].Min,tree[i*2+1].Min);
    return;
}
void push_down(int i)
{
    if(!tree[i].lazy) return;
    tree[i*2].Min=tree[i*2].lazy=tree[i].lazy;
    tree[i*2+1].Min=tree[i*2+1].lazy=tree[i].lazy;
    tree[i].lazy=0;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    tree[i].lazy=0;
    if(l==r)
    {
        tree[i].Min=w[l];
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update(int i,int l,int r,long long val)
{
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].Min=tree[i].lazy=val;
        return;
    }
    push_down(i);
    if(l<=tree[i*2].r) update(i*2,l,r,val);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r,val);
    push_up(i);
    return;
}
long long query(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Min;
    push_down(i);
    long long res=INF;
    if(l<=tree[i*2].r) res=min(res,query(i*2,l,r));
    if(r>=tree[i*2+1].l) res=min(res,query(i*2+1,l,r));
    return res;
}
int root;
void modify(int u,int v,long long val)
{
    if(dep[u]<dep[v]) swap(u,v);
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        update(1,dfn[top[u]],dfn[u],val);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    update(1,dfn[u],dfn[v],val);
    return;
}
int getfa(int u,int k)
{
    for(int i=log2(n);i>=0;i--)
        if(k&(1<<i)) u=f[u][i];
    return u;
}
long long getmin(int u)
{
    if(u==root) return query(1,1,n);
    else if(dep[u]<dep[root])
    {
        int v=getfa(root,dep[root]-dep[u]-1);
        if(fa[v]!=u) return query(1,dfn[u],dfn[u]+size[u]-1);
        else if(dfn[v]+size[v]<=n) return min(query(1,1,dfn[v]-1),query(1,dfn[v]+size[v],n));
        else return query(1,1,dfn[v]-1);
    }
    else return query(1,dfn[u],dfn[u]+size[u]-1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    dfs1(1,0);
    dfs2(1,1);
    scanf("%d",&root);
    build(1,1,n);
    while(m--)
    {
        int op;
        scanf("%d",&op);
        if(op==1) scanf("%d",&root);
        else if(op==2)
        {
            int x,y;
            long long k;
            scanf("%d%d%lld",&x,&y,&k);
            modify(x,y,k);
        }
        else if(op==3)
        {
            int x;
            scanf("%d",&x);
            printf("%lld\n",getmin(x));
        }
    }
    return 0;
}