#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long INF=4485090715960753727;
int N,K;
long long dp[301][301][256],f[2];
int c[301],w[301],a[301];
long long ans=-INF;
int main()
{
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++)
    {
        char ch;
        for(ch=getchar();ch!='0'&&ch!='1';ch=getchar());
        a[i]=ch=='1';
    }
    for(int i=0;i<(1<<K);i++)
        scanf("%d%d",&c[i],&w[i]);
    memset(dp,-63,sizeof(dp));
    for(int i=N;i>=1;i--)
        for(int j=i;j<=N;j++)
        {
            if(i==j)
            {
                dp[i][j][a[i]]=0;
                continue;
            }
            int len=(j-i-1)%(K-1)+1;
            for(int k=j;k>i;k-=K-1)
                for(int l=0;l<(1<<len);l++)
                {
                    dp[i][j][l*2]=max(dp[i][j][l*2],dp[i][k-1][l]+dp[k][j][0]);
                    dp[i][j][l*2+1]=max(dp[i][j][l*2+1],dp[i][k-1][l]+dp[k][j][1]);
                }
            if(len==K-1)
            {
                f[0]=f[1]=-INF;
                for(int k=0;k<(1<<K);k++)
                    f[c[k]]=max(f[c[k]],dp[i][j][k]+w[k]);
                dp[i][j][0]=f[0],dp[i][j][1]=f[1];
            }
        }
    for(int k=0;k<(1<<K);k++)
        ans=max(ans,dp[1][N][k]);
    printf("%lld",ans);
    return 0;
}