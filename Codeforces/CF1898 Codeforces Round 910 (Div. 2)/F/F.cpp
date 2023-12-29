#include<iostream>
#include<cstdio>
#include<queue>
#include<tuple>
using namespace std;
const int N=1005;
const int INF=1e9;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
char s[N][N];
int f[N][N];
pair<int,int>dis[N][N][2];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        for(int j=1;j<=m;j++)
            s[i][j]=str[j-1];
    }
    int tot=0;
    int sx=0,sy=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='V') sx=i,sy=j;
            else if(s[i][j]=='.') tot++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f[i][j]=INF;
    queue<pair<int,int>>q;
    q.emplace(sx,sy);
    f[sx][sy]=0;
    int cnt=0,mn=INF;
    while(!q.empty())
    {
        auto [ux,uy]=q.front();
        q.pop();
        if(ux==1||ux==n||uy==1||uy==m)
        {
            mn=min(mn,f[ux][uy]);
            cnt++;
        }
        for(auto [dx,dy]:dir)
        {
            int tx=ux+dx,ty=uy+dy;
            if(tx<1||tx>n||ty<1||ty>m) continue;
            if(s[tx][ty]=='#') continue;
            if(f[tx][ty]>f[ux][uy]+1)
            {
                f[tx][ty]=f[ux][uy]+1;
                q.emplace(tx,ty);
            }
        }
    }
    if(cnt==0)
    {
        cout<<tot<<"\n";
        return;
    }
    if(cnt==1)
    {
        cout<<tot-mn<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dis[i][j][0]=dis[i][j][1]={INF,INF};
    int num=0;
    queue<tuple<int,int,int>>que;
    for(int i=1;i<=n;i++)
        for(int j:{1,m})
            if(s[i][j]!='#') que.emplace(i,j,0),dis[i][j][0]={0,++num};
    for(int i:{1,n})
        for(int j=1;j<=m;j++)
            if(s[i][j]!='#') que.emplace(i,j,0),dis[i][j][0]={0,++num};
    while(!que.empty())
    {
        auto [ux,uy,op]=que.front();
        que.pop();
        for(auto [dx,dy]:dir)
        {
            int tx=ux+dx,ty=uy+dy;
            if(tx<1||tx>n||ty<1||ty>m) continue;
            if(s[tx][ty]=='#') continue;
            if(dis[tx][ty][0].first>dis[ux][uy][op].first+1)
            {
                dis[tx][ty][0]=make_pair(dis[ux][uy][op].first+1,dis[ux][uy][op].second);
                que.emplace(tx,ty,0);
            }
            else if(dis[ux][uy][op].second!=dis[tx][ty][0].second&&dis[tx][ty][1].first>dis[ux][uy][op].first+1)
            {
                dis[tx][ty][1]=make_pair(dis[ux][uy][op].first+1,dis[ux][uy][op].second);
                que.emplace(tx,ty,1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(f[i][j]<INF) ans=max(ans,tot-f[i][j]-dis[i][j][0].first-dis[i][j][1].first);
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
