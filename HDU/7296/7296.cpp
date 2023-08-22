#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=20005,M=2005;
const int INF=1061109567;
int n,m;
int a[N];
int f[M][M],mn[M][M];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<=m;i++)
    {
        memset(f[i],63,sizeof(int)*(m+1));
        memset(mn[i],63,sizeof(int)*(m+1));
    }
    for(int i=1;i<m;i++)
    {
        int pi=i%(m+1);
        f[pi][i]=a[i];
        for(int j=1;j<=min(m,i);j++)
            mn[pi][j]=min(mn[pi][j-1],f[pi][j]);
    }
    for(int i=1;i<=n;i++)
    {
        int pi=i%(m+1),pij=pi,lim=min(m,i);
        for(int j=1;j<=lim;j++)
        {
            pij=pij-1;
            if(pij<0) pij=m;
            f[pi][j]=min(f[pi][j],mn[pij][lim-j]+a[i]);
            mn[pi][j]=min(mn[pi][j-1],f[pi][j]);
        }
        if(i>=m)
        {
            int ppi=(i-m)%(m+1);
            memset(f[ppi],63,sizeof(int)*(min(i-m,m)+1));
            memset(mn[ppi],63,sizeof(int)*(min(i-m,m)+1));
        }
    }
    int ans=INF;
    for(int i=n-m+1;i<=n;i++)
    {
        int pi=i%(m+1),lim=min(m+1,m-n+i-1);
        for(int j=1;j<=lim;j++)
            ans=min(ans,f[pi][j]);
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