#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,q,s,t;
long long a[N];
int main()
{
    scanf("%d%d%d%d",&n,&q,&s,&t);
    for(int i=0;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=n;i>=1;i--)
        a[i]-=a[i-1];
    long long ans=0;
    for(int i=1;i<=n;i++)
        if(a[i]>=0) ans-=(long long)a[i]*s;
        else ans+=(long long)-a[i]*t;
    while(q--)
    {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        if(a[l]>=0) ans+=(long long)a[l]*s;
        else ans-=(long long)-a[l]*t;
        a[l]+=x;
        if(a[l]>=0) ans-=(long long)a[l]*s;
        else ans+=(long long)-a[l]*t;
        if(r+1<=n)
        {
            if(a[r+1]>=0) ans+=(long long)a[r+1]*s;
            else ans-=(long long)-a[r+1]*t;
            a[r+1]-=x;
            if(a[r+1]>=0) ans-=(long long)a[r+1]*s;
            else ans+=(long long)-a[r+1]*t;
        }
        printf("%lld\n",ans);
    }
    return 0;
}