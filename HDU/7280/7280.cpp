#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
const long long INF=4557430888798830399;
int n,m,q;
int L;
vector<pair<int,int>>G[N];
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
        Line tag;
    }tree[N*100];
    int rt[N],tot;
    Segment_Tree(){tot=0;}
    int new_node()
    {
        int now=++tot;
        tree[now].ls=tree[now].rs=0;
        tree[now].tag.k=0,tree[now].tag.b=INF;
        return now;
    }
    void clear()
    {
        tot=0;
        for(int i=1;i<=n;i++)
            rt[i]=0;
        return; 
    }
    void modify(int &i,long long l,long long r,Line t)
    {
        if(!i) i=new_node();
        if(t.calc(l)<tree[i].tag.calc(l)) swap(tree[i].tag,t);
        if(l==r) return;
        if(t.calc(r)>tree[i].tag.calc(r)) return;
        long long mid=l+r>=0?(l+r)/2:(l+r-1)/2;
        if(tree[i].tag.calc(mid)>t.calc(mid)) modify(tree[i].ls,l,mid,tree[i].tag),tree[i].tag=t;
        else modify(tree[i].rs,mid+1,r,t);
        return;
    }
    long long query(int i,long long l,long long r,long long t)
    {
        if(!i) return INF;
        if(l==r) return tree[i].tag.calc(t);
        long long mid=l+r>=0?(l+r)/2:(l+r-1)/2;
        long long res=tree[i].tag.calc(t);
        if(t<=mid) res=min(res,query(tree[i].ls,l,mid,t));
        else res=min(res,query(tree[i].rs,mid+1,r,t));
        return res;
    }
    int merge(int u,int v,long long l,long long r)
    {
        if(!u) return v;
        if(!v) return u;
        if(l==r)
        {
            if(tree[u].tag.calc(l)<tree[v].tag.calc(l)) tree[u].tag=tree[v].tag;
            return u;
        }
        modify(u,l,r,tree[v].tag);
        long long mid=l+r>=0?(l+r)/2:(l+r-1)/2;
        tree[u].ls=merge(tree[u].ls,tree[v].ls,l,mid);
        tree[u].rs=merge(tree[u].rs,tree[v].rs,mid+1,r);
        return u;
    }
}T;
long long s[N];
long long f[N];
void dfs(int u,int father)
{
    int son=0;
    for(auto [v,w]:G[u])
    {
        if(v==father) continue;
        s[v]=s[u]+w;
        dfs(v,u);
        son++;
        T.rt[u]=T.merge(T.rt[u],T.rt[v],-m,m);
    }
    if(son==0) f[u]=0;
    else f[u]=T.query(T.rt[u],-m,m,s[u])+s[u]*s[u]+(long long)L*L;
    T.modify(T.rt[u],-m,m,(Line){-2*s[u]+2*L,s[u]*s[u]-2*s[u]*L+f[u]});
    return;
}
void solve()
{
    cin>>n>>L;
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        G[x].emplace_back(y,z);
        G[y].emplace_back(x,z);
    }
    m=n*100000;
    cin>>q;
    while(q--)
    {
        int u;
        cin>>u;
        s[u]=0;
        T.clear();
        dfs(u,0);
        cout<<f[u]<<"\n";
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