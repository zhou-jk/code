#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<bitset>
#include<functional>
#include<algorithm>
using namespace std;
constexpr int N=10005,M=500005;
struct Union_Set
{
    int n;
    vector<int>fa;
    Union_Set(int _n):n(_n)
    {
        fa=vector<int>(_n);
        for(int i=0;i<_n;i++)
            fa[i]=i;
    }
    void init(int _n)
    {
        n=_n;
        fa.resize(n);
        for(int i=0;i<n;i++)
            fa[i]=i;
        return; 
    }
    int getf(int v)
    {
        if(v==fa[v]) return v;
        else return fa[v]=getf(fa[v]);
    }
    bool merge(int u,int v)
    {
        int fu=getf(u),fv=getf(v);
        if(fu!=fv)
        {
            fa[fv]=fu;
            return true;
        }
        else return false;
    }
};
long long minimum_spanning_tree(int n,vector<tuple<int,int,int>>edge)
{
    sort(edge.begin(),edge.end(),[](const tuple<int,int,int> &a,const tuple<int,int,int> &b){return get<2>(a)<get<2>(b);});
    Union_Set us(n);
    long long sum=0;
    for(int i=0;i<(int)edge.size();i++)
    {
        auto &[u,v,w]=edge[i];
        if(us.merge(u,v)) sum+=w;
    }
    return sum;
}

struct Trajan_SCC
{
    int n;
    Trajan_SCC(int _n=0):n(_n){}
    void init(int _n)
    {
        n=_n;
        return;
    }
    vector<int>G[N];
    void add_edge(int u,int v)
    {
        G[u].emplace_back(v);
        return;
    }
    int dfn[N],low[N],idx;
    bool ins[N];
    stack<int>s;
    int bel[N],tot;
    vector<int>block[N];
    void dfs(int u)
    {
        dfn[u]=low[u]=++idx;
        ins[u]=true;
        s.push(u);
        for(int v:G[u])
        {
            if(!dfn[v])
            {
                dfs(v);
                low[u]=min(low[u],low[v]);
            }
            else if(ins[v]) low[u]=min(low[u],dfn[v]);
        }
        if(dfn[u]==low[u])
        {
            tot++;
            block[tot].clear();
            while(!s.empty()&&s.top()!=u)
            {
                int v=s.top();
                s.pop();
                ins[v]=false;
                bel[v]=tot;
                block[tot].push_back(v);
            }
            s.pop();
            ins[u]=false;
            bel[u]=tot;
            block[tot].push_back(u);
        }
        return;
    }
    void tarjan()
    {
        fill(dfn+1,dfn+n+1,0);
        fill(low+1,low+n+1,0);
        idx=0;
        fill(bel+1,bel+n+1,0);
        tot=0;
        fill(ins+1,ins+n+1,false);
        for(int i=1;i<=n;i++)
            if(!dfn[i]) dfs(i);
        return;
    }
};

struct Kosaraju_SCC
{
    int n;
    Kosaraju_SCC(int _n=0):n(_n){}
    void init(int _n)
    {
        n=_n;
        return;
    }
    bitset<N>mp[N],rmp[N];
    vector<int>block[N];
    int bel[N],tot;
    void add_edge(int u,int v)
    {
        mp[u][v]=1;
        rmp[v][u]=1;
        return;
    }
    bitset<N>vis;
    vector<int>out;
    void dfs1(int x)
    {
        vis[x]=1;
        for(auto now=mp[x]&(~vis);now.any();now=now&(~vis))
            dfs1(now._Find_first());
        out.push_back(x);
        return;
    }
    void dfs2(int x)
    {
        block[tot].push_back(x);
        vis[x]=1;
        bel[x]=tot;
        for(auto now=rmp[x]&(~vis);now.any();now=now&(~vis))
            dfs2(now._Find_first());
        return;
    }
    void kosaraju()
    {
        out.clear();
        vis.reset();
        for(int i=1;i<=n;i++)
            if(!vis[i]) dfs1(i);
        vis.reset();
        fill(bel+1,bel+n+1,0);
        tot=0;
        for(int i=out.size()-1;i>=0;i--)
        {
            int u=out[i];
            if(!vis[u])
            {
                tot++;
                block[tot].clear();
                dfs2(u);
            }
        }
        return;
    }
};

