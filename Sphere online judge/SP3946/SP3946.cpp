#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100001;
int n,m;
int a[N];
int b[N],q;
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
    if(l==r) return b[l];
    int mid=(l+r)/2;
    if(k<=tree[tree[v].lc].sum-tree[tree[u].lc].sum) return query(tree[u].lc,tree[v].lc,l,mid,k);
    else return query(tree[u].rc,tree[v].rc,mid+1,r,k-(tree[tree[v].lc].sum-tree[tree[u].lc].sum));
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    q=unique(b+1,b+n+1)-b-1;
    build(rt[0],1,q);
    for(int i=1;i<=n;i++)
    {
        int u=lower_bound(b+1,b+q+1,a[i])-b;
        rt[i]=update(rt[i-1],1,q,u);
    }
    while(m--)
    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",query(rt[l-1],rt[r],1,q,k));
    }
    return 0;
}