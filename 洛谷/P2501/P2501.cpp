#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=35001;
const int INF=1061109567;
int n;
int a[N],dp[N],k[N];
long long f[N],sum1[N],sum2[N];
struct Edge
{
    int to,next;
}edge[N];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int main()
{
    scanf("%d",&n);
    a[0]=-INF;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]-=i;
    a[++n]=INF-1;
    memset(k,63,sizeof(k));
    for(int i=1;i<=n;i++)
        dp[i]=upper_bound(k+1,k+n+1,a[i])-k,k[dp[i]]=a[i];
    printf("%d\n",n-*max_element(dp+1,dp+n+1));
    memset(f,63,sizeof(f));
    for(int i=n;i>=0;i--)
        add_edge(dp[i],i);
    f[0]=0;
    for(int u=1;u<=n;u++)
        for(int i=head[dp[u]-1];i;i=edge[i].next)
            {
                int v=edge[i].to;
                if(v>u) break;
                if(a[v]>a[u]) continue;
                sum1[v-1]=sum2[v-1]=0;
                for(int k=v;k<=u;k++)
                    sum1[k]=sum1[k-1]+abs(a[k]-a[v]),sum2[k]=sum2[k-1]+abs(a[k]-a[u]);
                for(int k=v;k<u;k++)
                    f[u]=min(f[u],f[v]+sum1[k]-sum1[v]+sum2[u]-sum2[k]);
            }
    printf("%lld",f[n]);
    return 0;
}