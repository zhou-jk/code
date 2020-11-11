#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int n,k;
int a[N];
int cnt[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		cnt[a[i]]++;
	int ans=0,ret=(n+1)/2;
	for(int i=1;i<=k;i++)
	{
		int num=min(cnt[i]/2,ret);
		ans+=num*2,ret-=num,cnt[i]-=num*2;
	}
	if(ret>0)
	{
		for(int i=1;i<=k;i++)
			if(cnt[i]>0&&ret>0) ans++,ret--,cnt[i]--;
	}
	printf("%d",ans);
	return 0;
}
