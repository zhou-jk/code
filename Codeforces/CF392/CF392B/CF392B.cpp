#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[4][4];
long long f[4][4],dp[41][4][4];
int main()
{
    memset(dp,63,sizeof(dp));
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            scanf("%d",&a[i][j]),f[i][j]=a[i][j];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            for(int k=1;k<=3;k++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            dp[1][i][j]=f[i][j];
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
        for(int j=1;j<=3;j++)
            for(int k=1;k<=3;k++)
                dp[i][j][k]=min(dp[i-1][j][6-j-k]+dp[i-1][6-j-k][k]+a[j][k],dp[i-1][j][k]*2+dp[i-1][k][j]+a[j][6-j-k]+a[6-j-k][k]);
    printf("%lld",dp[n][1][3]);
    return 0;
}