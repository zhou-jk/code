#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,Q;
long long a[N];
long long s[N];
struct Node
{
	int l,r;
	long long Max,tag;
}tree[N<<2];
void push_up(int i)
{
	tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
	return;
}
void add(int i,long long v)
{
	tree[i].Max+=v;
	tree[i].tag+=v;
	return;
}
void push_down(int i)
{
	if(!tree[i].tag) return;
	add(i*2,tree[i].tag);
	add(i*2+1,tree[i].tag);
	tree[i].tag=0;
	return;
}
void build(int i,int l,int r)
{
	tree[i].l=l,tree[i].r=r;
	if(l==r)
	{
		tree[i].Max=a[l]-s[l-1];
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	push_up(i);
	return;
}
void modify(int i,int l,int r,long long v)
{
	if(l>r) return;
	if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
	push_down(i);
	if(l<=tree[i*2].r) modify(i*2,l,r,v);
	if(r>=tree[i*2+1].l) modify(i*2+1,l,r,v);
	push_up(i);
	return;
}
void query(int i,int &res)
{
	if(res!=-1) return;
	if(tree[i].Max<0) return;
	if(tree[i].l==tree[i].r)
	{
		if(tree[i].Max==0) res=tree[i].l;
		return;
	}
	push_down(i);
	query(i*2,res);
	query(i*2+1,res);
	return;
}
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	build(1,1,n);
	while(Q--)
	{
		int p,x;
		scanf("%d%d",&p,&x);
		modify(1,p+1,n,a[p]-x);
		modify(1,p,p,x-a[p]);
		a[p]=x;
		int ans=-1;
		query(1,ans);
		printf("%d\n",ans);
	}
	return 0;
}
