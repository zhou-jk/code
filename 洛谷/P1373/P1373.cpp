#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1000000007;
int f[801][801][17][2];
int n,m,k;
int w[801][801],ans;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    k++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&w[i][j]);
            f[i][j][w[i][j]%k][0]=1;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int p=0;p<=k;p++)
            {
                f[i][j][p][0]=(f[i][j][p][0]+f[i-1][j][(p-w[i][j]+k)%k][1])%mod;
                f[i][j][p][0]=(f[i][j][p][0]+f[i][j-1][(p-w[i][j]+k)%k][1])%mod;
                f[i][j][p][1]=(f[i][j][p][1]+f[i-1][j][(p+w[i][j])%k][0])%mod;
                f[i][j][p][1]=(f[i][j][p][1]+f[i][j-1][(p+w[i][j])%k][0])%mod;
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans=(ans+f[i][j][0][1])%mod;
    printf("%d",ans);
    return 0;
}