#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long ans=0;
    for(int i=1;i<=n;i++)
        if(a[i]>a[i-1]) ans+=a[i]-a[i-1];
    ans--;
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