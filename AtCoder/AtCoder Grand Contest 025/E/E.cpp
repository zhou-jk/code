#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int N=2005;
int n,m;
int u[N],v[N];
vector<int>G[N];
int dep[N];
int fa[N][20];
void init(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u][0]=father;
    for(int i=1;(1<<i)<=n;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int v:G[u])
    {
        if(v==father) continue;
        init(v,u);
    }
    return;
}
int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=log2(n);i>=0;i--)
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    if(u==v) return u;
    for(int i=log2(n);i>=0;i--)
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
set<int>pos[N];
vector<pair<int,int>>edge;
int bel[N*N],rev[N*N];
void dfs(int u,int father)
{
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    if((int)pos[u].size()==1)
    {
        int id=*pos[u].begin();
        if(edge[id].first!=u) swap(edge[id].first,edge[id].second),rev[id]^=1;
        int a=father,b=edge[id].second;
        pos[u].erase(pos[u].begin());
        pos[b].erase(pos[b].find(id));
        if(a!=b)
        {
            edge.emplace_back(a,b);
            int idn=(int)edge.size()-1;
            pos[a].insert(idn);
            pos[b].insert(idn);
            bel[id]=idn;
        }
    }
    else if((int)pos[u].size()>=2)
    {
        int a,b;
        int ida=*pos[u].begin();
        if(edge[ida].second!=u) swap(edge[ida].first,edge[ida].second),rev[ida]^=1;
        a=edge[ida].first;
        pos[u].erase(pos[u].begin());
        pos[a].erase(pos[a].find(ida));
        int idb=*pos[u].begin();
        if(edge[idb].first!=u) swap(edge[idb].first,edge[idb].second),rev[idb]^=1;
        b=edge[idb].second;
        pos[u].erase(pos[u].begin());
        pos[b].erase(pos[b].find(idb));
        if(a!=b)
        {
            edge.emplace_back(a,b);
            int id=(int)edge.size()-1;
            pos[a].insert(id);
            pos[b].insert(id);
            bel[ida]=bel[idb]=id;
        }
        while(!pos[u].empty())
        {
            int id=*pos[u].begin();
            if(edge[id].first!=u) swap(edge[id].first,edge[id].second),rev[id]^=1;
            int a=father,b=edge[id].second;
            pos[u].erase(pos[u].begin());
            pos[b].erase(pos[b].find(id));
            if(a!=b)
            {
                edge.emplace_back(a,b);
                int idn=(int)edge.size()-1;
                pos[a].insert(idn);
                pos[b].insert(idn);
                bel[id]=idn;
            }
        }
    }
    return;
}
int getr(int v)
{
    if(bel[v]==-1) return rev[v];
    if(getr(bel[v])) swap(edge[v].first,edge[v].second),rev[v]^=1;
    bel[v]=-1;
    return rev[v];
}
bool c0[N],c1[N];
void add(int u,int v)
{
    int s=LCA(u,v);
    while(u!=s)
        c0[u]=true,u=fa[u][0];
    while(v!=s)
        c1[v]=true,v=fa[v][0];
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    init(1,0);
    edge.resize(m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        edge[i]={u[i],v[i]};
        pos[u[i]].insert(i);
        pos[v[i]].insert(i);
    }
    memset(bel,-1,sizeof(bel));
    dfs(1,0);
    for(int i=0;i<m;i++)
        getr(i);
    for(int i=0;i<m;i++)
        add(edge[i].first,edge[i].second);
    int ans=0;
    for(int i=2;i<=n;i++)
        if(c0[i]&&c1[i]) ans+=2;
        else if(c0[i]||c1[i]) ans++;
    printf("%d\n",ans);
    for(int i=0;i<m;i++)
        printf("%d %d\n",edge[i].first,edge[i].second);
    return 0;
}