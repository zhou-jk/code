#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    long long s=0;
    for(int i=1;i<=n;i++)
        s+=a[i];
    s/=2;
    long long ans=0;
    for(int i=n;i>=1;i--)
        if(s>=a[i]) s-=a[i],a[i]=0,ans++;
        else if(s) a[i]-=s,s=0,ans++;
    for(int i=1;i<=n;i++)
        ans+=a[i];
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