#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
int n,x;
int a[N];
void solve()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=(x-a[n])*2;
    for(int i=1;i<=n;i++)
        ans=max(ans,a[i]-a[i-1]);
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