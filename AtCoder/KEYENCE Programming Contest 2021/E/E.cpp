#include<iostream>
#include<cstdio>
using namespace std;
const int N=405;
int n;
int a[N];
int dp[N][N][N];
int dfs(int l,int r,int k)
{
    if(dp[l][r][k]!=-1) return dp[l][r][k];
    if(l==0&&r==n+1) return dp[l][r][k]=0;
    if(l>=1)
    {
        if(k>0) dp[l][r][k]=max(dp[l][r][k],dfs(l-1,r,k-1)+a[l]);
        if(a[l]>a[r]) dp[l][r][k]=max(dp[l][r][k],dfs(l-1,r,k+1));
    }
    if(r<=n)
    {
        if(k>0) dp[l][r][k]=max(dp[l][r][k],dfs(l,r+1,k-1)+a[r]);
        if(a[r]>a[l]) dp[l][r][k]=max(dp[l][r][k],dfs(l,r+1,k+1));
    }
    return dp[l][r][k];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int l=0;l<=n+1;l++)
        for(int r=l+1;r<=n+1;r++)
            for(int k=0;k<=n;k++)
                dp[l][r][k]=-1;
    for(int i=0;i<=n;i++)
        printf("%d\n",dfs(i,i+1,1));
    return 0;
}