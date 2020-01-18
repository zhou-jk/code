#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000000;
int n;
int prime[N+1][24],cnt[N+1];
int dp[N+1];
bool isprime[N+1];
int main()
{
    memset(isprime,true,sizeof(isprime));
    for(int i=2;i<=N;i++)
        if(isprime[i])
        {
            prime[i][++cnt[i]]=i;
            for(int j=i+i;j<=N;j+=i)
                isprime[j]=false,prime[j][++cnt[j]]=i;
        }
    for(int i=2;i<=N;i++)
    {
        dp[i]=dp[i-1]+1;
        for(int j=1;j<=cnt[i];j++)
            dp[i]=min(dp[i],dp[i/prime[i][j]]+1);
    }
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",dp[n]);
    return 0;
}