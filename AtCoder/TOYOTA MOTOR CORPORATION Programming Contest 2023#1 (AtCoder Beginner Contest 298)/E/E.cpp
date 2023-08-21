#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
const int MOD=998244353;
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=(long long)res*a%MOD;
        a=(long long)a*a%MOD,b>>=1;
    }
    return res;
}
int getinv(int a)
{
    return qpow(a,MOD-2);
}
int n,a,b,p,q;
int f[N][N],g[N][N];
int main()
{
    scanf("%d%d%d%d%d",&n,&a,&b,&p,&q);
    f[0][a]=1;
    int invp=getinv(p);
    for(int i=1;i<=n;i++)
        for(int j=0;j<n;j++)
            for(int k=1;k<=p;k++)
                if(f[i-1][j]) f[i][min(j+k,n)]=(f[i][min(j+k,n)]+(long long)f[i-1][j]*invp)%MOD;
    g[0][b]=1;
    int invq=getinv(q);
    for(int i=1;i<=n;i++)
        for(int j=0;j<n;j++)
            for(int k=1;k<=q;k++)
                if(g[i-1][j]) g[i][min(j+k,n)]=(g[i][min(j+k,n)]+(long long)g[i-1][j]*invq)%MOD;
    int ans=0;
    for(int i=0;i<=n;i++)
        for(int j=b;j<=n;j++)
            ans=(ans+(long long)f[i][n]*g[i][j])%MOD;
    printf("%d",ans);
    return 0;
}