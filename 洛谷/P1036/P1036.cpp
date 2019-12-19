#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1061109567;
int n,m;
struct Edge
{
    int to,next;
}edge[60001];
int head[30001],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int son[30001],f[30001],top[30001],size[30001],dfn[30001],dep[30001],Index;
int a[30001],w[30001];
void init(int u,int father)
{
    dep[u]=dep[father]+1;
    f[u]=father;
    size[u]=1;
    son[u]=0;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        init(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
    }
    return;
}
void dfs(int u,int father)
{
    dfn[u]=++Index;
    top[u]=father;
    w[Index]=a[u];
    if(!son[u]) return;
    dfs(son[u],father);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==son[u]||v==f[u]) continue;
        dfs(v,v);
    }
    return;
}
struct Node
{
    int l,r;
    int Max,sum;
}tree[120001];
void push_up(int i)
{
    tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].Max=tree[i].sum=w[l];
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update(int i,int u,int k)
{
    if(u<tree[i].l||u>tree[i].r) return;
    if(tree[i].l==tree[i].r)
    {
        tree[i].Max=tree[i].sum=k;
        return;
    }
    if(u<=tree[i*2].r) update(i*2,u,k);
    else update(i*2+1,u,k);
    push_up(i);
    return;
}
int querymax(int i,int l,int r)
{
    if(r<tree[i].l||l>tree[i].r) return 0;
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Max;
    int ans=-INF;
    if(l<=tree[i*2].r) ans=max(ans,querymax(i*2,l,r));
    if(r>=tree[i*2+1].l) ans=max(ans,querymax(i*2+1,l,r));
    return ans;
}
int querysum(int i,int l,int r)
{
    if(r<tree[i].l||l>tree[i].r) return 0;
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
    int ans=0;
    if(l<=tree[i*2].r) ans+=querysum(i*2,l,r);
    if(r>=tree[i*2+1].l) ans+=querysum(i*2+1,l,r);
    return ans;
}
void add(int x,int k)
{
    update(1,dfn[x],k);
    return;
}
int getmax(int x,int y)
{
    int ans=-INF;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=max(ans,querymax(1,dfn[top[x]],dfn[x]));
        x=f[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans=max(ans,querymax(1,dfn[x],dfn[y]));
    return ans;
}
int getsum(int x,int y)
{
    int ans=0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans+=querysum(1,dfn[top[x]],dfn[x]);
        x=f[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans+=querysum(1,dfn[x],dfn[y]);
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    init(1,0);
    dfs(1,1);
    build(1,1,Index);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        char s[10];
        int x,y;
        scanf("%s",s);
        scanf("%d%d",&x,&y);
        if(s[0]=='C') add(x,y);
        else if(s[1]=='M') printf("%d\n",getmax(x,y));
        else if(s[1]=='S') printf("%d\n",getsum(x,y));
    }
    return 0;
}
