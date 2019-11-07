#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a,u,v,ans;
int val[10001][32],dp[10001][32];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&u,&v);
        int like=0,hate=0;
        for(int j=1;j<=u;j++)
        {
            int x;
            scanf("%d",&x);
            like|=1<<((x-a+n)%n);
        }
        for(int j=1;j<=v;j++)
        {
            int x;
            scanf("%d",&x);
            hate|=1<<((x-a+n)%n);
        }
        for(int j=0;j<32;j++)
            if((like&j)||(hate&~j)) val[a][j]++;
    }
    for(int k=0;k<32;k++)
    {
        memset(dp[0],-63,sizeof(dp[0]));
        dp[0][k]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<32;j++)
                dp[i][j]=max(dp[i-1][(j&15)<<1],dp[i-1][(j&15)<<1|1])+val[i][j];
        ans=max(ans,dp[n][k]);
    }
    printf("%d",ans);
    return 0;
}