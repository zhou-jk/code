#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50005,Q=200005;
const int MOD=1000000007;
const int SIZE=200;
int n,m,q;
int a[N];
int b[N];
int tot,bel[N];
struct Query
{
    int l,r,id;
}query[Q];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int sum[2];
        int siz;
    }tree[N*4];
    Node merge(const Node &a,const Node &b)
    {
        Node c;
        c.l=a.l,c.r=b.r;
        c.siz=a.siz+b.siz;
        for(int o=0;o<=1;o++)
            c.sum[o]=(a.sum[o]+b.sum[o^(a.siz&1)])%MOD;
        return c;
    }
    void push_up(int i)
    {
        tree[i]=merge(tree[ls],tree[rs]);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].sum[0]=tree[i].sum[1]=0;
            tree[i].siz=0;
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void add(int i,int u)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].siz++;
            tree[i].sum[tree[i].siz&1]=(tree[i].sum[tree[i].siz&1]+b[u])%MOD;
            return;
        }
        if(u<=tree[ls].r) add(ls,u);
        else add(rs,u);
        push_up(i);
        return;
    }
    void del(int i,int u)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].sum[tree[i].siz&1]=(tree[i].sum[tree[i].siz&1]-b[u]+MOD)%MOD;
            tree[i].siz--;
            return;
        }
        if(u<=tree[ls].r) del(ls,u);
        else del(rs,u);
        push_up(i);
        return;
    }
    Node query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i];
        if(r<=tree[rs].r) return query(ls,l,r);
        else if(l>=tree[rs].l) return query(rs,l,r);
        else return merge(query(ls,l,r),query(rs,l,r));
    }
    #undef ls
    #undef rs
}T;
void add(int x)
{
    T.add(1,x);
    return;
}
void del(int x)
{
    T.del(1,x);
    return;
}
int ans[Q];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        b[++m]=a[i];
    sort(b+1,b+m+1);
    m=unique(b+1,b+m+1)-b-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+m+1,a[i])-b;
    T.build(1,1,m);
    for(int i=1;i<=q;i++)
    {
        int ql,qr;
        cin>>ql>>qr;
        ql++,qr++;
        query[i].l=ql,query[i].r=qr,query[i].id=i;
    }
    tot=(n-1)/SIZE+1;
    for(int i=1;i<=n;i++)
        bel[i]=(i-1)/SIZE+1;
    sort(query+1,query+q+1,[=](const Query &x,const Query &y)
    {
        if(bel[x.l]!=bel[y.l]) return bel[x.l]<bel[y.l];
        else return (bel[x.l]&1)?x.r<y.r:x.r>y.r;
    });
    int l=1,r=0;
    for(int i=1;i<=q;i++)
    {
        int ql=query[i].l,qr=query[i].r;
        while(l<ql) del(a[l++]);
        while(l>ql) add(a[--l]);
        while(r<qr) add(a[++r]);
        while(r>qr) del(a[r--]);
        Segment_Tree::Node sum=T.query(1,1,m);
        ans[query[i].id]=sum.sum[1];
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<"\n";
    return 0;
}