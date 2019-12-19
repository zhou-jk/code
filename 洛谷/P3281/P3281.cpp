#include<iostream>
#include<cstdio>
#include<cstring>
const int N=100001;
const int MOD=20130427;
int n,m,B;
int L[N],R[N];
long long s[N],sum[N];
long long a[N][2],dp[N][2],f[N][2],g[N][2];
int solve(int *p,int l)
{
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    a[l][0]=1;
    for(int i=l-1;i>=0;i--)
    {
        int c=(i==l-1?0:B);
        a[i][0]=a[i+1][0];
        a[i][1]=(c-1+a[i+1][1]*B%MOD+a[i+1][0]*p[i]%MOD)%MOD;
        g[i][0]=(g[i+1][0]+a[i+1][0])%MOD;
        g[i][1]=(c-1+g[i][0]*p[i]%MOD+(g[i+1][1]+a[i+1][1])*B%MOD)%MOD;
        f[i][0]=(f[i+1][0]*B%MOD+p[i]*g[i][0]%MOD)%MOD;
        f[i][1]=(sum[c]+f[i+1][0]*B%MOD*p[i]%MOD+sum[p[i]]*g[i][0]%MOD+f[i+1][1]*B%MOD*B%MOD+sum[B]*(g[i+1][1]+a[i +1][1])%MOD)%MOD;
        dp[i][0]=(dp[i+1][0]+f[i][0])%MOD;
        dp[i][1]=(dp[i+1][0]*p[i]%MOD+dp[i+1][1]*B%MOD+f[i][1])%MOD;
    }
    return (dp[0][0]+dp[0][1])%MOD;
}
int main()
{
    scanf("%d",&B);
    s[0]=1;
    for(int i=1;i<=N;i++)
        s[i]=(s[i-1]*B+1)%MOD;
    sum[0]=0;
    for(int i=1;i<=B;i++)
        sum[i]=(sum[i-1]+i-1)%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&L[n-i]);
    for(int i=0;i<n;i++)
        if(L[i]>0)
        {
            L[i]--;
            break;
        }
        else L[i]=B-1;
    if(!L[n-1]) n--;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&R[m-i]);
    printf("%d",(solve(R,m)-solve(L,n)+MOD)%MOD);
    return 0;
}