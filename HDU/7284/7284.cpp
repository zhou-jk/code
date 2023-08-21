#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,m;
int a[N];
struct Segment_Tree_1
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int cnt,rev;
        long long tag,sum;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].sum=tree[ls].sum+tree[rs].sum;
        tree[i].cnt=tree[ls].cnt+tree[rs].cnt;
        return;
    }
    void add(int i,long long x,int rev)
    {
        tree[i].sum=tree[i].cnt*x+tree[i].sum*rev;
        tree[i].tag=x+tree[i].tag*rev;
        tree[i].rev*=rev;
        return;
    }
    void push_down(int i)
    {
        add(ls,tree[i].tag,tree[i].rev);
        add(rs,tree[i].tag,tree[i].rev);
        tree[i].tag=0;
        tree[i].rev=1;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tag=0;
        tree[i].rev=1;
        if(l==r)
        {
            tree[i].sum=tree[i].cnt=0;
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,int v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].sum=v;
            tree[i].cnt=1;
            return;
        }
        push_down(i);
        if(u<=tree[ls].r) modify(ls,u,v);
        else modify(rs,u,v);
        push_up(i);
        return;
    }
    void modify(int i,int l,int r,long long x)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,x,-1);
        push_down(i);
        if(l<=tree[ls].r) modify(ls,l,r,x);
        if(r>=tree[rs].l) modify(rs,l,r,x);
        push_up(i);
        return;
    }
    long long query(int i,int l,int r)
    {
        if(!tree[i].cnt) return 0;
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        push_down(i);
        long long res=0;
        if(l<=tree[ls].r) res+=query(ls,l,r);
        if(r>=tree[rs].l) res+=query(rs,l,r);
        return res;
    }
    #undef ls
    #undef rs
}T1;
struct Segment_Tree_2
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int cnt;
        long long sum,tag;
        pair<int,int> mn;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].sum=tree[ls].sum+tree[rs].sum;
        tree[i].cnt=tree[ls].cnt+tree[rs].cnt;
        tree[i].mn=min(tree[ls].mn,tree[rs].mn);
        return;
    }
    void add(int i,long long v)
    {
        if(!tree[i].cnt) return;
        tree[i].sum-=tree[i].cnt*v;
        tree[i].tag+=v;
        tree[i].mn.first-=v;
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
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tag=0;
        if(l==r)
        {
            tree[i].mn=make_pair(a[l],l);
            tree[i].sum=a[l];
            tree[i].cnt=1;
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void remove(int i,int u)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].mn=make_pair(INF,u);
            tree[i].sum=0;
            tree[i].cnt=0;
            return;
        }
        push_down(i);
        if(u<=tree[ls].r) remove(ls,u);
        else remove(rs,u);
        push_up(i);
        return;
    }
    void modify(int i,int l,int r,int x)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            add(i,x);
            while(tree[i].mn.first<0)
                T1.modify(1,tree[i].mn.second,tree[i].mn.first+x),remove(1,tree[i].mn.second);
            return;
        }
        push_down(i);
        if(l<=tree[ls].r) modify(ls,l,r,x);
        if(r>=tree[rs].l) modify(rs,l,r,x);
        push_up(i);
        return;
    }
    long long query(int i,int l,int r)
    {
        if(!tree[i].cnt) return 0;
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        push_down(i);
        long long res=0;
        if(l<=tree[ls].r) res+=query(ls,l,r);
        if(r>=tree[rs].l) res+=query(rs,l,r);
        return res;
    }
    #undef ls
    #undef rs
}T2;
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    T1.build(1,1,n);
    T2.build(1,1,n);
    while(m--)
    {
        int op,l,r;
        cin>>op;
        if(op==1)
        {
            int x;
            cin>>l>>r>>x;
            T2.modify(1,l,r,x);
            T1.modify(1,l,r,x);
        }
        else if(op==2)
        {
            cin>>l>>r;
            long long ans=T1.query(1,l,r)+T2.query(1,l,r);
            cout<<ans<<"\n";
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}