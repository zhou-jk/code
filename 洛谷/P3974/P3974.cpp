#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1001;
int T,n,m;
int a[N][N];
long long dp[N][N];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=m;j>0;j--)
                dp[i][j]=max(max(dp[i-1][j],dp[i][j+1]),dp[i-1][j+1]+a[i][j]);
        printf("%lld\n",dp[n][1]);
    }
    return 0;
}