#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000001;
int n,m,r;
int a[N],w[N];
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
struct Binary_Indexed_Tree
{
    long long C[N];
    Binary_Indexed_Tree()
    {
        memset(C,0,sizeof(C));
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    long long query(int x)
    {
        long long ans=0;
        for(int i=x;i>0;i-=lowbit(i))
            ans+=C[i];
        return ans;
    }
}tree;
int dfn[N],Index;
int size[N];
void dfs(int u,int father)
{
    dfn[u]=++Index;
    w[Index]=u;
    size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
        size[u]+=size[v];
    }
    return;
}
int main()
{
    scanf("%d%d%d",&n,&m,&r);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs(r,0);
    for(int i=1;i<=n;i++)
        tree.add(dfn[i],a[i]);
    while(m--)
    {
        int op,x,y;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&x,&y);
            tree.add(dfn[x],y);
        }
        else if(op==2)
        {
            scanf("%d",&x);
            printf("%lld\n",tree.query(dfn[x]+size[x]-1)-tree.query(dfn[x]-1));
        }
    }
    return 0;
}