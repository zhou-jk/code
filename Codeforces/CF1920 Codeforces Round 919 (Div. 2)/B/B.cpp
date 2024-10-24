#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
const long long INF=1e18;
int n,k,x;
int a[N];
long long sum[N];
void solve()
{
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    long long ans=-INF;
    for(int i=0;i<=k;i++)
        ans=max(ans,sum[n]-sum[min(i+x,n)]-(sum[min(i+x,n)]-sum[i]));
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