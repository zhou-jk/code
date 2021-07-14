#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
const int MOD=1000000007;
int n,m,t;
int b[N][N];
int f[N][N];
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&b[i][j]);
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=m;j++)
        {
            f[i][0]=1;
            for(int k=i;k>1;k--)
                for(int l=0;l<n;l++)
                    for(int x=1;x<=m;x++)
                        if(b[i][j]+t*(l+1)>b[k-1][x]) f[k-1][l+1]=(f[k-1][l+1]+f[k][l])%MOD;
                        else f[k-1][l]=(f[k-1][l]+f[k][l])%MOD;
            for(int k=1;k<n;k++)
                ans=(ans+1LL*k*f[1][k])%MOD;
            for(int k=1;k<=i;k++)
                for(int l=0;l<=n;l++)
                    f[k][l]=0;
        }
        for(int j=i+1;j<=n;j++)
            ans=1LL*ans*m%MOD;
        printf("%d\n",ans);
    }
    return 0;
}