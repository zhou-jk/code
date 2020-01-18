#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=12345678;
int n,m,K;
long long dp[152][152][22][22];
long long ans;
int main()
{
    scanf("%d%d%d",&n,&m,&K);
    dp[0][0][0][0]=1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=K;k++)
                for(int l=0;l<=K;l++)
                {
                    dp[i+1][j][k+1][max(0,l-1)]=(dp[i+1][j][k+1][max(0,l-1)]+dp[i][j][k][l])%MOD;
					dp[i][j+1][max(0,k-1)][l+1]=(dp[i][j+1][max(0,k-1)][l+1]+dp[i][j][k][l])%MOD;
                } 
    for(int i=0;i<=K;i++)
        for(int j=0;j<=K;j++)
            ans=(ans+dp[n][m][i][j])%MOD;
    printf("%lld",ans);
    return 0;
}