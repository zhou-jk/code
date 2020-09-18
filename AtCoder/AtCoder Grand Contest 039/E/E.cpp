#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=45;
int n;
int a[N][N];
long long dp[N][N][N];
long long dfs(int l,int i,int r)
{
	if(dp[l][i][r]!=-1) return dp[l][i][r];
	if(l==r) return 1;
	if(l==i||i==r) return 0;
	long long res=0;
	for(int j=l;j<i;j++)
		for(int k=i+1;k<=r;k++)
			if(a[j][k])
				for(int p=j;p<i;p++)
					for(int q=i+1;q<=k;q++)
						res+=dfs(l,j,p)*dfs(p+1,i,q-1)*dfs(q,k,r);
	return dp[l][i][r]=res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++)
		for(int j=1;j<=n*2;j++)
			scanf("%1d",&a[i][j]);
	memset(dp,-1,sizeof(dp));
	long long ans=0;
	for(int i=2;i<=n*2;i++)
		if(a[1][i]) ans+=dfs(2,i,2*n);
	printf("%lld",ans);
	return 0;
}
