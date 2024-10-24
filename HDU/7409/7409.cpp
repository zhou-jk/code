#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
long long k;
int a[N];
bool check(long long x)
{
    long long cnt=0;
    for(int i=1,j=n;i<=n;i++)
    {
        while(j>=1&&a[i]+a[j]>x) j--;
        if(i<j) cnt+=j-i;
    }
    return cnt>=k;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>k;
    sort(a+1,a+n+1);
    long long l=a[1]+a[2],r=a[n-1]+a[n],ans=-1;
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