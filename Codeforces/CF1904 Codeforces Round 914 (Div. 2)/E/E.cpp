#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
int n,q;
vector<int>G[N];
int dfn[N],ed[N],Index;
int dis[N],w[N];
void init(int u,int father)
{
    dfn[u]=++Index;
    w[Index]=u;
    for(int v:G[u])
    {
        if(v==father) continue;
        dis[v]=dis[u]+1;
        init(v,u);
    }
    ed[u]=Index;
    return;
}
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        int mx,tag;
    }tree[N*4];
    void push_up(int i)
    {
        tree[i].mx=max(tree[ls].mx,tree[rs].mx);
        return;
    }
    void add(int i,int v)
    {
        tree[i].mx+=v;
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
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tag=0;
        if(l==r)
        {
            tree[i].mx=dis[w[l]];
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void add(int i,int l,int r,long long v)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,v);
        push_down(i);
        if(l<=tree[ls].r) add(ls,l,r,v);
        if(r>=tree[rs].l) add(rs,l,r,v);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l>r) return 0;
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].mx;
        push_down(i);
        if(r<=tree[ls].r) return query(ls,l,r);
        else if(l>=tree[rs].l) return query(rs,l,r);
        else return max(query(ls,l,r),query(rs,l,r));
    }
    #undef ls
    #undef rs
}T;
vector<pair<vector<int>,int>> query[N];
int ans[N];
void dfs(int u,int father)
{
    for(auto [p,id]:query[u])
    {
        vector<pair<int,int>>seg;
        for(int v:p)
        {
            if(dfn[v]<=dfn[u]&&dfn[u]<=ed[v])
            {
                int w=*prev(upper_bound(G[v].begin(),G[v].end(),u,[=](const int &x,const int &y){return dfn[x]<dfn[y];}));
                if(1<=dfn[w]-1) seg.emplace_back(1,dfn[w]-1);
                if(ed[w]+1<=n) seg.emplace_back(ed[w]+1,n);
            }
            else seg.emplace_back(dfn[v],ed[v]);
        }
        sort(seg.begin(),seg.end());
        if(seg.empty())
        {
            ans[id]=T.query(1,1,n);
            continue;
        }
        int res=T.query(1,1,seg.front().first-1);
        for(int i=0,j=0;i<(int)seg.size();i=j)
        {
            int r=seg[i].second;
            while(j<(int)seg.size()&&seg[j].first<=r) r=max(r,seg[j].second),j++;
            if(j<(int)seg.size()) res=max(res,T.query(1,r+1,seg[j].first-1));
            else res=max(res,T.query(1,r+1,n));
        }
        ans[id]=res;
    }
    for(int v:G[u])
    {
        if(v==father) continue;
        int l=dfn[v],r=ed[v];
        if(l<=r) T.add(1,l,r,-1);
        if(1<=l-1) T.add(1,1,l-1,1);
        if(r+1<=n) T.add(1,r+1,n,1);
        dfs(v,u);
        if(l<=r) T.add(1,l,r,1);
        if(1<=l-1) T.add(1,1,l-1,-1);
        if(r+1<=n) T.add(1,r+1,n,-1);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for(int i=1;i<=q;i++)
    {
        int x,k;
        cin>>x>>k;
        vector<int>p(k);
        for(int j=0;j<k;j++)
            cin>>p[j];
        query[x].emplace_back(p,i);
    }
    init(1,0);
    T.build(1,1,n);
    for(int u=1;u<=n;u++)
        sort(G[u].begin(),G[u].end(),[=](const int &x,const int &y){return dfn[x]<dfn[y];});
    dfs(1,0);
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<"\n";
    return 0;
}