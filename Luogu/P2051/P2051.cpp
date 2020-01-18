#include<iostream>
#include<cstdio>
using namespace std;
const int mod=9999973;
inline long long count(long long x)
{
    return (x*(x-1)/2)%mod;
}
int n,m;
long long f[101][101][101];
long long ans;
int main()
{
    scanf("%d%d",&n,&m);
    f[0][0][0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=m-j;k++)
            {
                f[i][j][k]=f[i-1][j][k];
                if(k>0) f[i][j][k]=(f[i][j][k]+f[i-1][j+1][k-1]*(j+1))%mod,f[i][j][k]=(f[i][j][k]+f[i-1][j][k-1]*j*(m-j-k+1))%mod;
                if(j>0) f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k]*(m-j-k+1))%mod;
                if(k>1) f[i][j][k]=(f[i][j][k]+(f[i-1][j+2][k-2]*count(j+2)))%mod;
                if(j>1) f[i][j][k]=(f[i][j][k]+f[i-1][j-2][k]*count(m-j-k+2))%mod;
            }
    for(int i=0;i<=m;i++)
        for(int j=0;j<=m;j++)
            ans=(ans+f[n][i][j])%mod;
    printf("%lld",ans);
    return 0;
}