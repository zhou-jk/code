#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1001;
struct Node
{
    int x,y,z;
}a[N];
int n,x0;
long long f[N][N][2];
long long sum[N];
bool cmp(Node a,Node b)
{
    return a.x<b.x;
}
int main()
{
    scanf("%d%d",&n,&x0);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].x);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].y);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].z);
    sort(a+1,a+n+1,cmp);
    memset(f,-63,sizeof(f));
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i].z;
    for(int i=1;i<=n;i++)
        f[i][i][0]=f[i][i][1]=a[i].y-abs(x0-a[i].x)*sum[n];
    for(int len=1;len<n;len++)
        for(int i=1;i+len<=n;i++)
        {
            int j=i+len;
            f[i][j][0]=max(f[i+1][j][0]-(a[i+1].x-a[i].x)*(sum[n]-sum[j]+sum[i])+a[i].y,f[i+1][j][1]-(a[j].x-a[i].x)*(sum[n]-sum[j]+sum[i])+a[i].y);
            f[i][j][1]=max(f[i][j-1][0]-(a[j].x-a[i].x)*(sum[n]-sum[j-1]+sum[i-1])+a[j].y,f[i][j-1][1]-(a[j].x-a[j-1].x)*(sum[n]-sum[j-1]+sum[i-1])+a[j].y);
        }
    printf("%.3lf",0.001*max(f[1][n][0],f[1][n][1]));
    return 0;
}