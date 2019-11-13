#include<iostream>
#include<cstdio>
const int N=300001;
int n;
struct Node
{
    int id;
    int l;
    long long v;
}a[N];
int main() 
{
    scanf("%d",&n);
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%lld",&a[i].l,&a[i].v);
        sum+=a[i].l;
        for(int j=0;j<=61;j++)
            if((a[i].v>>j)&1) a[i].id=j;
    }
    if(sum<0)
    {
        for(int i=1;i<=n;i++)
            a[i].l=-a[i].l;
    }
    long long ans=0;
    for(int i=0;i<=61;i++)
    {
        long long t=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j].id!=i) continue;
            t+=a[j].l;
        }
        if(t>0)
        {
            ans|=(1ll<<i);
            for(int j=1;j<=n;j++)
                if((a[j].v>>i)&1) a[j].l=-a[j].l;
        }
    }
    printf("%lld",ans);
    return 0;
}