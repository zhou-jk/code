#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100001;
const int MOD=998244353;
const int M=1000000009;
struct Edge
{
    int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
vector<pair<int,int>>H[N];
long long h[N];
int fa[N],size[N];
int n;
int X,dist;
int ans;
void init(int u,int father,int dis)
{
    if(dis>dist) dist=dis,X=u;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        fa[v]=u;
        init(v,u,dis+1);
    }
    return;
}
void dfs1(int u,int father)
{
    H[u].clear();
    size[u]=1;
    h[u]=1;
    bool leaf=true;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs1(v,u);
        leaf=false;
        size[u] += size[v] ;
        H[u].push_back(make_pair(h[v],v));
    }
    if(!leaf)
    {
        sort(H[u].begin(),H[u].end());
        int cnt=1;
        h[u]=h[u]*H[u][0].first%MOD;
        for(int i=1;i<H[u].size();i++)
            h[u]=h[u]*H[u][i].first%MOD;
    }
    h[u]=(h[u]+size[u])%M;
    h[u]=h[u]*h[u]%MOD;
    return;
}
void dfs(int u,int father,int num)
{
    if(num+H[u].size()<4) ans++;
    for(int i=0;i<H[u].size();i++)
        if(i==0||H[u][i].first!=H[u][i-1].first) dfs(H[u][i].second,u,1);
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dist=-1 ;
    init(1,0,0);
    dist=-1;
    init(X,0,0);
    int f=dist&1;
    dist>>=1;
    while(dist--) X=fa[X];
    int X2=X;
    if(f) X=fa[X];
    dfs1(X,X2);
    if(X!=X2) dfs1(X2,X);
    if(X==X2) dfs(X,X2,0);
    else if(h[X]==h[X2]) dfs(X,X2,1);
    else dfs(X,X2,1),dfs(X2,X,1);
    printf("%d",ans);
    return 0 ;
}