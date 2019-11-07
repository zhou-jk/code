#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=300001,K=51;
const int MOD=998244353;
int n,q;
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
int dep[N],f[N][K];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    f[u][0]=father;
    for(int i=1;(1<<i)<=n;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int query(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=log2(n);i>=0;i--)
    {
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
        if(x==y) return x;
    }
    for(int i=log2(n);i>=0;i--)
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
long long sum[K][N];
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
    dep[0]=-1;
    dfs(1,0);
    dep[0]=0;
    for(int i=1;i<=n;i++)
    {
        long long fac=1;
        for(int j=1;j<K;j++)
            sum[j][i]=fac*i%MOD,fac=fac*i%MOD;
    }
    for(int j=1;j<K;j++)
        for(int i=1;i<=n;i++)
            sum[j][i]=(sum[j][i]+sum[j][i-1])%MOD;
    scanf("%d",&q);
    while(q--)
    {
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        int lca=query(u,v);
        long long ans=(sum[k][dep[u]]+sum[k][dep[v]])%MOD;
        ans=(ans-sum[k][dep[lca]]+MOD)%MOD;
        ans=(ans-sum[k][dep[f[lca][0]]]+MOD)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}