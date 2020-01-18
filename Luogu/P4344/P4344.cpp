#include<iostream>
#include<cstdio>
using namespace std;
int T,n;
struct Node
{
    int l,r;
    int sum,len;
    int Max,lm,rm,mark;
}tree[800001];
void push_up(int i)
{
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    tree[i].len=tree[i*2].len+tree[i*2+1].len;
    tree[i].lm=(tree[i*2].len==tree[i*2].lm)?(tree[i*2].lm+tree[i*2+1].lm):tree[i*2].lm;
    tree[i].rm=(tree[i*2+1].len==tree[i*2+1].rm)?(tree[i*2+1].rm+tree[i*2].rm):tree[i*2+1].rm;
    tree[i].Max=max(tree[i*2].rm+tree[i*2+1].lm,max(tree[i*2].Max,tree[i*2+1].Max));
}
void push_down(int i)
{
    if(tree[i].mark==-1) return;
    tree[i*2].mark=tree[i*2+1].mark=tree[i].mark;
    tree[i*2].sum=tree[i*2].len*tree[i].mark;
    tree[i*2+1].sum=tree[i*2+1].len*tree[i].mark;
    tree[i*2].lm=tree[i*2].rm=tree[i*2].Max=tree[i*2].len*(tree[i].mark^1);
    tree[i*2+1].lm=tree[i*2+1].rm=tree[i*2+1].Max=tree[i*2+1].len*(tree[i].mark^1);
    tree[i].mark=-1;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r,tree[i].mark=-1;
    if(l==r)
    {
        tree[i].sum=tree[i].len=1;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update_zero(int i,int l,int r,int v)
{
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].mark=v;
        tree[i].sum=tree[i].len*v;
        tree[i].lm=tree[i].rm=tree[i].Max=tree[i].len*(v^1);
        return;
    } 
    push_down(i);
    if(l<=tree[i*2].r) update_zero(i*2,l,r,v);
    if(r>=tree[i*2+1].l) update_zero(i*2+1,l,r,v);
    push_up(i);
    return;
}
int num=0;
void update_one(int i,int l,int r,int v)
{
    if(tree[i].sum==tree[i].len) return;
    if(num==0)return;
    if(l<=tree[i].l&&tree[i].r<=r)
        if(tree[i].len-tree[i].sum<=num)
        {
            num-=(tree[i].len-tree[i].sum);
            tree[i].mark=1;
            tree[i].sum=tree[i].len;
            tree[i].Max=tree[i].lm=tree[i].rm=0;
            return;
        }
    if(tree[i].l==tree[i].r) return;
    push_down(i);
    if(l<=tree[i*2].r) update_one(i*2,l,r,v);
    if(r>=tree[i*2+1].l) update_one(i*2+1,l,r,v);
    push_up(i);
    return;
}
int query_one(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
    push_down(i);
    int res=0;
    if(l<=tree[i*2].r) res+=query_one(i*2,l,r);
    if(r>=tree[i*2+1].l) res+=query_one(i*2+1,l,r);
    return res;
}
int query_max(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Max;
    push_down(i);
    int mid=(tree[i].l+tree[i].r)/2;
    if(r<=tree[i*2].r) return query_max(i*2,l,r);
    else if(l>=tree[i*2+1].l) return query_max(i*2+1,l,r);
    else return max(max(query_max(i*2,l,r),query_max(i*2+1,l,r)),min(mid-l+1,tree[i*2].rm)+min(r-mid,tree[i*2+1].lm));
}
int main()
{
    scanf("%d%d",&n,&T);
    build(1,1,n);
    while(T--)
    {
        int op,l,r;
        scanf("%d",&op);
        if(op==0)
        {
            scanf("%d%d",&l,&r);
            update_zero(1,l,r,0);
        }
        else if(op==1)
        {
            int l1,r1,l2,r2;
            scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
            num=query_one(1,l1,r1);
            update_zero(1,l1,r1,0);
            update_one(1,l2,r2,1);    
        }
        else if(op==2)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",query_max(1,l,r));
        }
    }
    return 0;
}