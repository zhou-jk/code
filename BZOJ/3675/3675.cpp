#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n,pos,K;
long long f[N][2],sum[N];
int q[N],head,tail;
double slope(int x,int y)
{
    if(sum[x]==sum[y]) return -1e9;
    return (double)(sum[y]*sum[y]-sum[x]*sum[x]-f[y][pos^1]+f[x][pos^1])/(1.0*(sum[y]-sum[x]));
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
        pos=k&1;
        head=tail=1;
        for(int i=1;i<=n;i++)
        {
            while(head<tail&&slope(q[head],q[head+1])<=sum[i]) head++;
            while(head<tail&&slope(q[tail-1],q[tail])>=slope(q[tail-1],i)) tail--;
            f[i][pos]=f[q[head]][pos^1]+sum[q[head]]*(sum[i]-sum[q[head]]);
            q[++tail]=i; 
        }
    }
    printf("%lld",f[n][pos]);
    return 0;
}