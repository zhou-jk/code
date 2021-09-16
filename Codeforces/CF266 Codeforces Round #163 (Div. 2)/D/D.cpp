#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=205,M=20005;
const int INF=1061109567;
int n,m;
int u[M],v[M],w[M];
int dis[N][N];
int rnk[N][N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=i==j?0:INF;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        dis[u[i]][v[i]]=min(dis[u[i]][v[i]],w[i]);
        dis[v[i]][u[i]]=min(dis[v[i]][u[i]],w[i]);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    double ans=INF;
    for(int u=1;u<=n;u++)
    {
        iota(rnk[u]+1,rnk[u]+n+1,1);
        sort(rnk[u]+1,rnk[u]+n+1,[=](const int &x,const int &y){return dis[u][x]>dis[u][y];});
        ans=min<double>(ans,dis[u][rnk[u][1]]);
    }
    for(int i=1;i<=m;i++)
    {
        int x=u[i],y=v[i],z=w[i];
        int p=1;
        for(int j=2;j<=n;j++)
            if(dis[y][rnk[x][j]]>dis[y][rnk[x][p]]) ans=min(ans,(dis[x][rnk[x][j]]+dis[y][rnk[x][p]]+z)/2.0),p=j;
    }
    printf("%.10lf",ans);
    return 0;
}