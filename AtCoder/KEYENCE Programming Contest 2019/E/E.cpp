#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N=200005;
const long long INF=4557430888798830399;
int n,d;
long long a[N];
int fa[N];
int getf(int v)
{
	if(v==fa[v]) return v;
	fa[v]=getf(fa[v]);
	return fa[v];
}
bool merge(int u,int v)
{
	int f1=getf(u),f2=getf(v);
	if(f1!=f2)
	{
		fa[f2]=f1;
		return true;
	}
	else return false;
}
long long f(int j)
{
	return -1LL*j*d+a[j];
}
long long g(int j)
{
	return 1LL*j*d+a[j];
}
long long dis(int i,int j)
{
	return 1LL*abs(i-j)*d+a[i]+a[j];
}
struct Segment_Treef
{
	int Min(int x,int y)
	{
		return f(x)<f(y)?x:y;
	}
	struct Node
	{
		int l,r;
		int val;
	}tree[N<<2];
	void push_up(int i)
	{
		tree[i].val=Min(tree[i*2].val,tree[i*2+1].val);
		return;
	}
	void build(int i,int l,int r)
	{
		tree[i].l=l,tree[i].r=r;
		if(l==r)
		{
			tree[i].val=0;
			return;
		}
		int mid=(l+r)/2;
		build(i*2,l,mid);
		build(i*2+1,mid+1,r);
		push_up(i);
		return;
	}
	void modify(int i,int u,int v)
	{
		if(tree[i].l==tree[i].r)
		{
			tree[i].val=Min(tree[i].val,v);
			return;
		}
		if(u<=tree[i*2].r) modify(i*2,u,v);
		else modify(i*2+1,u,v);
		push_up(i);
		return;
	}
	int query(int i,int l,int r)
	{
		if(l>r) return 0;
		if(l<=tree[i].l&&tree[i].r<=r) return tree[i].val;
		int res=0;
		if(l<=tree[i*2].r) res=Min(res,query(i*2,l,r));
		if(r>=tree[i*2+1].l) res=Min(res,query(i*2+1,l,r));
		return res;
	}
}T1;
struct Segment_Treeg
{
	int Min(int x,int y)
	{
		return g(x)<g(y)?x:y;
	}
	struct Node
	{
		int l,r;
		int val;
	}tree[N<<2];
	void push_up(int i)
	{
		tree[i].val=Min(tree[i*2].val,tree[i*2+1].val);
		return;
	}
	void build(int i,int l,int r)
	{
		tree[i].l=l,tree[i].r=r;
		if(l==r)
		{
			tree[i].val=0;
			return;
		}
		int mid=(l+r)/2;
		build(i*2,l,mid);
		build(i*2+1,mid+1,r);
		push_up(i);
		return;
	}
	void modify(int i,int u,int v)
	{
		if(tree[i].l==tree[i].r)
		{
			tree[i].val=Min(tree[i].val,v);
			return;
		}
		if(u<=tree[i*2].r) modify(i*2,u,v);
		else modify(i*2+1,u,v);
		push_up(i);
		return;
	}
	int query(int i,int l,int r)
	{
		if(l>r) return 0;
		if(l<=tree[i].l&&tree[i].r<=r) return tree[i].val;
		int res=0;
		if(l<=tree[i*2].r) res=Min(res,query(i*2,l,r));
		if(r>=tree[i*2+1].l) res=Min(res,query(i*2+1,l,r));
		return res;
	}
}T2;
long long ans;
int to[N];
int x[N],y[N];
int solve()
{
	memset(to,0,sizeof(to));
	T1.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int u=getf(i);
		int x=T1.Min(T1.query(1,1,u-1),T1.query(1,u+1,n));
		if(!to[i]||dis(i,x)<dis(i,to[i])) to[i]=x;
		T1.modify(1,u,i);
	}
	T2.build(1,1,n);
	for(int i=n;i>=1;i--)
	{
		int u=getf(i);
		int x=T2.Min(T2.query(1,1,u-1),T2.query(1,u+1,n));
		if(!to[i]||dis(i,x)<dis(i,to[i])) to[i]=x;
		T2.modify(1,u,i);
	}
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	for(int i=1;i<=n;i++)
	{
		int u=getf(i);
		if(!x[u]||!y[u]||dis(i,to[i])<dis(x[u],y[u])) x[u]=i,y[u]=to[i];
	}
	int num=0;
	for(int u=1;u<=n;u++)
		if(getf(u)==u)
		{
			long long w=dis(x[u],y[u]);
			if(merge(x[u],y[u])) num++,ans+=w;
		}
	return num;
}
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	a[0]=INF;
	int tot=n;
	while(tot>1)
		tot-=solve();
	printf("%lld",ans);
	return 0;
}
