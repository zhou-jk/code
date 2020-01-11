#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100001;
int n,m;
int a[N],w[N];
int b[N],q;
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
int query(int u,int v,int l,int r,int k)
{
    if(l==r) return w[l];
    int mid=(l+r)/2;
    int sum=tree[tree[v].lc].sum-tree[tree[u].lc].sum;
    if(sum>=k) return query(tree[u].lc,tree[v].lc,l,mid,k);
    else return query(tree[u].rc,tree[v].rc,mid+1,r,k-sum);
}
int dfn[N],Index;
int size[N];
void dfs(int u,int father)
{
	size[u]=1;
    dfn[u]=++Index;
    w[Index]=u;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==father) continue;
        dfs(v,u);
        size[u]+=size[v];
    }
    return;
}
int getkth(int u,int k)
{
    return query(rt[dfn[u]-1],rt[dfn[u]+size[u]-1],1,q,k);
}
int main()
{
    scanf("%d",&n);
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
    for(int i=1;i<n;i++)
	build(rt[0],1,q);
    dfs(1,0);
    scanf("%d",&m);
    while(m--)
    {
        int u,k;
        scanf("%d%d",&u,&k);
        printf("%d\n",getkth(u,k));
    }
    return 0;
}

