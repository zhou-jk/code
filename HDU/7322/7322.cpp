#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
const int N=505;
const int MOD=998244353;
const long long INF=4557430888798830399;
int n,m;
int f[N][N];
long long dis[N][N],g[N][N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j) dis[i][j]=0,f[i][j]=1,g[i][j]=0;
            else dis[i][j]=INF,f[i][j]=0,g[i][j]=INF;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        dis[x][y]=z;
        f[x][y]=1;
        g[x][y]=z;
    }
    long long ans=INF;
    int cnt=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<k;i++)
            for(int j=1;j<k;j++)
                if(g[i][k]+g[k][j]<INF)
                {
                    long long now=dis[j][i]+g[i][k]+g[k][j];
                    if(ans>now) ans=now,cnt=f[j][i];
                    else if(ans==now) cnt=(cnt+f[j][i])%MOD;
                }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=k&&j!=k)
                {
                    if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j],f[i][j]=(long long)f[i][k]*f[k][j]%MOD;
                    else if(dis[i][j]==dis[i][k]+dis[k][j]) f[i][j]=(f[i][j]+(long long)f[i][k]*f[k][j])%MOD;
                }
    }
    if(ans>=INF) cout<<-1<<" "<<-1<<"\n";
    else cout<<ans<<" "<<cnt<<"\n";
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