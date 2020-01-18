#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000001;
int n,m;
int a[N];
struct Node
{
    int lc,rc;
    int sum;
}tree[N<<5];
int rt[N],tot;
void build(int &i,int l,int r)
{
    i=++tot;
    if(l==r)
    {
        tree[i].sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(tree[i].lc,l,mid);
    build(tree[i].rc,mid+1,r);
    return;
}
int update(int i,int l,int r,int u,int val)
{
    int now=++tot;
    tree[now]=tree[i];
    if(l==r)
    {
        tree[now].sum=val;
        return now;
    }
    int mid=(l+r)/2;
    if(u<=mid) tree[now].lc=update(tree[i].lc,l,mid,u,val);
    else tree[now].rc=update(tree[i].rc,mid+1,r,u,val);
    return now;
}
int query(int i,int l,int r,int u)
{
    if(l==r) return tree[i].sum;
    int mid=(l+r)/2;
    if(u<=mid) return query(tree[i].lc,l,mid,u);
    else return query(tree[i].rc,mid+1,r,u);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(rt[0],1,n);
    for(int i=1;i<=m;i++)
    {
        int op,v,loc,value;
        scanf("%d%d%d",&v,&op,&loc);
        if(op==1)
        {
            scanf("%d",&value);
            rt[i]=update(rt[v],1,n,loc,value);
        }
        else if(op==2)
        {
            printf("%d\n",query(rt[v],1,n,loc));
            rt[i]=rt[v];
        }
    }
}