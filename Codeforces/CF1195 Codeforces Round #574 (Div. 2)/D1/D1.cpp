#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
const int MOD=998244353;
int n;
int a[N];
vector<int>d[N];
vector<int>convert(int x)
{
	if(x==0) return {0};
	vector<int>res;
	while(x) res.emplace_back(x%10),x/=10;
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		d[i]=convert(a[i]);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		long long fac=1;
		for(int u:d[i])
			ans=(ans+fac*u%MOD*n%MOD)%MOD,fac=fac*100%MOD;
	}
	for(int i=1;i<=n;i++)
	{
		long long fac=10;
		for(int u:d[i])
			ans=(ans+fac*u%MOD*n%MOD)%MOD,fac=fac*100%MOD;
	}
	printf("%lld",ans);
	return 0;
}
