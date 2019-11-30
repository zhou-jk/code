#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=101,M=20001;
int s,n,m;
int a[N][N];
int dp[M];
int main()
{
    scanf("%d%d%d",&s,&n,&m);
    for(int i=1;i<=s;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[j][i]);
            a[j][i]=a[j][i]*2+1;
        }
    for(int i=1;i<=n;i++)
        sort(a[i]+1,a[i]+s+1);
    for(int i=1;i<=n;i++)
        for(int j=m;j>=0;j--)
            for(int k=1;k<=s;k++)
                if(j>=a[i][k]) dp[j]=max(dp[j-a[i][k]]+k*i,dp[j]);
    printf("%d",*max_element(dp,dp+m+1));
    return 0;
}