#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N=1000001;
int n,m,r;
int a[N];
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
struct Binary_Indexed_Tree
{
    long long C[N];
    Binary_Indexed_Tree()
    {
        memset(C,0,sizeof(C));
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,long long y)
    {
        if(x==0) return;
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    long long query(int x)
    {
        long long ans=0;
        for(int i=x;i>0;i-=lowbit(i))
            ans+=C[i];
        return ans;
    }
}tree[2];
int dfn[N],Index;
int size[N];
int son[N],top[N],fa[N],dep[N];
void dfs1(int u,int father)
{
    fa[u]=father;
    dep[u]=dep[father]+1;
    size[u]=1;
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
void dfs2(int u,int father)
{
    top[u]=father;
    dfn[u]=++Index;
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
int LCA(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    return u;
}
void update(int u,int v,long long val)
{
    int lca=LCA(u,v);
    tree[0].add(dfn[u],val),tree[0].add(dfn[v],val);
    tree[0].add(dfn[lca],-val),tree[0].add(dfn[fa[lca]],-val);
    tree[1].add(dfn[u],val*dep[u]),tree[1].add(dfn[v],val*dep[v]);
    tree[1].add(dfn[lca],-val*dep[lca]),tree[1].add(dfn[fa[lca]],-val*dep[fa[lca]]);
    return;
}
void update(int i,long long val)
{
    tree[0].add(dfn[i],val),tree[0].add(dfn[fa[i]],-val);
    tree[1].add(dfn[i],val*dep[i]),tree[1].add(dfn[fa[i]],-val*dep[fa[i]]);
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs1(r,0);
    dfs2(r,r);
    for(int i=1;i<=n;i++)
        update(i,a[i]);
    while(m--)
    {
        int op,a,b,x;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d%d",&a,&b,&x);
            update(a,b,x);
        }
        else if(op==2)
        {
            scanf("%d",&x);
            printf("%lld\n",tree[0].query(dfn[x]+size[x]-1)-tree[0].query(dfn[x]-1));
        }
        else if(op==3)
        {
            scanf("%d",&x);
            printf("%lld\n",tree[1].query(dfn[x]+size[x]-1)-tree[1].query(dfn[x]-1)-(tree[0].query(dfn[x]+size[x]-1)-tree[0].query(dfn[x]-1))*(dep[x]-1));
        }
    }
    return 0;
}