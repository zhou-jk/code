#include<iostream>
#include<cstdio>
using namespace std;
const int N=3005;
const int MOD=1000000007;
const int INV2=500000004;
int n,m;
int f[N][N];
int main()
{
    scanf("%d%d",&n,&m);
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(j-1>=0) f[i][j]=(f[i][j]+(long long)f[i-1][j-1]*(m-(j-1))%MOD*4)%MOD;
            if(i-2>=0) f[i][j]=(f[i][j]+(long long)f[i-2][j-1]*(m-(j-1))%MOD*(n-(i-1)))%MOD;
            if(j-2>=0) f[i][j]=(f[i][j]+(long long)f[i-1][j-2]*(m-(j-2))%MOD*(m-(j-2)-1)%MOD*INV2)%MOD;
        }
    int ans=0;
    for(int j=1;j<=m;j++)
        ans=(ans+f[n][j])%MOD;
    printf("%d",ans);
    return 0;
}