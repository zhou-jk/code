#include<iostream>
#include<cstdio>
using namespace std;
const int N=20005;
const int INF=1001;
int n,Q;
int a[N],w[N];
struct Edge
{
    int to,val,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v,int w)
{
    edge[++cnt]=(Edge){v,w,head[u]};
    head[u]=cnt;
}
int fa[N],son[N],dep[N],size[N];
int dfn[N],top[N],Index;
void dfs1(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u]=father;
    size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        a[v]=edge[i].val;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
    }
    return;
}
void dfs2(int u,int father)
{
    dfn[u]=++Index;
    w[Index]=a[u];
    top[u]=father;
    if(!son[u]) return;
    dfs2(son[u],father);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
    return;
}
struct Node
{
    int l,r;
    int sum,Max,Min,lazy;
}tree[N<<2];
void push_up(int i)
{
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
    tree[i].Min=min(tree[i*2].Min,tree[i*2+1].Min);
    return;
}
void push_down(int i)
{
    if(tree[i].lazy==1) return;
    tree[i*2].lazy=-tree[i*2].lazy,tree[i*2+1].lazy=-tree[i*2+1].lazy;
    tree[i*2].sum=-tree[i*2].sum,tree[i*2+1].sum=-tree[i*2+1].sum;
    tree[i*2].Min=-tree[i*2].Min,tree[i*2].Max=-tree[i*2].Max;
    tree[i*2+1].Min=-tree[i*2+1].Min,tree[i*2+1].Max=-tree[i*2+1].Max;
    swap(tree[i*2].Min,tree[i*2].Max);
    swap(tree[i*2+1].Min,tree[i*2+1].Max);
    tree[i].lazy=1;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    tree[i].lazy=1;
    if(l==r)
    {
        tree[i].sum=tree[i].Max=tree[i].Min=w[l];
        return ;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void add(int i,int u,int val)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum=tree[i].Max=tree[i].Min=val;
        return ;
    }
    push_down(i);
    if(u<=tree[i*2].r) add(i*2,u,val);
    else add(i*2+1,u,val);
    push_up(i);
    return;
}
void update(int i,int l,int r)
{
	if(l>r) return;
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].lazy=-tree[i].lazy;
        tree[i].sum=-tree[i].sum;
        tree[i].Min=-tree[i].Min,tree[i].Max=-tree[i].Max;
        swap(tree[i].Min,tree[i].Max);
        return;
    }
    push_down(i);
    if(l<=tree[i*2].r) update(i*2,l,r);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r);
    push_up(i);
    return;
}
int querymin(int i,int l,int r)
{
	if(l>r) return INF;
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Min;
    push_down(i);
    int res=INF;
    if(l<=tree[i*2].r) res=min(res,querymin(i*2,l,r));
    if(r>=tree[i*2+1].l) res=min(res,querymin(i*2+1,l,r));
    return res;
}
int querymax(int i,int l,int r)
{
	if(l>r) return -INF;
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Max;
    push_down(i);
    int res=-INF;
    if(l<=tree[i*2].r) res=max(res,querymax(i*2,l,r));
    if(r>=tree[i*2+1].l) res=max(res,querymax(i*2+1,l,r));
    return res;
}
int querysum(int i,int l,int r)
{
	if(l>r) return 0;
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
    push_down(i);
    int res=0;
    if(l<=tree[i*2].r) res+=querysum(i*2,l,r);
    if(r>=tree[i*2+1].l) res+=querysum(i*2+1,l,r);
    return res;
}
void modify(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        update(1,dfn[top[u]],dfn[u]);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    update(1,dfn[u]+1,dfn[v]);
    return;
}
int asksum(int u,int v)
{
	int res=0;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res+=querysum(1,dfn[top[u]],dfn[u]);
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    res+=querysum(1,dfn[u]+1,dfn[v]);
    return res;
}
int askmin(int u,int v)
{
	int res=INF;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=min(res,querymin(1,dfn[top[u]],dfn[u]));
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    res=min(res,querymin(1,dfn[u]+1,dfn[v]));
    return res;
}
int askmax(int u,int v)
{
	int res=-INF;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=max(res,querymax(1,dfn[top[u]],dfn[u]));
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    res=max(res,querymax(1,dfn[u]+1,dfn[v]));
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x++,y++;
        add_edge(x,y,z);
        add_edge(y,x,z);
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,n);
    scanf("%d",&Q);
    while(Q--)
    {
        int u,v;
        string op;
        cin>>op;
        if(op=="C")
        {
            scanf("%d%d",&u,&v);
            u++;
            add(1,dfn[u],v);
        }
        if(op=="N")
        {
            scanf("%d%d",&u,&v);
            u++,v++;
            modify(u,v);
        }
        if(op=="SUM")
        {
            scanf("%d%d",&u,&v);
            u++,v++;
            printf("%d\n",asksum(u,v));
        }
        if(op=="MIN")
        {
            scanf("%d%d",&u,&v);
            u++,v++;
            printf("%d\n",askmin(u,v));
        }
        if(op=="MAX")
        {
            scanf("%d%d",&u,&v);
            u++,v++;
            printf("%d\n",askmax(u,v));
        }
    }
    return 0;
}