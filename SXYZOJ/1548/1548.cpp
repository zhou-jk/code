#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=85;
const int MOD=1000000007;
int n;
int l[N],r[N];
int f[2][N][2];
int lessx(int l,int r,int x)
{
    return 1LL*(r-l+1)*(x-l+x-r)/2%MOD;
}
int greaterx(int l,int r,int x)
{
    return 1LL*(r-l+1)*(r+l-x-x)/2%MOD;
}
int solve(int x)
{
    int cur=0;
    f[cur][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        cur^=1;
        for(int j=0;j<=i;j++)
            for(int k=0;k<2;k++)
                f[cur][j][k]=0;
        for(int j=0;j<=i;j++)
            for(int k=0;k<2;k++)
            {
                int L=l[i],R=min(x,r[i]);
                if(L<=R&&j>=1) f[cur][j][k]=(f[cur][j][k]+1LL*f[cur^1][j-1][k]*lessx(L,R,x))%MOD;
                L=max(x,l[i]),R=r[i];
                if(L<=R) f[cur][j][k]=(f[cur][j][k]+1LL*f[cur^1][j][k]*greaterx(L,R,x))%MOD;
                if(l[i]<=x&&x<=r[i]&&k==1) f[cur][j][k]=(f[cur][j][k]+f[cur^1][j][0])%MOD;
            }
    }
    int res=f[cur][(n-1)/2][1];
    for(int j=0;j<=n;j++)
        for(int k=0;k<2;k++)
            f[cur^1][j][k]=f[cur][j][k]=0;
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&l[i],&r[i]);
    int L=*min_element(l+1,l+n+1),R=*max_element(r+1,r+n+1);
    int ans=0;
    for(int i=L;i<=R;i++)
        ans=(ans+solve(i))%MOD;
    printf("%d",ans);
    return 0;
}