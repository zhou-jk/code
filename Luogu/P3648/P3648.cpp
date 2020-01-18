#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n,K;
long long f[N][201],sum[N];
int pre[N][201];
int q[N],head,tail;
double slope(int i,int x,int y)
{
    if(sum[x]==sum[y]) return -1e9;
    return (double)(sum[y]*sum[y]-sum[x]*sum[x]-f[y][i-1]+f[x][i-1])/(sum[y]-sum[x]);
}
int main()
{
    scanf("%d%d",&n,&K);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum[i]=sum[i-1]+x;
    }
    for(int k=1;k<=K;k++)
    {
        head=tail=1;
        for(int i=1;i<=n;i++)
        {
            while(head<tail&&slope(k,q[head],q[head+1])<=sum[i]) head++;
            while(head<tail&&slope(k,q[tail-1],q[tail])>=slope(k,q[tail-1],i)) tail--;
            f[i][k]=f[q[head]][k-1]+sum[q[head]]*(sum[i]-sum[q[head]]);
            pre[i][k]=q[head];
            q[++tail]=i; 
        }
    }
    printf("%lld\n",f[n][K]);
    for(int i=pre[n][K],j=K;i;i=pre[i][--j])
        printf("%d ",i);
    return 0;
}