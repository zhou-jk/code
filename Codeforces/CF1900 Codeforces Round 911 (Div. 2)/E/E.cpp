#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m;
int a[N];
vector<int>G[N];
int dfn[N],low[N],Index;
bool book[N];
int bel[N],tot;
void tarjan(int u)
{
    static stack<int> s;
    dfn[u]=low[u]=++Index;
    book[u]=true;
    s.emplace(u);
    for(int v:G[u])
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(book[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        tot++;
        while(!s.empty()&&s.top()!=u)
        {
            book[s.top()]=false;
            bel[s.top()]=tot;
            s.pop();
        }
        book[u]=false;
        bel[u]=tot;
        s.pop();
    }
    return;
}
int c[N];
long long s[N];
int f[N];
long long g[N];
vector<int>E[N];
int deg[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
    }
    fill(dfn+1,dfn+n+1,0);
    fill(low+1,low+n+1,0);
    Index=tot=0;
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i);
    fill(c+1,c+tot+1,0);
    fill(s+1,s+tot+1,0);
    for(int i=1;i<=n;i++)
        c[bel[i]]++,s[bel[i]]+=a[i];
    fill(deg+1,deg+tot+1,0);
    for(int i=1;i<=tot;i++)
        E[i].clear();
    for(int u=1;u<=n;u++)
        for(int v:G[u])
            if(bel[u]!=bel[v])
            {
                E[bel[u]].emplace_back(bel[v]);
                deg[bel[v]]++;
            }
    queue<int>q;
    fill(f+1,f+n+1,0);
    for(int i=1;i<=tot;i++)
        if(deg[i]==0)
        {
            q.emplace(i);
            f[i]=c[i],g[i]=s[i];
        }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:E[u])
        {
            deg[v]--;
            if(f[u]+c[v]>f[v]) f[v]=f[u]+c[v],g[v]=g[u]+s[v];
            else if(f[v]==f[u]+c[v]&&g[u]+s[v]<g[v]) g[v]=g[u]+s[v];
            if(deg[v]==0) q.emplace(v);
        }
    }
    int len=0;
    long long ans=0;
    for(int i=1;i<=n;i++)
        if(f[i]>len) len=f[i],ans=g[i];
        else if(f[i]==len&&g[i]<ans) ans=g[i];
    cout<<len<<" "<<ans<<"\n";
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