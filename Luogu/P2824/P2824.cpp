#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
int a[100001];
int ans;
struct Seg
{
    int op,x,val;
}ask[100001];
struct Node
{
    int l,r,v,sum,lazy;
}tree[400001];
void push_up(int i)
{
    if(tree[i].lazy!=-1) tree[i].sum=tree[i].lazy*(tree[i].r-tree[i].l+1);
    else tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}
void push_down(int i)
{
    if(tree[i].lazy==-1) return;
    tree[i*2].v=tree[i*2+1].v=tree[i*2].lazy=tree[i*2+1].lazy=tree[i].lazy;
    tree[i*2].sum=tree[i].lazy*(tree[i*2].r-tree[i*2].l+1);
    tree[i*2+1].sum=tree[i].lazy*(tree[i*2+1].r-tree[i*2+1].l+1);
    tree[i].lazy=-1;
    return;
}
void build(int i,int l,int r,int x)
{
    tree[i].l=l,tree[i].r=r,tree[i].lazy=-1;
    if(l==r)
    {
        tree[i].v=tree[i].sum=a[l]>=x;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid,x);
    build(i*2+1,mid+1,r,x);
    push_up(i);
    return;
}
void update(int i,int l,int r,int x)
{
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].v=x;
        tree[i].sum=x*(tree[i].r-tree[i].l+1);
        tree[i].lazy=x;
        return;
    }
    push_down(i);
    if(l<=tree[i*2].r) update(i*2,l,r,x);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r,x);
    push_up(i);
    return;
}
int query(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
    push_down(i);
    int res=0;
    if(l<=tree[i*2].r) res+=query(i*2,l,r);
    if(r>=tree[i*2+1].l) res+=query(i*2+1,l,r);
    return res;
}
bool check(int x)
{
    build(1,1,n,x);
    for(int i=1;i<=m;i++)
    {
        int val=query(1,ask[i].x,ask[i].val);
        if(val==0||val==ask[i].val-ask[i].x+1) continue;
        if(ask[i].op==1) update(1,ask[i].x,ask[i].x+val-1,1),update(1,ask[i].x+val,ask[i].val,0);
        else update(1,ask[i].x,ask[i].val-val,0),update(1,ask[i].val-val+1,ask[i].val,1);
    }
    return query(1,k,k);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&ask[i].op,&ask[i].x,&ask[i].val);
    scanf("%d",&k);
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}