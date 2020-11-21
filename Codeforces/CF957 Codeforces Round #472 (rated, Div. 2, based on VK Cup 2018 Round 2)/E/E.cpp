#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n,w;
int x[N],v[N];
pair<double,double>p[N];
int tx[N],ty[N];
struct BIT
{
	int C[N];
	int lowbit(int x)
	{
		return x&-x;
	}
	void add(int x,int y)
	{
		for(int i=x;i<=n;i+=lowbit(i))
			C[i]+=y;
		return;
	}
	int getsum(int x)
	{
		int res=0;
		for(int i=x;i>0;i-=lowbit(i))
			res+=C[i];
		return res;
	}
}T;
vector<int>pos[N];
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&v[i]);
	for(int i=1;i<=n;i++)
		p[i]={(double)-x[i]/(v[i]+w),(double)-x[i]/(v[i]-w)};
	sort(p+1,p+n+1);
	static double b[N];
	int tot=0;
	for(int i=1;i<=n;i++)
		b[++tot]=p[i].second;
	sort(b+1,b+tot+1);
	tot=unique(b+1,b+tot+1)-b-1;
	for(int i=1;i<=n;i++)
		ty[i]=lower_bound(b+1,b+tot+1,p[i].second)-b;
	tot=0;
	for(int i=1;i<=n;i++)
		b[++tot]=p[i].first;
	sort(b+1,b+tot+1);
	tot=unique(b+1,b+tot+1)-b-1;
	for(int i=1;i<=n;i++)
		tx[i]=lower_bound(b+1,b+tot+1,p[i].first)-b;
	for(int i=1;i<=n;i++)
		pos[tx[i]].emplace_back(ty[i]);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int y:pos[i])
			ans+=T.getsum(y-1);
		for(int y:pos[i])
			T.add(y,1);
	}
	printf("%lld",1LL*n*(n-1)/2-ans);
	return 0;
}
