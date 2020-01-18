#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=18;
const int MOD=1000000007;
int T;
long long l,r;
long long fac[N+1],Pow[N+1];
long long f[N+1],g[N+1],num[N+1];
void calc(long long x,long long dp[])
{
    int len=0;
    while(x)
        num[++len]=x%10,x/=10;
    for(int i=len;i>0;i--)
    {
        for(int j=0;j<=9;j++)
            dp[j]=(dp[j]+fac[i-1]*num[i]%MOD)%MOD;
        for(int j=0;j<num[i];j++)
            dp[j]=(dp[j]+Pow[i-1])%MOD;
        long long sum=0;
        for(int j=i-1;j>0;j--) 
            sum=(sum*10+num[j])%MOD;
        dp[num[i]]=(dp[num[i]]+sum+1)%MOD;
        dp[0]=(dp[0]-Pow[i-1]+MOD)%MOD;
    }
    return;
}
int main()
{
    scanf("%d",&T);
    Pow[0]=1;
    for(int i=1;i<=N;i++)
        Pow[i]=Pow[i-1]*10,fac[i]=fac[i-1]*10+Pow[i-1];
    while(T--)
    {
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        scanf("%lld%lld",&l,&r);
        calc(r,f);
        calc(l-1,g);
        long long ans=0;
        for(int i=0;i<=9;i++)
            ans=(ans+(f[i]-g[i]+MOD)%MOD*i%MOD)%MOD;
        printf("%lld\n",ans);
    }
    return 0 ;
}