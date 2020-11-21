#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int prime[N],tot;
bool isprime[N];
void init(int n=100000)
{
	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(isprime[i]) prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
	return;
}
long long d(int n)
{
	vector<int>pos;
	for(int i=1;i<=tot&&prime[i]<=sqrt(n);i++)
		if(n%prime[i]==0)
		{
			int cnt=0;
			while(n%prime[i]==0) cnt++,n/=prime[i];
			pos.emplace_back(cnt);
		}
	if(n!=1) pos.emplace_back(1);
	long long res=1;
	for(int c:pos)
		res*=(c+1);
	return res;
}
int T;
int a,b,c;
void solve()
{
	scanf("%d%d%d",&a,&b,&c);
	int ab=__gcd(a,b),ac=__gcd(a,c),bc=__gcd(b,c),abc=__gcd(ab,bc);
	long long ans=d(a)*d(b)*d(c);
	ans-=(d(c)*d(ab)*(d(ab)-1)+d(b)*d(ac)*(d(ac)-1)+d(a)*d(bc)*(d(bc)-1))/2;
	ans+=d(abc)*(d(abc)-1)*(d(abc)-2)/6*4;
	ans+=d(abc)*(d(abc)-1)*(d(ab)+d(bc)+d(ac)-3*d(abc)+2)/2;
	ans-=(d(ab)-d(abc))*(d(bc)-d(abc))*(d(ac)-d(abc));
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
