#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
long long a[N];
vector<pair<long long,long long> >res;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int j=n;
	for(int i=1;i<=n-1;i++)
		if(a[i]>0)
		{
			j=i;
			break;
		}
	if(j==1)
	{
		for(int i=2;i<=n-1;i++)
			res.push_back(make_pair(a[1],a[i])),a[1]-=a[i];
		res.push_back(make_pair(a[n],a[1])),a[n]-=a[1];
		printf("%lld\n",a[n]);
		for(auto [x,y]:res)
			printf("%lld %lld\n",x,y);
		return 0;
	}
	for(int i=j;i<=n-1;i++)
		res.push_back(make_pair(a[1],a[i])),a[1]-=a[i];
	for(int i=1;i<=j-1;i++)
		res.push_back(make_pair(a[n],a[i])),a[n]-=a[i];
	printf("%lld\n",a[n]);
	for(auto [x,y]:res)
		printf("%lld %lld\n",x,y);
	return 0;
}
