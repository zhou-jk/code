#include<iostream>
#include<cstdio>
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
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        long long sum,lazy;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
        return;
    }
    void push_down(int i)
    {
        if(tree[i].lazy==0) return;
        tree[i*2].lazy+=tree[i].lazy;
        tree[i*2+1].lazy+=tree[i].lazy;
        tree[i*2].sum+=tree[i].lazy*(tree[i*2].r-tree[i*2].l+1);
        tree[i*2+1].sum+=tree[i].lazy*(tree[i*2+1].r-tree[i*2+1].l+1);
        tree[i].lazy=0;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].lazy=0;
        if(l==r)
        {
            tree[i].sum=w[l];
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void update(int i,int l,int r,long long val)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            tree[i].lazy+=val;
            tree[i].sum+=(tree[i].r-tree[i].l+1)*val;
            return;
        }
        push_down(i);
        if(l<=tree[i*2].r) update(i*2,l,r,val);
        if(r>=tree[i*2+1].l) update(i*2+1,l,r,val);
        push_up(i);
        return;
    }
    long long query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        push_down(i);
        long long res=0;
        if(l<=tree[i*2].r) res+=query(i*2,l,r);
        if(r>=tree[i*2+1].l) res+=query(i*2+1,l,r);
        return res;
    }
}T;
int dfn[N],Index;
int size[N];
void dfs(int u,int father)
{
    dfn[u]=++Index;
    w[Index]=a[u];
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
    T.build(1,1,n);
    while(m--)
    {
        int op,x,y;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&x,&y);
            T.update(1,dfn[x],dfn[x]+size[x]-1,y);
        }
        else if(op==2)
        {
            scanf("%d",&x);
            printf("%lld\n",T.query(1,dfn[x],dfn[x]+size[x]-1));
        }
    }
    return 0;
}