#include<iostream>
#include<cstdio>
using namespace std;
const int N=500001;
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
int fa[N],dep[N],dfn[N],w[N],Index,top[N],son[N],size[N];
void init(int u,int father)
{
    fa[u]=father;
    dep[u]=dep[father]+1;
	size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        init(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v; 
    }
	return;
}
void dfs(int u,int father)
{
    top[u]=father;
	dfn[u]=++Index;
	w[Index]=u;
	if(!son[u]) return;
    dfs(son[u],father);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs(v,v);
    }
	return;
}
struct Node
{
    int l,r;
    int sum,lazy;
}tree[N<<2];
void push_up(int i)
{
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
	return;
}
void push_down(int i)
{
	if(tree[i].lazy==-1) return;
	tree[i*2].lazy=tree[i*2+1].lazy=tree[i].lazy;
	if(tree[i].lazy)
	{
		tree[i*2].sum=(tree[i*2].r-tree[i*2].l+1);
		tree[i*2+1].sum=(tree[i*2+1].r-tree[i*2+1].l+1);
	}
	else tree[i*2].sum=tree[i*2+1].sum=0;
	tree[i].lazy=-1;
	return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r,tree[i].lazy=-1;
	if(l==r) return;
	int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
	return;
}
void update(int i,int l,int r,int u)
{
    if(l>r) return;
	if(l<=tree[i].l&&tree[i].r<=r)
	{
		tree[i].lazy=u;
		if(u) tree[i].sum=tree[i].r-tree[i].l+1;
		else tree[i].sum=0;
		return;
	}
	push_down(i);
	if(l<=tree[i*2].r) update(i*2,l,r,u);
	if(r>=tree[i*2+1].l) update(i*2+1,l,r,u);
	push_up(i);
	return;
}
int lca(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
	if(dep[u]<dep[v]) return u;
	else return v;
}
int query(int u,int v)
{
    while(dep[u]-dep[top[u]]<v)
    {
        v-=dep[u]-dep[top[u]]+1;
        u=fa[top[u]];
    }
    return w[dfn[u]-v];
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
    init(1,0);
    dfs(1,1);
	build(1,1,n);
    for(int i=1;i<=m;i++)
    {
		int k,rt;
        scanf("%d%d",&k,&rt);
        update(1,1,n,1);
        for(int i=2;i<=k;i++)
        {
			int u;
            scanf("%d",&u);
            int t=lca(rt,u);
            int l=dep[rt]-dep[t]+1,r=dep[u]-dep[t]+1;
            int dis=l+r-1,mid=dis/2;
            if(mid<r)
            {
                int v=query(u,mid-1);
                update(1,dfn[v],dfn[v]+size[v]-1,0);
            }
            else
            {
                int v=query(rt,dis-mid-1);
                update(1,1,dfn[v]-1,0);
                update(1,dfn[v]+size[v],n,0);
            }
        }
        printf("%d\n",tree[1].sum);
    }
    return 0;
}