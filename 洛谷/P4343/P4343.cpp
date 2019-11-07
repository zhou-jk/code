#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int a[100001];
long long l,r,mid;
long long ans1,ans2;
int calc(long long x)
{
    int cnt=0;
    long long res=0;
    for (int i=1;i<=n;i++)
    {
        res=max(res+a[i],0ll);
        if(res>=x) res=0,cnt++;
    }
    return cnt;
}
 
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    l=1,r=1e18;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(calc(mid)>k) ans1=mid,l=mid+1;
        else r=mid-1;
    }
    l=1,r=1e18;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(calc(mid)<k) ans2=mid,r=mid-1;
        else l=mid+1;
    }
    ans1++,ans2--;
    if(calc(ans1)!=k||calc(ans2)!=k) printf("-1");
    else printf("%lld %lld",ans1,ans2);
    return 0;
}