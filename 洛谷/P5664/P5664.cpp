#include<iostream>
#include<cstdio>
using namespace std;
const int N=101,M=2001;
int n,m;
int a[N][M];
long long dp[N][M];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    return 0;
}