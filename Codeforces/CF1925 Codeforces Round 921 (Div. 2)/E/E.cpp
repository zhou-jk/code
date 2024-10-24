#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=300005;
int n,m,q;
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        long long sum;
        pair<long long,long long>tag;
    }tree[N*4];
    void push_up(int i)
    {
        tree[i].sum=tree[ls].sum+tree[rs].sum;
        return;
    }
    void cover(int i,const pair<long long,long long> &v)
    {
        tree[i].sum=(v.first+v.first+v.second*(tree[i].r-tree[i].l))*(tree[i].r-tree[i].l+1)/2;
        tree[i].tag=v;
        return;
    }
    void push_down(int i)
    {
        if(tree[i].tag==make_pair(0ll,0ll)) return;
        cover(ls,tree[i].tag);
        cover(rs,make_pair(tree[i].tag.first+(tree[ls].r-tree[ls].l+1)*tree[i].tag.second,tree[i].tag.second));
        tree[i].tag={0,0};
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tag={0,0};
        if(l==r)
        {
            tree[i].sum=0;
            return;
        }
        int mid=(l+r)>>1;
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
            return;
        }
        push_down(i);
        if(u<=tree[ls].r) modify(ls,u,v);
        else modify(rs,u,v);
        push_up(i);
        return;
    }
    void cover(int i,int l,int r,const pair<long long,long long> &v)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return cover(i,make_pair(v.first+(tree[i].l-l)*v.second,v.second));
        push_down(i);
        if(l<=tree[ls].r) cover(ls,l,r,v);
        if(r>=tree[rs].l) cover(rs,l,r,v);
        push_up(i);
        return;
    }
    long long query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        push_down(i);
        long long res=0;
        if(l<=tree[ls].r) res+=query(ls,l,r);
        if(r>=tree[rs].l) res+=query(rs,l,r);
        return res;
    }
    #undef ls
    #undef rs
}T;
int x[N],v[N];
set<int>s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
        cin>>x[i];
    for(int i=1;i<=m;i++)
        cin>>v[x[i]];
    sort(x+1,x+m+1);
    for(int i=1;i<=m;i++)
        s.insert(x[i]);
    T.build(1,1,n);
    for(int i=2;i<=m;i++)
        if(x[i-1]+1<=x[i]-1) T.cover(1,x[i-1]+1,x[i]-1,make_pair((long long)v[x[i-1]]*(x[i]-x[i-1]-1),-v[x[i-1]]));
    while(q--)
    {
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1)
        {
            v[l]=r;
            auto it=s.lower_bound(l);
            if(it!=s.end())
            {
                int suf=*it;
                if(l+1<=suf-1) T.cover(1,l+1,suf-1,make_pair((long long)v[l]*(suf-l-1),-v[l]));
            }
            if(it!=s.begin())
            {
                int pre=*prev(it);
                if(pre+1<=l-1) T.cover(1,pre+1,l-1,make_pair((long long)v[pre]*(l-pre-1),-v[pre]));
            }
            T.modify(1,l,0);
            s.insert(l);
        }
        else if(op==2)
        {
            long long ans=T.query(1,l,r);
            cout<<ans<<"\n";
        }
    }
    return 0;
}