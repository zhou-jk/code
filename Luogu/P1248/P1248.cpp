#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node
{
	int id,m;
}d[1001];
bool cmp(Node x,Node y)
{
	return x.m<y.m;
}
int n,t,k;
int a[1001],b[1001],ans[1001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		d[i].id=i,d[i].m=min(a[i],b[i]);
	sort(d+1,d+n+1,cmp);
	k=0,t=n+1;
	for(int i=1;i<=n;i++)
		if(d[i].m==a[d[i].id]) ans[++k]=d[i].id;
		else ans[--t]=d[i].id;
	t=0,k=0;
	for(int i=1;i<=n;i++)
		k+=a[ans[i]],t=max(t,k)+b[ans[i]];
	printf("%d\n",t);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}