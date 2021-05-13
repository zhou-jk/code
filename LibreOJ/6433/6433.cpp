#include<iostream>
#include<cstdio>
using namespace std;
const int N=20;
const int MOD=998244353;
int n;
int a[N];
int g[1<<N],f[1<<N];
int sum[1<<N];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int S=1;S<(1<<n);S++)
        for(int i=0;i<n;i++)
            if(S&(1<<i)) sum[S]+=a[i];
    f[0]=1;
    for(int S=1;S<(1<<n);S++)
        for(int i=0;i<n;i++)
            if(S&(1<<i))
            {
                if(sum[S]>=0) f[S]=(f[S]+f[S^(1<<i)])%MOD;
            }
    g[0]=1;
    for(int S=1;S<(1<<n);S++)
        for(int i=0;i<n;i++)
            if(S&(1<<i))
            {
                if(sum[S]<0) g[S]=(g[S]+g[S^(1<<i)])%MOD;
            }
    int ans=0;
    for(int i=0;i<n;i++)
        for(int S=0;S<(1<<n);S++)
            if(!(S&(1<<i)))
            {
                int T=((1<<n)-1)^S^(1<<i);
                ans=(ans+1LL*f[S]*g[T]%MOD*sum[S|(1<<i)])%MOD;
            }
    ans=(ans+MOD)%MOD;
    printf("%d",ans);
    return 0;
}