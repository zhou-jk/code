#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a,b;
long long dp[20][20],num[20];
long long dfs(int k,bool limit,bool lead,int flag,long long sum)
{
    long long ans=0;
    if(k==0) return sum;
    if(!limit&&lead&&dp[k][sum]!=-1) return dp[k][sum];
    int up=limit?num[k]:9;
    for(int j=0;j<=up;j++)
        ans+=dfs(k-1,(j==up)&&limit,lead||j,flag,sum+((j||lead)&&(j==flag)));
    if(!limit&&lead) dp[k][sum]=ans;
    return ans;
}
long long calc(long long x,int d)
{
    memset(dp,-1,sizeof(dp));
    int len=0;
    while(x)
        num[++len]=x%10,x/=10;
    return dfs(len,true,false,d,false);
}
int main()
{
    scanf("%lld%lld",&a,&b);
    for(int i=0;i<=9;i++)
        printf("%lld ",calc(b,i)-calc(a-1,i));
    return 0;
}