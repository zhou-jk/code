#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=70005,M=100005;
const int MOD=1000000007;
int n,m,q;
struct Edge
{
    int u,v,w;
}e[M];
int fa[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    else return fa[v]=getf(fa[v]);
}
vector<int>G[N*2];
int tot;
int a[N*2];
void kruskal()
{
    sort(e+1,e+m+1,[=](const Edge &a,const Edge &b){return a.w<b.w;});
    for(int i=1;i<=n;i++)
        fa[i]=i;
    tot=n;
    for(int i=1;i<=m;i++)
    {
        int f1=getf(e[i].u),f2=getf(e[i].v);
        if(f1==f2) continue;
        tot++;
        fa[f1]=fa[f2]=fa[tot]=tot;
        a[tot]=e[i].w;
        G[tot].emplace_back(f1),G[f1].emplace_back(tot);
        G[tot].emplace_back(f2),G[f2].emplace_back(tot);
    }
    return;
}
int dfn[N*2],Index;
int mn[N*2][20],lg2[N*2];
void dfs(int u,int father)
{
    dfn[u]=++Index;
    mn[Index][0]=father;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int lca(int u,int v)
{
    if(u==v) return u;
    u=dfn[u],v=dfn[v];
    if(u>v) swap(u,v);
    u++;
    int d=lg2[v-u+1];
    if(dfn[mn[u][d]]<dfn[mn[v-(1<<d)+1][d]]) return mn[u][d];
    else return mn[v-(1<<d)+1][d];
}
void init_lca(int n)
{
    lg2[0]=-1;
    for(int i=1;i<=n;i++)
        lg2[i]=lg2[i/2]+1;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            if(dfn[mn[i][j-1]]<dfn[mn[i+(1<<(j-1))][j-1]]) mn[i][j]=mn[i][j-1];
            else mn[i][j]=mn[i+(1<<(j-1))][j-1];
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    kruskal();
    for(int i=tot;i>=1;i--)
        if(!dfn[i]) dfs(i,0);
    init_lca(tot);
    scanf("%d",&q);
    int A,B,C,P;
    scanf("%d%d%d%d",&A,&B,&C,&P);
    auto rnd=[&]()
    {
        return A=(A*B+C)%P;
    };
    long long ans=0;
    while(q--)
    {
        int u=rnd()%n+1,v=rnd()%n+1;
        if(getf(u)!=getf(v)) ans--;
        else
        {
            int l=lca(u,v);
            ans+=a[l];
        }
    }
    ans%=MOD;
    printf("%lld",ans);
    return 0;
}