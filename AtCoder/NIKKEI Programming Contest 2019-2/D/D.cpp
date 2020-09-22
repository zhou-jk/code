#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=100005;
const long long INF=4557430888798830399;
int n,m;
vector<pair<int,int> >pre[N];
struct Node
{
	int l,r;
	long long Min;
}tree[N<<2];
long long f[N];
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
		tree[i].Min=f[l];
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	push_up(i);
	return;
}
long long query(int i,int l,int r)
{
	if(l>r) return INF;
	if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Min;
	long long res=INF;
	if(l<=tree[i*2].r) res=min(res,query(i*2,l,r));
	if(r>=tree[i*2+1].l) res=min(res,query(i*2+1,l,r));
	return res;
}
void modify(int i,int u,long long val)
{
	if(tree[i].l==tree[i].r)
	{
		tree[i].Min=val;
		return;
	}
	if(u<=tree[i*2].r) modify(i*2,u,val);
	else modify(i*2+1,u,val);
	push_up(i);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		pre[r].push_back(make_pair(l,c));
	}
	memset(f,63,sizeof(f));
	f[1]=0;
	build(1,1,n);
	for(int r=1;r<=n;r++)
	{
		for(auto [l,c]:pre[r])
			f[r]=min(f[r],query(1,l,r-1)+c);
		modify(1,r,f[r]);
	}
	if(f[n]>=INF) printf("-1");
	else printf("%lld",f[n]);
	return 0;
}
