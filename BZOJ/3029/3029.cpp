#include<iostream>
#include<cstdio>
using namespace std;
int n,l,k;
int a[201];
double p[201],dp[201][201][401],ans;
int main()
{
    scanf("%d%d%d",&n,&l,&k);
    for(int i=1;i<=n;i++)
	{
        double tmp;
        scanf("%lf",&tmp);
        p[i]=tmp/100.0;
    }
    for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
    if(k>=400) k=400,dp[0][0][k]=1;
    else dp[0][0][200+k]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
            for(int v=1;v<=400;v++)
			{
                dp[i][j][v]=dp[i-1][j][v]*(1-p[i]);
                if(j==0) continue;
                if(a[i]==-1) dp[i][j][v]+=dp[i-1][j-1][v+1]*p[i];
                else if(v>=a[i]) dp[i][j][v]+=dp[i-1][j-1][v-a[i]]*p[i];
            }
    for(int i=l;i<=n;i++)
        for(int j=200;j<=400;j++)
			ans+=dp[n][i][j];
    printf("%.6lf",ans);
    return 0;
}
