#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=1000000007;
int T,n,h;
long long dp[601][601];
long long dfs(int x,int y)
{
	if(x==0) return 1;
	if(y==0) return x==1;
	if(dp[x][y]!=-1) return dp[x][y];
	dp[x][y]=0;
	for(int i=1;i<=x;i++)
		dp[x][y]=(dp[x][y]+dfs(i-1,y-1)*dfs(x-i,y-1)%MOD)%MOD;
	return dp[x][y];
}
int main()
{
	memset(dp,-1,sizeof(dp));
    scanf("%d",&T);
	while(T--)
	{
        scanf("%d%d",&n,&h);
		if(h==0) printf("%lld\n",dfs(n,h));
		else printf("%lld\n",(dfs(n,h)-dfs(n,h-1)+MOD)%MOD);
	}
	return 0;
}