#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=80005;
int n,m,Q;
int a[N];
int b[N<<1],num;
struct Ask
{
	int k,a,b;
}ask[N];
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
int dep[N];
int dfn[N],Index;
int fa[N][18],size[N],rt[N];
int lowbit(int x)
{
	return x&-x;
}
struct Node
{
	int sum;
	int lc,rc;
}tree[N*256];
int tot;
void update(int &i,int l,int r,int pos,int v)
{
	if(!i) i=++tot;
	tree[i].sum+=v;
	if(l==r) return;
	int mid=(l+r)/2;
	if(pos<=mid) update(tree[i].lc,l,mid,pos,v);
	else update(tree[i].rc,mid+1,r,pos,v);
	return;
}
int query(int *u,int c1,int *v,int c2,int l,int r,int k)
{
	if(l==r) return l;
	int sum=0;
	for(int i=1;i<=c1;i++)
		sum+=tree[tree[u[i]].lc].sum;
	for(int i=1;i<=c2;i++)
		sum-=tree[tree[v[i]].lc].sum;
	int mid=(l+r)/2;
	if(k<=sum)
	{
		for(int i=1;i<=c1;i++)
			u[i]=tree[u[i]].lc;
		for(int i=1;i<=c2;i++)
			v[i]=tree[v[i]].lc;
		return query(u,c1,v,c2,l,mid,k);
	}
	else
	{
		for(int i=1;i<=c1;i++)
			u[i]=tree[u[i]].rc;
		for(int i=1;i<=c2;i++)
			v[i]=tree[v[i]].rc;
		return query(u,c1,v,c2,mid+1,r,k-sum);
	}
}
void dfs(int u,int father)
{
	fa[u][0]=father;
	dep[u]=dep[father]+1;
	dfn[u]=++Index;
	size[u]=1;
	for(int i=1;(1<<i)<=n;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==father) continue;
		dfs(v,u);
		size[u]+=size[v];
	}
	return;
}
int querylca(int u,int v)
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
void modify(int x,int y)
{
	for(int j=dfn[x];j<=n;j+=lowbit(j))
		update(rt[j],1,num,a[x],-1);
	for(int j=dfn[x]+size[x];j<=n;j+=lowbit(j))
		update(rt[j],1,num,a[x],1);
	a[x]=lower_bound(b+1,b+num+1,y)-b;
	for(int j=dfn[x];j<=n;j+=lowbit(j))
		update(rt[j],1,num,a[x],1);
	for(int j=dfn[x]+size[x];j<=n;j+=lowbit(j))
		update(rt[j],1,num,a[x],-1);
	return;
}
int getsum(int x,int y,int k)
{
	static int X[N],Y[N];
	int C1=0,C2=0;
	int lca=querylca(x,y),len=dep[x]+dep[y]-dep[lca]-dep[fa[lca][0]];
	for(int j=dfn[x];j>0;j-=lowbit(j))
		X[++C1]=rt[j];
	for(int j=dfn[y];j>0;j-=lowbit(j))
		X[++C1]=rt[j];
	for(int j=dfn[lca];j>0;j-=lowbit(j))
		Y[++C2]=rt[j];
	for(int j=dfn[fa[lca][0]];j>0;j-=lowbit(j))
		Y[++C2]=rt[j];
	if(k>len) return -1;
	else return b[query(X,C1,Y,C2,1,num,len-k+1)];
}
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[++num]=a[i];
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	for(int i=1;i<=Q;i++)
	{
		scanf("%d%d%d",&ask[i].k,&ask[i].a,&ask[i].b);
		if(!ask[i].k) b[++num]=ask[i].b;
	}
	sort(b+1,b+1+num);
	num=unique(b+1,b+1+num)-b-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+num+1,a[i])-b;
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=dfn[i];j<=n;j+=lowbit(j))
			update(rt[j],1,num,a[i],1);
		for(int j=dfn[i]+size[i];j<=n;j+=lowbit(j))
			update(rt[j],1,num,a[i],-1);
	}
	for(int i=1;i<=Q;i++)
		if(ask[i].k)
		{
			int res=getsum(ask[i].a,ask[i].b,ask[i].k);
			if(res==-1) printf("invalid request!\n");
			else printf("%d\n",res);
		}
		else modify(ask[i].a,ask[i].b);
	return 0;
}
