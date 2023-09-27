#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
const int N=1000005;
int n,m,k;
int a[N];
vector<int>pos[N];
vector<tuple<int,int,int>>seg[N];
struct Segment_Tree
{ 
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r,cnt;
        long long sum;
    }tree[N*4];
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r,tree[i].cnt=tree[i].sum=0;
        if(l==r) return;
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        return;
    }
    void push_up(int i)
    {
        if(tree[i].cnt) tree[i].sum=tree[i].r-tree[i].l+1;
        else tree[i].sum=tree[ls].sum+tree[rs].sum;
        return;
    }
    void modify(int i,int l,int r,int k)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            tree[i].cnt+=k;
            if(tree[i].cnt) tree[i].sum=tree[i].r-tree[i].l+1;
            else if(tree[i].l==tree[i].r) tree[i].sum=0;
            else tree[i].sum=tree[ls].sum+tree[rs].sum;
            return;
        }
        if(l<=tree[ls].r) modify(ls,l,r,k);
        if(r>=tree[rs].l) modify(rs,l,r,k);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        int res=0;
        if(l<=tree[ls].r) res+=query(ls,l,r);
        if(r>=tree[rs].l) res+=query(rs,l,r);
        return res;
    }
    #undef ls
    #undef rs
}T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    m=*max_element(a+1,a+n+1);
    for(int u=1;u<=m;u++)
        pos[u].emplace_back(0); 
    for(int i=1;i<=n;i++)
        pos[a[i]].emplace_back(i);
    for(int u=1;u<=m;u++)
    {
        pos[u].emplace_back(n+1);
        for(int i=1;i<(int)pos[u].size();i++)
            if(i+k<(int)pos[u].size())
            {
                int ll=pos[u][i-1]+1,lr=pos[u][i];
                int rl=pos[u][i+k-1],rr=pos[u][i+k]-1;
                seg[ll].emplace_back(rl,rr,1),seg[lr+1].emplace_back(rl,rr,-1);
            }
    }
    T.build(1,1,n);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(auto [l,r,v]:seg[i])
            T.modify(1,l,r,v);
        ans+=n-i+1-T.query(1,i,n);
    }
    cout<<ans;
    return 0;
}
