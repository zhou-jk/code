#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n,m;
char s[N];
int a[N];
int get_id(int x,int y)
{
    return (x-1)*m+y;
}
int to[N];
int deg[N];
bool vis[N];
int cnt;
void dfs(int u)
{
    vis[u]=true;
    cnt++;
    int v=to[u];
    if(v&&!vis[v]) dfs(v);
    return;
}
int tot;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>s[get_id(i,j)];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[get_id(i,j)];
    fill(deg+1,deg+n*m+1,0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x=i,y=j;
            if(s[get_id(i,j)]=='u') x=i-a[get_id(i,j)],y=j;
            else if(s[get_id(i,j)]=='d') x=i+a[get_id(i,j)],y=j;
            else if(s[get_id(i,j)]=='l') x=i,y=j-a[get_id(i,j)];
            else if(s[get_id(i,j)]=='r') x=i,y=j+a[get_id(i,j)];
            if(x<1||x>n||y<1||y>m)
            {
                to[get_id(i,j)]=0;
                continue;
            }
            to[get_id(i,j)]=get_id(x,y);
            deg[get_id(x,y)]++;
        }
    fill(vis+1,vis+n*m+1,false);
    for(int i=1;i<=n*m;i++)
        if(deg[i]==0)
        {
            cnt=0;
            dfs(i);
            if(cnt==n*m) cout<<"Yes\n";
            else cout<<"No\n";
            return;
        }
    cnt=0;
    dfs(1);
    if(cnt==n*m) cout<<"Yes\n";
    else cout<<"No\n";
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