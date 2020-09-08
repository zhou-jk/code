#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int T;
long long n;
int a,b,c,d;
map<long long,long long>f;
long long dfs(long long n)
{
	if(n==0) return 0;
	if(n==1) return d;
	if(f[n]) return f[n];
	long long x=n/2*2,y=(n+1)/2*2;
	f[n]=min(dfs(x/2)+1LL*(n-x)*d+a,dfs(y/2)+1LL*(y-n)*d+a);
	x=n/3*3,y=(n+2)/3*3;
	f[n]=min(f[n],min(dfs(x/3)+1LL*(n-x)*d+b,dfs(y/3)+1LL*(y-n)*d+b));
	x=n/5*5,y=(n+4)/5*5;
	f[n]=min(f[n],min(dfs(x/5)+1LL*(n-x)*d+c,dfs(y/5)+1LL*(y-n)*d+c));
	f[n]=min((__int128)f[n],(__int128)n*d);
	return f[n];
}
void solve()
{
	scanf("%lld%d%d%d%d",&n,&a,&b,&c,&d);
	f.clear();
	printf("%lld\n",dfs(n));
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
