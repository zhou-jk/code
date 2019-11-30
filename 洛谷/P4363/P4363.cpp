#include<iostream>
#include<cstdio>
using namespace std;
const int N=11;
const int INF=1061109567;
int n,m;
int a[N][N],b[N][N],f[1<<(N<<1)];
int now=1;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&b[i][j]);
    for(int i=(1<<(n+m))-1;i>=0;i--)
    {
        int tot=0,cur=0;
        for(int j=0;j<n+m;j++)
            if((i>>j)&1) tot++;
        if(tot!=n) continue;
        if(now)
        {
            now=0;
            continue;
        }
        int x=n+1,y=1;
        for(int j=0;j<n+m;j++)
        {
            if((i>>j)&1) x--;
            else
            {
                if(y<=m) cur+=x-1;
                y++;
            }
        }
        if(cur&1) f[i]=INF;
        else f[i]=-INF;
        x=n+1,y=1;
        for(int j=0;j<n+m;j++)
        {
            if((i>>j)&1) x--;
            else
            {
                if(j&&((i>>(j-1))&1))
                {
                    if(cur&1) f[i]=min(f[i],f[i^(3<<(j-1))]-b[x][y]);
                    else f[i]=max(f[i],f[i^(3<<(j-1))]+a[x][y]);
                }
                y++;
            }
        }
    }
    printf("%d",f[(1<<n)-1]);
    return 0;
}