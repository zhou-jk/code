#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,q;
int x[N],d[N],l[N];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        long long sum,mx,tag;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
        tree[i].mx=max(tree[i*2].mx,tree[i*2+1].mx);
        return;
    }
    void add(int i,long long v)
    {
        tree[i].sum+=v;
        tree[i].mx+=v;
        tree[i].tag+=v;
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].tag) return;
        add(i*2,tree[i].tag);
        add(i*2+1,tree[i].tag);
        tree[i].tag=0;
        return;
    }
    void build(int i,int l,int r,int f)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].sum=tree[i].mx=l*f;
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid,f);
        build(i*2+1,mid+1,r,f);
        push_up(i);
        return;
    }
    void modify(int i,int l,int r,int v)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[i*2].r) modify(i*2,l,r,v);
        if(r>=tree[i*2+1].l) modify(i*2+1,l,r,v);
        push_up(i);
        return;
    }
    long long query(int i,int u)
    {
        if(tree[i].l==tree[i].r) return tree[i].sum;
        push_down(i);
        if(u<=tree[i*2].r) return query(i*2,u);
        else return query(i*2+1,u);
    }
    int higher_bound(int i,int v)
    {
        if(tree[i].mx<v) return tree[i].l-1;
        if(tree[i].l==tree[i].r) return tree[i].l;
        push_down(i);
        if(tree[i*2+1].mx<v) return higher_bound(i*2,v);
        else return higher_bound(i*2+1,v);
    }
    int upper_bound(int i,int v)
    {
        if(tree[i].mx<=v) return tree[i].r+1;
        if(tree[i].l==tree[i].r) return tree[i].r;
        push_down(i);
        if(tree[i*2].mx<=v) return upper_bound(i*2+1,v);
        else return upper_bound(i*2,v);
    }
}Tx,Ty;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++)
        scanf("%d%d%d",&x[i],&d[i],&l[i]);
    Tx.build(1,1,n,1);
    Ty.build(1,1,n,-1);
    for(int i=q;i>=1;i--)
        if(d[i]==1)
        {
            int p=Ty.higher_bound(1,-x[i]);
            if(p>=1) Tx.modify(1,1,p,-l[i]*2);
        }
        else if(d[i]==2)
        {
            int p=Tx.upper_bound(1,x[i]);
            if(p<=n) Ty.modify(1,p,n,-l[i]*2);
        }
    for(int i=1;i<=n;i++)
        printf("%lld\n",-(Tx.query(1,i)+Ty.query(1,i))/2);
    return 0;
}