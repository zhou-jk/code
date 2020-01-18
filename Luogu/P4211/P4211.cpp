#include<iostream>
#include<cstdio>
using namespace std;
const int N=50005;
const int MOD=201314;
int n,q;
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
int fa[N],size[N],dep[N],son[N];
void dfs1(int u,int father)
{
	dep[u]=dep[father]+1;
	size[u]=1;
	fa[u]=father;
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
int top[N];
int dfn[N],Index;
void dfs2(int u,int father)
{
	dfn[u]=++Index;
	top[u]=father;
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
int rt[N],tot;
struct Chairman_Tree
{
	struct Node
	{
		int lc,rc;
		int lazy,sum;
	}tree[N*150];
	int modify(int i,int l,int r,int L,int R)
	{
		int u=++tot;
		tree[u]=tree[i];
		if(L<=l&&r<=R)
		{
			tree[u].lazy++;
			return u;
		}
		tree[u].sum+=R-L+1;
		int mid=(l+r)/2;
		if(R<=mid) tree[u].lc=modify(tree[i].lc,l,mid,L,R);
		else if(L>mid) tree[u].rc=modify(tree[i].rc,mid+1,r,L,R);
		else tree[u].lc=modify(tree[i].lc,l,mid,L,mid),tree[u].rc=modify(tree[i].rc,mid+1,r,mid+1,R);
		return u;
	}
	int query(int u,int l,int r,int L,int R)
	{
		if(!u) return 0;
		if(L<=l&&r<=R) return (tree[u].sum+(long long)tree[u].lazy*(R-L+1)%MOD)%MOD;
		int res=(long long)tree[u].lazy*(R-L+1)%MOD;
		int mid=(l+r)/2;
		if(R<=mid) return (res+query(tree[u].lc,l,mid,L,R))%MOD;
		else if(L>mid) return (res+query(tree[u].rc,mid+1,r,L,R))%MOD;
		else return (res+query(tree[u].lc,l,mid,L,mid)+query(tree[u].rc,mid+1,r,mid+1,R))%MOD;
	}
}T;
void modify(int root,int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		rt[root]=T.modify(rt[root],1,n,dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	rt[root]=T.modify(rt[root],1,n,dfn[u],dfn[v]);
	return;
}
int query(int root,int u,int v)
{
	int res=0;
	if(dep[u]<dep[v]) swap(u,v);
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		res=(res+T.query(root,1,n,dfn[top[u]],dfn[u]))%MOD;
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	res=(res+T.query(root,1,n,dfn[u],dfn[v]))%MOD;
	return res;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		x++;
		add_edge(x,i);
		add_edge(i,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		rt[i]=rt[i-1],modify(i,i,1);  
	while(q--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		l++,r++,k++;
		int ans=(query(rt[r],k,1)-query(rt[l-1],k,1)+MOD)%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
