#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n,q;
int lg2[N];
vector<int>G[N];
int siz[N];
long long f1[N],f2[N],d[N];
int dep[N],fa[N][20];
void dfs1(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u][0]=father;
    for(int i=1;(1<<i)<=n;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    siz[u]=1;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        f1[u]+=f1[v]+siz[v];
    }
    return;
}
void dfs2(int u,int father)
{
    for(int v:G[u])
    {
        if(v==father) continue;
        f2[v]=f2[u]+n-siz[v]+f1[u]-f1[v]-siz[v];
        dfs2(v,u);
    }
    d[u]=f1[u]+f2[u];
    return;
}
int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=lg2[n];i>=0;i--)
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    if(u==v) return u;
    for(int i=lg2[n];i>=0;i--)
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int jump(int u,int k)
{
    for(int i=0;(1<<i)<=n;i++)
        if(k&(1<<i)) u=fa[u][i];
    return u;
}
int dis(int u,int v)
{
    return dep[u]+dep[v]-dep[LCA(u,v)]*2;
}
void solve()
{
    int l,r;
    scanf("%d%d",&l,&r);
    if(dep[l]<dep[r]) swap(l,r);
    int w=dis(l,r);
    if(w%2==0)
    {
        int u=jump(l,w/2);
        long long ans=d[l]+d[r]-d[u]-(long long)w/2*n;
        printf("%lld\n",ans);
    }
    else
    {
        int u=jump(l,w/2);
        long long ans=d[l]+d[r]-d[u]-(long long)w/2*n;
        ans-=(long long)siz[u];
        printf("%lld\n",ans);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    lg2[0]=-1;
    for(int i=1;i<=n;i++)
        lg2[i]=lg2[i/2]+1;
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs1(1,0);
    dfs2(1,0);
    scanf("%d",&q);
    while(q--)
        solve();
    return 0;
}