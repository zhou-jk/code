#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005,M=15;
const int INF=1061109567;
int n,p,m;
int h[N];
int b[N],tot;
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1 
    struct Node
    {
        int l,r;
        int mn,tag;
    }tree[N*4];
    void push_up(int i)
    {
        tree[i].mn=min(tree[ls].mn,tree[rs].mn);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tag=0;
        if(l==r)
        {
            tree[i].mn=INF;
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return; 
    }
    void add(int i,int v)
    {
        tree[i].mn+=v;
        tree[i].tag+=v;
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].tag) return;
        add(ls,tree[i].tag);
        add(rs,tree[i].tag);
        tree[i].tag=0;
        return;
    }
    void add(int i,int l,int r,int v)
    {
        if(l>r) return;
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[ls].r) add(ls,l,r,v);
        if(r>=tree[rs].l) add(rs,l,r,v);
        push_up(i);
        return; 
    }
    void modify(int i,int u,int v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].mn=min(tree[i].mn,v);
            return;
        }
        push_down(i);
        if(u<=tree[ls].r) modify(ls,u,v);
        else modify(rs,u,v);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l>r) return INF;
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].mn;
        push_down(i);
        int res=INF;
        if(l<=tree[ls].r) res=min(res,query(ls,l,r));
        if(r>=tree[rs].l) res=min(res,query(rs,l,r));
        return res;
    }
    #undef ls
    #undef rs
}T[M];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>p>>m;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<=n;i++)
        b[++tot]=h[i];
    sort(b+1,b+tot+1);
    tot=unique(b+1,b+tot+1)-b-1;
    for(int i=1;i<=n;i++)
        h[i]=lower_bound(b+1,b+tot+1,h[i])-b;
    int ans=0;
    for(int i=1;i<p;i++)
        if(h[i]>=h[p]) ans++;
    for(int k=1;k<=m;k++)
        T[k].build(1,1,tot);
    T[1].modify(1,h[p],0);
    for(int i=p+1;i<=n;i++)
        for(int k=m;k>=1;k--)
        {
            if(k-1>=1) T[k].modify(1,h[i],T[k-1].query(1,1,h[i]-1));
            T[k].add(1,1,h[i]-1,1);
        }
    int res=T[m].query(1,1,tot);
    if(res>=INF)
    {
        cout<<-1;
        return 0;
    }
    cout<<res+ans;
    return 0;
}