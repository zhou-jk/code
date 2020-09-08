#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=3005;
const int MOD=998244353;
int A,B,C,D;
long long dp[N][N];
long long dfs(int r,int c)
{
	if(r<A||c<B) return 0;
	if(dp[r][c]!=-1) return dp[r][c];
	int res=0;
	res=(res+dfs(r,c-1)*r%MOD)%MOD;
	res=(res+dfs(r-1,c)*c%MOD)%MOD;
	res=(res-dfs(r-1,c-1)*(r-1)%MOD*(c-1)%MOD+MOD)%MOD;
	return dp[r][c]=res;
}
int main()
{
	scanf("%d%d%d%d",&A,&B,&C,&D);
	memset(dp,-1,sizeof(dp));
	dp[A][B]=1;
	printf("%lld",dfs(C,D));
	return 0;
}

