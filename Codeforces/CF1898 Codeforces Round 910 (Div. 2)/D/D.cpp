#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=2e9;
int n;
int a[N],b[N];
int v[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    long long sum=0;
    for(int i=1;i<=n;i++)
        sum+=abs(a[i]-b[i]);
    long long ans=sum;
    int mx=-INF,mn=INF;
    for(int i=1;i<=n;i++)
        mx=max(mx,min(a[i],b[i])),mn=min(mn,max(a[i],b[i]));
    if(mx>mn) ans+=(mx-mn)*2;
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
