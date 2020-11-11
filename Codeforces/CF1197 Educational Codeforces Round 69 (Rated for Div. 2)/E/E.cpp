#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005;
const int MOD=1000000007;
const long long INF=4557430888798830399;
int n;
struct Doll
{
	int in,out;
	bool operator<(const Doll &b)const
	{
		return out<b.out;
	}
}d[N];
long long dp[N],f[N];
long long Min[N],sum[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&d[i].out,&d[i].in);
	sort(d+1,d+n+1);
	int Max=0;
	for(int i=1;i<=n;i++)
		Max=max(Max,d[i].in);
	memset(dp,63,sizeof(dp));
	long long m=INF,ans=0;
	Min[0]=INF;
	for(int i=1;i<=n;i++)
	{
		if(i==1||d[1].out>d[i].in) dp[i]=d[i].in,f[i]=1;
		int j=upper_bound(d+1,d+i,(Doll){0,d[i].in})-d-1;
		if(j<=i-1)
		{
			if(Min[j]+d[i].in<dp[i]) dp[i]=Min[j]+d[i].in,f[i]=sum[j];
			else if(Min[j]+d[i].in==dp[i]) f[i]=(f[i]+sum[j])%MOD;
		}
		if(d[i].out>Max)
		{
			if(dp[i]<m) m=dp[i],ans=f[i];
			else if(dp[i]==m) ans=(ans+f[i])%MOD;
		}
		Min[i]=Min[i-1],sum[i]=sum[i-1];
		if(dp[i]-d[i].out<Min[i]) Min[i]=dp[i]-d[i].out,sum[i]=f[i];
		else if(dp[i]-d[i].out==Min[i]) sum[i]=(sum[i]+f[i])%MOD;
	}
	printf("%lld",ans);
	return 0;
}
