#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
char s[N];
int dp[N];
vector<int>G[N];
int ans;
void dfs(int u,int father)
{
    int mx=0,sum=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        if(dp[v]>mx) mx=dp[v];
        sum+=dp[v];
    }
    if(s[u]=='1') sum--;
    if(s[u]=='1')
    {
        dp[u]=max(sum,1);
        ans=max(ans,mx+1);
    }
    else dp[u]=max(sum,0);
    ans=max(ans,dp[u]);
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    scanf("%s",s+1);
    dfs(1,0);
    printf("%d",ans);
    return 0;
}