struct Tarjan_Cut
{
    int n;
    Tarjan_Cut(int _n=0):n(_n){}
    void init(int _n)
    {
        n=_n;
        return;
    }
    vector<int>G[N];
    void add_edge(int u,int v)
    {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        return;
    }
    int dfn[N],low[N],idx;
    bool iscut[N];
    void dfs(int u,int father)
    {
        int children=0;
        dfn[u]=low[u]=++idx;
        for(int v:G[u])
        {
            if(!dfn[v])
            {
                children++;
                dfs(v,u);
                low[u]=min(low[u],low[v]);
                if(u!=father&&low[v]>=dfn[u]) iscut[u]=true;
                else if(u==father&&children>=2) iscut[u]=true;
            }
            else if(v!=father) low[u]=min(low[u],dfn[v]);
        }
        return;
    }
    int cut[N],tot;
    void tarjan()
    {
        fill(dfn+1,dfn+n+1,0);
        fill(low+1,low+n+1,0);
        idx=0;
        fill(iscut+1,iscut+n+1,false);
        for(int i=1;i<=n;i++)
            if(!dfn[i]) dfs(i,i);
        tot=0;
        for(int i=1;i<=n;i++)
            if(iscut[i]) cut[++tot]=i;
        return;
    }
};
struct Tarjan_Bridge
{
    int n,m;
    Tarjan_Bridge(int _n=0):n(_n),m(0){}
    void init(int _n)
    {
        n=_n,m=0;
        return;
    }
    vector<pair<int,int>>G[N];
    pair<int,int>edge[M];
    void add_edge(int u,int v)
    {
        m++;
        edge[m]=make_pair(u,v);
        G[u].emplace_back(v,m);
        G[v].emplace_back(u,m);
        return;
    }
    int dfn[N],low[N],idx;
    bool isbridge[M];
    void dfs(int u,int prev)
    {
        low[u]=dfn[u]=++idx;
        for(auto [v,id]:G[u])
        {
            if(!dfn[v])
            {
                dfs(v,id);
                low[u]=min(low[u],low[v]);
                if(low[v]>dfn[u]) isbridge[id]=true;
            }
            else if(dfn[v]<dfn[u]&&id!=prev) low[u]=min(low[u],dfn[v]);
        }
        return;
    }
    pair<int,int>bridge[M];
    int tot;
    void tarjan()
    {
        fill(dfn+1,dfn+n+1,0);
        fill(low+1,low+n+1,0);
        idx=0;
        fill(isbridge+1,isbridge+m+1,false);
        for(int i=1;i<=n;i++)
            if(!dfn[i]) dfs(i,0);
        tot=0;
        for(int i=1;i<=m;i++)
            if(isbridge[i]) bridge[++tot]=edge[i];
        return;
    }
};
struct Trajan_EBC
{
    int n,m;
    Trajan_EBC(int _n=0):n(_n),m(0){}
    void init(int _n)
    {
        n=_n,m=0;
        return;
    }
    vector<pair<int,int>>G[N];
    void add_edge(int u,int v)
    {
        m++;
        G[u].emplace_back(v,m);
        G[v].emplace_back(u,m);
        return;
    }
    int dfn[N],low[N],idx;
    bool ins[N];
    stack<int>s;
    int bel[N],tot;
    vector<int>block[N];
    void dfs(int u,int prev)
    {
        dfn[u]=low[u]=++idx;
        ins[u]=true;
        s.push(u);
        for(auto [v,id]:G[u])
        {
            if(id==prev) continue;
            if(!dfn[v])
            {
                dfs(v,id);
                low[u]=min(low[u],low[v]);
            }
            else if(ins[v]) low[u]=min(low[u],dfn[v]);
        }
        if(dfn[u]==low[u])
        {
            tot++;
            block[tot].clear();
            while(!s.empty()&&s.top()!=u)
            {
                int v=s.top();
                s.pop();
                ins[v]=false;
                bel[v]=tot;
                block[tot].push_back(v);
            }
            s.pop();
            ins[u]=false;
            bel[u]=tot;
            block[tot].push_back(u);
        }
        return;
    }
    void tarjan()
    {
        fill(dfn+1,dfn+n+1,0);
        fill(low+1,low+n+1,0);
        idx=0;
        fill(bel+1,bel+n+1,0);
        tot=0;
        fill(ins+1,ins+n+1,false);
        for(int i=1;i<=n;i++)
            if(!dfn[i]) dfs(i,0);
        return;
    }
};