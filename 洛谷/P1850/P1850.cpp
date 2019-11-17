#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=1061109567;
const int N=2001;
int n,m,v,e;
int c[N],d[N],f[N][N];
double k[N],dp[N][N][2];
int main()
{
    memset(f,63,sizeof(f));
    memset(dp,127,sizeof(dp));
    scanf("%d%d%d%d",&n,&m,&v,&e);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    for(int i=1;i<=n;i++)
        scanf("%lf",&k[i]);
    for(int i=1;i<=v;i++)
        f[i][i]=0;
    dp[1][0][0]=dp[1][1][1]=0;
    for(int i=1;i<=e;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        f[x][y]=min(f[x][y],z);
        f[y][x]=min(f[y][x],z);
    }
    for(int k=1;k<=v;k++)
        for(int i=1;i<=v;i++)
            for(int j=1;j<=v;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=2;i<=n;i++)
    {
        dp[i][0][0]=dp[i-1][0][0]+f[c[i-1]][c[i]];
        for(int j=1;j<=m;j++)
        {
            dp[i][j][0]=min(dp[i-1][j][0]+f[c[i-1]][c[i]],dp[i-1][j][1]+k[i-1]*f[d[i-1]][c[i]]+(1-k[i-1])*f[c[i-1]][c[i]]);
            dp[i][j][1]=min(dp[i-1][j-1][0]+k[i]*f[c[i-1]][d[i]]+(1-k[i])*f[c[i-1]][c[i]],dp[i-1][j-1][1]+k[i-1]*k[i]*f[d[i-1]][d[i]]+(1-k[i-1])*k[i]*f[c[i-1]][d[i]]+k[i-1]*(1-k[i])*f[d[i-1]][c[i]]+(1-k[i-1])*(1-k[i])*f[c[i-1]][c[i]]);
        }
    }
    double ans=INF;                        
    for(int i=0;i<=m;i++)
        ans=min(ans,min(dp[n][i][0],dp[n][i][1])); 
    printf("%.2lf",ans);
    return 0;
}