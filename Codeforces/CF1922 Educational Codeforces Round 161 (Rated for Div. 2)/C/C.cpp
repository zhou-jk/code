#include<iostream>
#include<cstdio>
using namespace std;
const int N=300005;
int n,m;
int a[N];
long long pre[N],suf[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    pre[0]=suf[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        if(i>1&&a[i]-a[i-1]<a[i+1]-a[i]) pre[i]=pre[i-1]+a[i+1]-a[i];
        else pre[i]=pre[i-1]+1;
    }
    for(int i=n;i>=1;i--)
    {
        if(i<n&&a[i+1]-a[i]<a[i]-a[i-1]) suf[i]=suf[i+1]+a[i]-a[i-1];
        else suf[i]=suf[i+1]+1;
    }
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(x<y) cout<<pre[y-1]-pre[x-1]<<"\n";
        else cout<<suf[y+1]-suf[x+1]<<"\n";
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