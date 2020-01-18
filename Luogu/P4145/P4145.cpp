#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
long long a[100001];
struct Node
{
    int l,r;
    long long sum;
    bool flag;
}tree[400001];
void push_up(int i)
{
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    tree[i].flag=tree[i*2].flag&tree[i*2+1].flag;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].sum=a[l];
        if(a[l]==1||a[l]==0) tree[i].flag=true;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
 }
void update(int i,int l,int r)
{
    if(tree[i].flag) return;
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum=(long long)sqrt(tree[i].sum);
        if(tree[i].sum==1||tree[i].sum==0) tree[i].flag=true;
        return;
    }
    int mid=(tree[i].l+tree[i].r)/2;
    if(l<=tree[i*2].r) update(i*2,l,r);
    if(r>=tree[i*2+1].l) update(i*2+1,l,r);
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(l>r) swap(l,r);
        if(op==0) update(1,l,r);
        else if(op==1) printf("%lld\n",query(1,l,r));
    }
    return 0;
}