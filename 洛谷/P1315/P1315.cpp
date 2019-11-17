#include<iostream>
#include<cstdio>
using namespace std;
const int N=10001;
int n,m,k;
int t[N],wait[N],sum[N],reach[N],out[N];
struct pass
{
    int t,u,v;
}a[N];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<n;i++)
        scanf("%d",&t[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].t,&a[i].u,&a[i].v);
    for(int i=1;i<=m;i++)
    {
        wait[a[i].u]=max(wait[a[i].u],a[i].t);
        out[a[i].v]++;
    }
    sum[1]=wait[1];
    for(int i=1;i<=n;i++)
        out[i]+=out[i-1];
    for(int i=2;i<=n;i++)
        sum[i]=max(sum[i-1],wait[i-1])+t[i-1];
    int ans=0;
    for(int i=1;i<=m;i++)
        ans+=sum[a[i].v]-a[i].t;
    while(k--)
    {
        reach[n]=reach[n-1]=n;
        for(int i=n-2;i>0;i--)
        {
            if(sum[i+1]<=wait[i+1]) reach[i]=i+1;
            else reach[i]=reach[i+1];
        }
        int pos,Max=-1;
        for(int i=1;i<n;i++)
            if(out[reach[i]]-out[i]>Max&&t[i]>0) Max=out[reach[i]]-out[i],pos=i;
        ans-=Max;
        t[pos]--;
        for(int i=2;i<=n;i++)
            sum[i]=max(sum[i-1],wait[i-1])+t[i-1];
    }
    printf("%d",ans);
    return 0;
}