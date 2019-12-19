#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100001;
struct Edge
{
    int to,next;
}edge[N<<2];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int n,m;
int f[N][31],dep[N];
int rt[N],tot;
int a[N];
int b[N],q;
struct Node
{
    int lc,rc;
    int sum;
}tree[N<<5];
void push_up(int i)
{
    tree[i].sum=tree[tree[i].lc].sum+tree[tree[i].rc].sum;
    return;
}
void build(int &i,int l,int r)
{
    i=++tot;
    if(l==r) return;
    int mid=(l+r)/2;
    build(tree[i].lc,l,mid);
    build(tree[i].rc,mid+1,r);
    return;
}
int update(int i,int l,int r,int u)
{
    int now=++tot;
    tree[now].lc=tree[i].lc,tree[now].rc=tree[i].rc;
    tree[now].sum=tree[i].sum;
    if(l==r)
    {
        tree[now].sum++;
        return now;
    }
    int mid=(l+r)/2;
    if(u<=mid) tree[now].lc=update(tree[i].lc,l,mid,u);
    else tree[now].rc=update(tree[i].rc,mid+1,r,u);
    push_up(now);
    return now;
}
int query(int u,int v,int x,int y,int l,int r,int k)
{
    if(l==r) return b[l];
    int mid=(l+r)/2;
    int sum=tree[tree[u].lc].sum+tree[tree[v].lc].sum-tree[tree[x].lc].sum-tree[tree[y].lc].sum;
    if(sum>=k) return query(tree[u].lc,tree[v].lc,tree[x].lc,tree[y].lc,l,mid,k);
    else return query(tree[u].rc,tree[v].rc,tree[x].rc,tree[y].rc,mid+1,r,k-sum);
}
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    f[u][0]=father;
    for(int i=1;(1<<i)<=n;i++)
        f[u][i]=f[f[u][i-1]][i-1];
    int p=lower_bound(b+1,b+q+1,a[u])-b;
    rt[u]=update(rt[father],1,q,p);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
    }
    return;
}
int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    for(int i=log2(n);i>=0;i--)
    {
        if(dep[f[u][i]]>=dep[v]) u=f[u][i];
        if(u==v) return u; 
    }
    for(int i=log2(n);i>=0;i--)
        if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];
}
int getkth(int u,int v,int k)
{
    int lca=LCA(u,v);
    return query(rt[u],rt[v],rt[lca],rt[f[lca][0]],1,q,k);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    sort(b+1,b+n+1);
    q=unique(b+1,b+n+1)-b-1;
    build(rt[0],1,q);
    dfs(1,0);
    while(m--)
    {
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        printf("%d\n",getkth(u,v,k));
    }
    return 0;
}