#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int n,m;
int a[N];
struct Node
{
    int l,r;
    int sum,lazy,lazy_xor;
    int lmax0,rmax0,max0;
    int lmax1,rmax1,max1;
    Node operator +(const Node& b)const
    {
        Node res;
        res.l=l,res.r=b.r;
        res.sum=sum+b.sum;
        res.lazy=-1;
        res.lazy_xor=0;
        res.lmax0=lmax0;
        if(lmax0==r-l+1) res.lmax0+=b.lmax0;
        res.rmax0=b.rmax0;
        if(b.rmax0==b.r-b.l+1) res.rmax0+=rmax0;
        res.max0=max(rmax0+b.lmax0,max(max0,b.max0));
        res.lmax1=lmax1;
        if(lmax1==r-l+1) res.lmax1+=b.lmax1;
        res.rmax1=b.rmax1;
        if(b.rmax1==b.r-b.l+1) res.rmax1+=rmax1;
        res.max1=max(rmax1+b.lmax1,max(max1,b.max1));
        return res;        
    }
}tree[N<<2];
void push_up(int i)
{
    tree[i]=tree[i*2]+tree[i*2+1];
    return;
}

void push_down(int i)
{
    if(tree[i].lazy!=-1)
    {
        tree[i*2].sum=(tree[i*2].r-tree[i*2].l+1)*tree[i].lazy;
        tree[i*2].lazy=tree[i].lazy;
        tree[i*2].lazy_xor=0;
        tree[i*2].lmax0=tree[i*2].rmax0=tree[i*2].max0=tree[i*2].lazy?0:tree[i*2].r-tree[i*2].l+1;
        tree[i*2].lmax1=tree[i*2].rmax1=tree[i*2].max1=tree[i*2].sum;
        tree[i*2+1].sum=(tree[i*2+1].r-tree[i*2+1].l+1)*tree[i].lazy;
        tree[i*2+1].lazy=tree[i].lazy;
        tree[i*2+1].lazy_xor=0;
        tree[i*2+1].lmax0=tree[i*2+1].rmax0=tree[i*2+1].max0=tree[i*2+1].lazy?0:tree[i*2+1].r-tree[i*2+1].l+1;
        tree[i*2+1].lmax1=tree[i*2+1].rmax1=tree[i*2+1].max1=tree[i*2+1].sum;
        tree[i].lazy=-1;
    }
    if(tree[i].lazy_xor)
    {
        tree[i*2].sum=tree[i*2].r-tree[i*2].l+1-tree[i*2].sum;
        tree[i*2].lazy_xor^=1;
        swap(tree[i*2].lmax0,tree[i*2].lmax1);
        swap(tree[i*2].rmax0,tree[i*2].rmax1); 
        swap(tree[i*2].max0,tree[i*2].max1);
        tree[i*2+1].sum=tree[i*2+1].r-tree[i*2+1].l+1-tree[i*2+1].sum;
        tree[i*2+1].lazy_xor^=1;
        swap(tree[i*2+1].lmax0,tree[i*2+1].lmax1);
        swap(tree[i*2+1].rmax0,tree[i*2+1].rmax1); 
        swap(tree[i*2+1].max0,tree[i*2+1].max1);
        tree[i].lazy_xor=0;
    }
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    tree[i].lazy=-1,tree[i].lazy_xor=0;
    if(l==r)
    {
        tree[i].sum=a[l];
        tree[i].lmax0=tree[i].rmax0=tree[i].max0=tree[i].sum^1;     
        tree[i].lmax1=tree[i].rmax1=tree[i].max1=tree[i].sum;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update(int i,int l,int r,int val)
{
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].sum=(tree[i].r-tree[i].l+1)*val;
        tree[i].lazy=val;
        tree[i].lazy_xor=0;
        tree[i].lmax0=tree[i].rmax0=tree[i].max0=val?0:tree[i].r-tree[i].l+1;
        tree[i].lmax1=tree[i].rmax1=tree[i].max1=tree[i].sum;
        return;
    }
    push_down(i);
    if(l<=tree[i*2].r) update(i*2,l,r,val);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r,val);
    push_up(i);
    return;
}
void update_xor(int i,int l,int r)    
{
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].sum=tree[i].r-tree[i].l+1-tree[i].sum;
        tree[i].lazy_xor^=1;
        swap(tree[i].lmax0,tree[i].lmax1);
        swap(tree[i].rmax0,tree[i].rmax1); 
        swap(tree[i].max0,tree[i].max1);
        return;
    }
    push_down(i);
    if(l<=tree[i*2].r) update_xor(i*2,l,r);
    if(r>=tree[i*2+1].l) update_xor(i*2+1,l,r);
    push_up(i);
    return;
}
int query_sum(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
    push_down(i);
    int res=0;
    if(l<=tree[i*2].r) res+=query_sum(i*2,l,r);
    if(r>=tree[i*2+1].l) res+=query_sum(i*2+1,l,r);
    return res;
}
int query_max(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].max1;
    push_down(i);
    int mid=(tree[i].l+tree[i].r)/2;
    if(r<=tree[i*2].r) return query_max(i*2,l,r);
    else if(l>=tree[i*2+1].l) return query_max(i*2+1,l,r);
    else
    {
        int res1=max(query_max(i*2,l,r),query_max(i*2+1,l,r));
        int res2=min(tree[i*2].rmax1,mid-l+1)+min(tree[i*2+1].lmax1,r-mid-1+1);
        return max(res1,res2);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    build(1,0,n-1);
    for(int i=1;i<=m;i++)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==0) update(1,l,r,0);
        else if(op==1) update(1,l,r,1);
        else if(op==2) update_xor(1,l,r);
        else if(op==3) printf("%d\n",query_sum(1,l,r));
        else if(op==4) printf("%d\n",query_max(1,l,r));
    }
    return 0;
}