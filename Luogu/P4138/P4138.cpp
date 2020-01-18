#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2005;
const int INF=1061109567;
int n;
struct Node
{
	int a,b;
}p[N];
bool cmp(Node x,Node y)
{
	return x.a>y.a;
}
int dp[N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].a,&p[i].b);
	sort(p+1,p+n+1,cmp);
	for(int i=0;i<=n;i++)
		dp[0][i]=dp[i][n+1]=-INF;
	dp[0][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=max(dp[i-1][j],dp[i-1][max(j-p[i].a,0)+1]+p[i].b);
	int ans=-INF;
	for(int i=0;i<=n;i++)
		ans=max(ans,dp[n][i]);
	printf("%d",ans);
	return 0;
}
