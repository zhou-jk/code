#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1061109567;
const int N=1000001;
int n,m;
int a[N];
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
    head[u]=cnt++;
    return;
}
int dfn[N],size[N],son[N],top[N],down[N],fa[N],id[N],Index;
void dfs1(int u,int father)
{
    fa[u]=father;
    size[u]=1;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs1(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
    }
    return;
}
void dfs2(int u,int father)
{
    dfn[u]=++Index;
    top[u]=father;
    id[Index]=u;
    if(!son[u])
    {
        down[u]=u;
        return;
    }
    dfs2(son[u],father);
    down[u]=down[son[u]];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
    return;
}
long long f[N][2];
void dfs(int u,int father)
{
    f[u][1]=a[u];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
        f[u][0]+=max(f[v][0],f[v][1]);
        f[u][1]+=f[v][0];
    }
    return;
}
struct Matrix
{
    long long C[2][2];
    Matrix operator=(const int &u)
    {
        int g0=0,g1=a[u];
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(v==fa[u]||v==son[u]) continue;
            g0+=max(f[v][0],f[v][1]),g1+=f[v][0];
        }
        C[0][0]=g0,C[0][1]=g0,C[1][0]=g1,C[1][1]=-INF;
        return *this;
    }
    Matrix operator*(const Matrix &b)const
    {
        Matrix res;
        res.C[0][0]=max(C[0][0]+b.C[0][0],C[0][1]+b.C[1][0]);
        res.C[0][1]=max(C[0][0]+b.C[0][1],C[0][1]+b.C[1][1]);
        res.C[1][0]=max(C[1][0]+b.C[0][0],C[1][1]+b.C[1][0]);
        res.C[1][1]=max(C[1][0]+b.C[0][1],C[1][1]+b.C[1][1]);
        return res;
    }
}t[N];
struct Node
{
    int l,r;
    Matrix sum;
}tree[N<<2];
void push_up(int i)
{
    tree[i].sum=tree[i*2].sum*tree[i*2+1].sum;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        t[l]=tree[i].sum=id[l];
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update(int i,int u)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum=t[u];
        return;
    }
    if(u<=tree[i*2].r) update(i*2,u);
    else update(i*2+1,u);
    push_up(i);
    return;
}
Matrix query(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
    if(r<=tree[i*2].r) return query(i*2,l,r);
    else if(l>=tree[i*2+1].l) return query(i*2+1,l,r);
    else return query(i*2,l,r)*query(i*2+1,l,r);
}
void modify(int u,int w)
{
    t[dfn[u]].C[1][0]+=w-a[u];
    a[u]=w;
    while(u)
    {
        Matrix f=query(1,dfn[top[u]],dfn[down[u]]);
        update(1,dfn[u]);
        Matrix g=query(1,dfn[top[u]],dfn[down[u]]);
        u=fa[top[u]];
        if(!u) break;
        t[dfn[u]].C[0][0]+=max(g.C[0][0],g.C[1][0])-max(f.C[0][0],f.C[1][0]);
        t[dfn[u]].C[0][1]=t[dfn[u]].C[0][0];
        t[dfn[u]].C[1][0]+=g.C[0][0]-f.C[0][0];
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs1(1,0);
    dfs2(1,1);
    dfs(1,0);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int u,w;
        scanf("%d%d",&u,&w);
        modify(u,w);
        Matrix ans=query(1,dfn[top[1]],dfn[down[1]]);
        printf("%lld\n",max(ans.C[0][0],ans.C[1][0]));
    }
    return 0;
}