#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
const int N=100005;
const long long INF=4557430888798830399;
int n;
int a[N];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        long long mx[2][2];
    }tree[N*4];
    Node merge(const Node &a,const Node &b)
    {
        Node c;
        c.l=a.l,c.r=b.r;
        for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++)
                c.mx[i][j]=INF;
        for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++)
                for(int k=0;k<=1;k++)
                    c.mx[i][j]=min(c.mx[i][j],max(a.mx[i][k],b.mx[k][j]));
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
            tree[i].mx[0][0]=a[l];
            if(l+1<=n) tree[i].mx[0][1]=a[l]+a[l+1];
            else tree[i].mx[0][1]=INF;
            if(l-1>=1) tree[i].mx[1][0]=-INF;
            else tree[i].mx[1][0]=INF;
            tree[i].mx[1][1]=INF;
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
            if(v==1) tree[i].mx[0][0]=INF;
            else tree[i].mx[0][1]=INF;
            return;
        }
        if(u<=tree[ls].r) modify(ls,u,v);
        else modify(rs,u,v);
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
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    T.build(1,1,n);
    vector<tuple<int,int,int>>seg;
    for(int i=1;i<=n;i++)
    {
        seg.emplace_back(a[i],i,1);
        if(i+1<=n) seg.emplace_back(a[i]+a[i+1],i,2);
    }
    sort(seg.begin(),seg.end());
    long long ans=INF;
    for(auto [v,i,len]:seg)
    {
        ans=min(ans,T.query(1,1,n).mx[0][0]-v);
        T.modify(1,i,len);
    }
    cout<<ans<<"\n";
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