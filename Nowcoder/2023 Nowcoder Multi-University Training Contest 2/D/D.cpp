#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2005;
int n,m,k;
int a[N][N];
bool vis[N];
int ans[N];
void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=n+1;i<=k;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=a[(i-1)%n+1][j];
    fill(vis+1,vis+m+1,false);
    for(int i=k;i>=1;i--)
    {
        int mx=0;
        for(int j=1;j<=m;j++)
            if(!vis[j]&&a[i][j]>a[i][mx]) mx=j;
        ans[i]=mx;
        vis[mx]=true;
    }
    sort(ans+1,ans+k+1);
    for(int i=1;i<=k;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
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