#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
int n;
int a[N];
int s[N];
bool check(int x)
{
    int pre=0;
    for(int i=2;i<=n;i+=2)
        if(s[i-1]-pre>=x) pre=min(pre,s[i]);
    return s[n]-pre>=x;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int w=0,b=0;
    for(int i=1;i<=n;i++)
        if(i%2==1) b+=a[i],s[i]=s[i-1]+a[i];
        else w+=a[i],s[i]=s[i-1]-a[i];
    if(n%2==0) printf("%d %d",max(w,b),min(w,b));
    else
    {
        int l=-w-b,r=w+b,ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        printf("%d %d",w+ans,b-ans);
    }
    return 0;
}