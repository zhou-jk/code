#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000001;
const int MOD=1000000007;
int a,b,k,t;
int n;
long long dp[N],f[N];
long long ans;
int main()
{
    scanf("%d%d%d%d",&a,&b,&k,&t);
    n=k*t*2;
    dp[n]=1;
    for(int i=1;i<=t*2;i++)
    {
        f[0]=dp[0];
        for(int j=1;j<=n*2+k;j++)
            f[j]=(f[j-1]+dp[j])%MOD;
        for(int j=0;j<=k;j++)
            dp[j]=f[j+k];
        for(int j=k+1;j<=n*2;j++)
            dp[j]=(f[j+k]-f[j-k-1]+MOD)%MOD;
    }
    for(int i=n-a+b+1;i<=n*2;i++)
        ans=(ans+dp[i])%MOD;
    printf("%lld",ans);
    return 0;
}