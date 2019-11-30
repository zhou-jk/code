#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3005;
int n,v;
int a[N],sum[N];
int f[N][N],dp[N][N],m[N][N];
int main()
{
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            int mid=(i+j)/2;
            f[i][j]+=a[mid]*(mid-i)-(sum[mid-1]-sum[i-1])+(sum[j]-sum[mid])-a[mid]*(j-mid);
        }
    memset(dp,63,sizeof(dp));
    for(int i=1;i<=n;i++)
        dp[i][1]=f[1][i];
    for(int j=2;j<=v;j++)
    {
        m[n+1][j]=n;
        for(int i=n;i>0;i--)
            for(int k=m[i][j-1];k<=m[i+1][j];k++)
                if(dp[i][j]>dp[k][j-1]+f[k+1][i]) dp[i][j]=dp[k][j-1]+f[k+1][i],m[i][j]=k;    
    }
    printf("%d",dp[n][v]);
    return 0;    
}