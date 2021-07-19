#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
const int N=200005;
int n,m;
int a[N];
int x[N],y[N],c[N];
vector<pair<int,int>>star[N];
int ls[N],rs[N],root;
stack<int>s;
void insert(int i)
{
    int j=0;
    while(!s.empty()&&a[i]>a[s.top()]) j=s.top(),s.pop();
    if(s.empty()) root=i;
    else rs[s.top()]=i;
    ls[i]=j;
    s.emplace(i);
    return;
}
struct Segment_Tree
{
    struct Node
    {
        int ls,rs;
        long long mx,tag;
    }tree[N*30];
    int rt[N],tot;
    int new_node()
    {
        int now=++tot;
        tree[now].ls=tree[now].rs=0;
        tree[now].mx=0;
        tree[now].tag=0;
        return now;
    }
    void push_up(int i)
    {
        tree[i].mx=max(tree[tree[i].ls].mx,tree[tree[i].rs].mx);
        return;
    }
    void add(int i,long long v)
    {
        if(!i) return;
        tree[i].tag+=v;
        tree[i].mx+=v;
        return;
    }
    void push_down(int i)
    {
        if(tree[i].tag==0) return;
        add(tree[i].ls,tree[i].tag);
        add(tree[i].rs,tree[i].tag);
        tree[i].tag=0;
        return;
    }
    void add(int &i,int l,int r,int L,int R,long long v)
    {
        if(L>R) return;
        if(!i) i=new_node();
        if(L<=l&&r<=R) return add(i,v);
        push_down(i);
        int mid=(l+r)/2;
        if(L<=mid) add(tree[i].ls,l,mid,L,R,v);
        if(R>mid) add(tree[i].rs,mid+1,r,L,R,v);
        push_up(i);
        return;
    }
    void modify(int &i,int l,int r,int u,long long v)
    {
        if(!i) i=new_node();
        if(l==r)
        {
            tree[i].mx=max(tree[i].mx,v);
            return;
        }
        push_down(i);
        int mid=(l+r)/2;
        if(u<=mid) modify(tree[i].ls,l,mid,u,v);
        else modify(tree[i].rs,mid+1,r,u,v);
        push_up(i);
        return;
    }
    long long query(int i,int l,int r,int L,int R)
    {
        if(L>R) return 0;
        if(!i) return 0;
        if(L<=l&&r<=R) return tree[i].mx;
        push_down(i);
        int mid=(l+r)/2;
        long long res=0;
        if(L<=mid) res=max(res,query(tree[i].ls,l,mid,L,R));
        if(R>mid) res=max(res,query(tree[i].rs,mid+1,r,L,R));
        return res;
    }
    int merge(int u,int v,int l,int r)
    {
        if(!u) return v;
        if(!v) return u;
        if(l==r)
        {
            tree[u].mx=max(tree[u].mx,tree[v].mx);
            return u;
        }
        push_down(u);
        push_down(v);
        int mid=(l+r)/2;
        tree[u].ls=merge(tree[u].ls,tree[v].ls,l,mid);
        tree[u].rs=merge(tree[u].rs,tree[v].rs,mid+1,r);
        push_up(u);
        return u;
    }
}T;
long long g[N];
void dfs(int u)
{
    if(ls[u]) dfs(ls[u]);
    if(rs[u]) dfs(rs[u]);
    if(ls[u]&&rs[u])
    {
        long long gl=g[ls[u]];
        if(a[ls[u]]<a[u]) gl=max(gl,T.query(T.rt[ls[u]],1,n,a[ls[u]]+1,a[u]));
        long long gr=g[rs[u]];
        if(a[rs[u]]<a[u]) gr=max(gr,T.query(T.rt[rs[u]],1,n,a[rs[u]]+1,a[u]));
        T.add(T.rt[ls[u]],1,n,a[u]+1,n,gr);
        T.add(T.rt[rs[u]],1,n,a[u]+1,n,gl);
        T.rt[u]=T.merge(T.rt[ls[u]],T.rt[rs[u]],1,n);
        g[u]=gl+gr;
        for(auto [y,c]:star[u])
            T.modify(T.rt[u],1,n,y,c+gl+gr);
    }
    else if(ls[u]&&!rs[u])
    {
        long long gl=g[ls[u]];
        if(a[ls[u]]<a[u]) gl=max(gl,T.query(T.rt[ls[u]],1,n,a[ls[u]]+1,a[u]));
        T.rt[u]=T.rt[ls[u]];
        g[u]=gl;
        for(auto [y,c]:star[u])
            T.modify(T.rt[u],1,n,y,c+gl);
    }
    else if(!ls[u]&&rs[u])
    {
        long long gr=g[rs[u]];
        if(a[rs[u]]<a[u]) gr=max(gr,T.query(T.rt[rs[u]],1,n,a[rs[u]]+1,a[u]));
        T.rt[u]=T.rt[rs[u]];
        g[u]=gr;
        for(auto [y,c]:star[u])
            T.modify(T.rt[u],1,n,y,c+gr);
    }
    else
    {
        for(auto [y,c]:star[u])
            T.modify(T.rt[u],1,n,y,c);
        g[u]=T.query(T.rt[u],1,n,1,a[u]);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&x[i],&y[i],&c[i]);
    long long sum=0,ans=0;
    for(int i=1;i<=m;i++)
    {
        sum+=c[i];
        if(y[i]<=a[x[i]]) ans+=c[i];
        else star[x[i]].emplace_back(y[i],c[i]);
    }
    for(int i=1;i<=n;i++)
        insert(i);
    dfs(root);
    long long res=g[root];
    if(a[root]<n) res=max(res,T.query(T.rt[root],1,n,a[root]+1,n));
    ans+=res;
    ans=sum-ans;
    printf("%lld",ans);
    return 0;
}