#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=200005;
int n;
int a[N];
long long sum[N];
long long f[N];
bool check(long long x)
{
    f[0]=0;
    deque<int>q;
    q.emplace_back(0);
    for(int i=1;i<=n+1;i++)
    {
        while(!q.empty()&&sum[q.front()]<sum[i-1]-x) q.pop_front();
        f[i]=f[q.front()]+a[i];
        while(!q.empty()&&f[q.back()]>=f[i]) q.pop_back();
        q.emplace_back(i);
    }
    return f[n+1]<=x;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[n+1]=0;
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    long long l=1,r=sum[n],ans=-1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<"\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}