#include<iostream>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=2005,M=100005;
int n,m,d;
int a[N];
int v[M];
void solve()
{
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>v[i];
    int ans=0;
    for(int t=1;t<=min(2*n,d);t++)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]==i) cnt++;
        ans=max(ans,cnt+(d-t)/2);
        if(t>m) v[t]=v[t-m];
        for(int i=1;i<=v[t];i++)
            a[i]++;
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