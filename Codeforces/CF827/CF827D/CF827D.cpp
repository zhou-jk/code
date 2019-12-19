#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200001;
const int INF=1061109567;
int n,m;
struct Edge
{
	int to,val,id,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v,int w,int id)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].val=w;
    edge[cnt].id=id;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
struct Line
{
    int u,v,w;
    int id;
    bool flag;
}e[N<<1];
bool cmp(Line x,Line y)
{
    return x.w<y.w;
}
struct Node
{
	int l,r;
    int Max,Min,lazy;
}tree[N<<2];
int pre[N],a[N],w[N];
int ans[N];
int f[N];
int getf(int v)
{
    if(v==f[v]) return v;
    f[v]=getf(f[v]);
    return f[v];
}
bool merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2)
    {
        f[f2]=f1;
        return true;
    }
    return false;
}
void kruskal()
{
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
        if(merge(e[i].u,e[i].v))
		{
			e[i].flag=true;
			add_edge(e[i].u,e[i].v,e[i].w,e[i].id);
			add_edge(e[i].v,e[i].u,e[i].w,e[i].id);
		}
    return;
}
int fa[N],dep[N],size[N],son[N];
void dfs1(int u,int father)
{
	size[u]=1;
    fa[u]=father;
    dep[u]=dep[father]+1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        pre[v]=edge[i].id;
        a[v]=edge[i].val;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
    }
    return;
}
int top[N],dfn[N],Index;
void dfs2(int u,int father)
{
    dfn[u]=++Index;
    top[u]=father;
    w[Index]=a[u];
    if(!son[u]) return;
    dfs2(son[u],father);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==son[u]||v==fa[u]) continue;
        dfs2(v,v);
    }
    return;
}
void push_up(int i)
{
	tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
	tree[i].Min=min(tree[i*2].Min,tree[i*2+1].Min);
    return;
}
void push_down(int i)
{
    if(tree[i].lazy>=INF) return;
    tree[i*2].Min=min(tree[i*2].Min,tree[i].lazy);
    tree[i*2].lazy=min(tree[i*2].lazy,tree[i].lazy);
    tree[i*2+1].Min=min(tree[i*2+1].Min,tree[i].lazy);
    tree[i*2+1].lazy=min(tree[i*2+1].lazy,tree[i].lazy);
	tree[i].lazy=INF;
    return;
}
void build(int i,int l,int r)
{
	tree[i].l=l,tree[i].r=r;
    tree[i].Min=tree[i].lazy=INF;
	if(l==r)
    {
        tree[i].Max=w[l];
        return;
    }
	int mid=(l+r)/2;
	build(i*2,l,mid);
    build(i*2+1,mid+1,r);
	push_up(i);
    return;
}
void update(int i,int l,int r,int val)
{
    if(r<tree[i].l||l>tree[i].r) return;
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].Min=min(tree[i].Min,val);
        tree[i].lazy=min(tree[i].lazy,val);
		return;
	}
	push_down(i);
    if(l<=tree[i*2].r) update(i*2,l,r,val);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r,val);
	push_up(i);
    return;
}
int querymax(int i,int l,int r)
{
	if(r<tree[i].l||l>tree[i].r) return 0;
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Max;
	push_down(i);
    int res=0;
    if(l<=tree[i*2].r) res=max(res,querymax(i*2,l,r));
    if(r>=tree[i*2+1].l) res=max(res,querymax(i*2+1,l,r));
    return res;
}
int querymin(int i,int u)
{
	if(tree[i].l==tree[i].r) return tree[i].Min;
	push_down(i);
	if(u<=tree[i*2].r) return querymin(i*2,u);
    else return querymin(i*2+1,u);
}
int getmax(int u,int v)
{
	int res=0;
    if(dep[u]<dep[v]) swap(u,v);
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
void modifymin(int u,int v,int val)
{
    if(dep[u]<dep[v]) swap(u,v);
	while(top[u]!=top[v])
    {
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		update(1,dfn[top[u]],dfn[u],val);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	update(1,dfn[u]+1,dfn[v],val);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        e[i].id=i;
    }
    sort(e+1,e+m+1,cmp);
	kruskal();
	dfs1(1,0);
    dfs2(1,1);
	build(1,1,n);
    for(int i=1;i<=m;i++)
		if(!e[i].flag)
        {
			ans[e[i].id]=getmax(e[i].u,e[i].v)-1;
			modifymin(e[i].u,e[i].v,e[i].w);
		}
    for(int i=2;i<=n;i++)
    {
        int res=querymin(1,dfn[i]);
        if(res>=INF) ans[pre[i]]=-1;
        else ans[pre[i]]=res-1;
    }
    for(int i=1;i<=m;i++)
        printf("%d ",ans[i]);
	return 0;
}