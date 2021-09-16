#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=205;
const int INF=1061109567;
int n,L;
int x[N],t[N];
int f[N][N][N][2];
int main()
{
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    memset(f,63,sizeof(f));
    f[0][0][0][0]=f[0][0][0][1]=0;
    for(int l=0;l<=n;l++)
        for(int r=0;r<=n;r++)
            if(r<n-l+1)
                for(int k=0;k<=l+r;k++)
                    for(int op=0;op<2;op++)
                        if(f[l][r][k][op]<INF)
                        {
                            if(op==0)
                            {
                                f[l+1][r][k+(f[l][r][k][op]+(L-x[n-l])-(l>0?L-x[n-l+1]:0)<=t[n-l])][0]=min(f[l+1][r][k+(f[l][r][k][op]+(L-x[n-l])-(l>0?L-x[n-l+1]:0)<=t[n-l])][0],f[l][r][k][op]+(L-x[n-l])-(l>0?L-x[n-l+1]:0));
                                f[l][r+1][k+(f[l][r][k][op]+(l>0?L-x[n-l+1]:0)+x[r+1]<=t[r+1])][1]=min(f[l][r+1][k+(f[l][r][k][op]+(l>0?L-x[n-l+1]:0)+x[r+1]<=t[r+1])][1],f[l][r][k][op]+(l>0?L-x[n-l+1]:0)+x[r+1]);
                            }
                            else if(op==1)
                            {
                                f[l+1][r][k+(f[l][r][k][op]+x[r]+L-x[n-l]<=t[n-l])][0]=min(f[l+1][r][k+(f[l][r][k][op]+x[r]+L-x[n-l]<=t[n-l])][0],f[l][r][k][op]+x[r]+L-x[n-l]);
                                f[l][r+1][k+(f[l][r][k][op]+x[r+1]-x[r]<=t[r+1])][1]=min(f[l][r+1][k+(f[l][r][k][op]+x[r+1]-x[r]<=t[r+1])][1],f[l][r][k][op]+x[r+1]-x[r]);
                            }
                        }
    int ans=0;
    for(int l=0;l<=n;l++)
        for(int r=0;r<=n;r++)
            if(r<n-l+1)
                for(int k=0;k<=l+r;k++)
                    for(int op=0;op<2;op++)
                        if(f[l][r][k][op]<INF) ans=max(ans,k);
    printf("%d",ans);
    return 0;
}