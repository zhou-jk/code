#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n,m,q;
int r[N];
int c[N];
vector<pair<int,int>>G[N];
long long dis[N];
int pre[N];
int mi[20][N];
int dfn[N],Index;
int lg2[N];
void init(int n=100000)
{
    lg2[0]=-1;
    for(int i=1;i<=n;i++)
        lg2[i]=lg2[i/2]+1;
    return;
}
int dmin(int x,int y)
{
    return dfn[x]<dfn[y]?x:y;
}
void dfs(int u,int father)
{
    if(c[u]) pre[u]=u;
    else pre[u]=pre[father];
    dfn[u]=++Index;
    mi[0][dfn[u]]=father;
    for(auto [v,w]:G[u])
    {
        if(v==father) continue;
        dis[v]=dis[u]+w;
        dfs(v,u);
    }
    return;
}
int lca(int u,int v)
{
    if(u==v) return u;
    u=dfn[u],v=dfn[v];
    if(u>v) swap(u,v);
    int d=lg2[v-u];
    return dmin(mi[d][u+1],mi[d][v-(1<<d)+1]);
}
int p[N],k;
void solve()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
        scanf("%d",&r[i]);
    for(int i=1;i<=n;i++)
        G[i].clear();
    long long sum=0;
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].emplace_back(y,z);
        G[y].emplace_back(x,z);
        sum+=z;
    }
    for(int i=1;i<=n;i++)
        c[i]=0;
    for(int i=1;i<=m;i++)
        c[r[i]]=1;
    dis[1]=0;
    Index=0;
    dfs(1,0);
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
            mi[i][j]=dmin(mi[i-1][j],mi[i-1][j+(1<<(i-1))]);
    while(q--)
    {
        scanf("%d",&k);
        for(int i=1;i<=k;i++)
            scanf("%d",&p[i]);
        auto check=[=](long long x)
        {
            vector<int>pos;
            for(int i=1;i<=k;i++)
                if(dis[p[i]]-dis[pre[p[i]]]>x) pos.emplace_back(p[i]);
            if(pos.empty()) return true;
            int l=pos[0];
            for(int i=1;i<(int)pos.size();i++)
                l=lca(l,pos[i]);
            for(int u:pos)
                if(dis[u]-dis[l]>x) return false;
            return true;
        };
        long long l=0,r=sum,ans=-1;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(check(mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}