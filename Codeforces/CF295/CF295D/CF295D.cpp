#include<iostream>
#include<cstdio>
using namespace std;
const int N=2001;
const int MOD=1000000007;
int n,m;
long long dp[N][N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        dp[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        long long sum=0;
        dp[i][1]=1;
        for(int j=2;j<=m;j++)
            sum=(sum+dp[i-1][j])%MOD,dp[i][j]=(dp[i][j]+dp[i][j-1]+sum)%MOD;
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        for(int j=2;j<=m;j++)
            ans=(ans+(dp[i][j]-dp[i-1][j]+MOD)*dp[n-i+1][j]%MOD*(m-j+1)%MOD)%MOD;
    printf("%lld",ans);
    return 0;
}