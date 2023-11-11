#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
const int N=200005;
int n,m;
vector<int>G[N];
int dfn[N],low[N],Index;
int tot;
void tarjan(int u)
{
    static bool vis[N];
    static stack<int>s;
    dfn[u]=low[u]=++Index;
    vis[u]=true;
    s.emplace(u);
    for(int v:G[u])
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        tot++;
        while(!s.empty()&&s.top()!=u)
        {
            vis[s.top()]=false;
            s.pop();
        }
        vis[u]=false;
        s.pop();
    }
    return;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
    }
    Index=0;
    for(int i=1;i<=n;i++)
        dfn[i]=low[i]=0;
    tot=0;
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    if(tot==1) cout<<"YES\n";
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