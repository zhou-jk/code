#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
struct Node
{
	int a,b;
}p[N];
long long sum[N];
struct Fraction
{
	long long p,q;
	bool operator<(const Fraction &b)const
	{
		return (double)p/q<(double)b.p/b.q;
	}
};
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].a,&p[i].b);
	sort(p+1,p+n+1,[=](const Node &x,const Node &y){return max(x.a,x.b)<max(y.a,y.b);});
	for(int i=n;i>=1;i--)
		sum[i]=sum[i+1]+max(p[i].a,p[i].b);
	long long to=0;
	for(int i=1;i<=n;i++)
		to+=p[i].a;
	Fraction ans=(Fraction){0,1};
	for(int i=1;i<=n;i++)
	{
		int pos=n+1;
		int l=1,r=n;
		auto check=[=](int x){return sum[x]-(x<=i?max(p[i].a,p[i].b):0)>=to-p[i].b;};
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid)) l=mid+1,pos=mid;
			else r=mid-1;
		}
		if(pos>n) continue;
		long long ret=sum[pos]-(pos<=i?max(p[i].a,p[i].b):0)-(to-p[i].b);
		Fraction res=(Fraction){1LL*(pos-1-(pos>i))*p[i].b+min(ret,(long long)p[i].b),1LL*p[i].b*n};
		ans=max(ans,res);
	}
	long long d=gcd(ans.p,ans.q);
	ans.p/=d,ans.q/=d;
	printf("%lld %lld",ans.p,ans.q);
	return 0;
}

