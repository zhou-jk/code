#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
const int N=200005;
int n,x;
int a[N];
long long sum[N];
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	long long ans=LONG_LONG_MAX;
	for(int i=1;i<=n;i++)
	{
		__int128 res=1LL*n*x+1LL*i*x;
		for(int j=n,k=1;j>=1;j-=i,k++)
			res+=(sum[j]-sum[max(j-i,0)])*max(5,2*k+1);
		if(res<ans) ans=res;
	}
	printf("%lld",ans);
	return 0;
}