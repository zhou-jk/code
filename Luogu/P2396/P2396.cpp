#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000007;
const int N=24;
int n,K;
int a[3];
int s[N+1];
int dp[1<<N|1],f[1<<N|1];
long long fac(int n)
{
    long long res=1;
    for(int i=2;i<=n;i++)
        res=res*i%MOD;
    return res;
}
int lowbit(int x)
{
    return x&-x;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        f[1<<(i-1)]=s[i];
    }
    scanf("%d",&K);
    if(K==0)
    {
        printf("%lld",fac(n));
        return 0;
    }
    for(int i=1;i<=K;i++)
        scanf("%d",&a[i]);
    dp[0]=1;
    for(int i=1;i<(1<<n);i++)
    {
        int k=lowbit(i);
        f[i]=f[i^k]+f[k];
        bool flag=true;
        for(int j=1;j<=K;j++)
            if(f[i]==a[j])
            {
                flag=false;
                break;
            }
        if(flag)
            for(int j=i;j;j&=j-1)
                dp[i]=(dp[i]+dp[i^lowbit(j)])%MOD;
    }
    printf("%d",dp[(1<<n)-1]);
    return 0;
}