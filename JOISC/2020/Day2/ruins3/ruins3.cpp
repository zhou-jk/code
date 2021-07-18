#include<iostream>
#include<cstdio>
using namespace std;
const int N=605;
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
int a[N];
bool c[N*2];
int suf0[N*2],suf1[N*2];
int C[N][N];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD; 
    }
    return;
}
int g[N][N];
int f[N*2][N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        c[a[i]]=true;
    for(int i=n*2;i>=1;i--)
        suf1[i]=suf1[i+1]+c[i],suf0[i]=suf0[i+1]+(!c[i]);
    init(n);
    g[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
        {
            g[i][j]=g[i-1][j];
            if(j-1>=0) g[i][j]=(g[i][j]+1LL*g[i-1][j-1]*j%MOD*2)%MOD;
            if(j-2>=0) g[i][j]=(g[i][j]+1LL*g[i-1][j-2]*(j-1)%MOD*j)%MOD;
        }
    f[n*2+1][0]=1;
    for(int i=n*2;i>=1;i--)
        if(c[i])
        {
            for(int j=0;j<=suf1[i+1];j++)
            {
                f[i][j]=(f[i][j]+f[i+1][j])%MOD; 
                for(int k=1;k-1<=suf1[i+1]-j;k++)
                    f[i][j+k]=(f[i][j+k]+1LL*f[i+1][j]*(k+1)%MOD*C[suf1[i+1]-j][k-1]%MOD*g[k-1][k-1])%MOD;
            }
        }
        else
        {
            for(int j=suf0[i+1];j<=suf1[i+1];j++)
                f[i][j]=(f[i][j]+1LL*f[i+1][j]*(j-suf0[i+1]))%MOD;
        }
    int ans=1LL*f[1][n]*getinv(ksm(2,n))%MOD;
    printf("%d",ans);
    return 0;
}