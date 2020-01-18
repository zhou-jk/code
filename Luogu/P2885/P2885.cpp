#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=1061109567;
int n,c;
int h[100001],dp[100001][101];
int low[101],high[101];
int main()  
{  
    scanf("%d%d",&n,&c);
    int maxh=0;
    memset(dp,63,sizeof(dp));
    memset(low,63,sizeof(low));
    memset(high,63,sizeof(high));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		maxh=max(h[i],maxh);
	}
	for(int i=1;i<=maxh;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int t=INF,j=maxh;j>0;j--)
			low[j]=t=min(t,dp[i-1][j]+c*j);
		for(int t=INF,j=1;j<=maxh;j++)
			high[j]=t=min(t,dp[i-1][j]-c*j);
		for(int j=h[i];j<=maxh;j++)
		    dp[i][j]=(j-h[i])*(j-h[i])+min(high[j]+j*c,low[j]-j*c);
	}
	int ans=INF;
	for(int i=h[n];i<=maxh;i++)
		ans=min(ans,dp[n][i]);
	printf("%d",ans);
    return 0;  
}