#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=101,M=6;
const int MOD=1000000007;
int n,m;
long long dp[2][1<<M][1<<M];
vector<int> f[1<<M][1<<M];
bool check(int x,int y)
{
    for(int i=0;i<m;i++)
    {
        if(i<m-2&&((x>>i)&1)&&((y>>(i+2))&1)&&(!((x>>(i+1))&1)||!((y>>(i+1))&1))) return false;
        if(i>1&&((x>>i)&1)&&((y>>(i-2))&1)&&(!((x>>(i-1))&1)||!((y>>(i-1))&1))) return false;
    }
    return true;
}
bool judge(int x,int y,int z)
{
    for(int i=0;i<m;i++)
    {
        if(i<m-1&&((x>>i)&1)&&((z>>(i+1))&1)&&(!((y>>i)&1)||!((y>>(i+1))&1))) return false;
        if(i>0&&((x>>i)&1)&&((z>>(i-1))&1)&&(!((y>>i)&1)||!((y>>(i-1))&1))) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    if(n==1)
    {
        printf("%d",1<<m);
        return 0;
    }
    for(int i=0;i<(1<<m);i++)
        dp[1][i][0]=1;
    for(int i=0;i<(1<<m);i++)
        for(int j=0;j<(1<<m);j++)
            if(check(i,j)) dp[0][i][j]+=dp[1][j][0];
    for(int i=0;i<(1<<m);i++)
        for(int j=0;j<(1<<m);j++)
            if(check(i,j))
                for(int k=0;k<(1<<m);k++)
                    if(check(j,k)&&judge(i,j,k)) f[i][j].push_back(k);
    for(int i=3;i<=n;i++)
    {
        memset(dp[i&1],0,sizeof(dp[i&1]));
        for(int j=0;j<(1<<m);j++)
            for(auto k:f[0][j])
                for(auto l:f[j][k])
                    dp[i&1][l][k]=(dp[i&1][l][k]+dp[(i&1)^1][k][j])%MOD;
    }
    long long ans=0;
    for(int i=0;i<(1<<m);i++)
        for(int j=0;j<(1<<m);j++)
            ans=(ans+dp[n&1][i][j])%MOD;
    printf("%lld",ans);
    return 0;
}