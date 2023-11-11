#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005,M=1000005;
const long long INF=4557430888798830399;
int n,m;
int fa[N],c[N];
vector<int>G[N];
struct Line
{
    long long k,b;
    long long calc(const long long &u)const
    {
        return k*u+b;
    }
};
struct Segment_Tree
{
    struct Node
    {
        int ls,rs;
        Line seg;
        long long tag;
    }tree[M*25];
    int rt[N],tot;
    Segment_Tree():tot(0){}
    int new_node()
    {
        int now=++tot;
        tree[now].ls=tree[now].rs=0;
        tree[now].seg.k=0,tree[now].seg.b=INF;
        return now;
    }
    void clear()
    {
        tot=0;
        for(int i=1;i<=n;i++)
            rt[i]=0;
        return; 
    }
    void add(int i,long long v)
    {
        if(!i) return;
        tree[i].seg.b+=v;
        tree[i].tag+=v;
        return;
    }
    void push_down(int i)
    {
        if(!tree[i].tag) return;
        add(tree[i].ls,tree[i].tag);
        add(tree[i].rs,tree[i].tag);
        tree[i].tag=0;
        return;
    }
    void add(int &i,int l,int r,int L,int R,long long v)
    {
        if(!i) return;
        if(L<=l&&r<=R) return add(i,v);
        push_down(i);
        int mid=(l+r)/2;
        if(L<=mid) add(tree[i].ls,l,mid,L,R,v);
        if(R>mid) add(tree[i].rs,mid+1,r,L,R,v);
        return;
    }
    void insert(int &i,int l,int r,Line t)
    {
        if(!i) i=new_node();
        if(t.calc(l)<tree[i].seg.calc(l)) swap(tree[i].seg,t);
        if(l==r) return;
        if(t.calc(r)>=tree[i].seg.calc(r)) return;
        push_down(i);
        int mid=(l+r)/2;
        if(tree[i].seg.calc(mid)>t.calc(mid)) insert(tree[i].ls,l,mid,tree[i].seg),tree[i].seg=t;
        else insert(tree[i].rs,mid+1,r,t);
        return;
    }
    long long query(int i,int l,int r,long long t)
    {
        if(!i) return INF;
        if(l==r) return tree[i].seg.calc(t);
        push_down(i); 
        int mid=(l+r)/2;
        long long res=tree[i].seg.calc(t);
        if(t<=mid) res=min(res,query(tree[i].ls,l,mid,t));
        else res=min(res,query(tree[i].rs,mid+1,r,t));
        return res;
    }
    int merge(int u,int v,int l,int r)
    {
        if(!u) return v;
        if(!v) return u;
        if(l==r)
        {
            if(tree[u].seg.calc(l)<tree[v].seg.calc(l)) tree[u].seg=tree[v].seg;
            return u;
        }
        insert(u,l,r,tree[v].seg);
        push_down(u),push_down(v);
        int mid=(l+r)/2;
        tree[u].ls=merge(tree[u].ls,tree[v].ls,l,mid);
        tree[u].rs=merge(tree[u].rs,tree[v].rs,mid+1,r);
        return u;
    }
}T;
int siz[N];
long long b[N]; 
void dfs(int u,int father)
{
    siz[u]=1;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
    if(siz[u]==1)
    {
        T.insert(T.rt[u],1,m,(Line){c[u],0});
        return;
    }
    long long sum=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        b[v]=T.query(T.rt[v],1,m,c[u]);
        sum+=b[v];
    }
    for(int v:G[u])
    {
        if(v==father) continue;
        long long ret=sum-b[v];
        T.add(T.rt[v],1,m,1,m,ret);
        T.rt[u]=T.merge(T.rt[u],T.rt[v],1,m); 
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
        cin>>fa[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    m=1000000;
    for(int i=2;i<=n;i++)
        G[fa[i]].emplace_back(i),G[i].emplace_back(fa[i]);
    dfs(1,0);
    cout<<T.query(T.rt[1],1,m,c[1]);
    return 0;
}
