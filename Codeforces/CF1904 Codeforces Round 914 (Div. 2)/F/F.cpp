#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=200005;
int n,m;
vector<int>G[N];
int fa[N][20],dep[N];
int ida[N][20],idb[N][20],tot;
vector<int>E[N*40];
int deg[N*40];
int dfn[N],ed[N],Index;
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u][0]=father;
    ida[u][0]=idb[u][0]=u;
    for(int i=1;(1<<i)<=n;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=1;(1<<i)<=n;i++)
        if(fa[u][i])
        {
            ida[u][i]=++tot;
            E[ida[u][i]].emplace_back(ida[u][i-1]);
            E[ida[u][i]].emplace_back(ida[fa[u][i-1]][i-1]);
            deg[ida[u][i-1]]++,deg[ida[fa[u][i-1]][i-1]]++;
        }
    for(int i=1;(1<<i)<=n;i++)
        if(fa[u][i])
        {
            idb[u][i]=++tot;
            E[idb[u][i-1]].emplace_back(idb[u][i]);
            E[idb[fa[u][i-1]][i-1]].emplace_back(idb[u][i]);
            deg[idb[u][i]]++,deg[idb[u][i]]++;
        }
    dfn[u]=++Index;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    ed[u]=Index;
    return;
}
int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=__lg(n);i>=0;i--)
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    if(u==v) return u;
    for(int i=__lg(n);i>=0;i--)
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
vector<int>get_node(int u,int v,int t)
{
    if(dep[u]<dep[v]) swap(u,v);
    vector<int>res;
    for(int i=__lg(n);i>=0;i--)
        if(dep[fa[u][i]]>=dep[v])
        {
            if(t==1) res.emplace_back(ida[u][i]);
            else res.emplace_back(idb[u][i]);
            u=fa[u][i];
        }
    return res;
}
int ans[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    tot=n;
    dfs(1,0);
    for(int i=1;i<=m;i++)
    {
        int op,a,b,c;
        cin>>op>>a>>b>>c;
        int l=lca(a,b);
        vector<int>p;
        if(l==c)
        {
            vector<int> pa=get_node(a,l,op),pb=get_node(b,l,op);
            p.insert(p.end(),pa.begin(),pa.end());
            p.insert(p.end(),pb.begin(),pb.end());
        }
        else if(dfn[c]<=dfn[a]&&dfn[a]<=ed[c])
        {
            vector<int>pb=get_node(b,l,op);
            vector<int>p1=get_node(a,c,op),p2=get_node(fa[c][0],l,op);
            p.insert(p.end(),p1.begin(),p1.end());
            p.insert(p.end(),p2.begin(),p2.end());
            p.emplace_back(l);
            p.insert(p.end(),pb.begin(),pb.end());
        }
        else
        {
            vector<int>pa=get_node(a,l,op);
            vector<int>p1=get_node(b,c,op),p2=get_node(fa[c][0],l,op);
            p.insert(p.end(),pa.begin(),pa.end());
            p.emplace_back(l);
            p.insert(p.end(),p1.begin(),p1.end());
            p.insert(p.end(),p2.begin(),p2.end());
        }
        if(op==1)
        {
            for(int v:p)
                E[c].emplace_back(v),deg[v]++;
        }
        else if(op==2)
        {
            for(int v:p)
                E[v].emplace_back(c),deg[c]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=tot;i++)
        if(deg[i]==0) q.emplace(i);
    int now=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(1<=u&&u<=n) ans[u]=++now;
        for(int v:E[u])
        {
            deg[v]--;
            if(deg[v]==0) q.emplace(v);
        }
    }
    if(now!=n)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}