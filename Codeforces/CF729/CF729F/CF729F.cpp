#include<iostream>
#include<cstdio>
using namespace std;
const int N=2101;
int n;
int a[N<<1],sum[N<<1];
int dp[2][N][200][100];
bool book[2][N][200][100];
int dfs(int t,int l,int d,int k)
{
    if(book[t][l][d][k]!=0) return dp[t][l][d][k];
    book[t][l][d][k]=1;
    int r=n+1-(l+d-100);
    if(t==0)
    {
        if(l+k<r)
        {
            dp[t][l][d][k]=dfs(1,l+k,d-k,k);
            if(l+k+1<r) dp[t][l][d][k]=max(dp[t][l][d][k],dfs(1,l+k+1,d-k-1,k+1));
        }
        else dp[t][l][d][k]=(sum[l]-sum[0])-(sum[n]-sum[r-1]);
    }
    else
    {
        if(r-k>l)
        {
            dp[t][l][d][k]=dfs(0,l,d+k,k);
            if(r-k-1>l) dp[t][l][d][k]=min(dp[t][l][d][k],dfs(0,l,d+k+1,k+1));
        }
        else dp[t][l][d][k]=(sum[l]-sum[0])-(sum[n]-sum[r-1]);
    }
    return dp[t][l][d][k];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    printf("%d",dfs(0,0,100,1));
    return 0;
}