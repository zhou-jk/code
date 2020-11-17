#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int T;
int n;
long long W;
pair<int,int>a[N];
void solve()
{
	scanf("%d%lld",&n,&W);
	for(int i=1;i<=n;i++)
	{
		int w;
		scanf("%d",&w);
		a[i]={w,i};
	}
	sort(a+1,a+n+1,greater<pair<int,int>>());
	vector<int>pos;
	long long sum=0;
	for(int i=1;i<=n;i++)
		if(sum+a[i].first<=W)
		{
			sum+=a[i].first;
			pos.emplace_back(a[i].second);
			if((W+1)/2<=sum)
			{
				int k=pos.size();
				printf("%d\n",k);
				for(int u:pos)
					printf("%d ",u);
				printf("\n");
				return;
			}
		}
	printf("-1\n");
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
