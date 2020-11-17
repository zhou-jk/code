#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
int n;
int a[N];
int Lg[N];
int L[N][22],R[N][22];
struct Segment_Tree
{
	struct Node
	{
		int Min,Max;
	}tree[N<<2];
	void push_up(int i)
	{
		if(!i) return;
		tree[i].Min=min(tree[i*2].Min,tree[i*2+1].Min);
		tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
		return;
	}
	void build(int i,int l,int r,int k)
	{
		if(l==r)
		{
			tree[i].Min=L[l][k];
			tree[i].Max=R[l][k];
			return;
		}
		int mid=(l+r)/2;
		build(i*2,l,mid,k);
		build(i*2+1,mid+1,r,k);
		push_up(i);
		return;
	}
	Node query(int i,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return {tree[i].Min,tree[i].Max};
		int mid=(l+r)/2;
		if(R<=mid) return query(i*2,l,mid,L,R);
		else if(L>mid) return query(i*2+1,mid+1,r,L,R);
		else
		{
			Node a=query(i*2,l,mid,L,R),b=query(i*2+1,mid+1,r,L,R);
			return {min(a.Min,b.Min),max(a.Max,b.Max)};
		}
	}
}T[22];
int solve(int u)
{
	int l=u,r=u;
	int tot=0;
	for(int j=Lg[n*3];j>=0;j--)
	{
		Segment_Tree::Node nxt=T[j].query(1,1,3*n,l,r);
		int nl=nxt.Min,nr=nxt.Max;
		if(nr-nl+1<n)
		{
			l=nl,r=nr;
			tot+=1<<j;
		}
	}
	return tot+1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1)
	{
		printf("0");
		return 0;
	}
	Lg[0]=1;
	for(int i=1;i<=n*3;i++)
		Lg[i]=Lg[i/2]+1;
	for(int i=1;i<=n;i++)
		a[i+n+n]=a[i+n]=a[i];
	for(int i=1;i<=n*3;i++)
		L[i][0]=max(i-a[i],1),R[i][0]=min(i+a[i],n*3);
	T[0].build(1,1,3*n,0);
	for(int k=1;k<=Lg[n*3];k++)
	{
		for(int i=1;i<=n*3;i++)
		{
			Segment_Tree::Node nxt=T[k-1].query(1,1,3*n,L[i][k-1],R[i][k-1]);
			L[i][k]=nxt.Min,R[i][k]=nxt.Max;
		}
		T[k].build(1,1,3*n,k);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",solve(i+n));
	return 0;
}
