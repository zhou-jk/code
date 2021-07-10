#include<iostream>
#include<cstdio>
using namespace std;
const int N=505;
int n;
int MOD;
int f[N][N*N/2],sum[N*N/2];
int dp[N];
int A[N];
int main()
{
    scanf("%d%d",&n,&MOD);
    f[0][0]=sum[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i*(i-1)/2;j++)
            f[i][j]=((long long)sum[j]-(j>min(i-1,j)?sum[j-min(i-1,j)-1]:0)+MOD)%MOD;
        sum[0]=f[i][0];
        for(int j=1;j<=(i+1)*i/2;j++)
            sum[j]=(sum[j-1]+f[i][j])%MOD;
    }
    A[0]=1;
    for(int i=1;i<=n;i++)
        A[i]=1LL*A[i-1]*(n-i+1)%MOD;
    for(int i=1;i<=n;i++)
    {
        sum[0]=f[i][0];
        for(int j=1;j<=i*(i-1)/2;j++)
            sum[j]=(sum[j-1]+f[i][j])%MOD;
        int s=0,sj=0;
        for(int x=2;x<=i*(i-1)/2;x++)
        {
            if(x<=i+1)
            {
                sj=(sj+s)%MOD;
                sj=(sj+2LL*sum[x-2])%MOD;
            }
            else
            {
                sj=(sj+s)%MOD;
                sj=(sj-1LL*sum[x-(i+2)]*(i+2)%MOD+MOD)%MOD;
                sj=(sj+2LL*sum[x-2])%MOD;
            }
            dp[i]=(dp[i]-1LL*f[i][x]*sj%MOD+MOD)%MOD;
            s=(s+sum[x-2])%MOD;
            if(x>i+1) s=((long long)s-sum[x-1-(i+1)]+MOD)%MOD;
            dp[i]=(dp[i]+1LL*f[i][x]*s%MOD*(i+2)%MOD)%MOD;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int sum=1LL*dp[n-i]%MOD;
        ans=(ans+1LL*sum*A[i-1])%MOD;
    }
    printf("%d",ans);
    return 0;
}