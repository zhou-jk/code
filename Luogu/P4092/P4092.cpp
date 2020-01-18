#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int dep[100001],fa[100001],size[100001];
int top[100001],son[100001];
int dfn[100001],id[100001],Index;
struct Edge
{
    int to,next;
}edge[200001];
int head[100001],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void init(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u]=father;
    size[u]=1;
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
    id[Index]=u;
    if(!son[u]) return;
    dfs(son[u],father);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs(v,v);
    }
    return;
}
struct Node
{
    int l,r;
    int sum;
}tree[400001];
void push_up(int i)
{
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    return;
}
void update(int i,int u,int val)
{
    if(u<tree[i].l||u>tree[i].r) return;
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum=val;
        return;
    }
    if(u<=tree[i*2].r) update(i*2,u,val);
    else update(i*2+1,u,val);
    push_up(i);
    return;
}
int query(int i,int l,int r)
{
    if(r<tree[i].l||l>tree[i].r) return 0;
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
    int res=0;
    if(l<=tree[i*2].r) res+=query(i*2,l,r);
    if(r>=tree[i*2+1].l) res+=query(i*2+1,l,r);
    return res;
}
int ask(int u)
{
    if(query(1,dfn[u],dfn[u])) return u;
    while(u)
    {
        int t=query(1,dfn[top[u]],dfn[u]);
        if(t==0)
        {
            u=fa[top[u]];
            continue;
        }
        else
        {
            int l=dfn[top[u]],r=dfn[u],mid,ans;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(query(1,mid,r)) ans=mid,l=mid+1;
                else r=mid-1;
            }
            return id[ans];
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    init(1,0);
    dfs(1,1);
    build(1,1,Index);
    update(1,1,1);
    while(m--)
    {
        char ch;
        int x;
        for(ch=getchar();ch!='C'&&ch!='Q';ch=getchar());
        scanf("%d",&x);
        if(ch=='C') update(1,dfn[x],1);
        else if(ch=='Q') printf("%d\n",ask(x));
    }
    return 0;
}