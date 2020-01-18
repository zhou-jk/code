#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100000;
int n,q;
int dep[N+1],fa[N+1][17];
int res[N+1];
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
struct Node
{
    int lc,rc;
    int pos,sum;
}tree[N*60];
int rt[N+1],tot;
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u][0]=father;
    for(int i=1;(1<<i)<=n;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int query(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=log2(n);i>=0;i--)
    {
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
        if(u==v) return u;
    }
    for(int i=log2(n);i>=0;i--)
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
void push_up(int i)
{
    if(tree[tree[i].lc].sum>=tree[tree[i].rc].sum) tree[i].sum=tree[tree[i].lc].sum,tree[i].pos=tree[tree[i].lc].pos;
    else tree[i].sum=tree[tree[i].rc].sum,tree[i].pos=tree[tree[i].rc].pos;
    return;
}
void update(int &i,int l,int r,int u,int v)
{
    if(!i) i=++tot;
    if(l==r)
    {
        tree[i].sum+=v;
        tree[i].pos=l;
        return;
    }
    int mid=(l+r)/2;
    if(u<=mid) update(tree[i].lc,l,mid,u,v);
    else update(tree[i].rc,mid+1,r,u,v);
    push_up(i);
    return;
}
int merge(int u,int v,int l,int r)
{
    if(!u) return v;
    if(!v) return u;
    if(l==r)
    {
        tree[u].sum+=tree[v].sum;
        return u;
    }
    int mid=(l+r)/2;
    tree[u].lc=merge(tree[u].lc,tree[v].lc,l,mid);
    tree[u].rc=merge(tree[u].rc,tree[v].rc,mid+1,r);
    push_up(u);
    return u;
}
void Dfs(int u,int father)
{
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        Dfs(v,u);
        rt[u]=merge(rt[u],rt[v],1,N);
    }
    if(tree[rt[u]].sum>0) res[u]=tree[rt[u]].pos;
    return;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs(1,0);
    while(q--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int lca=query(x,y);
        update(rt[x],1,N,z,1);
        update(rt[y],1,N,z,1);
        update(rt[lca],1,N,z,-1);
        update(rt[fa[lca][0]],1,N,z,-1);
    }
    Dfs(1,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",res[i]);
    return 0;
}