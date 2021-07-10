#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
pair<long long,long long>p[N];
bool check(long long x)
{
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=p[i].first;
    long long now=sum-x;
    long long ret=x;
    for(int i=1;i<=n;i++)
        if(ret>0)
        {
            if(p[i].second>now) return false;
            ret-=p[i].first;
            now+=p[i].first;
        }
    return ret<=0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        p[i]={a,b};
    }
    sort(p+1,p+n+1,[=](const pair<long long,long long> &x,const pair<long long,long long> &y){return x.second<y.second;});
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=p[i].first;
    long long l=0,r=sum,ans=-1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    long long res=ans+(sum-ans)*2;
    printf("%lld",res);
    return 0;
}