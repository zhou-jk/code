#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
unsigned int s;
unsigned int get(unsigned int x)
{
	x^=x<<13;
	x^=x>>17;
	x^=x<<5;
	return s=x; 
}
const int N=500005;
int n,q;
int root;
vector<int>G[N];
int f[N][19],dep[N];
int dis[N],top[N],son[N],len[N],fa[N];
void dfs1(int u,int father)
{
    dis[u]=dep[u]=dep[father]+1;
    f[u][0]=father;
    fa[u]=father;
    for(int i=1;(1<<i)<=n;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs1(v,u);
        if(dis[v]>dis[son[u]]) son[u]=v;
    }
    if(son[u]) dis[u]=dis[son[u]];
    return;
}
void dfs2(int u,int father)
{
    top[u]=father;
    len[u]=dis[u]-dep[top[u]]+1;
    if(!son[u]) return;
    dfs2(son[u],father);
    for(int v:G[u])
    {
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
    return;
}
vector<int> up[N],down[N];
int kth_ancestor(int x,int k)
{
    if(k>=dep[x]) return 0;
    if(k==0) return x;
    int h=__lg(k);
    x=f[x][h];
    k^=1<<h;
    if(k==0) return x;
    if(k>dep[x]-dep[top[x]]) return up[top[x]][k-dep[x]+dep[top[x]]];
    else if(k<dep[x]-dep[top[x]]) return down[top[x]][dep[x]-dep[top[x]]-k];
    else return top[x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q>>s;
    for(int i=1;i<=n;i++)
    {
        int f;
        cin>>f;
        if(f==0) root=i;
        else G[f].emplace_back(i),G[i].emplace_back(f);
    }
    dfs1(root,0);
    dfs2(root,root);
    for(int u=1;u<=n;u++)
        if(u==top[u])
        {
            for(int i=1,x=u;i<=len[u]&&x;i++) up[u].push_back(x),x=fa[x];
            for(int i=1,x=u;i<=len[u];i++) down[u].push_back(x),x=son[x];
        }
    int lastans=0;
    long long ans=0;
    for(int i=1;i<=q;i++)
    {
        int x=((get(s)^lastans)%n)+1,k=(get(s)^lastans)%dep[x];
        lastans=kth_ancestor(x,k);
        ans^=(long long)i*lastans;
    }
    cout<<ans;
    return 0;
}