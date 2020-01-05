#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
int a[N],sum[N];
int dp[N][N];
int main()
{
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        dp[i][i]=a[i];
    }
    for(int i=n-1;i>=1;i--)
        for(int j=i+1;j<=n;j++)
            dp[i][j]=max(sum[j]-sum[i-1]-dp[i+1][j],sum[j]-sum[i-1]-dp[i][j-1]);
    printf("%d %d",dp[1][n],sum[n]-dp[1][n]);
    return 0;
}
