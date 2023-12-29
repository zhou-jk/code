#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2005;
int n,k;
long long a[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(k>=3)
    {
        cout<<0<<"\n";
        return;
    }
    if(k==1)
    {
        long long mn=a[2]-a[1];
        for(int i=2;i<=n;i++)
            mn=min(mn,a[i]-a[i-1]);
        long long ans=min(mn,a[1]);
        cout<<ans<<"\n";
        return;
    }
    long long ans=a[1];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            long long d=a[j]-a[i];
            int p=lower_bound(a+1,a+n+1,d)-a;
            long long res=min(d,a[1]);
            res=min(res,a[p]-d);
            if(p-1>=1) res=min(res,d-a[p-1]);
            ans=min(ans,res);
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