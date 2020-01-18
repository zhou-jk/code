#include<iostream>
#include<cstdio>
using namespace std;
int n;
struct Edge
{
    int to,next;
}edge[1000001];
int head[1000001],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
long long ans;
int a[1000001][2];
long long f[1000001][2];
bool vis[1000001];
inline void dfs(int u,int father)
{
    f[u][0]=0;
    f[u][1]=a[u][0];
    vis[u]=true;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father)
        {
            f[v][1]=-1e9;
            continue;
        }
        dfs(v,father);
        f[u][0]+=max(f[v][0],f[v][1]);
        f[u][1]+=f[v][0];
    }
    return;
}
void dp(int x)
{
    int pos=x;
    vis[x]=true;
    while(!vis[a[pos][1]])
        pos=a[pos][1],vis[pos]=true;
    long long res=0; 
    dfs(pos,pos);
    res=max(f[pos][0],f[pos][1]);
    dfs(a[pos][1],a[pos][1]);
    res=max(res,max(f[a[pos][1]][0],f[a[pos][1]][1]));
    ans+=res;
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
        add_edge(a[i][1],i);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) dp(i);
    printf("%lld",ans);
    return 0;
}