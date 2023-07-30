#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
int a[N+N];
long long sum[N+N];
bool check(long long x)
{
    for(int i=1;i<=n;i++)
    {
        int j=lower_bound(sum+i,sum+n+n+1,sum[i-1]+x)-sum;
        if(j>=i+n) continue;
        int k=lower_bound(sum+j+1,sum+n+n+1,sum[j]+x)-sum;
        if(k>=i+n) continue;
        int l=lower_bound(sum+k+1,sum+n+n+1,sum[k]+x)-sum;
        if(l>=i+n) continue;
        return true;
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        a[i+n]=a[i];
    for(int i=1;i<=n+n;i++)
        sum[i]=sum[i-1]+a[i];
    long long l=0,r=sum[n],ans=0;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%lld",ans);
    return 0;
}