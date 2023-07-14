#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int INF=1061109567;
int n,m;
int a[N],b[N];
int ap[N],an[N],bp[N],bn[N];
struct Segment_Tree
{
	#define ls i*2
	#define rs i*2+1
	struct Node
	{
		int mn,mx;
	}tree[N<<2];
	void push_up(int i)
	{
		tree[i].mn=min(tree[ls].mn,tree[rs].mn);
		tree[i].mx=max(tree[ls].mx,tree[rs].mx);
		return;
	}
	void build(int i,int l,int r)
	{
		if(l==r)
		{
			tree[i].mn=INF,tree[i].mx=-INF;
			return;
		}
		int mid=(l+r)/2;
		build(ls,l,mid);
		build(rs,mid+1,r);
		push_up(i);
		return;
	}
	void modify(int i,int l,int r,int u,int val)
	{
		if(l==r)
		{
			tree[i].mn=tree[i].mx=val;
			return;
		}
		int mid=(l+r)/2;
		if(u<=mid) modify(ls,l,mid,u,val);
		else modify(rs,mid+1,r,u,val);
		push_up(i);
		return;
	}
	int querymin(int i,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return tree[i].mn;
		int mid=(l+r)/2;
		int res=INF;
		if(L<=mid) res=min(res,querymin(ls,l,mid,L,R));
		if(R>mid) res=min(res,querymin(rs,mid+1,r,L,R));
		return res;
	}
	int querymax(int i,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return tree[i].mx;
		int mid=(l+r)/2;
		int res=-INF;
		if(L<=mid) res=max(res,querymax(ls,l,mid,L,R));
		if(R>mid) res=max(res,querymax(rs,mid+1,r,L,R));
		return res;
	}
}Tap,Tan,Tbp,Tbn;
long long solve(int l1,int r1,int l2,int r2)
{
	int apos=ap[r1]-ap[l1-1],aneg=an[r1]-an[l1-1];
	int bpos=bp[r2]-bp[l2-1],bneg=bn[r2]-bn[l2-1];
	long long res;
	if(apos==r1-l1+1)
	{
		if(bpos==r2-l2+1) res=(long long)Tap.querymax(1,1,n,l1,r1)*Tbp.querymin(1,1,m,l2,r2);
		else if(bneg==r2-l2+1) res=(long long)Tap.querymin(1,1,n,l1,r1)*Tbn.querymin(1,1,m,l2,r2);
		else res=(long long)Tap.querymin(1,1,n,l1,r1)*Tbn.querymin(1,1,m,l2,r2);
	}
	else if(aneg==r1-l1+1)
	{
		if(bpos==r2-l2+1) res=(long long)Tan.querymax(1,1,n,l1,r1)*Tbp.querymax(1,1,m,l2,r2);
		else if(bneg==r2-l2+1) res=(long long)Tan.querymin(1,1,n,l1,r1)*Tbn.querymax(1,1,m,l2,r2);
		else res=(long long)Tan.querymax(1,1,n,l1,r1)*Tbp.querymax(1,1,m,l2,r2);
	}
	else
	{
		if(bpos==r2-l2+1) res=(long long)Tap.querymax(1,1,n,l1,r1)*Tbp.querymin(1,1,m,l2,r2);
		else if(bneg==r2-l2+1) res=(long long)Tan.querymin(1,1,n,l1,r1)*Tbn.querymax(1,1,m,l2,r2);
		else res=max((long long)Tan.querymax(1,1,n,l1,r1)*Tbp.querymax(1,1,m,l2,r2),(long long)Tap.querymin(1,1,n,l1,r1)*Tbn.querymin(1,1,m,l2,r2));
	}
	return res;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int Q;
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	Tap.build(1,1,n);
	Tan.build(1,1,n);
	Tbp.build(1,1,m);
	Tbn.build(1,1,m);
	for(int i=1;i<=n;i++)
	{
		ap[i]=ap[i-1],an[i]=an[i-1];
		if(a[i]>=0) Tap.modify(1,1,n,i,a[i]),ap[i]++;
		if(a[i]<=0) Tan.modify(1,1,n,i,a[i]),an[i]++;
	}
	for(int i=1;i<=m;i++)
	{
		bp[i]=bp[i-1],bn[i]=bn[i-1];
		if(b[i]>=0) Tbp.modify(1,1,m,i,b[i]),bp[i]++;
		if(b[i]<=0) Tbn.modify(1,1,m,i,b[i]),bn[i]++;
	}
	while(Q--)
	{
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		printf("%lld\n",solve(l1,r1,l2,r2));
	}
	return 0;
}