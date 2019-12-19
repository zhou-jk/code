#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=50001;
int n,m;
int a[N];
int dp[N],f[1000001];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=sqrt(a[i]);j++)
            if(a[i]%j==0)
            {
                if(j>=m) dp[i]=max(dp[i],f[j]+1);
                if(a[i]/j>=m) dp[i]=max(dp[i],f[a[i]/j]+1);
            }
        for(int j=1;j<=sqrt(a[i]);j++)
            if(a[i]%j==0) f[j]=max(f[j],dp[i]),f[a[i]/j]=max(f[a[i]/j],dp[i]);
        ans=max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}