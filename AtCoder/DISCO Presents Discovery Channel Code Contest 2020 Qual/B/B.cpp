#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N];
long long sum[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	long long ans=1e18;
	for(int i=1;i<n;i++)
		ans=min(ans,abs(sum[i]-(sum[n]-sum[i])));
	printf("%lld",ans);
	return 0;
}
