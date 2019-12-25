#include<bits/stdc++.h>
using namespace std;

template<typename T>
void read(T &x)
{
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}
template<typename T>
void print(T x)
{
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
template<typename T>
void write(T x) {if(!x) putchar('0');else print(x);putchar('\n');}

const int maxn = 3e5+10;
const long long INF = 123456789123456789;

int n,m;
long long dis[maxn];
int w[maxn];
long long f(long long x,long long k,long long b)
{
    return k*x+b;
}
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        long long k,b;
        long long Min;
    }tree[maxn<<2];
    void push_up(int i)
    {
        tree[i].Min=min(tree[i].Min,min(tree[i*2].Min,tree[i*2+1].Min));
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].k=0,tree[i].b=INF;
        tree[i].Min=INF;
        if(l==r) return;
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        return;
    }
    void modify(int i,long long k,long long b)
    {
        if(tree[i].b==INF)
        {
            tree[i].k=k,tree[i].b=b;
            tree[i].Min=min(tree[i].Min,min(f(dis[w[tree[i].l]],k,b),f(dis[w[tree[i].r]],k,b)));
            return;
        }
        if(tree[i].l==tree[i].r)
        {
            if(f(dis[w[tree[i].l]],k,b)<f(dis[w[tree[i].l]],tree[i].k,tree[i].b))
            {
                tree[i].k=k,tree[i].b=b;
                tree[i].Min=f(dis[w[tree[i].l]],k,b);
            }
            return;
        }
        int mid=(tree[i].l+tree[i].r)/2;
        if(k<tree[i].k)
        {
            if(f(dis[w[mid]],k,b)<f(dis[w[mid]],tree[i].k,tree[i].b)) modify(i*2,tree[i].k,tree[i].b),tree[i].k=k,tree[i].b=b;
            else modify(i*2+1,k,b);
        }
        if(tree[i].k<k)
        {
            if(f(dis[w[mid]],k,b)<f(dis[w[mid]],tree[i].k,tree[i].b)) modify(i*2+1,tree[i].k,tree[i].b),tree[i].k=k,tree[i].b=b;
            else modify(i*2,k,b);
        }
        tree[i].Min=min(tree[i].Min,min(f(dis[w[tree[i].l]],k,b),f(dis[w[tree[i].r]],k,b)));
        tree[i].Min=min(tree[i].Min,min(f(dis[w[tree[i].l]],tree[i].k,tree[i].b),f(dis[w[tree[i].r]],tree[i].k,tree[i].b)));
        push_up(i);
        return;
    }
    void update(int i,int l,int r,long long k,long long b)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            modify(i,k,b);
            return;
        }
        if(l<=tree[i*2].r) update(i*2,l,r,k,b);
        if(r>=tree[i*2+1].l) update(i*2+1,l,r,k,b);
        push_up(i);
        return;
    }
    long long query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Min;
        long long ans=min(f(dis[w[max(l,tree[i].l)]],tree[i].k,tree[i].b),f(dis[w[min(tree[i].r,r)]],tree[i].k,tree[i].b));
        if(tree[i].b==INF) ans=INF;
        if(l<=tree[i*2].r) ans=min(ans,query(i*2,l,r));
        if(r>=tree[i*2+1].l) ans=min(ans,query(i*2+1,l,r));
        return ans;
    }
}T;
int dfn[maxn],hs[maxn],top[maxn],sz[maxn],dfn_cnt,dep[maxn],fa[maxn];
struct Edge{int to,next,w;}edge[maxn<<1];
int head[maxn],cnt;
void add(int u,int v,int w) {edge[++cnt]=(Edge){v,head[u],w},head[u]=cnt;}
void ins(int u,int v,int w) {add(u,v,w),add(v,u,w);}

void dfs(int x,int father)
{
    fa[x]=father,dep[x]=dep[father]+1,sz[x]=1;
    for(int i=head[x];i;i=edge[i].next)
        if(edge[i].to!=father)
        {
            dis[edge[i].to]=dis[x]+edge[i].w;
            dfs(edge[i].to,x);
            sz[x]+=sz[edge[i].to];
            if(sz[hs[x]]<sz[edge[i].to]) hs[x]=edge[i].to;
        }
}

void dfs2(int x,int father)
{
    top[x]=father;
    dfn[x]=++dfn_cnt;w[dfn_cnt]=x;
    if(!hs[x]) return;
    dfs2(hs[x],father);
    for(int i=head[x];i;i=edge[i].next)
        if(edge[i].to!=fa[x]&&edge[i].to!=hs[x]) dfs2(edge[i].to,edge[i].to);
}
int lca(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=fa[top[x]];
    }if(dep[x]>dep[y]) swap(x,y);return x;
}

long long query(int x,int y)
{
    long long ans=INF;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=min(ans,T.query(1,dfn[top[x]],dfn[x]));
        x=fa[top[x]];
    }if(dep[x]>dep[y]) swap(x,y);
    ans=min(ans,T.query(1,dfn[x],dfn[y]));
    return ans;
}

void update(int x,int t,long long k,long long b)
{
    while(top[x]!=top[t])
    {
        if(dep[top[x]]<dep[top[t]]) swap(x,t);
        T.update(1,dfn[top[x]],dfn[x],k,b);
        x=fa[top[x]];
    }T.update(1,dfn[t],dfn[x],k,b);
}
void solve(int s,int t,long long a,long long b)
{
    int l=lca(s,t);
    // y=a*dis+b=a*(dis[s]-dis[x])+b -> k=-a,b=a*dis[s]+b
    update(s,l,-a,a*dis[s]+b);
    // y=a*dis+b=a*(dis[x]+dis[s]-2*dis[l])+b -> k=a,b=a*(dis[s]-2*dis[l])+b
    update(t,l,a,a*(dis[s]-2*dis[l])+b);
}
signed main()
{
    read(n),read(m);
    for(int i=1,x,y,z;i<n;i++) read(x),read(y),read(z),ins(x,y,z);
    dfs(1,0);
    dfs2(1,1);
    T.build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op,s,t,a,b;
        read(op),read(s),read(t);
        if(op==1) read(a),read(b),solve(s,t,a,b);
        else write(query(s,t));
    }
    return 0;
}

