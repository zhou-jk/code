#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const int MOD=1000000007;
int n;
int c[N];
int lst[N];
long long dp[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(lst[c[i]]&&lst[c[i]]<i-1) dp[i]=(dp[i]+dp[lst[c[i]]])%MOD;
		lst[c[i]]=i;
	}
	printf("%lld",dp[n]);
	return 0;
}
