#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1061109567;
int m,n;
struct Edge
{
    int to,next;
}edge[20001];
int head[10001],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int c[10001],root; 
int f[10001][2];
void dfs(int u,int father)
{
    if(u<=n) return;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
        f[u][0]+=min(f[v][0]-1,f[v][1]);
        f[u][1]+=min(f[v][1]-1,f[v][0]);
    }
    return;
}
signed main()
{
    scanf("%d%d",&m,&n);
    root=n+1;
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=m-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=m;i++)
    {
        f[i][0]=f[i][1]=1;
        if(i<=n) f[i][c[i]^1]=INF;
    }
    dfs(root,root);
    printf("%d",min(f[root][0],f[root][1]));
    return 0;
}