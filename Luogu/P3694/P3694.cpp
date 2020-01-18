#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100001;
const int M=20;
int n,m;
int sum[N][M+1],dp[1<<M];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            sum[i][j]=sum[i-1][j];
        int x;
        scanf("%d",&x);
        sum[i][x]++;
    }
    memset(dp,63,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<(1<<m);i++)
    {
        int l=0,r=0;
        for(int j=1;j<=m;j++)
            if(i&(1<<(j-1))) l+=sum[n][j],r+=sum[n][j];
        for(int j=1;j<=m;j++)
            if(i&(1<<(j-1))) dp[i]=min(dp[i],dp[i^(1<<(j-1))]+(sum[n][j]-sum[r][j]+sum[l-sum[n][j]][j]));
    }
    printf("%d",dp[(1<<m)-1]);
    return 0;
}