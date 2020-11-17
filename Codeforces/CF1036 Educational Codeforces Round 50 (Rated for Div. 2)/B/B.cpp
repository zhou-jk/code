#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int T;
long long n,m,k;
void solve()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	if(n<0) n=-n;
	if(m<0) m=-m;
	if(n>m) swap(n,m);
	if(k<m) printf("-1\n");
	else printf("%lld\n",k-(k-n)%2-(k-m)%2);
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
