#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
struct Node
{
    int l,r;
    long long sum;
}tree[N<<2];
int T,q,MOD;
void push_up(int i)
{
    tree[i].sum=(tree[i*2].sum*tree[i*2+1].sum)%MOD;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].sum=1;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update(int i,int u,int val)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum=val;
        return;
    }
    if(u<=tree[i*2].r) update(i*2,u,val);
    else update(i*2+1,u,val);
    push_up(i);
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&q,&MOD);
        build(1,1,q);
        for(int i=1;i<=q;i++)
        {
            int op,x;
            scanf("%d%d",&op,&x);
            if(op==1) update(1,i,x),printf("%lld\n",tree[1].sum%MOD);
            else update(1,x,1),printf("%lld\n",tree[1].sum%MOD);
        }
    }
    return 0;
}