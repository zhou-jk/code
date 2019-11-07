#include<iostream>
#include<cstdio>
using namespace std;
int op,n,m;
long long dp[1001];
long long sum[1001];
long long ans;
long long count(long long n)
{
    if((n&3)&1) return ((n&3)>>1)^1;
    return ((n&3)>>1)^n;
}
int main()
{
    scanf("%d%d%d",&op,&n,&m);
    for(int i=1;i<=n;i++)
    {
        long long x;
        scanf("%lld",&x);
        sum[i]=sum[i-1]^count(x);
    }
    for(int i=1;i<m;i++)
        for(int j=n-1;j>=i;j--)
            for(int k=i-1;k>=0;k--)
			    dp[j]=max(dp[j],dp[k]+(sum[j]^sum[k]));
	for(int i=m-1;i<n;i++)
        ans=max(ans,dp[i]+(sum[n]^sum[i]));
	printf("%lld",ans);
    return 0;
}