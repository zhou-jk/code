#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s,d,m;
int a[51][11];
int dp[500001];
int main()
{
    scanf("%d%d%d",&s,&d,&m);
    for(int i=1;i<=s;i++)
        for(int j=1;j<=d;j++)   
            scanf("%d",&a[i][j]);
    for(int j=1;j<=d;j++)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=s;i++)
            for(int k=a[i][j];k<=m;k++)
                dp[k]=max(dp[k],dp[k-a[i][j]]+a[i][j+1]-a[i][j]);
        m+=max(0,dp[m]);
    }
    printf("%d",m);
    return 0;
}