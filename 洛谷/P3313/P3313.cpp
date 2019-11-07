#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int Index;
int C[100001],W[100001];
int dep[100001],size[100001],fa[100001],son[100001],dfn[100001],top[100001],a[100001];
struct Node
{
    int ls,rs;
    int sum,Max;
}tree[3000001];
int root[100001],tot;
struct Edge
{
    int next,to;
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
    fa[u]=father;
    dep[u]=dep[father]+1;
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
    top[u]=father;
    dfn[u]=++Index;
    a[Index]=u;
    if(son[u]) dfs(son[u],father);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs(v,v);
    }
    return;
}
void push_up(int i)
{
    tree[i].sum=tree[tree[i].ls].sum+tree[tree[i].rs].sum;
    tree[i].Max=max(tree[tree[i].ls].Max,tree[tree[i].rs].Max);
    return;
}
void update(int &i,int l,int r,int u,int sum)
{
    if(!i) i=++tot;
    if(l==r)
    {
        tree[i].sum=sum,tree[i].Max=sum;
        return ;
    }
    int mid=(l+r)/2;
    if(u<=mid) update(tree[i].ls,l,mid,u,sum);
    else update(tree[i].rs,mid+1,r,u,sum);
    push_up(i);
    if(!tree[i].sum) i=0;
    return;
}
int querysum(int i,int l,int r,int L,int R)
{
    if(!i) return 0;
    if(L<=l&&r<=R) return tree[i].sum;
    int mid=(l+r)/2,res=0;
    if(L<=mid) res+=querysum(tree[i].ls,l,mid,L,R);
    if(R>mid) res+=querysum(tree[i].rs,mid+1,r,L,R);
    return res;
}
int querymax(int i,int l,int r,int L,int R)
{
    if(!i) return 0;
    if(L<=l&&r<=R) return tree[i].Max;
    int mid=(l+r)/2;
    int res=0;
    if(L<=mid) res=max(res,querymax(tree[i].ls,l,mid,L,R));
    if(R>mid) res=max(res,querymax(tree[i].rs,mid+1,r,L,R));
    return res;
}
void changereli(int u,int v)
{
    update(root[v],1,n,dfn[u],W[u]);
    update(root[C[u]],1,n,dfn[u],0);
    C[u]=v;
    return;
}
void changesum(int u,int v)
{
    update(root[C[u]],1,n,dfn[u],v);
    W[u]=v;
    return;
}
int getmax(int x,int y)
{
    int ans=0,Root=root[C[x]];
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<=dep[top[y]]) swap(x,y);
        ans=max(ans,querymax(Root,1,n,dfn[top[x]],dfn[x]));
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans=max(ans,querymax(Root,1,n,dfn[x],dfn[y]));
    return ans;
}
int getsum(int x,int y)
{
    int ans=0,Root=root[C[x]];
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<=dep[top[y]]) swap(x,y);
        ans+=querysum(Root,1,n,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans+=querysum(Root,1,n,dfn[x],dfn[y]);
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&W[i],&C[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    init(1,0);
    dfs(1,1);
    for(int i=1;i<=n;i++)
        update(root[C[a[i]]],1,n,i,W[a[i]]);
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        int u,v;
        scanf("%d%d",&u,&v);
        if(s=="CC") changereli(u,v);
        else if(s=="CW") changesum(u,v);
        else if(s=="QS") printf("%d\n",getsum(u,v));
        else if(s=="QM") printf("%d\n",getmax(u,v));
    }
    return 0;
}