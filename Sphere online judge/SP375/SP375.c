#include<stdio.h>
#include<string.h>
#define N 10005
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(A, B)   \
    {                \
        int __T = A; \
        A = B;       \
        B = __T;     \
    }
int T,n;
int a[N],w[N];
struct 
{
	int u,v,w;
}e[N];
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
void dfs1(int u,int father)
{
	fa[u]=father;
	dep[u]=dep[father]+1;
	size[u]=1;
	son[u]=0;
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
int top[N],dfn[N],Index;
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
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
	return;
}
struct Node
{
	int l,r;
	int Max;
}tree[N<<2];
void push_up(int i)
{
	tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
	return;
}
void build(int i,int l,int r)
{
	tree[i].l=l,tree[i].r=r;
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
void modify(int i,int u,int val)
{
	if(tree[i].l==tree[i].r)
	{
		tree[i].Max=val;
		return;
	}
	if(u<=tree[i*2].r) modify(i*2,u,val);
	else modify(i*2+1,u,val);
	push_up(i);
	return;
}
int query(int i,int l,int r)
{
	if(l>r) return 0;
	if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Max;
	int res=0;
	if(l<=tree[i*2].r) res=max(res,query(i*2,l,r));
	if(r>=tree[i*2+1].l) res=max(res,query(i*2+1,l,r));
	return res;
}
int getsum(int u,int v)
{
	int res=0;
	if(dep[u]<dep[v]) swap(u,v);
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		res=max(res,query(1,dfn[top[u]],dfn[u]));
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	res=max(res,query(1,dfn[u]+1,dfn[v]));
	return res;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		Index=cnt=0;
		memset(head,0,sizeof(head));
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			add_edge(e[i].u,e[i].v,e[i].w);
			add_edge(e[i].v,e[i].u,e[i].w);
		}
		dfs1(1,0);
		dfs2(1,1);
		build(1,1,n);
		while(1)
		{
			char s[10];
			scanf("%s",s+1);
			if(s[1]=='D') break;
			int x,y;
			scanf("%d%d",&x,&y);
			if(s[1]=='C')
			{
				int u=e[x].u,v=e[x].v;
				if(dep[u]<dep[v]) swap(u,v);
				modify(1,dfn[u],y);
			}
			else if(s[1]=='Q') printf("%d\n",getsum(x,y));
		}
	}
	return 0;
}
