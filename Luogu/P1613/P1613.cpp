#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dis[51][51],n,m;
bool f[51][51][65];
int main()
{
    memset(dis,63,sizeof(dis));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        dis[x][y]=1;
        f[x][y][0]=true;
    }
    for(int k=1;k<=64;k++)
        for(int i=1;i<=n;i++)
            for(int l=1;l<=n;l++)
                for(int j=1;j<=n;j++)
                if(f[i][l][k-1]&f[l][j][k-1])
                {
                    f[i][j][k]=true;
                    dis[i][j]=1;
                }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    printf("%d",dis[1][n]);
    return 0;
}