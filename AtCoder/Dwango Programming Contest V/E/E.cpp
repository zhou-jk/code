#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
const int MOD=998244353;
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*__gcd(a[i],i-1)%MOD;
	printf("%lld",ans);
	return 0;
}
