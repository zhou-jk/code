#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node
{
    int l,r;
    long long Min,Max,c,k,b;
}tree[400001];
int n,m;
int L,R,p[100001][2];
int a[100001],q[100001];
void push_up(int i)
{
    tree[i].Min=tree[i*2].Min;
    tree[i].Max=tree[i*2+1].Max;
    return;
}
void build(int i,int l,int r)
{
    tree[i].c=1,tree[i].k=tree[i].b=0;
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].Min=tree[i].Max=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    push_up(i);
    return;
}
void add(int i,long long c,long long k,long long b)
{
    tree[i].Min=tree[i].Min*c+k*a[tree[i].l]+b;
    tree[i].Max=tree[i].Max*c+k*a[tree[i].r]+b;
    tree[i].c*=c,tree[i].k*=c,tree[i].b*=c;
    tree[i].k+=k,tree[i].b+=b;
    return;
}
void push_down(int i,int l,int r)
{
    add(i*2,tree[i].c,tree[i].k,tree[i].b);
    add(i*2+1,tree[i].c,tree[i].k,tree[i].b);
    tree[i].c=1,tree[i].k=tree[i].b=0;
    return;
}
void updatel(int i,int l,int r)
{
    if(l==r)
    {
        add(i,0,0,L);
        return;
    }
    push_down(i,l,r);
    int mid=(l+r)/2;
    if(tree[i*2+1].Min<L) add(i*2,0,0,L),updatel(i*2+1,mid+1,r);
    else updatel(i*2,l,mid);
    push_up(i);
    return;
}

void updater(int i,int l,int r)
{
    if(l==r)
    {
        add(i,0,0,R);
        return;
    }
    push_down(i,l,r);
    int mid=(l+r)/2;
    if(tree[i*2].Max>R) add(i*2+1,0,0,R),updater(i*2,l,mid);
    else updater(i*2+1,mid+1,r);
    push_up(i);
    return;
}
int query(int k,int l,int r,int x)
{
    if(l==r) return tree[k].Max;
    push_down(k,l,r);
    int mid=(l+r)/2;
    if(x<=mid) return query(k*2,l,mid,x);
    else return query(k*2+1,mid+1,r,x);
}
int main()
{
    scanf("%d%d%d",&m,&L,&R);
    for(int i=1;i<=m;i++)
    {
        char s[5];
        scanf("%s %d",s,&p[i][1]);
        if(s[0]=='+') p[i][0]=1;
        if(s[0]=='-') p[i][0]=2;
        if(s[0]=='*') p[i][0]=3;
        if(s[0]=='@') p[i][0]=4;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        q[i]=a[i];
    }
    sort(a+1,a+n+1);
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        if(p[i][0]==1) add(1,1,0,p[i][1]);
        if(p[i][0]==2) add(1,1,0,-p[i][1]);
        if(p[i][0]==3) add(1,p[i][1],0,0);
        if(p[i][0]==4) add(1,1,p[i][1],0);
        if(tree[1].Min<L) updatel(1,1,n);
        if(tree[1].Max>R) updater(1,1,n);
    }
    for(int i=1;i<=n;i++)
    {
        int x=lower_bound(a+1,a+n+1,q[i])-a;
        printf("%d\n",query(1,1,n,x));
    }
    return 0;
}