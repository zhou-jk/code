#include<iostream>
#include<cstdio>
using namespace std;
const int M=10;
const long long INF=4557430888798830399;
int n,q;
long long a[100001];
long long power[M+1];
struct Node
{
    int l,r;
    long long Max;
    long long add,change;
    bool same;
    int lev;
    long long val;
    long long get()
    {
        return power[lev+1]+val;
    }
    Node operator =(const long long &b)
    {
        int p=lower_bound(power,power+M+1,b)-power-1;
        lev=p,val=b-power[p+1];
        return *this;
    }
}tree[400001];
void push_up(int i)
{
    tree[i].Max=max(tree[i*2].Max,tree[i*2+1].Max);
    if(tree[i*2].same&&tree[i*2+1].same&&tree[i*2].val==tree[i*2+1].val&&tree[i*2].lev==tree[i*2+1].lev)
    {
        tree[i].same=true;
        tree[i].val=tree[i*2].val;
        tree[i].lev=tree[i*2].lev;
    }
    else tree[i].same=false;
    return;
}
void build(int i,int l,int r)
{
    tree[i].l=l,tree[i].r=r;
    tree[i].add=0,tree[i].change=-INF;
    if(l==r)
    {
        tree[i].same=true;
        tree[i]=a[l];
        tree[i].Max=tree[i].val;
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void push_down(int i)
{
    if(tree[i].change!=-INF)
    {
        long long c=tree[i].change;
        tree[i*2].same=true;
        tree[i*2+1].same=true;
        tree[i*2]=c;
        tree[i*2].add=0;
        tree[i*2].change=c;
        tree[i*2].Max=tree[i*2].val;
        tree[i*2+1]=c;
        tree[i*2+1].add=0;
        tree[i*2+1].change=c;
        tree[i*2+1].Max=tree[i*2+1].val;
        tree[i].add=0;
        tree[i].change=-INF;
    }
    else if(tree[i].add)
    {
        if(tree[i*2].same)
        {
            if(tree[i*2].change!=-INF) tree[i*2].change+=tree[i].add;
            else tree[i*2].add+=tree[i].add;
            tree[i*2].val+=tree[i].add;
            tree[i*2]=tree[i*2].get();
            tree[i*2].Max=tree[i*2].val;
        }
        else
        {
            tree[i*2].Max+=tree[i].add;
            tree[i*2].add+=tree[i].add;
        }
        if(tree[i*2+1].same)
        {
            if(tree[i*2+1].change!=-INF) tree[i*2+1].change+=tree[i].add;
            else tree[i*2+1].add+=tree[i].add;
            tree[i*2+1].val+=tree[i].add;
            tree[i*2+1]=tree[i*2+1].get();
            tree[i*2+1].Max=tree[i*2+1].val;
        }
        else
        {
            tree[i*2+1].Max+=tree[i].add;
            tree[i*2+1].add+=tree[i].add;
        }
        tree[i].add=0;
        tree[i].change=-INF;
    }
    return;
}
bool getsum(int i)
{
    if(tree[i].l==tree[i].r) return tree[i].val==0;
    else if(tree[i].same) return tree[i].val==0;
    push_down(i);
    bool res=false;
    if(tree[i*2].Max>=0) res|=getsum(i*2);
    if(tree[i*2+1].Max>=0) res|=getsum(i*2+1);
    push_up(i);
    return res; 
}
bool flag;
void add(int i,int l,int r,long long v)
{
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        if(tree[i].same)
        {
            if(tree[i].change!=-INF) tree[i].change+=v;
            else tree[i].add+=v;
            tree[i].val+=v;
            tree[i]=tree[i].get();
            tree[i].Max=tree[i].val;
            if(tree[i].Max==0) flag=true;
        }
        else
        {
            tree[i].Max+=v;
            tree[i].add+=v;
            if(tree[i].Max>=0) flag|=getsum(i);
        }
        return;
    }
    push_down(i);
    if(l<=tree[i*2].r) add(i*2,l,r,v);
    if(r>=tree[i*2+1].l) add(i*2+1,l,r,v);
    push_up(i);
    return;
}
void update(int i,int l,int r,long long v)
{
    if(l<=tree[i].l&&tree[i].r<=r)
    {
        tree[i].same=true;
        tree[i]=v;
        tree[i].add=0;
        tree[i].change=v;
        tree[i].Max=tree[i].val;
        return;
    }
    push_down(i);
    if(l<=tree[i*2].r) update(i*2,l,r,v);
    if(tree[i*2+1].l<=r) update(i*2+1,l,r,v);
    push_up(i);
    return;
}
long long query(int i,int u)
{
    if(tree[i].l==tree[i].r) return tree[i].get();
    push_down(i);
    if(u<=tree[i*2].r) return query(i*2,u);
    else return query(i*2+1,u);
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    power[0]=1;
    for(int i=1;i<=M;i++)
        power[i]=power[i-1]*42;
    build(1,1,n);
    while(q--)
    {
        int op,l,r,p;
        long long c;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&p);
            printf("%lld\n",query(1,p));
        }
        else if(op==2)
        {
            scanf("%d%d%lld",&l,&r,&c);
            update(1,l,r,c);
        }
        else if(op==3)
        {
            scanf("%d%d%lld",&l,&r,&c);
            flag=false;
            add(1,l,r,c);
            while(flag)
            {
                flag=false;
                add(1,l,r,c);
            }
        }
    }
    return 0;
}