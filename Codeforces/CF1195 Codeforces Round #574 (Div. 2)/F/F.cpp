#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=300005;
int n,m,Q;
int c[N];
struct Node
{
	int l,r,id;
}ask[N];
int book[N];
int res[N];
struct BIT
{
	int C[N];
	int lowbit(int x) 
	{
		return x&-x;
	}
	void add(int x,int y)
	{
		for(int i=x;i<=m;i+=lowbit(i))
			C[i]+=y;
		return;
	}
	int getsum(int x)
	{
		int ans=0;
		for(int i=x;i>0;i-=lowbit(i))
			ans+=C[i];
		return ans;
	}
}T;
int st[N],ed[N];
pair<int,int> a[N];
int tot;
pair<int,int> b[N];
pair<int,int> slope(int x1,int y1,int x2,int y2)
{
	int x=x2-x1,y=y2-y1;
	int g=abs(__gcd(x,y));
	return make_pair(x/g,y/g);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		st[i]=m;
		static int x[N],y[N];
		for(int j=1;j<=k;j++)
			scanf("%d%d",&x[j],&y[j]);
		for(int j=2;j<=k;j++)
			a[++m]=slope(x[j-1],y[j-1],x[j],y[j]),b[++tot]=a[m];
		a[++m]=slope(x[k],y[k],x[1],y[1]),b[++tot]=a[m];
		ed[i]=m;
	}
	sort(b+1,b+tot+1);
	tot=unique(b+1,b+tot+1)-b-1;
	for(int i=1;i<=m;i++)
		c[i]=lower_bound(b+1,b+tot+1,a[i])-b;
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
	{
		scanf("%d%d",&ask[i].l,&ask[i].r);
		ask[i].l=st[ask[i].l]+1,ask[i].r=ed[ask[i].r];
		ask[i].id=i;
	}
	sort(ask+1,ask+Q+1,[=](const Node &x,const Node &y){return x.r<y.r;});
	for(int i=1,j=1;i<=Q;i++)
	{
		while(j<=ask[i].r)
		{
			if(book[c[j]]) T.add(book[c[j]],-1);
			T.add(j,1);
			book[c[j]]=j;
			j++;
		}
		res[ask[i].id]=T.getsum(ask[i].r)-T.getsum(ask[i].l-1);
	}
	for(int i=1;i<=Q;i++)
		printf("%d\n",res[i]);
	return  0;
}
