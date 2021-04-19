#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N],b[N];
vector<pair<int,int>>val;
bool vis[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	long long suma=0,sumb=0;
	for(int i=1;i<=n;i++)
		suma+=a[i],sumb+=b[i];
	for(int i=1;i<=n;i++)
		val.emplace_back(a[i],i),val.emplace_back(b[i],i);
	sort(val.begin(),val.end());
	long long sum=0;
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		auto [v,p]=val[i];
		sum+=v;
		if(vis[p]) flag=true;
		else vis[p]=true;
	}
	if(flag)
	{
		printf("%lld",min(sum,min(suma,sumb)));
		return 0;
	}
	sum-=val[n-1].first;
	vis[val[n-1].second]=false;
	sum+=val[n].first;
	if(vis[val[n].second]) flag=true;
	else vis[val[n].second]=true;
	if(flag) printf("%lld",min(sum,min(suma,sumb)));
	else printf("%lld",min(min(sum-val[n-2].first+val[n-1].first,sum-val[n].first+val[n+1].first),min(suma,sumb)));
	return 0;
}