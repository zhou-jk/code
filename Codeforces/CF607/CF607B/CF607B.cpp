#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=501;
int n;
int a[N];
int dp[N][N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,63,sizeof(dp));
    for(int i=1;i<=n;i++)
        dp[i][i]=1;
    for(int l=2;l<=n;l++)
        for(int i=1;i+l-1<=n;i++)
        {
            int j=i+l-1;
            if(a[i]==a[j]&&l>2) dp[i][j]=dp[i+1][j-1];
            else if(a[i]==a[j]) dp[i][j]=1;
            for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    printf("%d",dp[1][n]);
    return 0;
}