#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
const int N=2005;
int n,d;
int l[N];
bitset<N>f[N],g[N];
void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>l[i];
    sort(l+1,l+n+1);
    for(int i=1;i<=n-1;i++)
        if(l[i]>d-l[n])
        {
            cout<<"No\n";
            return;
        }
    g[0][0]=1;
    for(int i=1;i<=n-1;i++)
        g[i]=g[i-1]|(g[i-1]<<l[i]);
    if(g[n-1][d-l[n]])
    {
        cout<<"Yes\n";
        return;
    }
    if(l[n]>d/2)
    {
        cout<<"No\n";
        return ;
    }
    for(int j=0;j<=d;j++)
        f[j].reset();
    f[0][0]=1;
    for(int i=1;i<=n-1;i++)
        for(int j=d;j>=0;j--)
        {
            f[j]|=f[j]<<l[i];
            if(j>=l[i]) f[j]|=f[j-l[i]];
        }
    for(int i=l[n];i+l[n]<=d;i++)
        if(f[i][d-i])
        {
            cout<<"Yes\n";
            return;
        }
    cout<<"No\n";
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