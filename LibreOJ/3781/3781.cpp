#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50005;
int n;
struct Node
{
    int h,v,id;
}p[N];
int bv[N],totv;
pair<int,double> merge(pair<int,double> a,pair<int,double> b)
{
    pair<int,double>c=make_pair(0,0);
    c.first=max(a.first,b.first);
    if(c.first==a.first) c.second+=a.second;
    if(c.first==b.first) c.second+=b.second;
    return c;
}
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        pair<int,double> mx;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].mx=merge(tree[ls].mx,tree[rs].mx);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].mx=make_pair(0,0);
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void add(int i,int u,pair<int,double> v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].mx=merge(tree[i].mx,v);
            return;
        }
        if(u<=tree[ls].r) add(ls,u,v);
        else add(rs,u,v);
        push_up(i);
        return;
    }
    void modify(int i,int u,pair<int,double> v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].mx=v;
            return;
        }
        if(u<=tree[ls].r) modify(ls,u,v);
        else modify(rs,u,v);
        push_up(i);
        return;
    }
    pair<int,double>query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].mx;
        if(r<=tree[ls].r) return query(ls,l,r);
        else if(l>=tree[rs].l) return query(rs,l,r);
        else return merge(query(ls,l,r),query(rs,l,r));
    }
}T;
pair<int,double>f[N],g[N];
void solve1(int l,int r)
{
    if(l==r)
    {
        f[l]=merge(f[l],make_pair(1,1));
        return;
    }
    int mid=(l+r)/2;
    solve1(l,mid);
    static Node ql[N];
    static Node qr[N];
    int totl=0,totr=0;
    for(int i=l;i<=mid;i++)
        ql[++totl]=p[i];
    for(int i=mid+1;i<=r;i++)
        qr[++totr]=p[i];
    sort(ql+1,ql+totl+1,[](const Node &a,const Node &b){return a.h>b.h;});
    sort(qr+1,qr+totr+1,[](const Node &a,const Node &b){return a.h>b.h;});
    int j=1;
    for(int i=1;i<=totr;i++)
    {
        while(j<=totl&&ql[j].h>=qr[i].h) T.add(1,ql[j].v,f[ql[j].id]),j++;
        pair<int,double>t=T.query(1,qr[i].v,totv);
        t.first++;
        f[qr[i].id]=merge(f[qr[i].id],t);
    }
    for(int k=1;k<j;k++)
        T.modify(1,ql[k].v,make_pair(0,0));
    solve1(mid+1,r);
    return;
}
void solve2(int l,int r)
{
    if(l==r)
    {
        g[l]=merge(g[l],make_pair(1,1));
        return;
    }
    int mid=(l+r)/2;
    solve2(mid+1,r);
    static Node ql[N];
    static Node qr[N];
    int totl=0,totr=0;
    for(int i=l;i<=mid;i++)
        ql[++totl]=p[i];
    for(int i=mid+1;i<=r;i++)
        qr[++totr]=p[i];
    sort(ql+1,ql+totl+1,[](const Node &a,const Node &b){return a.h<b.h;});
    sort(qr+1,qr+totr+1,[](const Node &a,const Node &b){return a.h<b.h;});
    int j=1;
    for(int i=1;i<=totl;i++)
    {
        while(j<=totr&&qr[j].h<=ql[i].h) T.add(1,qr[j].v,g[qr[j].id]),j++;
        pair<int,double>t=T.query(1,1,ql[i].v);
        t.first++;
        g[ql[i].id]=merge(g[ql[i].id],t);
    }
    for(int k=1;k<j;k++)
        T.modify(1,qr[k].v,make_pair(0,0));
    solve2(l,mid);
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i].h,&p[i].v),p[i].id=i;
    for(int i=1;i<=n;i++)
        bv[++totv]=p[i].v;
    sort(bv+1,bv+totv+1);
    totv=unique(bv+1,bv+totv+1)-bv-1;
    for(int i=1;i<=n;i++)
        p[i].v=lower_bound(bv+1,bv+totv+1,p[i].v)-bv;
    T.build(1,1,totv);
    solve1(1,n);
    solve2(1,n);
    pair<int,double> ans=make_pair(0,0);
    for(int i=1;i<=n;i++)
        ans=merge(ans,f[i]);
    printf("%d\n",ans.first);
    for(int i=1;i<=n;i++)
        if(f[i].first+g[i].first-1==ans.first) printf("%.4lf ",f[i].second*g[i].second/ans.second);
        else printf("%.4lf ",0.0);
    return 0;
}