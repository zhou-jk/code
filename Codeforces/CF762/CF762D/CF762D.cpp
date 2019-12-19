#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n;
long long a[4][N];
long long f[4][N],dp[4][N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld", &a[i][j]);
    dp[1][1]=a[1][1],dp[2][1]=a[1][1]+a[2][1],dp[3][1]=a[1][1]+a[2][1]+a[3][1];
    f[1][1]=a[1][1],f[2][1]=a[2][1],f[3][1]=a[3][1];
    for(int j=2;j<=n;j++)
    {
        for(int i=1;i<=3;i++)
            dp[i][j]=f[i][j]=dp[i][j-1]+a[i][j];
        dp[1][j]=max(dp[1][j],f[2][j]+a[1][j]);
        dp[1][j]=max(dp[1][j],f[3][j]+a[2][j]+a[1][j]);
        dp[1][j]=max(dp[1][j],f[3][j-1]+a[3][j]+a[2][j]+a[2][j-1]+a[1][j-1]+a[1][j]);
        dp[2][j]=max(dp[2][j],f[1][j]+a[2][j]);
        dp[2][j]=max(dp[2][j],f[3][j]+a[2][j]);
        dp[3][j]=max(dp[3][j],f[2][j]+a[3][j]);
        dp[3][j]=max(dp[3][j],f[1][j]+a[2][j]+a[3][j]);
        dp[3][j]=max(dp[3][j],f[1][j-1]+a[1][j]+a[2][j]+a[2][j-1]+a[3][j-1]+a[3][j]);
    }
    printf("%lld",dp[3][n]);
    return 0;
}