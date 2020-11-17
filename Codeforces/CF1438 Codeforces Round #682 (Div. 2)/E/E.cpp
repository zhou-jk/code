#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=200005;
int n;
int a[N];
long long sum[N];
set<pair<long long,int>>S;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	long long ans=0;
	for(int r=1;r<=n;r++)
	{
		set<pair<long long,int>>::iterator it=S.lower_bound({sum[r-1]-a[r],0});
		while(it!=S.end())
		{
			int l=it->second;
			if(l+1<=r-1&&(a[l]^a[r])==sum[r-1]-sum[l]) ans++;
			it++;
		}
		S.insert({sum[r]+a[r],r});
	}
	printf("%lld",ans);
	return 0;
}
