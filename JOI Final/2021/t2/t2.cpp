#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
const long long INF=4557430888798830399;
int n,q;
long long x[N],w[N];
long long pre[N],suf[N],sum[N];
long long ans[N];
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&x[i]);
    for(int i=1;i<=q;i++)
        scanf("%lld",&w[i]);
    long long now=0;
    for(int i=1;i<=q;i++)
    {
        now+=w[i];
        pre[i]=min(pre[i-1],now),suf[i]=max(suf[i-1],now);
        sum[i]=-pre[i]+suf[i];
    }
    x[0]=-INF,x[n+1]=INF;
    for(int i=1;i<=n;i++)
    {
        int t1=upper_bound(sum+1,sum+q+1,x[i]-x[i-1])-sum-1,t2=upper_bound(sum+1,sum+q+1,x[i+1]-x[i])-sum-1;
        ans[i]=-pre[t1]+suf[t2];
        if(w[t1+1]<0) ans[i]+=x[i]-x[i-1]-sum[t1];
        if(w[t2+1]>0) ans[i]+=x[i+1]-x[i]-sum[t2];
    }
    for(int i=1;i<=n;i++)
        printf("%lld\n",ans[i]);
    return 0;
}