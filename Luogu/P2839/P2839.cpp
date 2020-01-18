#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20005;
int n,m;
int a[N],id[N];
int cmp(int x,int y)
{
    return a[x]<a[y];
}
struct Node
{
    int lc,rc,ls,rs,sum;
}tree[N<<6];
int rt[N],tot;
void push_up(int i)
{
    tree[i].sum=tree[tree[i].lc].sum+tree[tree[i].rc].sum;
    tree[i].ls=max(tree[tree[i].lc].ls,tree[tree[i].lc].sum+tree[tree[i].rc].ls);
    tree[i].rs=max(tree[tree[i].rc].rs,tree[tree[i].rc].sum+tree[tree[i].lc].rs);
    return;
}
void build(int &i,int l,int r)
{
    i=++tot;
    if(l==r)
    {
        tree[i].ls=tree[i].rs=tree[i].sum=1;
        return ;
    }
    int mid=(l+r)/2;
    build(tree[i].lc,l,mid);
    build(tree[i].rc,mid+1,r);
    push_up(i);
    return;
}
int update(int i,int l,int r,int u)
{
    int now=++tot;
    tree[now]=tree[i];
    if(l==r)
    {
        tree[now].ls=tree[now].rs=tree[now].sum=-1;
        return now;
    }
    int mid=(l+r)/2;
    if(u<=mid) tree[now].lc=update(tree[i].lc,l,mid,u);
    else tree[now].rc=update(tree[i].rc,mid+1,r,u);
    push_up(now);
    return now;
}
int querysum(int i,int l,int r,int L,int R)
{
    if(L>R) return 0;
    if(L<=l&&r<=R) return tree[i].sum;
    int mid=(l+r)/2;
    int res=0;
    if(L<=mid) res+=querysum(tree[i].lc,l,mid,L,R);
    if(mid<R) res+=querysum(tree[i].rc,mid+1,r,L,R);
    return res;
}
int queryleft(int i,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return tree[i].ls;
    int mid=(l+r)/2;
    if(R<=mid) return queryleft(tree[i].lc,l,mid,L,R);
    else if(mid<L) return queryleft(tree[i].rc,mid+1,r,L,R);
    else return max(queryleft(tree[i].lc,l,mid,L,mid),querysum(tree[i].lc,l,mid,L,mid)+queryleft(tree[i].rc,mid+1,r,mid+1,R));
}
int queryright(int i,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)return tree[i].rs;
    int mid=(l+r)/2;
    if(R<=mid) return queryright(tree[i].lc,l,mid,L,R);
    else if(mid<L) return queryright(tree[i].rc,mid+1,r,L,R);
    else return max(queryright(tree[i].rc,mid+1,r,mid+1,R),querysum(tree[i].rc,mid+1,r,mid+1,R)+queryright(tree[i].lc,l,mid,L,mid));
}
int q[5];
int check(int x)
{
    return querysum(rt[x],1,n,q[2]+1,q[3]-1)+queryleft(rt[x],1,n,q[3],q[4])+queryright(rt[x],1,n,q[1],q[2])>=0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        id[i]=i;
    }
    sort(id+1,id+n+1,cmp);
    build(rt[1],1,n);
    for(int i=2;i<=n;i++)
        rt[i]=update(rt[i-1],1,n,id[i-1]);
    scanf("%d",&m);
    int lastans=0;
    while(m--)
    {
        for(int i=1;i<=4;i++)
            scanf("%d",&q[i]),q[i]=((long long)q[i]+lastans)%n+1;
        sort(q+1,q+4+1);
        int l=1,r=n,mid,ans=1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(check(mid)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        lastans=a[id[ans]];
        printf("%d\n",lastans);
    }
    return 0;
}