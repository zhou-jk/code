#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5005;
const long long INF=4557430888798830399;
int n,A,B;
int a[N];
long long dp[N];
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	a[0]=0;
	a[n+1]=n+1;
	for(int i=1;i<=n+1;i++)
	{
		int cnta=0,cntb=0;
		for(int j=i-1;j>=0;j--)
			if(a[j]<a[i])
			{
				dp[i]=min(dp[i],dp[j]+1LL*cnta*A+1LL*cntb*B);
				cntb++;
			}
			else if(a[j]>a[i]) cnta++;
	}
	printf("%lld",dp[n+1]);
	return 0;
}
