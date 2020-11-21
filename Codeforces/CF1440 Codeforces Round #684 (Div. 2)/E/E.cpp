#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,Q;
int a[N];
struct Node
{
	int l,r;
	int tag;
	int Min,Max;
	long long sum;
}tree[N<<2];
void push_up(int i)
{
	tree[i].Min=min(tree[i*2].Min,tree[i*2+1].Min);
	tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
	tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
	return;
}
void build(int i,int l,int r)
{
	tree[i].l=l,tree[i].r=r;
	if(l==r)
	{
		tree[i].Min=tree[i].Max=a[l];
		tree[i].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	push_up(i);
	return;
}
void add(int i,int y)
{
	tree[i].Min=tree[i].Max=y;
	tree[i].tag=y;
	tree[i].sum=1LL*(tree[i].r-tree[i].l+1)*y;
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
void modify(int i,int l,int r,int y)
{
	if(tree[i].Min>=y) return;
	if(l<=tree[i].l&&tree[i].r<=r&&tree[i].Max<=y) return add(i,y);
	push_down(i);
	if(l<=tree[i*2].r) modify(i*2,l,r,y);
	if(r>=tree[i*2+1].l) modify(i*2+1,l,r,y);
	push_up(i);
	return;
}
int query(int i,int l,int r,int &y)
{
	if(tree[i].Min>y) return 0;
	if(l<=tree[i].l&&tree[i].r<=r&&tree[i].sum<=y)
	{
		y-=tree[i].sum;
		return tree[i].r-tree[i].l+1;
	}
	if(tree[i].l==tree[i].r) return 0;
	push_down(i);
	int res=0;
	if(l<=tree[i*2].r) res+=query(i*2,l,r,y);
	if(r>=tree[i*2+1].l) res+=query(i*2+1,l,r,y);
	return res;
}
int main()
{
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	while(Q--)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1) modify(1,1,x,y);
		else printf("%d\n",query(1,x,n,y));
	}
	return 0;
}
