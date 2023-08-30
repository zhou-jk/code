#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=3005;
const long long INF=4557430888798830399;
int n,t;
int a[N],b[N],c[N],d[N];
long long f[N][N];
long long pre[N][N],nxt[N][N];
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    memset(f,63,sizeof(f));
    f[0][0]=0;
    memset(pre,63,sizeof(pre));
    pre[0][0]=f[0][0]-(long long)0*(b[1]+c[1]);
    for(int j=1;j<=n;j++)
        pre[0][j]=min(pre[0][j-1],f[0][j]-(long long)j*(b[1]+c[1]));
    memset(nxt,63,sizeof(nxt));
    nxt[0][n]=f[0][n]+(long long)n*(a[1]+d[1]);
    for(int j=n-1;j>=0;j--)
        nxt[0][j]=min(nxt[0][j+1],f[0][j]+(long long)j*(a[1]+d[1]));
    long long ans=t;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            f[i][j]=f[i-1][j]+a[i]+b[i];
            if(j>=1) f[i][j]=min(f[i][j],f[i-1][j]+c[i]+d[i]);
            if(j-1>=0) f[i][j]=min(f[i][j],pre[i-1][j-1]+(long long)j*(b[i]+c[i]));
            if(j+1<=n) f[i][j]=min(f[i][j],nxt[i-1][j+1]-(long long)j*(a[i]+d[i]));
            f[i][j]+=2LL*j*t+t;
        }
        pre[i][0]=f[i][0]-(long long)0*(b[i+1]+c[i+1]);
        for(int j=1;j<=n;j++)
            pre[i][j]=min(pre[i][j-1],f[i][j]-(long long)j*(b[i+1]+c[i+1]));
        nxt[i][n]=f[i][n]+(long long)n*(a[i+1]+d[i+1]);
        for(int j=n-1;j>=0;j--)
            nxt[i][j]=min(nxt[i][j+1],f[i][j]+(long long)j*(a[i+1]+d[i+1]));
    }
    ans+=f[n][0];
    printf("%lld",ans);
    return 0;
}