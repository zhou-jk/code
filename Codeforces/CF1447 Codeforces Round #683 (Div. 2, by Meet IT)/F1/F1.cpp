#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005,M=105;
int n;
int a[N];
int cnt[N];
int b[N];
int pre[N*2];
int main()
{
	scanf("%d",&n);
	int m=100;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		cnt[a[i]]++;
	int mx=max_element(cnt+1,cnt+m+1)-cnt;
	int ans=0;
	for(int x=1;x<=m;x++)
	{
		if(x==mx) continue;
		memset(pre,-1,sizeof(pre));
		for(int i=1;i<=n;i++)
			if(a[i]==mx) b[i]=1;
			else if(a[i]==x) b[i]=-1;
			else b[i]=0;
		for(int i=1;i<=n;i++)
			b[i]+=b[i-1];
		int res=0;
		pre[n]=0;
		for(int i=1;i<=n;i++)
			if(pre[b[i]+n]==-1) pre[b[i]+n]=i;
			else res=max(res,i-pre[b[i]+n]);
		ans=max(ans,res);
	}
	printf("%d",ans);
	return 0;
}
