#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=100000000;
const int N=2001;
int n,f;
int a[N];
long long dp[N][N];
int main()
{
    scanf("%d%d",&n,&f);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        dp[i][a[i]%f]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<f;j++)
            dp[i][j]=(dp[i][j]+(dp[i-1][j]+dp[i-1][((j-a[i])%f+f)%f])%MOD)%MOD;
    printf("%lld",dp[n][0]);
    return 0;
}