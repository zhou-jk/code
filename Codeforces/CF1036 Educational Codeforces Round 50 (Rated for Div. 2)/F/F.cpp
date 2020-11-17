#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1000005;
const long long INF=1e18;
int T;
long long val[N*10];
int tot;
long long mul(long long a,long long b)
{
	__int128 c=(__int128)a*b;
	if(c>INF) return INF+1;
	else return c;
}
void init(int n=1000000)
{
	for(int i=2;i<=n;i++)
	{
		long long p=1LL*i*i*i;
		while(p<=INF)
		{
			auto check=[=](long long x)
			{
				long long t=(long long)sqrt(x);
				while(t*t<x) t++;
				while(t*t>x) t--;
				return t*t!=x;
			};
			if(check(p)) val[++tot]=p;
			p=mul(p,i);
		}
	}
	sort(val+1,val+tot+1);
	tot=unique(val+1,val+tot+1)-val-1;
	return;
}
long long n;
void solve()
{
	scanf("%lld",&n);
	long long t=sqrt(n);
	while(t*t<n) t++;
	while(t*t>n) t--;
	long long ans=(n-(upper_bound(val+1,val+tot+1,n)-val-1)-t);
	printf("%lld\n",ans);
	return;
}
int main()
{
	init();
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
