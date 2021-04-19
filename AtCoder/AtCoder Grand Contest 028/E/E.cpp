#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n;
int p[N];
int a[N];
int suf[N];
int f[N][2];
char s[N];
struct Segment_Tree
{
	struct Node
	{
		int l,r;
		int mx;
	}tree[N<<2];
	void push_up(int i)
	{
		tree[i].mx=max(tree[i*2].mx,tree[i*2+1].mx);
		return;
	}
	void build(int i,int l,int r)
	{
		tree[i].l=l,tree[i].r=r;
		if(l==r)
		{
			tree[i].mx=-INF;
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
			tree[i].mx=v;
			return;
		}
		if(u<=tree[i*2].r) modify(i*2,u,v);
		else modify(i*2+1,u,v);
		push_up(i);
		return;
	}
	int query(int i,int l,int r)
	{
		if(l>r) return -INF;
		if(l<=tree[i].l&&tree[i].r<=r) return tree[i].mx;
		int res=-INF;
		if(l<=tree[i*2].r) res=max(res,query(i*2,l,r));
		if(r>=tree[i*2+1].l) res=max(res,query(i*2+1,l,r));
		return res;
	}
}T[2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	int mx=0;
	for(int i=1;i<=n;i++)
		if(p[i]>mx) a[i]=2,mx=p[i];
		else a[i]=1;
	T[0].build(1,1,n);
	T[1].build(1,1,n);
	for(int i=1;i<=n;i++)
		f[i][a[i]%2]=a[i],f[i][(a[i]%2)^1]=-INF;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<2;j++)
			f[i][j]=max(f[i][j],T[(j-a[i]+2)%2].query(1,p[i]+1,n)+a[i]);
		for(int j=0;j<2;j++)
			T[j].modify(1,p[i],f[i][j]);
	}
	for(int i=n;i>=1;i--)
		suf[i]=suf[i+1]+(a[i]==2);
	int cnta=0,cntb=0;
	int mxa=0,mxb=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<2;j++)
			T[j].modify(1,p[i],-INF);
		auto check=[=](int ca,int cb,int ma,int mb)
		{
			int v=ca-cb+suf[i+1];
			if(v<0) return false;
			int mx=T[v%2].query(1,mb+1,n);
			if(v%2==0) mx=max(mx,0);
			return mx>=v;
		};
		if(check(cnta,cntb+(p[i]>mxb),mxa,max(mxb,p[i]))||check(cntb+(p[i]>mxb),cnta,max(mxb,p[i]),mxa)) s[i]='0',cntb+=(p[i]>mxb),mxb=max(mxb,p[i]);
		else if(check(cnta+(p[i]>mxa),cntb,max(mxa,p[i]),mxb)||check(cntb,cnta+(p[i]>mxa),mxb,max(mxa,p[i]))) s[i]='1',cnta+=(p[i]>mxa),mxa=max(mxa,p[i]);
		else
		{
			printf("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		printf("%c",s[i]);
	return 0;
}