#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long ans=1e18;
int f[200001][19];
long long dp[200001][19],g[200001][19];
long long dis[200001][19],w[200001];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&w[i]);
    for(int i=2;i<=n;i++)
        scanf("%lld",&dis[i][1]);
    for(int i=1;i<=n;i++)
        f[i][0]=i,f[i][1]=i/2;
    for(int i=2;(1<<i)<=n;i++)
        for(int j=2;j<=n;j++)
	    {
		    f[j][i]=f[f[j][i-1]][1];
		    if(!f[j][i]) continue;
		    dis[j][i]=dis[j][i-1]+dis[f[j][i-1]][1];
	    }
    for(int i=n;i>0;i--)
	{
        if(i*2>n)
        {
            for(int j=1;f[i][j-1]!=0;j++)
		        g[i][j]=(dis[i][j]+dis[(i>>(j-1))^1][1])*w[(i>>(j-1))^1];
        }
        else if(i*2+1>n)
        {
            for(int j=1;f[i][j-1]!=0;j++)
		        g[i][j]=dis[i*2][1]*w[i*2]+g[i*2][j+1];
        }
        else if(i*2<=n&&i*2+1<=n)
        {
            for(int j=1;f[i][j-1]!=0;j++)
		        g[i][j]=min(dis[i*2][1]*w[i*2]+g[i*2][1]+g[i*2+1][j+1],dis[i*2+1][1]*w[i*2+1]+g[i*2+1][1]+g[i*2][j+1]);
        }
    }
	for(int i=n;i>0;i--)
	{
		if(i*2>n)
        {
            for(int j=1;f[i][j-1]!=0;j++)
		        dp[i][j]=dis[i][j]*w[f[i][j]];
        }
        else if(i*2+1>n)
        {
            for(int j=1;f[i][j-1]!=0;j++)
                dp[i][j]=dis[i*2][1]*w[i*2]+dp[i*2][j+1];
        }
		else
        {
            for(int j=1;f[i][j-1];j++)
		        dp[i][j]=min(dis[i*2][1]*w[i*2]+g[i*2][1]+dp[i*2+1][j+1],dis[i*2+1][1]*w[i*2+1]+g[i*2+1][1]+dp[i*2][j+1]);
        }
    }
    for(int i=1;i<=n;i++)
	{
		long long sum=dp[i][1];
        for(int j=1;f[i][j]!=0;j++)
            if(((i>>(j-1))^1)>n) sum+=dis[f[i][j]][1]*w[f[i][j+1]];
            else sum+=dis[(i>>(j-1))^1][1]*w[(i>>(j-1))^1]+dp[(i>>(j-1))^1][2];
		ans=min(ans,sum);
	}
	printf("%lld",ans);
    return 0;
}