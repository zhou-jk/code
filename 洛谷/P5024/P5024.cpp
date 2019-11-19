#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long INF=4557430888798830399;
const int N=100001;
int n,m;
int a[N];
char type[2];
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
int fa[N],top[N],ed[N],size[N],son[N],dfn[N],w[N],Index;
long long f[N][2],g[N][2];
struct Matrix
{
    long long a[3][3];
    Matrix()
    {
        memset(a,63,sizeof(a));
        return;
    }
    Matrix(long long x,long long y)
    {
        a[1][1]=INF;
        a[1][2]=x;
        a[2][1]=y;
        a[2][2]=y;
        return;
    }
    Matrix operator *(const Matrix &b) const
    {
        Matrix res;
        for(int i=1;i<=2;i++)
            for(int j=1;j<=2;j++)
                for(int k=1;k<=2;k++)
                    res.a[i][j]=min(res.a[i][j],a[i][k]+b.a[k][j]);
        return res;
    }
};
struct Segment_Tree
{
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
            tree[i].sum=Matrix(g[w[l]][0],g[w[l]][1]);
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,Matrix v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].sum=v;
            return;
        }
        if(u<=tree[i*2].r) modify(i*2,u,v);
        else modify(i*2+1,u,v);
        push_up(i);
        return;
    }
    Matrix query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        if(r<=tree[i*2].r) return query(i*2,l,r);
        else if(l>=tree[i*2+1].l) return query(i*2+1,l,r);
        return query(i*2,l,r)*query(i*2+1,l,r);
    }
}T;
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
void dfs(int u)
{
    f[u][1]=a[u];
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa[u]) continue;
        dfs(v);
        f[u][0]+=f[v][1];
        f[u][1]+=min(f[v][0],f[v][1]);
    }
    return;
}
void dfs2(int u,int father)
{
    top[u]=father;
    dfn[u]=++Index;
    w[Index]=u;
    g[u][1]=a[u];
    if(!son[u])
    {
        ed[father]=Index;
        return;
    }
    dfs2(son[u],father);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==son[u]||v==fa[u]) continue;
        dfs2(v,v);
        g[u][0]+=f[v][1];
        g[u][1]+=min(f[v][1],f[v][0]);
    }
    return;
}
long long update(int u)
{
    T.modify(1,dfn[u],Matrix(g[u][0],g[u][1]));
    u=top[u];
    while(u>1)
    {
        Matrix res=T.query(1,dfn[u],ed[u]);
        g[fa[u]][0]-=f[u][1];
        g[fa[u]][1]-=min(f[u][0],f[u][1]);
        f[u][0]=res.a[1][2],f[u][1]=res.a[2][2];
        g[fa[u]][0]+=f[u][1];
        g[fa[u]][1]+=min(f[u][0],f[u][1]);
        T.modify(1,dfn[fa[u]],Matrix(g[fa[u]][0],g[fa[u]][1]));
        u=top[fa[u]];
    }
    Matrix ans=T.query(1,1,ed[1]);
    return min(ans.a[1][2],ans.a[2][2]);
}
int main()
{
    scanf("%d%d%s",&n,&m,type);
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
    dfs(1);
    dfs2(1,1);
    T.build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int a,x,b,y;
        scanf("%d%d%d%d",&a,&x,&b,&y);
        x^=1,y^=1;
        long long tmp1=g[a][x],tmp2=g[b][y];
        g[a][x]=INF;
        update(a);
        g[b][y]=INF;
        update(b);
        Matrix res=T.query(1,1,ed[1]);
        long long ans=min(res.a[1][2],res.a[2][2]);
        if(ans>=INF) printf("-1\n");
        else printf("%lld\n",ans);
        g[a][x]=tmp1;
        update(a);
        g[b][y]=tmp2;
        update(b);
    }
    return 0;
}