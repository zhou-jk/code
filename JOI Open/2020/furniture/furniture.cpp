#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005;
int n,m;
int c[N][N];
bool f[N][N],g[N][N];
int cnt[N+N];
int Q;
void updatef(int x,int y)
{
    if(x<1||x>n||y<1||y>m) return;
    f[x][y]=f[x-1][y]|f[x][y-1];
    if(!f[x][y])
    {
        if(g[x][y]) cnt[x+y]--;
        if(f[x+1][y]) updatef(x+1,y);
        if(f[x][y+1]) updatef(x,y+1);
    }
    return;
}
void updateg(int x,int y)
{
    if(x<1||x>n||y<1||y>m) return;
    g[x][y]=g[x+1][y]|g[x][y+1];
    if(!g[x][y])
    {
        if(f[x][y]) cnt[x+y]--;
        if(g[x-1][y]) updateg(x-1,y);
        if(g[x][y-1]) updateg(x,y-1);
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&c[i][j]);
    f[1][1]=true;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!c[i][j]) f[i][j]|=f[i-1][j]|f[i][j-1];
    g[n][m]=true;
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
            if(!c[i][j]) g[i][j]|=g[i+1][j]|g[i][j+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(f[i][j]&&g[i][j]) cnt[i+j]++;
    scanf("%d",&Q);
    while(Q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(!f[x][y]||!g[x][y]||cnt[x+y]>1)
        {
            if(f[x][y]&&g[x][y]) cnt[x+y]--;
            f[x][y]=g[x][y]=false;
            c[x][y]=1;
            if(x+1<=n&&f[x+1][y]) updatef(x+1,y);
            if(y+1<=m&&f[x][y+1]) updatef(x,y+1);
            if(x-1>=1&&g[x-1][y]) updateg(x-1,y);
            if(y-1>=1&&g[x][y-1]) updateg(x,y-1);
            printf("1\n");
        }
        else printf("0\n");
    }
    return 0;
}