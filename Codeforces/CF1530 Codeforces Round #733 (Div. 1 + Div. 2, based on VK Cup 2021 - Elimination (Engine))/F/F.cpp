#include<iostream>
#include<cstdio>
using namespace std;
const int N=21;
const int MOD=31607;
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
int lowbit(int x)
{
    return x&-x;
}
int n;
int a[N][N];
int inv[N][N];
int lg2[1<<N];
int sum[N][1<<N];
int ss[N];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    int inv4=getinv(10000);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=1LL*a[i][j]*inv4%MOD;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            inv[i][j]=getinv(a[i][j]);
    lg2[1]=0;
    for(int i=2;i<(1<<n);i++)
        lg2[i]=lg2[i/2]+1;
    for(int j=0;j<n;j++)
    {
        int s=1;
        for(int i=0;i<n;i++)
            s=1LL*s*a[i][j]%MOD;
        sum[j][0]=s;
        for(int S=1;S<(1<<n);S++)
        {
            int i=lg2[lowbit(S)];
            sum[j][S]=1LL*sum[j][S^(1<<i)]*inv[i][j]%MOD;
        }
    }
    for(int i=0;i<n;i++)
    {
        ss[i]=1;
        for(int j=0;j<n;j++)
            ss[i]=1LL*ss[i]*a[i][j]%MOD;
    }
    int ans=0;
    for(int T=0;T<(1<<2);T++)
        for(int S=0;S<(1<<n);S++)
        {
            int res=1;
            for(int i=0;i<n;i++)
                if(S&(1<<i)) res=1LL*res*ss[i]%MOD;
            if(T&(1<<0))
            {
                for(int i=0;i<n;i++)
                    if(!(S&(1<<i))) res=1LL*res*a[i][i]%MOD;
            }
            if(T&(1<<1))
            {
                for(int i=0;i<n;i++)
                    if((!(T&(1<<0)))||i!=n-i-1)
                    {
                        if(!(S&(1<<i))) res=1LL*res*a[i][n-i-1]%MOD;
                    }
            }
            for(int i=0;i<n;i++)
            {
                int p=sum[i][S];
                if((!(S&(1<<i)))&&(T&(1<<0))) p=1LL*p*inv[i][i]%MOD;
                if((!(T&(1<<0)))||i!=n-i-1)
                {
                    if((!(S&(1<<(n-i-1))))&&(T&(1<<1))) p=1LL*p*inv[n-i-1][i]%MOD;
                }
                res=1LL*res*(1-p+MOD)%MOD;
            }
            if((__builtin_popcount(S)+__builtin_popcount(T))&1) ans=(ans-res+MOD)%MOD;
            else ans=(ans+res)%MOD;
        }
    ans=(1-ans+MOD)%MOD;
    printf("%d",ans);
    return 0;
}