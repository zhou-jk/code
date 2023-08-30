#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=50005;
int n,q;
int a[N],b[N];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        set<pair<long long,long long>>s;
    }tree[N*4];
    Node merge(const Node &a,const Node &b)
    {
        Node c;
        c.l=a.l,c.r=b.r;
        set<pair<long long,long long>>tmp;
        for(auto [l1,r1]:a.s)
            for(auto [l2,r2]:b.s)
                tmp.emplace(l1+l2,r1+r2);
        auto [L,R]=*tmp.begin();
        for(auto [l,r]:tmp)
        {
            if(l>R+1) c.s.emplace(L,R),L=l,R=r;
            else R=max(R,r);
        }
        c.s.emplace(L,R);
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
            tree[i].s.clear();
            tree[i].s.emplace(0,0);
            tree[i].s.emplace(a[l],b[l]);
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,const pair<long long,long long> &v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].s.clear();
            tree[i].s.emplace(0,0);
            tree[i].s.emplace(v);
            return;
        }
        if(u<=tree[ls].r) modify(ls,u,v);
        if(u>=tree[rs].l) modify(rs,u,v);
        push_up(i);
        return;
    }
    Node query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i];
        if(r<=tree[ls].r) return query(ls,l,r);
        else if(l>=tree[rs].l) return query(rs,l,r);
        else return merge(query(ls,l,r),query(rs,l,r));
    }
    #undef ls
    #undef rs
}T;
void solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    T.build(1,1,n);
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int k,a,b;
            cin>>k>>a>>b;
            T.modify(1,k,make_pair(a,b));
        }
        else if(op==2)
        {
            int l,r;
            cin>>l>>r;
            auto res=T.query(1,l,r);
            long long ans=0;
            for(auto [l,r]:res.s)
                ans+=r-l+1;
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