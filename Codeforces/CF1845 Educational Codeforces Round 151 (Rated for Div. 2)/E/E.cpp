#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=1505,SQRTM=60;
const int MOD=1000000007;
int n,m;
int a[N];
int f[2][SQRTM+SQRTM][N];
int main()
{
    scanf("%d%d",&n,&m);
    int lim=floor(sqrt(2*m))+1;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    f[0][lim][0]=1;
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        cur^=1;
        for(int j=-lim;j<=lim;j++)
            for(int k=0;k<=m;k++)
                f[cur][j+lim][k]=0;
        for(int j=-lim;j<=lim;j++)
            for(int k=0;k<=m;k++)
                if(f[cur^1][j+lim][k])
                {
                    if(-lim<=j+a[i]&&j+a[i]<=lim&&k+abs(j+a[i])<=m) f[cur][j+a[i]+lim][k+abs(j+a[i])]=(f[cur][j+a[i]+lim][k+abs(j+a[i])]+f[cur^1][j+lim][k])%MOD;
                    if(-lim<=j+a[i]-1&&j+a[i]-1<=lim&&k+abs(j+a[i]-1)<=m) f[cur][j+a[i]-1+lim][k+abs(j+a[i]-1)]=(f[cur][j+a[i]-1+lim][k+abs(j+a[i]-1)]+f[cur^1][j+lim][k])%MOD;
                }
    }
    int ans=0;
    for(int k=0;k<=m;k++)
        if(k%2==m%2) ans=(ans+f[cur][lim][k])%MOD;
    printf("%d",ans);
    return 0;
}