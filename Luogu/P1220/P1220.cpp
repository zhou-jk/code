#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[51],b[51],sum[51];
int n,m,c;
int f[51][51][2];
int main()
{
    memset(f,63,sizeof(f));
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]),sum[i]=sum[i-1]+b[i];
    f[c][c][0]=f[c][c][1]=0;
    for(int i=2;i<=n;i++)
        for(int j=1;j+i-1<=n;j++)
        {
            int k=j+i-1;
            f[j][k][0]=min(f[j+1][k][0]+(a[j+1]-a[j])*(sum[j]+sum[n]-sum[k]),f[j+1][k][1]+(a[k]-a[j])*(sum[j]+sum[n]-sum[k]));
            f[j][k][1]=min(f[j][k-1][0]+(a[k]-a[j])*(sum[j-1]+sum[n]-sum[k-1]),f[j][k-1][1]+(a[k]-a[k-1])*(sum[j-1]+sum[n]-sum[k-1]));
        }
  printf("%d",min(f[1][n][0],f[1][n][1]));
  return 0;
}