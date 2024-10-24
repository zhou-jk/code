#include<iostream>
#include<cstdio>
#include<tuple>
#include<queue>
#include<cassert>
using namespace std;
const int N=1005,K=10;
const int INF=1e9;
int n,m,k;
int x,y,h;
char s[K][N][N];
int f[K][N][N];
void solve()
{
    cin>>n>>m>>k;
    for(int l=0;l<k;l++)
        for(int i=1;i<=n;i++)
        {
            string str;
            cin>>str;
            for(int j=1;j<=m;j++)
                s[l][i][j]=str[j-1];
        }
    cin>>h>>x>>y;
    if(x==n&&y==m)
    {
        cout<<1<<"\n";
        return;
    }
    for(int l=0;l<k;l++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                f[l][i][j]=INF;
    queue<tuple<int,int,int>>q;
    q.emplace(0,n,m);
    f[0][n][m]=0;
    while(!q.empty())
    {
        auto [uk,ux,uy]=q.front();
        q.pop();
        if(ux==n||s[uk][ux+1][uy]=='*')
        {
            int tk=(uk+1)%k;
            for(int tx=ux;ux-tx<=h&&tx>=1;tx--)
            {
                if(s[uk][tx][uy]=='*') break;
                for(int ty:{uy-1,uy,uy+1})
                {
                    if(tx<1||tx>n||ty<1||ty>m) continue;
                    if(s[uk][tx][ty]=='*'||s[tk][tx][ty]=='*') continue;
                    if(f[tk][tx][ty]>f[uk][ux][uy]+1)
                    {
                        f[tk][tx][ty]=f[uk][ux][uy]+1;
                        q.emplace(tk,tx,ty);
                    }
                }
            }
        }
        else if(ux+1<=n)
        {
            int tx=ux+1;
            int tk=(uk+1)%k;
            if(s[uk][tx][uy]=='*') break;
            for(int ty:{uy-1,uy,uy+1})
            {
                if(tx<1||tx>n||ty<1||ty>m) continue;
                if(s[uk][tx][ty]=='*'||s[tk][tx][ty]=='*') continue;
                if(f[tk][tx][ty]>f[uk][ux][uy]+1)
                {
                    f[tk][tx][ty]=f[uk][ux][uy]+1;
                    q.emplace(tk,tx,ty);
                }
            }
        }
    }
    int ans=INF;
    for(int l=0;l<k;l++)
        ans=min(ans,f[l][x][y]);
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