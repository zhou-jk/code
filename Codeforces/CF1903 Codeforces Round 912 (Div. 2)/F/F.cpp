#include<iostream>
#include<cstdio>
#include<array>
#include<stack>
#include<vector>
using namespace std;
const int N=100005,M=200005;
int n,m;
pair<int,int>edge[M];
array<int,2>id[N];
vector<int>G[N*10];
int tot;
void add(const array<int,2> &u,const array<int,2> &v,int a,int b)
{
    G[u[a]].emplace_back(v[b]);
    G[v[b^1]].emplace_back(u[a^1]);
    return;
}
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        array<int,2> p;
    }tree[N*4];
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].p=id[l];
            return;
        }
        tree[i].p[0]=++tot,tree[i].p[1]=++tot;
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        return;
    }
    void add_edge(int i)
    {
        if(tree[i].l==tree[i].r) return;
        add_edge(ls);
        add_edge(rs);
        add(tree[i].p,tree[ls].p,0,0);
        add(tree[i].p,tree[rs].p,0,0);
        return;
    }
    void get(int i,int l,int r,const array<int,2> &v)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            add(v,tree[i].p,1,0);
            return;
        }
        if(l<=tree[ls].r) get(ls,l,r,v);
        if(r>=tree[rs].l) get(rs,l,r,v);
        return;
    }
    #undef ls
    #undef rs
}T;
int dfn[N*10],low[N*10],Index;
bool book[N*10];
int bel[N*10],cnt;
void tarjan(int u)
{
    static stack<int> s;
    dfn[u]=low[u]=++Index;
    book[u]=true;
    s.emplace(u);
    for(int v:G[u])
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(book[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        cnt++;
        while(!s.empty()&&s.top()!=u)
        {
            book[s.top()]=false;
            bel[s.top()]=cnt;
            s.pop();
        }
        book[u]=false;
        bel[u]=cnt;
        s.pop();
    }
    return;
}
bool check(int x)
{
    for(int i=1;i<=m;i++)
    {
        auto [u,v]=edge[i];
        if(u==v) G[id[u][0]].emplace_back(id[v][1]);
        else add(id[u],id[v],0,1);
    }
    T.add_edge(1);
    for(int i=1;i<=n;i++)
        if(i+1<=min(i+x-1,n)) T.get(1,i+1,min(i+x-1,n),id[i]);
    fill(dfn+1,dfn+tot+1,0);
    fill(low+1,low+tot+1,0);
    cnt=0;
    Index=0;
    for(int i=1;i<=tot;i++)
        if(!dfn[i]) tarjan(i);
    for(int i=1;i<=tot;i++)
        G[i].clear();
    for(int i=1;i<=tot;i+=2)
        if(bel[i]==bel[i+1]) return false;
    return true;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[i]={u,v};
    }
    tot=0;
    for(int i=1;i<=n;i++)
        id[i][0]=++tot,id[i][1]=++tot;
    T.build(1,1,n);
    int l=1,r=n,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
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