#include<iostream>
#include<cstdio>
using namespace std;
const int N=305;
int n,m;
int MOD;
int C[N][N];
int f[N][N];
int s[N][N];
int main()
{
    scanf("%d%d%d",&n,&m,&MOD);
    for(int i=0;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    for(int i=0;i<=m;i++)
        f[1][i]=1;
    for(int i=m;i>=0;i--)
        s[1][i]=(s[1][i+1]+f[1][i])%MOD;
    for(int i=2;i<=n+1;i++)
    {
        for(int j=0;j<=m;j++)
            for(int k=1;k<i;k++)
                f[i][j]=(f[i][j]+1LL*f[i-k][j]*C[i-2][k-1]%MOD*s[k][j+1])%MOD;
        for(int j=m;j>=0;j--)
            s[i][j]=(s[i][j+1]+f[i][j])%MOD;
    }
    printf("%d",f[n+1][0]);
    return 0;
}