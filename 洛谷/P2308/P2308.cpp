#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int a[50],sum[61];
int L[50],R[50];
int f[50][50],dp[50][50];
void dfs(int x,int y)
{
    if(x==y) return;
    L[x]++,R[y]++;
    dfs(x,f[x][y]);
    dfs(f[x][y]+1,y);
    return;
}
void print(int x,int y)
{
    if(x==y) return;
    print(x,f[x][y]);
    print(f[x][y]+1,y);
    printf("%d ",sum[y]-sum[x-1]);
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    memset(dp,63,sizeof(dp));
    for(int i=1;i<=n;i++)
        dp[i][i]=0;
    for(int i=n-1;i>0;i--)
        for(int j=i+1;j<=n;j++)
            for(int k=i;k<j;k++)
                if(dp[i][j]>=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]) dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1],f[i][j]=k;
    dfs(1,n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=L[i];j++)
            printf("(");
        printf("%d",a[i]);
        if(!R[i]&&i!=n) printf("+");
        for(int j=1;j<=R[i];j++)
            printf(")");
        if(R[i]&&i!=n) printf("+");
    }
    printf("\n%d\n",dp[1][n]);
    print(1,n);
    return 0;
}