#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    long long ans=0;
    if(n%2==0)
    {
        for(int i=1;i<=n;i++)
            if(i==n/2) ans-=a[i];
            else if(i==n/2+1) ans+=a[i];
            else if(i<n/2) ans-=a[i]*2;
            else ans+=a[i]*2;
    }
    else
    {
        int mid=(n+1)/2;
        for(int i=1;i<=mid-2;i++)
            ans-=a[i]*2;
        for(int i=mid+2;i<=n;i++)
            ans+=a[i]*2;
        long long vl=a[mid+1]*2ll-a[mid]-a[mid-1],vr=a[mid]+a[mid+1]-a[mid-1]*2ll; 
        ans+=max(vl,vr);
    }
    printf("%lld",ans);
    return 0; 
}