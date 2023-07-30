#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=505,M=10005;
const int INF=1061109567;
int n,m;
int p[M];
int c[N],e[N];
int f[N][M];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&c[i],&e[i]);
    fill(f[0]+1,f[0]+m+1,INF);
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            f[i][j]=f[i-1][j];
        for(int j=0;j<=m;j++)
            f[i][min(j+c[i],m)]=min(f[i][min(j+c[i],m)],f[i-1][j]+e[i]);
    }
    sort(p+1,p+m+1,greater<int>());
    int ans=0;
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        sum+=p[i];
        ans=max(ans,sum-f[n][i]);
    }
    printf("%d",ans);
    return 0;
}