#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
const int INF=1061109567;
int n,x;
int a[N];
int f[N][N][N],g[N][N][N];
void solve()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=x;k++)
            if(k!=a[i]) f[i][i][k]=1,g[i][i][k]=0;
            else f[i][i][a[i]]=0,g[i][i][a[i]]=1;
    }
    for(int len=2;len<=n;len++)
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            pair<int,int>mn={INF,INF},smn={INF,INF};
            for(int k=1;k<=x;k++)
            {
                f[l][r][k]=g[l][r][k]=INF;
                for(int i=l;i<r;i++)
                {
                   f[l][r][k]=min(f[l][r][k],f[l][i][k]+f[i+1][r][k]);
                   g[l][r][k]=min(g[l][r][k],g[l][i][k]+g[i+1][r][k]); 
                }
                if(g[l][r][k]<mn.first) smn=mn,mn={g[l][r][k],k};
                else if(g[l][r][k]<smn.first) smn={g[l][r][k],k};
            }
            for(int k=1;k<=x;k++)
            {
                if(k!=mn.second) f[l][r][k]=min(f[l][r][k],mn.first+1);
                else f[l][r][k]=min(f[l][r][k],smn.first+1);
                if(k!=mn.second) g[l][r][k]=min(g[l][r][k],mn.first+1);
                else g[l][r][k]=min(g[l][r][k],smn.first+1);
                f[l][r][k]=min(f[l][r][k],g[l][r][k]+1);
            }
        }
    int ans=INF;
    for(int k=1;k<=x;k++)
        ans=min(ans,f[1][n][k]);
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