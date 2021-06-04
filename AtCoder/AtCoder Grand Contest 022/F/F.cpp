#include<iostream>
#include<cstdio>
#include<cassert>
using namespace std;
const int N=55;
const int MOD=1000000007;
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=1LL*res*a%MOD;
        a=1LL*a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int x)
{
    return ksm(x,MOD-2);
}
int n;
int fac[N],inv[N];
void init(int n=50)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=1LL*fac[i-1]*i%MOD;
    inv[n]=getinv(fac[n]);
    for(int i=n;i>=1;i--)
        inv[i-1]=1LL*inv[i]*i%MOD;
    return;
}
int f[N][N][N+N];
int main()
{
    init();
    scanf("%d",&n);
    f[1][1][-1+n]=f[1][1][0+n]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=-n;k<=n;k++)
                if(f[i][j][k+n])
                {
                    for(int x=0;x<=n;x++)
                        for(int y=0;y<=n;y++)
                            if(x+y>0&&j+x+y<=n&&k+x+y>=0&&k-x-y<=0&&(k+x-y)%2==0)
                                if((k+x-y)/2>=-n&&(k+x-y)/2<=n) f[i+1][j+x+y][(k+x-y)/2+n]=(f[i+1][j+x+y][(k+x-y)/2+n]+1LL*f[i][j][k+n]*inv[x]%MOD*inv[y]%MOD)%MOD;
                }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+f[i][n][n])%MOD;
    ans=1LL*ans*fac[n]%MOD;
    printf("%d",ans);
    return 0;
}