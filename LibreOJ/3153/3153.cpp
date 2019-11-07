#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,q;
int a[500001];
int L[500001],R[500001];
int st[500001],top;
int ans[500001];
struct Ask
{
	int r,id;
};
vector<Ask> ask[500001],p[500001];
struct Node
{
	int l,r;
	int val,Max;
	int sum,lazy;
}tree[2000001];
void push_up(int i)
{
	tree[i].val=max(tree[i*2].val,tree[i*2+1].val);
	tree[i].sum=max(tree[i*2].sum,tree[i*2+1].sum);
	return;
}
void build(int i,int l,int r)
{
	tree[i].l=l,tree[i].r=r;
	if(l==r)
	{
		tree[i].val=tree[i].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	push_up(i);
	return;
}
void push_down(int i)
{
	if(!tree[i].lazy) return;
	tree[i*2].lazy=max(tree[i*2].lazy,tree[i].lazy);
	tree[i*2+1].lazy=max(tree[i*2+1].lazy,tree[i].lazy);
	tree[i*2].Max=max(tree[i*2].Max,tree[i].lazy);
	tree[i*2+1].Max=max(tree[i*2+1].Max,tree[i].lazy);
	tree[i*2].sum=max(tree[i*2].sum,tree[i*2].val+tree[i*2].Max);
	tree[i*2+1].sum=max(tree[i*2+1].sum,tree[i*2+1].val+tree[i*2+1].Max);
	tree[i].lazy=0;
	return;
}
void update(int i,int l,int r,int v)
{
	if(l>r) return;
	if(l<=tree[i].l&&tree[i].r<=r)
	{
		tree[i].Max=max(tree[i].Max,v);
		tree[i].sum=max(tree[i].sum,tree[i].val+tree[i].Max);
		tree[i].lazy=max(tree[i].lazy,v);
		return;
	}
	push_down(i);
	if(l<=tree[i*2].r) update(i*2,l,r,v);
	if(r>=tree[i*2+1].l) update(i*2+1,l,r,v);
	push_up(i);
	return;
}
int query(int i,int l,int r)
{
	if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
	push_down(i);
	int res=0;
	if(l<=tree[i*2].r) res=max(res,query(i*2,l,r));
	if(r>=tree[i*2+1].l) res=max(res,query(i*2+1,l,r));
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ask[l].push_back((Ask){r,i});
	}
	for(int i=1;i<=n;i++)
	{
		while(top&&a[i]>=a[st[top]]) top--;
		L[i]=st[top],st[++top]=i;
	}
	top=0;
	for(int i=n;i>=1;i--)
	{
		while(top&&a[i]>a[st[top]]) top--;
		R[i]=st[top],st[++top]=i;
	}
	build(1,1,n);
	for(int i=1;i<=n;i++)
		if(L[i]) p[L[i]].push_back((Ask){L[i],i});
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<p[i].size();j++)
			update(1,p[i][j].id*2-p[i][j].r,n,a[p[i][j].id]+a[p[i][j].r]);
		if(R[i]) update(1,R[i]*2-i,n,a[i]+a[R[i]]);
		for(int j=0;j<ask[i].size();j++)
			ans[ask[i][j].id]=query(1,i,ask[i][j].r);
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
    return 0;
}
