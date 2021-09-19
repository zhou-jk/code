#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
const int N=105;
const int MOD=1000000007;
int n,q;
int c[N];
int b[N];
int sb[N],sc[N];
int l,r;
int solve(int x)
{
    static int f[N][N*N],g[N][N*N];
    f[0][0]=g[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<max(i*x+sb[i-1],0);j++)
            f[i][j]=0;
        for(int j=max(i*x+sb[i-1],0);j<=sc[i];j++)
            f[i][j]=((long long)g[i-1][j-max(j-sc[i-1],0)]-(j-min(c[i],j)-1>=0?g[i-1][j-min(c[i],j)-1]:0)+MOD)%MOD;
        g[i][0]=f[i][0];
        for(int j=1;j<=sc[i];j++)
            g[i][j]=(g[i][j-1]+f[i][j])%MOD;
    }
    int ans=0;
    for(int j=0;j<=sc[n];j++)
        ans=(ans+f[n][j])%MOD;
    return ans;
}
unordered_map<int,int>res;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<n;i++)
        sb[i]=sb[i-1]+b[i];
    for(int i=1;i<n;i++)
        sb[i]+=sb[i-1];
    for(int i=1;i<=n;i++)
        sc[i]=sc[i-1]+c[i];
    r=(sc[n]-sb[n-1])/n;
    for(int i=1;i<n;i++)
        r=min(r,(sc[i]-sb[i-1])/i);
    l=-sb[n-1]/n;
    for(int i=1;i<n;i++)
        l=min(l,sb[i-1]/i);
    for(int i=l;i<=r;i++)
        res[i]=solve(i);
    int pw=1;
    for(int i=1;i<=n;i++)
        pw=1LL*pw*(c[i]+1)%MOD;
    scanf("%d",&q);
    while(q--)
    {
        int x;
        scanf("%d",&x);
        if(x<l) printf("%d\n",pw);
        else if(x>r) printf("%d\n",0);
        else printf("%d\n",res[x]);
    }
    return 0;
}