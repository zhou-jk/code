#include<iostream>
#include<cstdio>
using namespace std;
const int N=10001;
const int INF=1061109567;
int n,m,k;
long long f[N][4001];
long long ans=INF;
struct Bird
{
    int x,y;
}t[N];
struct Node
{
    int low,high;
    bool p;
}g[N];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&t[i].x,&t[i].y);
        g[i].low=1,g[i].high=m;
    }
    for(int i=1;i<=k;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].p=true,g[a].low=b+1,g[a].high=c-1;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            f[i][j]=INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=t[i].x+1;j<=m+t[i].x;j++)
            f[i][j]=min(f[i-1][j-t[i].x]+1,f[i][j-t[i].x]+1);
        for(int j=m+1;j<=m+t[i].x;j++)
            f[i][m]=min(f[i][m],f[i][j]); 
        for(int j=1;j<=m-t[i].y;j++)
            f[i][j]=min(f[i][j],f[i-1][j+t[i].y]);
        for(int j=1;j<g[i].low;j++)
            f[i][j]=INF;
        for(int j=g[i].high+1;j<=m;j++)
            f[i][j]=INF;
    }
    for(int i=1;i<=m;i++)
        ans=min(ans,f[n][i]);
    if(ans<INF)
    {
        printf("1\n%lld",ans);
        return 0;
    }
    int i,j;
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=m;j++)
            if(f[i][j]<INF) break;
        if(j<=m) break;
    }
    ans=0;
    for(int j=1;j<=i;j++)
        if(g[j].p) ans++;
    printf("0\n%lld",ans);
    return 0;
}