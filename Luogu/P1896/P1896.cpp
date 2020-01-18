#include<iostream>
#include<cstdio>
using namespace std;
const int N=10;
int n,K;
int num[1<<N];
long long dp[N][N*N][1<<N];
bool book[1<<N];
int main()
{
    scanf("%d%d",&n,&K);
    for(int i=0;i<(1<<n);i++)
        if(!(i&(i<<1)))
        {
            book[i]=true;
            int t=i;
            while(t)
            {
                if(t&1) num[i]++;
                t>>=1;
            }
            dp[1][num[i]][i]=1;
        }
    for(int i=2;i<=n;i++)
        for(int j=0;j<=K;j++)
            for(int k=0;k<(1<<n);k++)
            {
                if(!book[k]) continue;
                if(num[k]>j) continue;
                for(int l=0;l<(1<<n);l++)
                {
                    if(!book[l]) continue;
                    if((l&k)||((k<<1)&l)||((k>>1)&l)) continue;
                    dp[i][j][k]+=dp[i-1][j-num[k]][l];
                }
            }
    long long ans=0;
    for(int i=0;i<(1<<n);i++)
        ans+=dp[n][K][i];
    printf("%lld", ans);
    return 0;
}