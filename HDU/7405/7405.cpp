#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50005,M=505;
const int INF=1061109567;
int n,m;
int c[N];
int f[M];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    sort(c+1,c+n+1);
    if(c[n]==m)
    {
        cout<<0<<"\n";
        return;
    }
    for(int i=0;i<=m;i++)
        f[i]=-INF;
    int ans=INF;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,c[i]-f[m-c[i]]);
        for(int j=m;j>=c[i];j--)
        {
            if(j==c[i]) f[j]=j;
            else f[j]=max(f[j],f[j-c[i]]);
        }
    }
    if(ans>=INF) cout<<-1<<"\n";
    else cout<<ans<<"\n";
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