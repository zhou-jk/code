#include<iostream>
#include<cstdio>
using namespace std;
const int N=50005;
const int MOD=10007;
int n,m;
int a[N];
int l,r,mid,ans;
bool check(int x)
{
    int tot=0,cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(tot+a[i]>x)
        {
            cnt++;
            if(cnt>m+1) return false;
            tot=a[i];
        }
        else tot+=a[i];
    }
    return true;
}
int pre[N],sum[N];
long long dp[2][N];
long long res;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        l=max(l,a[i]);
        r+=a[i];
    }
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    printf("%d ",ans);
    int now=1,cur=0;     
    for(int i=1;i<=n;i++)
    { 
        while(sum[i]-sum[now]>ans) now++; 
        pre[i]=now;
    }
    for(int i=1;i<=n;i++)
        if(sum[i]>ans) break;
        else dp[cur][i]=1;
    for(int i=1;i<=n;i++)
        dp[cur][i]+=dp[cur][i-1];
    for(int i=2;i<=m+1;i++)
    {
        cur^=1;
        for(int j=1;j<=n;j++)
            dp[cur][j]=(dp[cur^1][j-1]-dp[cur^1][pre[j]-1]+MOD)%MOD; 
        res=(res+dp[cur][n])%MOD;
        for(int j=1;j<=n;j++)
            dp[cur][j]=(dp[cur][j]+dp[cur][j-1])%MOD; 
    }
    printf("%lld",res);
    return 0;
}