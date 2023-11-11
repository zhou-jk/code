#include<iostream>
#include<cstdio>
#include<vector>
#include<chrono>
#include<queue>
using namespace std;
const int N=100005;
const unsigned long long mask=chrono::steady_clock::now().time_since_epoch().count();
const unsigned long long S=1;
unsigned long long shift(unsigned long long x)
{
    x^=mask;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    x^=mask;
    return x;
}
int n,m;
vector<int>G[N];
int deg[N];
bool vis[N];
unsigned long long f[N];
void dfs(int u)
{
    f[u]=S;
    vis[u]=true;
    for(int v:G[u])
    {
        if(vis[v]) continue;
        dfs(v);
        f[u]+=shift(f[v]);
    }
    return;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        G[i].clear(),deg[i]=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
        deg[x]++,deg[y]++;
    }
    if(m==n-1)
    {
        cout<<"YES\n";
        return;
    }
    if(m>n)
    {
        cout<<"NO\n";
        return;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(deg[i]==1) q.emplace(i);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:G[u])
        {
            deg[v]--;
            if(deg[v]==1) q.emplace(v);
        }
    }
    for(int i=1;i<=n;i++)
        if(deg[i]==2) vis[i]=true;
        else vis[i]=false;
    for(int i=1;i<=n;i++)
        if(deg[i]==2) dfs(i);
    vector<int>pos;
    int u=0,v=0;
    for(int i=1;i<=n;i++)
        if(deg[i]==2)
        {
            u=i;
            for(int j:G[i])
                if(deg[j]==2)
                {
                    v=j;
                    break;
                }
            q.emplace(v);
            deg[v]--,deg[u]--;
            break;
        }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        pos.emplace_back(u);
        for(int v:G[u])
        {
            deg[v]--;
            if(deg[v]==1) q.emplace(v);
        }
    }
    pos.emplace_back(u);
    int l=pos.size();
    bool all_same=true;
    for(int i=1;i<l;i++)
        if(f[pos[i]]!=f[pos[i-1]])
        {
            all_same=false;
            break;
        }
    bool gap_same=false;
    if(l%2==0)
    {
        gap_same=true;
        for(int i=2;i<l;i++)
            if(f[pos[i]]!=f[pos[i-2]])
            {
                gap_same=false;
                break;
            }
    }
    if(all_same||gap_same) cout<<"YES\n";
    else cout<<"NO\n";
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