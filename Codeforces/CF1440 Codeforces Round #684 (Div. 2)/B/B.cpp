#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int T;
int n,k;
int a[N];
void solve()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n*k;i++)
		scanf("%d",&a[i]);
	long long ans=0;
	if(n==1)
	{
		for(int i=1;i<=n*k;i++)
			ans+=a[i];
		printf("%lld\n",ans);
		return ;
	}
	if(n==2)
	{
		for(int i=1;i<=n*k;i+=2)
			ans+=a[i];
		printf("%lld\n",ans);
		return ;
	}
	int mid=(n+1)/2-1;
	for(int i=k*mid+1;i<=n*k;i+=n-mid)
		ans+=a[i];
	printf("%lld\n",ans);
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
