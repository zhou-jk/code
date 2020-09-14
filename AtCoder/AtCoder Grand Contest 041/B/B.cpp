#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m,v,p;
int a[N];
bool check(int x)
{
	if(x<=p) return true;
	if(a[x]+m<a[p]) return false;
	long long ret=1LL*m*v;
	ret-=m;
	ret-=1LL*(p-1)*m+1LL*(n-(x+1)+1)*m;
	for(int i=p;i<x;i++)
		ret-=min(m,a[x]+m-a[i]);
	return ret<=0;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&v,&p);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	int l=1,r=n,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
