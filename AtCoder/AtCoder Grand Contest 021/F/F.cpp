#include<iostream>
#include<cstdio>
#include<vector>
#include<functional>
using namespace std;
const int N=8005;
const int g=3;
const int MOD=998244353;
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
std::vector<int>W[2];
void init_omega(int n)
{
    for(int len=1;len<=n;len<<=1)
    {
        int w=ksm(g,(MOD-1)/len),iw=getinv(w);
        W[0][len]=W[1][len]=1;
        for(int k=1;k<len;k++)
            W[0][len+k]=1LL*W[0][len+k-1]*w%MOD,W[1][len+k]=1LL*W[1][len+k-1]*iw%MOD;
    }
    return;
}
void init_poly(int _n)
{
    int n=1;
    while(n<=_n) n<<=1;
    W[0].resize(n*4+1);
    W[1].resize(n*4+1);
    init_omega(n*2);
    return;
}
typedef std::vector<int> Poly;
Poly ntt(const Poly &F,const Poly &G,const std::function<int(int,int)> &mul)
{
    Poly f=F,g=G;
    int n=f.size()-1,m=g.size()-1;
    m+=n,n=1;
    while(n<=m) n<<=1;
    f.resize(n);
    g.resize(n);
    std::vector<int>rev(n);
    for(int i=0;i<n;i++)
    {
        rev[i]=rev[i>>1]>>1;
        if(i&1) rev[i]|=n>>1;
    }
    static const int BIT=15;
    std::function<void(Poly &)> dft=[=](Poly &F)
    {
        int n=F.size();
        std::vector<unsigned long long>f(n);
        for(int i=0;i<n;i++)
            f[i]=F[rev[i]];
        for(int len=2;len<=n;len<<=1)
        {
            if(len&(1<<BIT))
            {
                for(int i=0;i<n;i++)
                    f[i]%=MOD;
            }
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    unsigned long long l=f[k];
                    int r=W[0][len+k-i]*f[k+len/2]%MOD;
                    f[k]=l+r;
                    f[k+len/2]=l+MOD-r;
                }
        }
        for(int i=0;i<n;i++)
            F[i]=f[i]%MOD;
        return;
    };
    dft(f);
    dft(g);
    for(int i=0;i<n;i++)
        f[i]=mul(f[i],g[i]);
    std::function<void(Poly &)> idft=[=](Poly &F)
    {
        int n=F.size();
        std::vector<unsigned long long>f(n);
        for(int i=0;i<n;i++)
            f[i]=F[rev[i]];
        for(int len=2;len<=n;len<<=1)
        {
            if(len&(1<<BIT))
            {
                for(int i=0;i<n;i++)
                    f[i]%=MOD;
            }
            for(int i=0;i<n;i+=len)
                for(int k=i;k<i+len/2;k++)
                {
                    unsigned long long l=f[k];
                    int r=W[1][len+k-i]*f[k+len/2]%MOD;
                    f[k]=l+r;
                    f[k+len/2]=l+MOD-r;
                }
        }
        for(int i=0;i<n;i++)
            F[i]=f[i]%MOD;
        int invn=getinv(n);
        for(int i=0;i<n;i++)
            F[i]=1LL*F[i]*invn%MOD;
        return;
    };
    idft(f);
    f.resize(m+1);
    return f;
}
Poly operator*(const Poly &F,const Poly &G)
{
    return ntt(F,G,[=](const int &x,const int &y){return 1LL*x*y%MOD;});
}
int fac[N],ifac[N];
void init(int n)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=1LL*fac[i-1]*i%MOD;
    ifac[n]=getinv(fac[n]);
    for(int i=n;i>=1;i--)
        ifac[i-1]=1LL*ifac[i]*i%MOD;
    return;
}
int C(int n,int m)
{
    if(m>n) return 0;
    else return 1LL*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int n,m;
int dp[N][N];
int main()
{
    init(8003);
    init_poly(8000);
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        dp[i][1]=1;
    for(int j=2;j<=m;j++)
    {
        Poly f(n),g(n);
        for(int k=0;k<n;k++)
            f[k]=1LL*dp[k][j-1]*ifac[k]%MOD;
        for(int k=0;k<n;k++)
            g[k]=ifac[k+3];
        Poly res=f*g;
        for(int i=0;i<=n;i++)
        {
            dp[i][j]=1LL*(1+i+i*(i-1)/2)*dp[i][j-1]%MOD;
            if(i-1>=0) dp[i][j]=(dp[i][j]+1LL*res[i-1]*fac[i+2])%MOD;
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)
        ans=(ans+1LL*dp[i][m]*C(n,i))%MOD;
    printf("%d",ans);
    return 0;
}