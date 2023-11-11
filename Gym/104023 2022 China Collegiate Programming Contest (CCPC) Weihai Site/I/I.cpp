#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=50005;
int n,k;
int a[N],b[N],ret[N];
long long c[N];
bool check(long long x)
{
    for(int i=1;i<=n;i++)
        c[i]=a[i]*x;
    priority_queue<long long,vector<long long>>q;
    for(int i=1;i<=n;i++)
        q.emplace(c[i]);
    for(int i=0;i<k;i++)
        ret[i]=b[i];
    for(int i=k-1;i>=0;i--)
        if(ret[i])
        {
            while(!q.empty())
            {
                long long u=q.top();
                q.pop();
                long long t=min(u/(1<<i),(long long)ret[i]);
                if(t==0) ret[i]--;
                else
                {
                    u-=t*(1<<i);
                    ret[i]-=t;
                    if(u) q.emplace(u);
                }
                if(!ret[i]) break;
            }
            if(q.empty()) return true;
        }
    return false;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<k;i++)
        cin>>b[i];
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    long long l=1,r=0;
    for(int i=0;i<k;i++)
        r+=(1LL<<i)*b[i];
    r/=sum;
    long long ans=0;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
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
