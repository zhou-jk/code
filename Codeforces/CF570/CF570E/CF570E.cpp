#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MOD=1000000007;
const int N=501;
int n,m;
char e[N][N];
long long dp[2][N][N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",e[i]+1);
    int cur=0;
    if(e[1][1]==e[n][m]) dp[cur][1][n]=1;
    for(int i=1;i<=(n+m)/2-1;i++)
    {
        cur^=1;
        memset(dp[cur],0,sizeof(dp[cur]));
        for(int x1=1;x1<=n;x1++)
            for(int x2=n;x2>=1;x2--)
            {
                int y1=i+2-x1,y2=n+m-i-x2;
                if(x1<1||x1>n||y1<1||y1>m) continue;
                if(x2<1||x2>n||y2<1||y2>m) continue;
                if(e[x1][y1]!=e[x2][y2]) continue;
                dp[cur][x1][x2]=(dp[cur][x1][x2]+dp[cur^1][x1][x2])%MOD;
                dp[cur][x1][x2]=(dp[cur][x1][x2]+dp[cur^1][x1-1][x2+1])%MOD;
                dp[cur][x1][x2]=(dp[cur][x1][x2]+dp[cur^1][x1-1][x2])%MOD;
                dp[cur][x1][x2]=(dp[cur][x1][x2]+dp[cur^1][x1][x2+1])%MOD;
            }
    }
    long long ans=0;
    if((n+m)%2)
    {
        for(int i=1;i<=n;i++)
            ans=(ans+dp[cur][i][i])%MOD;
        for(int i=1;i<n;i++)
            ans=(ans+dp[cur][i][i+1])%MOD;
    }
    else
    {
        for(int i=1;i<=n;i++)
            ans=(ans+dp[cur][i][i])%MOD;
    }
    printf("%lld",ans);
    return 0;
}