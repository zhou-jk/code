#include<iostream>
#include<cstdio>
using namespace std;
const int N=2001;
int n,m,k;
int sum[N][N];
int a[N][N],b[N][N],c[N][N],d[N][N];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x;
            scanf("%d",&x);
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+x;
        }
    for(int i=n;i>=k;i--)
        for(int j=m;j>=k;j--)
	        sum[i][j]-=sum[i-k][j]+sum[i][j-k]-sum[i-k][j-k];
	for(int i=k;i<=n;i++)
        for(int j=k;j<=m;j++)
            a[i][j]=max(sum[i][j],max(a[i-1][j],a[i][j-1]));
    for(int i=k;i<=n;i++)
        for(int j=m;j>=k;j--)
            b[i][j]=max(sum[i][j],max(b[i-1][j],b[i][j+1]));
    for(int i=n;i>=k;i--)
        for(int j=k;j<=m;j++)
            c[i][j]=max(sum[i][j],max(c[i+1][j],c[i][j-1]));
    for(int i=n;i>=k;i--)
        for(int j=m;j>=k;j--)
            d[i][j]=max(sum[i][j],max(d[i+1][j],d[i][j+1]));
    int ans=0;
    for(int i=k;i<=n-k;i++)
        for(int j=k;j<=m-k;j++)
            ans=max(ans,a[i][j]+b[i][j+k]+c[i+k][m]);
    for(int i=k;i<=n-k;i++)
        for(int j=k+k;j<=m;j++)
            ans=max(ans,b[i][j]+d[i+k][j]+a[n][j-k]);
    for(int i=k+k;i<=n;i++)
        for(int j=k;j<=m-k;j++)
            ans=max(ans,c[i][j]+d[i][j+k]+a[i-k][m]);
    for(int i=k;i<=n-k;i++)
        for(int j=k;j<=m-k;j++)
            ans=max(ans,a[i][j]+c[i+k][j]+b[n][j+k]);
    for(int i=k;i<=n;i++)
        for(int j=k+k;j<=m-k;j++)
            ans=max(ans,sum[i][j]+a[n][j-k]+b[n][j+k]);
    for(int i=k+k;i<=n-k;i++)
        for(int j=k;j<=m;j++)
            ans=max(ans,sum[i][j]+a[i-k][m]+c[i+k][m]);
	printf("%d",ans);
	return 0;
}