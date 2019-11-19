#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,m;
int a[101][101];
int dp[10001];
int main()
{
    scanf("%d%d%d",&t,&n,&m);
    for(int i=1;i<=t;i++)
        for(int j=1;j<=n;j++)   
            scanf("%d",&a[i][j]);
    for(int i=1;i<t;i++)
    {
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=n;j++)
            for(int k=a[i][j];k<=m;k++)
                dp[k]=max(dp[k],dp[k-a[i][j]]+a[i+1][j]-a[i][j]);
        m+=max(dp[m],0);
    }
    printf("%d",m);
    return 0;
}