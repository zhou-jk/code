#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=998244353;
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
int n,m;
long long Pw[N];
int Index;
struct tree
{
    int l,r;
    long long f,g,sum;
    long long mulg,mulf;
}tree[N<<3];
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    tree[i].g=1;
    tree[i].mulf=tree[i].mulg=1;
    if(l==r) return;
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    return;
}
void push_up(int i)
{
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum+tree[i].f)%MOD;
    return;
}
void addf(int i,long long val)
{
    tree[i].mulf=tree[i].mulf*val%MOD;
    tree[i].f=tree[i].f*val%MOD;
    tree[i].sum=tree[i].sum*val%MOD;
    return;
}
void addg(int i,long long val)
{
    tree[i].g=tree[i].g*val%MOD;
    tree[i].mulg=tree[i].mulg*val%MOD;
    return;
}
void push_down(int i)
{
    if(tree[i].mulf!=1)
    {
        addf(i*2,tree[i].mulf);
        addf(i*2+1,tree[i].mulf);
        tree[i].mulf=1;
    }
    if(tree[i].mulg!=1)
    {
        addg(i*2,tree[i].mulg);
        addg(i*2+1,tree[i].mulg);
        tree[i].mulg=1;
    }
    return;
}
void update(int i,int l,int r)
{
    if(tree[i].l!=tree[i].r) push_down(i);
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].f=(tree[i].f+Pw[Index])%MOD;
        addf(i*2,2),addf(i*2+1,2);
        push_up(i);
        return;
    }
    if(tree[i].l>r||tree[i].r<l)
    {
        tree[i].f=(tree[i].f+(Pw[Index]-tree[i].g+MOD)%MOD)%MOD;
        tree[i].g=(tree[i].g*2)%MOD;
        addg(i*2,2),addg(i*2+1,2);
        addf(i*2,2),addf(i*2+1,2);
        push_up(i);
        return;
    }
    tree[i].g=(tree[i].g+Pw[Index])%MOD;
    update(i*2,l,r);
    update(i*2+1,l,r);
    push_up(i);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    Pw[0]=1;
    for(int i=1;i<=m;i++)
        Pw[i]=Pw[i-1]*2%MOD;
    build(1,1,n);
    while(m--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            update(1,l,r);
            Index++;
        }
        else printf("%lld\n",tree[1].sum);
    }
    return 0;
}