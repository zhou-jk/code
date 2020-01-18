#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=80001;
int n,m,T;
int a[N];
int b[N],q;
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
struct Node
{
    int lc,rc;
    int sum;
}tree[N<<5];
int rt[N],tot;
void push_up(int i)
{
    tree[i].sum=tree[tree[i].lc].sum+tree[tree[i].rc].sum;
    return;
}
void build(int &i,int l,int r)
{
    i=++tot;
    if(l==r)return;
    int mid=(l+r)/2;
    build(tree[i].lc,l,mid);
    build(tree[i].rc,mid+1,r);
    return;
}
int update(int i,int l,int r,int u)
{
    int now=++tot;
    tree[now]=tree[i];
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
int dep[N];
int fa[N][17];
void dfs(int u,int father)
{
    fa[u][0]=father;
    dep[u]=dep[father]+1;
    rt[u]=update(rt[father],1,q,a[u]);
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
int query(int u,int v,int x,int y,int l,int r,int k)
{
    if(l==r) return b[l];
    int mid=(l+r)/2;
    int sum=tree[tree[u].lc].sum+tree[tree[v].lc].sum-tree[tree[x].lc].sum-tree[tree[y].lc].sum;
    if(k<=sum) return query(tree[u].lc,tree[v].lc,tree[x].lc,tree[y].lc,l,mid,k);
    else return query(tree[u].rc,tree[v].rc,tree[x].rc,tree[y].rc,mid+1,r,k-sum);
}
int f[N],size[N];
int getf(int v)
{
    if(v==f[v]) return v;
    f[v]=getf(f[v]);
    return f[v];
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2)
    {
        if(size[f1]<size[f2]) swap(f1,f2);
        f[f2]=f1;
        size[f1]+=size[f2];
        size[f2]=0;
    }
    return;
}
int LCA(int u,int v)
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
int getkth(int u,int v,int k)
{
    int lca=LCA(u,v);
    return query(rt[u],rt[v],rt[lca],rt[fa[lca][0]],1,q,k);
}
int main()
{
    int testcase;
    scanf("%d",&testcase);
    scanf("%d%d%d",&n,&m,&T);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[++q]=a[i];
        size[i]=1;
    }
    sort(b+1,b+q+1);
    q=unique(b+1,b+q+1)-b-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+q+1,a[i])-b;
    build(rt[0],1,q);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
        merge(x,y);
    }
    for(int i=1;i<=n;i++)
        if(!rt[i]) dfs(i,0);
    int lastans=0;
    while(T--)
    {
        char ch;
        for(ch=getchar();ch!='Q'&&ch!='L';ch=getchar());
        if(ch=='Q')
        {
            int u,v,k;
            scanf("%d%d%d",&u,&v,&k);
            u^=lastans,v^=lastans,k^=lastans;
            lastans=getkth(u,v,k);
            printf("%d\n",lastans);
        }
        else if(ch=='L')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x^=lastans,y^=lastans;
            if(size[getf(x)]>size[getf(y)]) swap(x,y);
            add_edge(x,y);
            add_edge(y,x);
            merge(x,y);
            dfs(x,y);
        }
    }
    return 0;
}