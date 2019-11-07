#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
using namespace std;
const int N=200001;
int n,m,q;
int x[N],y[N];
int tot,num;
struct Edge
{
    int to,next;
}edge[N<<1];
int head[N],cnt=1;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dfn[N],low[N],Index;
bool book[N];
stack<int>s;
int belong[N],color[N];
void tarjan(int u,int pre)
{
    belong[u]=num;
    dfn[u]=low[u]=++Index;
    s.push(u);
    book[u]=true;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if((pre^1)==i) continue;
        if(!dfn[v])
        {
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
        }
        else if(book[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        tot++;
        while(s.top()!=u)
        {
            color[s.top()]=tot;
            book[s.top()]=false;
            s.pop();
        }
        color[u]=tot;
        book[u]=false;
        s.pop();
    }
    return;
}
int dep[N],fa[N][20];
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u][0]=father;
    for(int i=1;(1<<i)<=n;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int query(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=log2(n);i>=0;i--)
    {
        if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
        if(u==v) return u;
    }
    for(int i=log2(n);i>=0;i--)
        if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int f[N],g[N];
bool vis[N];
void get(int u)
{
    vis[u]=true;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(vis[v]) continue;
        get(v);
        f[u]+=f[v],g[u]+=g[v];
    }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        add_edge(x[i],y[i]);
        add_edge(y[i],x[i]);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) num++,tarjan(i,0);
    memset(head,0,sizeof(head));
    cnt=0;
    for(int i=1;i<=m;i++)
        if(color[x[i]]!=color[y[i]]) add_edge(color[x[i]],color[y[i]]),add_edge(color[y[i]],color[x[i]]);
    for(int i=1;i<=tot;i++)
        if(!dep[i]) dfs(i,0);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(belong[x]!=belong[y])
        {
            printf("No");
            return 0;
        }
        x=color[x],y=color[y];
        int lca=query(x,y);
        f[x]++,f[lca]--,g[y]++,g[lca]--;
    }
    for(int i=1;i<=tot;i++)
        if(!vis[i]) get(i);
    for(int i=1;i<=tot;i++)
        if(f[i]&&g[i])
        {
            printf("No");
            return 0;
        }
    printf("Yes");
    return 0;
}