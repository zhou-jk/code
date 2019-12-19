#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int N=100001;
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
int f[N][18],dep[N];
int dfn[N],w[N],Index;
void init(int u,int father)
{
	dfn[u]=++Index;
	w[Index]=u;
	f[u][0]=father;
	dep[u]=dep[father]+1;
	for(int i=1;(1<<i)<=n;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father) continue;
		init(v,u);
	}
	return;
}
int query(int u,int v)
{
	if(!u) return v;
	if(!v) return u;
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=log2(n);i>=0;i--)
	{
		if(dep[f[u][i]]>=dep[v]) u=f[u][i];
		if(u==v) return u;
	}
	for(int i=log2(n);i>=0;i--)
		if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}
struct Node
{
	int lc,rc,dn,sum,ld,rd,num;
}tree[N*40];
int rt[N],tot;
vector<int>ad[N],del[N];
void push_up(int i)
{
	if(!tree[tree[i].lc].num)
	{
		tree[i].dn=tree[tree[i].rc].dn;
		tree[i].sum=tree[tree[i].rc].sum;
		tree[i].ld=tree[tree[i].rc].ld;
		tree[i].rd=tree[tree[i].rc].rd;
		tree[i].num=tree[tree[i].rc].num;
		return;
	}
	if(!tree[tree[i].rc].num)
	{
		tree[i].dn=tree[tree[i].lc].dn;
		tree[i].sum=tree[tree[i].lc].sum;
		tree[i].ld=tree[tree[i].lc].ld;
		tree[i].rd=tree[tree[i].lc].rd;
		tree[i].num=tree[tree[i].lc].num;
		return;
	}
	tree[i].dn=query(tree[tree[i].lc].dn,tree[tree[i].rc].dn);
	tree[i].sum=tree[tree[i].lc].sum+tree[tree[i].rc].sum+dep[tree[tree[i].lc].dn]+dep[tree[tree[i].rc].dn]-2*dep[tree[i].dn]-(dep[query(tree[tree[i].lc].rd,tree[tree[i].rc].ld)]-dep[tree[i].dn])-1;
	tree[i].ld=tree[tree[i].lc].ld;
	tree[i].rd=tree[tree[i].rc].rd;
	tree[i].num=tree[tree[i].lc].num+tree[tree[i].rc].num;
	return;
}
int merge(int u,int v,int l,int r)
{
	if(!u) return v;
	if(!v) return u;
	if(l==r)
	{
		tree[u].num+=tree[v].num;
		return u;
	}
	int mid=(l+r)/2;
	tree[u].lc=merge(tree[u].lc,tree[v].lc,l,mid);
	tree[u].rc=merge(tree[u].rc,tree[v].rc,mid+1,r);
	push_up(u);
	return u;
}
void update(int &i,int l,int r,int u,int v)
{
	if(!i) i=++tot;
	if(l==r)
	{
		tree[i].num+=v;
		if(!tree[i].num) return;
		tree[i].dn=tree[i].ld=tree[i].rd=w[l];
		tree[i].sum=1;
		return;
	}
	int mid=(l+r)/2;
	if(u<=mid) update(tree[i].lc,l,mid,u,v);
	else update(tree[i].rc,mid+1,r,u,v);
	push_up(i);
	return;
}
long long ans;
void dfs(int u,int father)
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father) continue;
		dfs(v,u);
		rt[u]=merge(rt[u],rt[v],1,n);
	}
	for(auto v:ad[u])
		update(rt[u],1,n,v,1);
	if(tree[rt[u]].num) ans+=tree[rt[u]].sum-1;
	for(auto v:del[u])
		update(rt[u],1,n,v,-2);
	return;
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
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int lca=query(x,y);
		ad[x].push_back(dfn[x]),ad[x].push_back(dfn[y]);
		ad[y].push_back(dfn[x]),ad[y].push_back(dfn[y]);
		del[lca].push_back(dfn[x]),del[lca].push_back(dfn[y]);
	}
	dfs(1,0);
	printf("%lld",ans/2);
	return 0;
}