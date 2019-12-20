#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=40001;
struct Edge
{
    int val,id;
}x[N<<1];
struct House
{
    int sa,sb,sh;
}a[N];
int n,m;
int pos[N<<1];
bool cmp1(Edge a,Edge b)
{
    return a.val<b.val;
}
bool cmp2(House a,House b)
{
    return a.sh<b.sh;
}
struct Node
{
    long long sum,lazy;
}tree[N<<4];
void push_up(int i)
{
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}
void push_down(int i,int l,int r)
{
    if(!tree[i].lazy) return;
    int mid=(l+r)/2;
    tree[i*2].sum=(pos[mid]-pos[l])*tree[i].lazy;
    tree[i*2+1].sum=(pos[r]-pos[mid])*tree[i].lazy;
    tree[i*2].lazy=tree[i*2+1].lazy=tree[i].lazy;
    tree[i].lazy=0;
    return;
}
void update(int i,int l,int r,int L,int R,long long v)
{
    if(L<=l&&r<=R)
    {
        tree[i].sum=(pos[r]-pos[l])*v;
        tree[i].lazy=v;
        return;
    }
    push_down(i,l,r);
    int mid=(l+r)/2;
    if(R<=mid) update(i*2,l,mid,L,R,v);
    else if(L>=mid) update(i*2+1,mid,r,L,R,v);
    else update(i*2,l,mid,L,R,v),update(i*2+1,mid,r,L,R,v);
    push_up(i);
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i].sa,&a[i].sb,&a[i].sh);
        x[i*2-1].val=a[i].sa,x[i*2].val=a[i].sb;
        x[i*2-1].id=x[i*2].id=i;
    }
    sort(x+1,x+2*n+1,cmp1);
    for(int i=1;i<=2*n;i++)
    {
        if(x[i].val>pos[m]) pos[++m]=x[i].val;
        if(x[i].val==a[x[i].id].sa) a[x[i].id].sa=m;
        else a[x[i].id].sb=m;
    }
    sort(a+1,a+n+1,cmp2);
    for(int i=1;i<=n;i++)
        update(1,1,m,a[i].sa,a[i].sb,a[i].sh);
    printf("%lld",tree[1].sum);
    return 0;
}