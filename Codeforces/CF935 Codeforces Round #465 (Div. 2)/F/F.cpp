#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100005;
int n,Q;
int a[N];
long long c[N];
struct Node
{
	int l,r;
	long long Min;
}tree[N<<2];
void push_up(int i)
{
	tree[i].Min=min(tree[i*2].Min,tree[i*2+1].Min);
	return;
}
void build(int i,int l,int r)
{
	tree[i].l=l,tree[i].r=r;
	if(l==r)
	{
		tree[i].Min=max(0LL,c[l-1])+max(0LL,-c[l]);
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	push_up(i);
	return;
}
long long ans;
void modify(int i,int u,int v)
{
	if(tree[i].l==tree[i].r)
	{
		ans+=-abs(c[u])+abs(c[u]+v);
		c[u]+=v;
		tree[i].Min=max(0LL,c[u-1])+max(0LL,-c[u]);
		if(v&&u+1<=n-1) modify(1,u+1,0);
		return;
	}
	if(u<=tree[i*2].r) modify(i*2,u,v);
	else modify(i*2+1,u,v);
	push_up(i);
	return;
}
long long query(int i,int l,int r)
{
	if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Min;
	if(r<=tree[i*2].r) return query(i*2,l,r);
	else if(l>=tree[i*2+1].l) return query(i*2+1,l,r);
	else return min(query(i*2,l,r),query(i*2+1,l,r));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		c[i]=a[i]-a[i+1];
	for(int i=1;i<=n-1;i++)
		ans+=abs(c[i]);
	build(1,2,n-1);
	scanf("%d",&Q);
	while(Q--)
	{
		int t,l,r,x;
		scanf("%d%d%d%d",&t,&l,&r,&x);
		if(t==1)
		{
			if(l==r)
			{
				if(l==1) printf("%lld\n",ans-abs(c[l])+abs(c[l]+x));
				else if(l==n) printf("%lld\n",ans-abs(c[l-1])+abs(c[l-1]-x));
				else printf("%lld\n",ans-abs(c[l-1])-abs(c[l])+abs(c[l-1]-x)+abs(c[l]+x));
			}
			else
			{
				long long del=2*(x-query(1,max(l,2),min(r,n-1)));
				if(l==1) del=max(del,(long long)-abs(c[l])+abs(c[l]+x));
				if(r==n) del=max(del,(long long)-abs(c[r-1])+abs(c[r-1]-x));
				printf("%lld\n",ans+max(0LL,del));
			}
		}
		else if(t==2)
		{
			if(r==n) ans+=-abs(c[n-1])+abs(c[n-1]-x),c[n-1]-=x,modify(1,n-1,0);
			else modify(1,r,x);
			if(l==1) continue;
			else if(l==2) ans+=-abs(c[1])+abs(c[1]-x),c[1]-=x,modify(1,2,0);
			else modify(1,l-1,-x);
		}
	}
	return 0;
}
