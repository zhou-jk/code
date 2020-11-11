#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300005;
int n,k;
int a[N];
int b[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		b[i]=a[i]-a[i+1];
	sort(b+1,b+n);
	long long ans=a[n]-a[1];
	for(int i=1;i<=k-1;i++)
		ans+=b[i];
	printf("%lld",ans);
	return 0;
}
