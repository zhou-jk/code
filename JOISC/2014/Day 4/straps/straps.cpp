#include<iostream>
#include<cstdio>
using namespace std;
const int N=2005;
const int INF=1061109567;
int n;
int a[N],b[N];
int f[N][N+N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for(int i=-n;i<=n;i++)
        f[0][i+n]=-INF;
    f[0][1+n]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=-n;j<=n;j++)
            f[i][j+n]=f[i-1][j+n];
        for(int j=-n;j<=n;j++)
            if(f[i-1][j+n]>-INF)
            {
                if(j+a[i]-1>=-n) f[i][min(j+a[i]-1,n)+n]=max(f[i][min(j+a[i]-1,n)+n],f[i-1][j+n]+b[i]);
            }
    }
    int ans=0;
    for(int i=0;i<=n;i++)
        ans=max(ans,f[n][i+n]);
    printf("%d",ans);
    return 0;
}