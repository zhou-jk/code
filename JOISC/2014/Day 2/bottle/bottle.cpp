#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
const int N=2005,M=200005;
const int INF=1061109567;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,p,Q;
char s[N][N];
int a[M],b[M];
vector<tuple<int,int,int>>edge;
void bfs()
{
    static int ret[N][N];
    static int bel[N][N];
    memset(ret,63,sizeof(ret));
    queue<pair<int,int> >q;
    for(int i=1;i<=p;i++)
        q.emplace(a[i],b[i]),bel[a[i]][b[i]]=i,ret[a[i]][b[i]]=0;
    while(!q.empty())
    {
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            auto [tx,ty]=make_pair(x+dir[i][0],y+dir[i][1]);
            if(tx<1||tx>n||ty<1||ty>m) continue;
            if(s[tx][ty]=='#') continue;
            if(ret[tx][ty]<INF)
            {
                edge.emplace_back(bel[x][y],bel[tx][ty],ret[x][y]+ret[tx][ty]);
                continue;
            }
            bel[tx][ty]=bel[x][y];
            ret[tx][ty]=ret[x][y]+1;
            q.emplace(tx,ty);
        }
    }
    return;
}
int fa[M];
int getf(int v)
{
    if(v==fa[v]) return fa[v];
    fa[v]=getf(fa[v]);
    return fa[v];
}
bool merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2)
    {
        fa[f2]=f1;
        return true;
    }
    else return false;
}
vector<pair<int,int>>G[M];
void kruskal()
{
    for(int i=1;i<=p;i++)
        fa[i]=i;
    sort(edge.begin(),edge.end(),[=](const tuple<int,int,int> &x,const tuple<int,int,int> &y){return get<2>(x)<get<2>(y);});
    for(auto [u,v,w]:edge)
        if(merge(u,v)) G[u].emplace_back(v,w),G[v].emplace_back(u,w);
    for(int i=1;i<=p;i++)
        if(getf(i)==i) G[0].emplace_back(i,INF),G[i].emplace_back(0,INF);
    return;
}
int dep[M];
int f[M][20],g[M][20];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    for(int i=1;(1<<i)<=p;i++)
        f[u][i]=f[f[u][i-1]][i-1],g[u][i]=max(g[u][i-1],g[f[u][i-1]][i-1]);
    for(auto [v,w]:G[u])
    {
        if(v==father) continue;
        f[v][0]=u;
        g[v][0]=w;
        dfs(v,u);
    }
    return;
}
int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=log2(p);i>=0;i--)
        if(dep[f[u][i]]>=dep[v]) u=f[u][i];
    if(u==v) return u;
    for(int i=log2(p);i>=0;i--)
        if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];
}
int jump(int u,int pos)
{
    int res=0;
    for(int i=log2(p);i>=0;i--)
    {
        if(u==pos) break;
        if(dep[f[u][i]]>=dep[pos]) res=max(res,g[u][i]),u=f[u][i];
    }
    return res;
}
int query(int u,int v)
{
    int lca=LCA(u,v);
    return max(jump(u,lca),jump(v,lca));
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&p,&Q);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=p;i++)
        scanf("%d%d",&a[i],&b[i]);
    bfs();
    kruskal();
    dfs(0,0);
    while(Q--)
    {
        int S,T;
        scanf("%d%d",&S,&T);
        int res=query(S,T);
        if(res>=INF) printf("-1\n");
        else printf("%d\n",res);
    }
    return 0;
}