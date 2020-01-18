#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000001;
const int INF=1061109567;
int n;
int a[N];
int dp[N][3];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]++;
    }
    memset(dp,63,sizeof(dp));
    dp[1][a[1]]=0;
    for(int i=2;i<=n;i++)
        if(a[i]==0) dp[i][0]=dp[i-1][0],dp[i][2]=dp[i-1][2]+2;
        else if(a[i]==1) dp[i][0]=dp[i-1][0]+1,dp[i][1]=min(dp[i-1][0],dp[i-1][1]),dp[i][2]=dp[i-1][2]+1;
        else if(a[i]==2) dp[i][0]=dp[i-1][0]+2,dp[i][1]=dp[i-1][0]+1,dp[i][2]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));
    if(min(dp[n][0],min(dp[n][1],dp[n][2]))>=INF) printf("BRAK");
    else printf("%d",min(dp[n][0],min(dp[n][1],dp[n][2])));
    return 0;
}