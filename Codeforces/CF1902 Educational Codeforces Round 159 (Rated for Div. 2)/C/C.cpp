#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
long long a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<1<<"\n";
        return;
    }
    sort(a+1,a+n+1);
    int d=a[2]-a[1];
    for(int i=2;i<=n;i++)
        d=gcd(d,a[i]-a[i-1]);
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=(a[n]-a[i])/d;
    long long ret=(a[n]-(a[1]-d))/d;
    for(int i=n;i>=2;i--)
        if(a[i]-a[i-1]>d)
        {
            ret=(a[n]-(a[i]-d))/d;
            break;
        }
    ans+=ret;
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