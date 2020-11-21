#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
int m[N];
int a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&m[i]);
	for(int i=1;i<=n;i++)
		a[i]=m[i]+1;
	for(int i=1;i<=n;i++)
		if(a[i]<a[i-1]) a[i]=a[i-1];
	for(int i=n;i>=1;i--)
		if(a[i]<a[i+1]-1) a[i]=a[i+1]-1;
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=a[i]-m[i]-1;
	printf("%lld",ans);
	return 0;
}
