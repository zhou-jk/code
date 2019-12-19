#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int M=201;
int n,m;
int a[M*M];
int f[M*M],dp[M*M];
int b[M],cnt[M];
int main()
{
	memset(dp,63,sizeof(dp));
	memset(f,-1,sizeof(f));
    scanf("%d%d",&n,&m);
	int tot=0;
	for(int i=1;i<=n;i++)
	{
        int x;
        scanf("%d",&x);
		if(x!=a[tot]) a[++tot]=x;
	}
	n=tot;
	dp[0]=0;
    for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sqrt(n);j++)
			if(f[a[i]]<=b[j]) cnt[j]++;
		f[a[i]]=i;
		for(int j=1;j<=sqrt(n);j++)
			if(cnt[j]>j)
			{
				int t=b[j]+1;
				while(f[a[t]]>t) t++;
				b[j]=t,cnt[j]--;
			}
		for(int j=1;j<=sqrt(n);j++)
			dp[i]=min(dp[i],dp[b[j]]+j*j);
	}
	printf("%d",dp[n]);
	return 0;
}