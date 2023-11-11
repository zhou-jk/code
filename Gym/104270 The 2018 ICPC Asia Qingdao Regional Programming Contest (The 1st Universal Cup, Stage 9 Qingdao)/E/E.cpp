#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
long long m;
int a[N];
long long b[N];
bool check(long long x)
{
    long long tot=0;
    for(int i=1;i<=n;i++)
        b[i]=0;
    for(int i=1;i<=n;i++)
        if(b[i]<x)
        {
            long long t=(x-b[i]+a[i]-1)/a[i];
            tot+=t*2-1;
            if(tot>m) return false;
            b[i+1]+=a[i+1]*(t-1);
        }
        else tot++;
    return true;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long l=1,r=*max_element(a+1,a+n+1)*m,ans=0;
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