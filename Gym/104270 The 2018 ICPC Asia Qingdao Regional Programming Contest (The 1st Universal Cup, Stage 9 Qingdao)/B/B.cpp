#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m,k;
int x[N],y[N],id[N];
int a[N];
struct Edge
{
    int to,next;
}edge[N<<1];
int head[N],cnt;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
struct Segment_Tree_RMQ
{
    int index(int l,int r)
    {
        return (l+r)|(l!=r);
    }
    #define ls index(l,mid)
    #define rs index(mid+1,r)
    struct Node
    {
        int mx; 
    }tree[N*2];
    void push_up(int i,int l,int r)
    {
        int mid=(l+r)/2;
        tree[i].mx=max(tree[ls].mx,tree[rs].mx);
        return;
    }
    void build(int i,int l,int r)
    {
        if(l==r)
        {
            tree[i].mx=0;
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i,l,r);
        return;
    }
    void modify(int i,int l,int r,int u,int v)
    {
        if(l==r)
        {
            tree[i].mx+=v;
            return;
        }
        int mid=(l+r)/2;
        if(u<=mid) modify(ls,l,mid,u,v);
        else modify(rs,mid+1,r,u,v);
        push_up(i,l,r);
        return;
    }
    int query(int l,int r)
    {
        return tree[index(l,r)].mx;
    }
    #undef ls
    #undef rs
}rmq;
struct Segment_Tree
{
    struct Node
    {
        int ls,rs;
        int mx1,mx2;
    }tree[N*25];
    int tot,rt[N];
    void clear()
    {
        tot=0;
        for(int i=1;i<=n;i++)
            rt[i]=0;
        return;
    }
    int new_node()
    {
        int now=++tot;
        tree[now].ls=tree[now].rs=0;
        tree[now].mx1=tree[now].mx2=0;
        return now;
    }
    void push_up(int i,int l,int r)
    {
        int mid=(l+r)/2;
        tree[i].mx1=max(tree[tree[i].ls].mx1,tree[tree[i].rs].mx1);
        tree[i].mx2=max(tree[i].ls?tree[tree[i].ls].mx2:rmq.query(l,mid),tree[i].rs?tree[tree[i].rs].mx2:rmq.query(mid+1,r));
        return;
    }
    void add(int &i,int l,int r,int u,int v)
    {
        if(!i)
        {
            i=new_node();
            if(l==r) tree[i].mx1=0,tree[i].mx2=rmq.query(l,r);
        }
        if(l==r)
        {
            tree[i].mx1+=v,tree[i].mx2-=v;
            return;
        }
        int mid=(l+r)/2;
        if(u<=mid) add(tree[i].ls,l,mid,u,v);
        else add(tree[i].rs,mid+1,r,u,v);
        push_up(i,l,r);
        return;
    }
    int merge(int u,int v,int l,int r)
    {
        if(!u) return v;
        if(!v) return u;
        if(l==r)
        {
            tree[u].mx1+=tree[v].mx1;
            tree[u].mx2-=rmq.query(l,r)-tree[v].mx2;
            return u;
        }
        int mid=(l+r)/2;
        tree[u].ls=merge(tree[u].ls,tree[v].ls,l,mid);
        tree[u].rs=merge(tree[u].rs,tree[v].rs,mid+1,r);
        push_up(u,l,r);
        return u;
    }
    int query_t1(int i,int l,int r,int L,int R)
    {
        if(!i) return 0;
        if(L<=l&&r<=R) return tree[i].mx1;
        int mid=(l+r)/2;
        if(R<=mid) return query_t1(tree[i].ls,l,mid,L,R);
        else if(L>mid) return query_t1(tree[i].rs,mid+1,r,L,R);
        else return max(query_t1(tree[i].ls,l,mid,L,R),query_t1(tree[i].rs,mid+1,r,L,R));
    }
    int query_t2(int i,int l,int r,int L,int R)
    {
        if(!i) return rmq.query(l,r);
        if(L<=l&&r<=R) return tree[i].mx2;
        int mid=(l+r)/2;
        if(R<=mid) return query_t2(tree[i].ls,l,mid,L,R);
        else if(L>mid) return query_t2(tree[i].rs,mid+1,r,L,R);
        else return max(query_t2(tree[i].ls,l,mid,L,R),query_t2(tree[i].rs,mid+1,r,L,R));
    }
}T;
int dfn[N],low[N],Index;
bool bridge[N+N];
void tarjan(int u,int prev)
{
    dfn[u]=low[u]=++Index;
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]) bridge[i]=bridge[i^1]=true;
        }
        else if(i!=(prev^1)) low[u]=min(low[u],dfn[v]);
    }
    return;
}
int bel[N],tot;
vector<int>block[N]; 
void dfs(int u)
{
    bel[u]=tot;
    block[tot].emplace_back(u);
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(bel[v]||bridge[i]) continue;
        dfs(v);
    }
    return;
}
vector<int>G[N];
void rebuild()
{
    fill(dfn+1,dfn+n+1,0);
    fill(low+1,low+n+1,0);
    for(int i=1;i<=cnt;i++)
        bridge[i]=false;
    Index=0;
    for(int i=1;i<=n;i++)
        if(!dfn[i]) tarjan(i,0);
    fill(bel+1,bel+n+1,0);
    tot=0;
    for(int i=1;i<=n;i++)
        block[i].clear();
    for(int i=1;i<=n;i++)
        if(!bel[i])
        {
            tot++;
            dfs(i);
        }
    for(int i=1;i<=tot;i++)
        G[i].clear();
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(bel[u]==bel[v]) continue;
            G[bel[u]].emplace_back(bel[v]);
        }
    return;
}
int siz[N],dep[N];
vector<int>color;
void init(int u,int father)
{
    siz[u]=block[u].size();
    dep[u]=dep[father]+1;
    for(int v:G[u])
    {
        if(v==father) continue;
        init(v,u);
        siz[u]+=siz[v];
    }
    for(int t:block[u])
        color.emplace_back(a[t]);
    return;
}
int res[N];
int top[N];
void dfs(int u,int father,int topf)
{
    top[u]=topf;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u,topf);
        T.rt[u]=T.merge(T.rt[u],T.rt[v],1,k);
    }
    for(int t:block[u])
        T.add(T.rt[u],1,k,a[t],1);
    res[u]=T.query_t1(T.rt[u],1,k,1,k)+T.query_t2(T.rt[u],1,k,1,k);
    return;
}
int ans[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    fill(head+1,head+n+1,0);
    cnt=1;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
        add_edge(x[i],y[i]);
        add_edge(y[i],x[i]);
        id[i]=cnt;
    }
    k=*max_element(a+1,a+n+1);
    rebuild();
    rmq.build(1,1,k);
    long long sum=0;
    T.clear();
    fill(siz+1,siz+n+1,0); 
    for(int i=1;i<=tot;i++)
        if(!siz[i])
        {
            color.clear();
            init(i,0);
            for(int c:color)
                rmq.modify(1,1,k,c,1);
            dfs(i,0,i);
            sum+=res[i];
            for(int c:color)
                rmq.modify(1,1,k,c,-1);
        }
    for(int i=1;i<=m;i++)
        if(!bridge[id[i]]) ans[i]=sum;
        else
        {
            if(dep[bel[x[i]]]<dep[bel[y[i]]]) swap(x[i],y[i]);
            ans[i]=res[bel[x[i]]]+sum-res[top[bel[x[i]]]];
        }
    for(int i=1;i<m;i++)
        cout<<ans[i]<<" ";
    cout<<ans[m]<<"\n";
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