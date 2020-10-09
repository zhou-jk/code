#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,X;
struct Node
{
	int b,l,u;
	long long v;
}a[N];
long long sum[N];
long long A,B;
bool check(long long x)
{
	int t=min(x/X,(long long)n),ret=x%X;
	for(int i=1;i<=t;i++)
	{
		long long add=0;
		if(ret>a[i].b) add=1LL*(ret-a[i].b)*a[i].u+1LL*a[i].b*a[i].l;
		else add=1LL*ret*a[i].l;
		if(sum[min(t+1,n)]-a[i].v+add>=B) return true;
	}
	for(int i=t+1;i<=n;i++)
	{
		long long add=0;
		if(ret>a[i].b) add=1LL*(ret-a[i].b)*a[i].u+1LL*a[i].b*a[i].l;
		else add=1LL*ret*a[i].l;
		if(sum[t]+add>=B) return true;
	}
	return sum[t]>=B;
}
int main()
{
	scanf("%d%d",&n,&X);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].b,&a[i].l,&a[i].u);
		a[i].v=1LL*(X-a[i].b)*a[i].u+1LL*a[i].b*a[i].l;
	}
	sort(a+1,a+n+1,[=](const Node &x,const Node &y){return x.v>y.v;});
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i].v;
	for(int i=1;i<=n;i++)
		B+=1LL*a[i].b*a[i].l;
	long long l=0,r=1e10,ans=-1;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld",ans);
	return 0;
}
