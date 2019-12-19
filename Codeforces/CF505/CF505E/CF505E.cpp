#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int N=100001;
int n,m,k,p;
long long h[N],a[N];
long long now[N];
bool check(long long x)
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    for(int i=1;i<=n;i++)
    {
        now[i]=x;
        if(x-m*a[i]>=0)continue;
        q.push(make_pair(x/a[i],i));
    }
    int times=0;
    for(;times<=k*m;times++)
    {
        if(q.empty()) break;
        pair<int,int> u=q.top();
        q.pop();
        if(u.first<=times/k)return false;
        now[u.second]+=p;
        if(now[u.second]-m*a[u.second]>=0) continue;
        q.push(make_pair(now[u.second]/a[u.second],u.second));
    }
    if(times>k*m) return false;
    for(int i=1;i<=n;i++)
    {
        long long sum=m*a[i]+h[i]-now[i];
        if(sum<=0) continue;
        else times+=ceil((double)sum/p);
        if(times>k*m) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&p);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&h[i],&a[i]);
    long long l=1,r=1e15,ans;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%lld",ans);
    return 0;
}