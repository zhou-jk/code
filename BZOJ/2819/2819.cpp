#include<iostream>
#include<cstdio>
using namespace std;
const int N=500005;
int n,Q;
int a[N],w[N];
inline char gc()
{
	static const int SIZE=1<<23;
	static char buf[SIZE],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc
template<typename T>
inline T read(T &x)
{
	x=0;
	char ch;
	bool flag=false;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar())
		if(ch=='-') flag=true;
	while(ch>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	if(flag) x=-x;
	return x;
}
template<typename T>
inline void write(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
template<typename T>
inline void writeln(T x)
{
	write(x);
	putchar('\n');
	return;
}
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
	int l,r,sum;
}tree[N<<2];
void push_up(int i)
{
	tree[i].sum=tree[i*2].sum^tree[i*2+1].sum;
	return;
}
void build(int i,int l,int r)
{
	tree[i].l=l,tree[i].r=r;
	tree[i].sum=0;
	if(l==r)
	{
		tree[i].sum=w[l];
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	push_up(i);
	return;
}
void update(int i,int u,int val)
{
	if(tree[i].l==tree[i].r)
	{
		tree[i].sum=val;
		return;
	}
	if(u<=tree[i*2].r) update(i*2,u,val);
	else update(i*2+1,u,val);
	push_up(i);
	return;
}
int query(int i,int l,int r)
{
	if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
	int res=0;
	if(l<=tree[i*2].r) res^=query(i*2,l,r);
	if(r>=tree[i*2+1].l) res^=query(i*2+1,l,r);
	return res;
}
int fa[N],son[N],dep[N],size[N];
void dfs1(int u,int father)
{
	dep[u]=dep[father]+1;
	fa[u]=father;
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
int dfn[N],Index,top[N];
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
int getxor(int u,int v)
{
	int res=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		res^=query(1,dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	res^=query(1,dfn[u],dfn[v]);
	return res;
}
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		add_edge(x,y);
		add_edge(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,Index);
	read(Q);
	while(Q--)
	{
		int x,y;
		char ch;
		for(ch=getchar();ch!='Q'&&ch!='C';ch=getchar());
		read(x),read(y);
		if(ch=='Q')
		{
			if(getxor(x,y)!=0) printf("Yes\n");
			else printf("No\n");
		}
		else if(ch=='C') update(1,dfn[x],y);
	}
	return 0;
}
