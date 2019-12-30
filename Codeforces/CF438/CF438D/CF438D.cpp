#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n,m;
int a[N];
struct Node
{
    int l,r;
    int Max;
    long long sum;
}tree[N<<2];
void push_up(int i)
{
    tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].Max=tree[i].sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void modify(int i,int l,int r,int mod)
{
    if(tree[i].Max<mod) return;
    if(tree[i].l==tree[i].r)
    {
        tree[i].Max%=mod,tree[i].sum%=mod;
        return;
    }
    if(l<=tree[i*2].r) modify(i*2,l,r,mod);
    if(r>=tree[i*2+1].l) modify(i*2+1,l,r,mod);
    push_up(i);
    return;
}
void update(int i,int u,int val)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].Max=tree[i].sum=val;
        return;
    }
    if(u<=tree[i*2].r) update(i*2,u,val);
    else update(i*2+1,u,val);
    push_up(i);
    return;
}
long long query(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
    long long res=0;
    if(l<=tree[i*2].r) res+=query(i*2,l,r);
    if(r>=tree[i*2+1].l) res+=query(i*2+1,l,r);
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1) printf("%lld\n",query(1,l,r));
        else if(op==2)
        {
            int val;
            scanf("%d",&val);
            modify(1,l,r,val);
        }
        else if(op==3) update(1,l,r); 
    }
    return 0;
}