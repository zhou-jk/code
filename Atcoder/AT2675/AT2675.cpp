#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n;
struct Graph
{
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
}g1,g2,g;
int a[N],b[N];
int a1[N],a2[N];
int st[N],top;
bool book[N];
int color[N];
void dfs1(int u)
{
    for(int i=g1.head[u];i;i=g1.edge[i].next)
    {
        int v=g1.edge[i].to;
        dfs1(v);
    }
    if(a1[u]) st[++top]=u;
    while(top>=2)
    {
        g.add_edge(st[top],st[top-1]);
        g.add_edge(st[top-1],st[top]);
        top-=2;
    }
    return;
}
void dfs2(int u)
{
    for(int i=g2.head[u];i;i=g2.edge[i].next)
    {
        int v=g2.edge[i].to;
        dfs2(v);
    }
    if(a2[u]) st[++top]=u;
    while(top>=2)
    {
        g.add_edge(st[top],st[top-1]);
        g.add_edge(st[top-1],st[top]);
        top-=2;
    }
    return;
}
void dfs(int u,int col)
{
    color[u]=col;
    book[u]=true;
    for(int i=g.head[u];i;i=g.edge[i].next)
    {
        int v=g.edge[i].to;
        if(book[v]) continue;
        dfs(v,-col);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    int rt1,rt2;
    for(int i=1;i<=n;i++)
        a1[i]=a2[i]=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==-1) rt1=i;
        else
        {
            g1.add_edge(a[i],i);
            a1[a[i]]^=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]==-1) rt2=i;
        else
        {
            g2.add_edge(b[i],i);
            a2[b[i]]^=1;
        }
    }
    for(int i=1;i<=n;i++)
        if(a1[i]!=a2[i])
        {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    printf("POSSIBLE\n");
    top=0;
    dfs1(rt1);
    top=0;
    dfs2(rt2);
    for(int i=1;i<=n;i++)
        if(!book[i]) dfs(i,1);
    for(int i=1;i<=n;i++)
        if(!a1[i]) printf("0 ");
        else printf("%d ",color[i]);
    return 0;
}