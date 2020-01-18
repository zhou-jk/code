#include<iostream>
#include<cstdio>
using namespace std;
int n;
struct Node
{
    int to,next;
}edge[1001];
int head[1001],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int f[1001][3],g[1001][2];
void dfs(int u)
{
    f[u][0]=f[u][1]=f[u][2]=1,g[u][0]=g[u][1]=0;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        dfs(v);
        f[u][0]=min(f[u][0]+f[v][0],g[u][0]+f[v][1]);
        f[u][1]=min(f[u][1]+g[v][0],g[u][1]+f[v][2]);
        f[u][2]=f[u][2]+g[v][1];
        g[u][0]+=f[v][0];
        g[u][1]+=g[v][0];
        f[u][1]=min(f[u][1],f[u][2]),f[u][0]=min(f[u][0],f[u][1]);
        g[u][0]=min(g[u][0],f[u][0]),g[u][1]=min(g[u][1],g[u][0]);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        add_edge(x,i);
    }
    dfs(1);
    printf("%d",f[1][0]);
    return 0;
}