#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=101;
int n,k;
int ans[N],res;
int w[N],dp[2005];
int DP(int u,int sum)
{
    memset(dp,63,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=u;i++)
        for(int j=w[i];j<=n*sum;j++)
            dp[j]=min(dp[j],dp[j-w[i]]+1);
    for(int i=1;i<=n*sum;i++)
        if(dp[i]>n) return i-1;
    return n*sum;
}
void dfs(int step,int l,int r,int sum)
{
    if(step>k)
    {
        if(res<r)
        {
            res=r;
            for(int i=1;i<=n;i++)
                ans[i]=w[i];
        }
        return;
    }
    for(int i=l+1;i<=r+1;i++)
    {
        w[step]=i;
        dfs(step+1,i,DP(step,sum+i),sum+i);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    dfs(1,0,0,0);
    for(int i=1;i<=k;i++)
        printf("%d ",ans[i]);
    printf("\nMAX=%d",res);
    return 0;
}