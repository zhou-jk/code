#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=105;
int n;
int a[N*2];
void solve()
{
    cin>>n;
    for(int i=1;i<=n*2;i++)
        cin>>a[i];
    sort(a+1,a+2*n+1);
    int ans=a[n]-a[1]+a[n*2]-a[n+1];
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" "<<a[i+n]<<"\n";
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
