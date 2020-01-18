#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1061109567;
int n; 
long long ans=INF,total;
long long sum[20001],dis[20001];
int w[20001],d[20001];
int q[20001],head=1,tail=1;
double calc(int x,int y)
{
    return ((double)sum[x]*dis[x]-sum[y]*dis[y])/(sum[x]-sum[y]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&d[i]);
        sum[i]=sum[i-1]+w[i];
    }
    for(int i=n;i>0;i--)
        dis[i]=dis[i+1]+d[i],total+=w[i]*dis[i];
    for(int i=1;i<=n;i++)
    {
        while(head<tail&&calc(q[head],q[head+1])>dis[i])
            head++;
        ans=min(ans,total-sum[q[head]]*dis[q[head]]-(sum[i]-sum[q[head]])*dis[i]);
        while(head<tail&&calc(q[tail-1],q[tail])<=calc(q[tail], i)) tail--;
        q[++tail]=i;
    }
    printf("%lld",ans);
    return 0;
}