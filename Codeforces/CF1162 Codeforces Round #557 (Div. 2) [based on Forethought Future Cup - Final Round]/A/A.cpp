#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
int n,h,m;
int a[N];
int main()
{
	scanf("%d%d%d",&n,&h,&m);
	for(int i=1;i<=n;i++)
		a[i]=h;
	for(int i=1;i<=m;i++)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		for(int j=l;j<=r;j++)
			a[j]=min(a[j],x);
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=1LL*a[i]*a[i];
	printf("%lld",ans);
	return 0;
}
