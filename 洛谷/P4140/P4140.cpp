#include<iostream>
#include<cstdio>
using namespace std;
const int N=100000;
int n;
const long long MOD=19961993;
const int prime[61]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281};
long long inv[61];
struct Node
{
    int l,r;
    long long sum,status;
    Node operator + (const Node &b) const
    {
        return (Node){min(l,b.l),max(r,b.r),sum*b.sum%MOD,status|b.status};
    }
}tree[N<<2|1];
void push_up(int i)
{
    tree[i]=tree[i*2]+tree[i*2+1];
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].sum=3,tree[i].status=1<<1;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void update(int i,int u,long long v)
{
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum=v,tree[i].status=0;
        for(int j=1;j<=60;j++)
            if(v%prime[j]==0) tree[i].status|=(1ll<<(j-1));
        return ;
    }
    if(u<=tree[i*2].r) update(i*2,u,v);
    else update(i*2+1,u,v);
    push_up(i);
    return;
}
Node query(int i,int l,int r)
{
    if(l<=tree[i].l&&tree[i].r<=r) return tree[i];
    if(r<=tree[i*2].r) return query(i*2,l,r);
    else if(l>=tree[i*2+1].l) return query(i*2+1,l,r);
    else return query(i*2,l,r)+query(i*2+1,l,r);
}
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=60;i++)
        inv[i]=ksm(prime[i],MOD-2);
    build(1,1,N);
    while(n--)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(!op)
        {
            Node res=query(1,x,y);
            for(int i=1;i<=60;i++)
                if((res.status>>(i-1))&1) res.sum=res.sum*inv[i]%MOD*(prime[i]-1)%MOD;
            printf("%lld\n",res.sum);
        }
        else update(1,x,y);
    }
    return 0;
}