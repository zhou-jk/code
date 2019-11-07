#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[30],sum=1; 
bool vis[30],dp[2001];
int ans=0;
void DP()
{
    memset(dp,false,sizeof(dp));
    dp[0]=true;
    for(int i=1;i<=n;i++)
        if(!vis[i])
            for(int j=2000;j>=a[i];j--)
                if(dp[j-a[i]]&&!dp[j]) dp[j]=true;
    int cnt=0;
    for(int i=1;i<=2000;i++)
        if(dp[i]) cnt++;
    ans=max(ans,cnt);
    return;
}
void dfs(int k)
{
    if(k==m)
    {
        DP();
        return;
    }
    for(int i=sum;i<=n;i++)
        if(!vis[i])
        {
            vis[i]=true;
            sum=i+1;
            dfs(k+1);
            vis[i]=false;
        }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    dfs(0);
    printf("%d",ans);
    return 0;
}