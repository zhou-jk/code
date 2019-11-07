#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T;
unsigned long long x,y;
unsigned long long dp[22][60005];
int a[22];
int change(int s,int i)
{
    int t[12];
    for(int i=0;i<=9;i++)
        t[i]=s%3,s/=3;
    if(t[i]==1) t[i]=2;
    else t[i]=1;
    s=0;
    for(int i=9;i>=0;i--)
        s=s*3+t[i];
    return s;
}
bool check(int s)
{
    for(int i=0;i<=9;i++)
    {
        if(s%3==1&&i%2==1) return false;
        else if(s%3==2&&i%2==0) return false;
        s/=3;
    }
    return true;
}
unsigned long long dfs(int pos,int s,int p,int z)
{
    if(pos==-1)return check(s);
    if(!p&&dp[pos][s]!=-1) return dp[pos][s];
    int num=p?a[pos]:9;
    unsigned long long ans=0;
    for(int i=0;i<=num;i++)
        ans+=dfs(pos-1,(z&&i==0)?0:change(s,i),p&&i==num,z&&i==0);
    if(!p) dp[pos][s]=ans;
    return ans;
}
unsigned long long cal(unsigned long long x)
{
    int pos=0;
    while(x)
        a[pos++]=x%10,x/=10;
    return dfs(pos-1,0,1,1);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d",&T);
    while(T--)
    {
        scanf("%llu%llu",&x,&y);
        printf("%llu\n",cal(y)-cal(x-1));
    }
    return 0;
}