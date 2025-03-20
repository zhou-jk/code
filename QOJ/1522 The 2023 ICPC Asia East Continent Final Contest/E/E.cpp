#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,d;
int a[N];
void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    m=0;
    for(int i=1;i<=n;i++)
        m+=a[i];
    sort(a+1,a+n+1);
    if(d==1)
    {
        long long ans=(long long)m*(m-1)/2;
        cout<<ans<<"\n";
    }
    else if(d==2)
    {
        long long ans=(long long)m*(m-1)/2;
        for(int i=1;i<=n;i++)
            ans-=(long long)a[i]*(a[i]-1)/2;
        cout<<ans<<"\n";
    }
    else
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
            ans+=(long long)(n-i+1)*(n-i)/2*(a[i]-a[i-1]);
        cout<<ans<<"\n";
    }
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