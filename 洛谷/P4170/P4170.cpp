#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=51;
int n;
char s[N];
int dp[N][N];
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    memset(dp,63,sizeof(dp));
    for(int i=1;i<=n;i++)
        dp[i][i]=1;
    for(int len=2;len<=n;len++) 
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(s[i]==s[j]) dp[i][j]=min(dp[i][j],min(dp[i+1][j],dp[i][j-1]));
            for(int k=i;k<j;k++) 
                dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);
        }
    printf("%d",dp[1][n]);
    return 0;
}