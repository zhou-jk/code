#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n,m,q;
int r[N];
int c[N];
vector<pair<int,int>>G[N];
long long dis[N],d[N];
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
    if(dfn[mi[d][u+1]]<dfn[mi[d][v-(1<<d)+1]]) return mi[d][u+1];
    else return mi[d][v-(1<<d)+1];
}
int p[N],k;
bool check(long long x)
{
    int l=0;
    for(int i=1;i<=k;i++)
        if(d[p[i]]>x)
        {
            if(l==0) l=p[i];
            else l=lca(l,p[i]);
        }
    if(l==0) return true;
    for(int i=1;i<=k;i++)
        if(d[p[i]]>x&&dis[p[i]]-dis[l]>x) return false;
    return true;
};
void solve()
{
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
        cin>>r[i];
    for(int i=1;i<=n;i++)
        G[i].clear();
    long long sum=0;
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
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
            if(dfn[mi[i-1][j]]<dfn[mi[i-1][j+(1<<(i-1))]]) mi[i][j]=mi[i-1][j];
            else mi[i][j]=mi[i-1][j+(1<<(i-1))];
    for(int i=1;i<=n;i++)
        d[i]=dis[i]-dis[pre[i]];
    while(q--)
    {
        cin>>k;
        for(int i=1;i<=k;i++)
            cin>>p[i];
        long long l=0,r=sum,ans=0;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(check(mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<ans<<"\n";
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    init();
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}