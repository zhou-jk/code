#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100001;
const long long INF=4557430888798830399;
int n,m;
long long a[N];
struct SegmentTree
{
    int l,r;
    long long Max[2],tag[2],st[2];
}tree[N<<3];
void pushup(int i)
{
    tree[i].Max[0]=max(tree[i*2].Max[0],tree[i*2+1].Max[0]);
    tree[i].Max[1]=max(tree[i*2].Max[1],tree[i*2+1].Max[1]);
    return;
}
void push_down(int i)
{
    int son;
    for(int k=0;k<=1;k++)
    {
        son=i*2|k;
        tree[son].Max[0]=max(tree[son].Max[0],max(tree[i].st[0],tree[son].Max[1]+tree[i].tag[0]));
        if(tree[son].st[1]==-INF) tree[son].tag[0]=max(tree[son].tag[0],tree[son].tag[1]+tree[i].tag[0]);
        else tree[son].st[0]=max(tree[son].st[0],tree[son].st[1]+tree[i].tag[0]);
        if(tree[i].tag[1])
        {
            if(tree[son].st[1]!=-INF) tree[son].st[1]+=tree[i].tag[1];
            else tree[son].tag[1]+=tree[i].tag[1];
            tree[son].Max[1]+=tree[i].tag[1];
        }
        if(tree[i].st[1]!=-INF)
        {
            tree[son].st[1]=tree[son].Max[1]=tree[i].st[1];
            tree[son].tag[1]=0;
        }
        tree[son].st[0]=max(tree[son].st[0],max(tree[son].st[1],tree[i].st[0]));
        tree[son].tag[0]=max(tree[son].tag[0],tree[son].tag[1]);
    }
    tree[i].tag[0]=tree[i].tag[1]=0;
    tree[i].st[0]=tree[i].st[1]=-INF;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    tree[i].tag[0]=tree[i].tag[1]=0;
    tree[i].st[0]=tree[i].st[1]=-INF;
    if(l==r)
    {
        tree[i].Max[0]=tree[i].Max[1]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    pushup(i);
    return;
}
void update(int i,int l,int r,long long u,int op)
{
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        if(op==0) tree[i].Max[1]+=u,tree[i].tag[1]+=u,tree[i].tag[0]=u;
        else tree[i].st[1]=tree[i].st[0]=tree[i].Max[1]=u;
        tree[i].Max[0]=max(tree[i].Max[0],tree[i].Max[1]);
        return;
    }
    push_down(i);
    if(l<=tree[i*2].r) update(i*2,l,r,u,op);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r,u,op);
    pushup(i);
    return;
}
long long Querymax(int i,int l,int r,int op)
{
    if(tree[i].l!=tree[i].r)push_down(i);
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        return tree[i].Max[op];
    }
    long long ans=-INF;
    int mid=(tree[i].l+tree[i].r)>>1;
    if(l<=mid)ans=max(ans,Querymax(i*2,l,r,op));
    if(r>mid)ans=max(ans,Querymax(i*2+1,l,r,op));
    return ans;
}
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    scanf("%d",&m);
    while(m--)
    {
        char ch;
        for(ch=getchar();ch<'A'||ch>'Z';ch=getchar());
        int l,r,x;
        scanf("%d%d",&l,&r);
        if(ch=='Q') printf("%lld\n",Querymax(1,l,r,1));
        if(ch=='A') printf("%lld\n",Querymax(1,l,r,0));
        if(ch=='P')
        {
            scanf("%d",&x);
            update(1,l,r,x,0);
        }
        if(ch=='C')
        {
            scanf("%d",&x);
            update(1,l,r,x,1);
        }
    }
    return 0;
} 