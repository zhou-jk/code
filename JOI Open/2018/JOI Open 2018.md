#### バブルソート 2 / Bubble Sort 2

可以发现，答案即为 $\max\limits_{i=1}^n \sum\limits_{j=1}^{i-1}[a_j>a_i]$。

因为是 $\max$，所以可能成为答案只有后缀最小值，可以把式子改写成 $\max\limits_{i=1}^n \left(i-\sum\limits_{j=1}^{n}[a_j\le a_i]\right)$。这个就可以直接使用平衡树或者值域线段树维护了。

---

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<chrono>
#include<random>
#include<numeric>
#include<algorithm>
#include"bubblesort2.h"
using namespace std;
const int N=500005;
int n,m,q;
int a[N],b[N];
int x[N],v[N];
int res[N];
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());
struct FHQ_Treap
{
    struct Node
    {
        int ls,rs;
        pair<int,int> val;
        int v,mx;
        int tag;
        unsigned long long rd;
        int siz;
        void clear()
        {
            ls=rs=0;
            val=make_pair(0,0);
            v=mx=0;
            tag=0;
            rd=0;
            siz=0;
            return;
        }
    }tree[N+N];
    int rt,tot;
    FHQ_Treap():rt(0),tot(0){}
    void clear()
    {
        rt=tot=0;
        return;
    }
    int new_node(pair<int,int> val,int v)
    {
        int now=++tot;
        tree[now].clear();
        tree[now].val=val,tree[now].mx=tree[now].v=v;
        tree[now].rd=rnd();
        tree[now].tag=0;
        tree[now].siz=1;
        return now;
    }
    void push_up(int u)
    {
        tree[u].siz=tree[tree[u].ls].siz+tree[tree[u].rs].siz+1;
        tree[u].mx=max(max(tree[tree[u].ls].mx,tree[tree[u].rs].mx),tree[u].v);
        return;
    }
    void add(int u,int v)
    {
        if(!u) return;
        tree[u].mx+=v;
        tree[u].v+=v;
        tree[u].tag+=v;
        return;
    }
    void push_down(int u)
    {
        if(!u) return;
        if(!tree[u].tag) return;
        add(tree[u].ls,tree[u].tag);
        add(tree[u].rs,tree[u].tag);
        tree[u].tag=0;
        return;
    }
    int merge(int u,int v)
    {
        if(!u) return v;
        if(!v) return u;
        push_down(u),push_down(v);
        if(tree[u].rd<tree[v].rd)
        {
            tree[u].rs=merge(tree[u].rs,v);
            push_up(u); 
            return u;
        }
        else
        {
            tree[v].ls=merge(u,tree[v].ls);
            push_up(v);
            return v;
        }
    }
    void split(int now,pair<int,int> k,int &x,int &y)
    {
        if(!now)
        {
            x=y=0;
            return;
        }
        push_down(now);
        if(tree[now].val<=k)
        {
            x=now;
            split(tree[now].rs,k,tree[x].rs,y);
        }
        else
        {
            y=now;
            split(tree[now].ls,k,x,tree[y].ls);
        }
        push_up(now);
        return;
    }
    void insert(pair<int,int> val,int v)
    {
        int x,y;
        split(rt,val,x,y);
        rt=merge(merge(x,new_node(val,v)),y);
        return;
    }
    void erase(pair<int,int> val)
    {
        int x,y,z;
        split(rt,val,x,z);
        split(x,make_pair(val.first,val.second-1),x,y);
        y=merge(tree[y].ls,tree[y].rs);
        rt=merge(merge(x,y),z);
        return;
    }
    void add(int l,int r,int v)
    {
        int x,y,z;
        split(rt,make_pair(r,n),x,z);
        split(x,make_pair(l-1,n),x,y);
        add(y,v);
        rt=merge(merge(x,y),z);
        return;
    }
    int query_size(int l,int r)
    {
        int x,y,z;
        split(rt,make_pair(r,n),x,z);
        split(x,make_pair(l-1,n),x,y);
        int res=tree[y].siz;
        rt=merge(merge(x,y),z);
        return res;
    }
    int query_max(int l,int r)
    {
        int x,y,z;
        split(rt,make_pair(r,n),x,z);
        split(x,make_pair(l-1,n),x,y);
        int res=tree[y].mx;
        rt=merge(merge(x,y),z);
        return res;
    }
}T;
vector<int> countScans(vector<int> A,vector<int> X,vector<int> V)
{
    n=A.size(),q=X.size();
    for(int i=1;i<=n;i++)
        a[i]=A[i-1];
    for(int i=1;i<=q;i++)
        x[i]=X[i-1]+1,v[i]=V[i-1];
    m=1000000000;
    T.clear();
    static int id[N];
    iota(id+1,id+n+1,1);
    sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]<a[y];});
    for(int i=1,j=1;i<=n;i=j)
    {
        while(j<=n&&a[id[i]]==a[id[j]]) j++;
        for(int k=i;k<j;k++)
            b[id[k]]=id[k]-(j-1);
    }
    for(int i=1;i<=n;i++)
        T.insert(make_pair(a[i],i),b[i]);
    for(int i=1;i<=q;i++)
    {
        T.erase(make_pair(a[x[i]],x[i]));
        T.add(a[x[i]],m,1);
        a[x[i]]=v[i];
        T.add(a[x[i]],m,-1);
        b[x[i]]=x[i]-(T.query_size(1,a[x[i]])+1);
        T.insert(make_pair(a[x[i]],x[i]),b[x[i]]);
        res[i]=T.query_max(1,m);
    }
    vector<int>S(q);
    for(int i=1;i<=q;i++)
        S[i-1]=res[i];
    return S;
}
```

---

#### 猫か犬 / Cats or Dogs

用 $f_{i,0/1}$ 表示这个点与猫/狗相连，最小需要阻塞的路径数。

然后动态 DP 就可以了。

---

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include"catdog.h"
using namespace std;
const int N=100005;
const int MAX=100000;
const int INF=1061109567;
int n;
vector<int>G[N];
int a[N];
int fa[N],son[N];
int siz[N];
void dfs1(int u,int father)
{
    fa[u]=father;
    siz[u]=1;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
    return;
}
int dfn[N],Index,id[N];
int top[N],down[N];
void dfs2(int u,int father)
{
    dfn[u]=++Index;
    top[u]=father;
    id[Index]=u;
    if(!son[u])
    {
        down[u]=u;
        return;
    }
    dfs2(son[u],father);
    down[u]=down[son[u]];
    for(int v:G[u])
    {
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
    return;
}
int f[N][2],g[N][2];
void dfs(int u,int father)
{
    f[u][0]=f[u][1]=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs(v,u);
        f[u][0]+=min(f[v][0],f[v][1]+1);
        f[u][1]+=min(f[v][0]+1,f[v][1]);
    }
    if(a[u]==1) f[u][1]+=MAX;
    else if(a[u]==2) f[u][0]+=MAX;
    return;
}
struct Matrix
{
    int mat[2][2];
    friend Matrix operator*(const Matrix &a,const Matrix &b)
    {
        Matrix c;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                c.mat[i][j]=INF;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    c.mat[i][j]=min(c.mat[i][j],a.mat[i][k]+b.mat[k][j]);
        return c;
    }
};
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        Matrix sum;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].sum=tree[rs].sum*tree[ls].sum;
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].sum.mat[0][0]=g[id[l]][0],tree[i].sum.mat[0][1]=g[id[l]][0]+1;
            tree[i].sum.mat[1][0]=g[id[l]][1]+1,tree[i].sum.mat[1][1]=g[id[l]][1];
            return;
        }
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].sum.mat[0][0]=g[id[u]][0],tree[i].sum.mat[0][1]=g[id[u]][0]+1;
            tree[i].sum.mat[1][0]=g[id[u]][1]+1,tree[i].sum.mat[1][1]=g[id[u]][1];
            return;
        }
        if(u<=tree[ls].r) modify(ls,u);
        else modify(rs,u);
        push_up(i);
        return;
    }
    Matrix query(int i,int u)
    {
        if(tree[i].l==tree[i].r) return tree[i].sum;
        if(u<=tree[ls].r) return query(ls,u);
        else return query(rs,u);
    }
    Matrix query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].sum;
        if(r<=tree[ls].r) return query(ls,l,r);
        else if(l>=tree[rs].l) return query(rs,l,r);
        else return query(rs,l,r)*query(ls,l,r);
    }
    #undef ls
    #undef rs
}T;
void modify(int u,int v)
{
    if(a[u]==1) g[u][1]-=MAX;
    else if(a[u]==2) g[u][0]-=MAX;
    a[u]=v;
    if(a[u]==1) g[u][1]+=MAX;
    else if(a[u]==2) g[u][0]+=MAX;
    while(u)
    {
        Matrix pre=T.query(1,dfn[top[u]],dfn[down[u]]);
        Matrix gg=T.query(1,dfn[fa[top[u]]]);
        T.modify(1,dfn[u]);
        Matrix suf=T.query(1,dfn[top[u]],dfn[down[u]]);
        u=fa[top[u]];
        if(!u) break;
        g[u][0]=min(gg.mat[0][0],gg.mat[0][1]),g[u][1]=min(gg.mat[1][0],gg.mat[1][1]);
        g[u][0]-=min(pre.mat[0][0],pre.mat[1][0]),g[u][1]-=min(pre.mat[0][1],pre.mat[1][1]);
        g[u][0]+=min(suf.mat[0][0],suf.mat[1][0]),g[u][1]+=min(suf.mat[0][1],suf.mat[1][1]);
    }
    return;
}
void initialize(int N,vector<int>A,vector<int>B)
{
    n=N;
    for(int i=0;i<n-1;i++)
        G[A[i]].emplace_back(B[i]),G[B[i]].emplace_back(A[i]);
    fill(a+1,a+n+1,3);
    dfs1(1,0);
    dfs2(1,1);
    dfs(1,0);
    for(int u=1;u<=n;u++)
    {
        for(int v:G[u])
        {
            if(v==fa[u]||v==son[u]) continue;
            g[u][0]+=min(f[v][0],f[v][1]+1);
            g[u][1]+=min(f[v][0]+1,f[v][1]);
        }
        if(a[u]==1) g[u][1]+=MAX;
        else if(a[u]==2) g[u][0]+=MAX;
    }
    T.build(1,1,Index);
    return;
}
int get_ans()
{
    Matrix ans=T.query(1,dfn[top[1]],dfn[down[1]]);
    return min({ans.mat[0][0],ans.mat[0][1],ans.mat[1][0],ans.mat[1][1]});
}
int cat(int v)
{
    modify(v,1);
    return get_ans();
}
int dog(int v)
{
    modify(v,2);
    return get_ans();
}
int neighbor(int v)
{
    modify(v,3);
    return get_ans();
}
```

---

#### 崖崩れ / Collapse

考虑计算 $\le p$ 的连通块个数，$\ge p+1$ 的同理。

令 $(u,v)$ 的边权为 $\max(u,v)$，询问即为询问 $1\sim p$ 的最小生成树中有多少条边权值 $\le p$。可以用 LCT 维护最小生成树森林，但是 LCT 维护最小生成树是不支持删边的，线段树分治一下就可以了。

---

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<tuple>
#include<stack>
#include"collapse.h"
using namespace std;
const int N=100005;
int n,m,q;
int t[N],x[N],y[N],w[N],p[N];
map<pair<int,int>,int>pos;
struct LCT
{
    struct Node
    {
        int fa,ls,rs;
        int rev;
        pair<int,tuple<int,int,int>>mx,val;
        void clear()
        {
            fa=ls=rs=0;
            mx=val=make_pair(0,make_tuple(0,0,0));
            rev=0;
            return;
        }
    }tree[N+N];
    int tot;
    LCT():tot(0){}
    LCT(int _n)
    {
        tot=_n;
        for(int i=1;i<=tot;i++)
            tree[i].clear();
        return;
    }
    void clear()
    {
        tot=0;
        return;
    }
    void resize(int _n)
    {
        for(int i=tot+1;i<=_n;i++)
            tree[i].clear();
        tot=_n;
        return;
    }
    int new_node(pair<int,tuple<int,int,int>> val=make_pair(0,make_tuple(0,0,0)))
    {
        int now=++tot;
        tree[now].clear();
        tree[now].mx=tree[now].val=val;
        return now;
    }
    void push_up(int u)
    {
        tree[u].mx=max(max(tree[tree[u].ls].mx,tree[tree[u].rs].mx),tree[u].val);
        return;
    }
    void reverse(int u)
    {
        swap(tree[u].ls,tree[u].rs);
        tree[u].rev^=1;
        return;
    }
    void push_down(int u)
    {
        if(!tree[u].rev) return;
        if(tree[u].ls) reverse(tree[u].ls);
        if(tree[u].rs) reverse(tree[u].rs);
        tree[u].rev=0;
        return;
    }
    int get(int u)
    {
        if(tree[tree[u].fa].ls==u) return 0;
        if(tree[tree[u].fa].rs==u) return 1;
        return -1;
    }
    bool isroot(int u)
    {
        return get(u)==-1;
    }
    void connect(int u,int v,int op)
    {
        if(u) tree[u].fa=v;
        if(v)
        {
            if(op==0) tree[v].ls=u;
            if(op==1) tree[v].rs=u;
        }
        return;
    }
    void rotate(int u)
    {
        int f=tree[u].fa,gf=tree[f].fa,r=get(u),gr=get(f);
        int v=0;
        if(r==1) v=tree[u].ls;
        if(r==0) v=tree[u].rs;
        connect(u,gf,gr);
        connect(v,f,r);
        connect(f,u,r^1);
        push_up(f);
        push_up(u);
        return;
    }
    void pushall(int u)
    {
        if(!isroot(u)) pushall(tree[u].fa);
        push_down(u);
        return;
    }
    void splay(int u)
    {
        pushall(u);
        while(!isroot(u))
        {
            int f=tree[u].fa;
            if(!isroot(f)) rotate(get(u)==get(f)?f:u);
            rotate(u);
        }
        return;
    }
    int access(int u)
    {
        int v;
        for(v=0;u;v=u,u=tree[u].fa)
        {
            splay(u);
            tree[u].rs=v;
            push_up(u);
        }
        return v;
    }
    void makeroot(int u)
    {
        access(u);
        splay(u);
        reverse(u);
        return;
    }
    int findroot(int u)
    {
        access(u);
        splay(u);
        push_down(u);
        while(tree[u].ls) u=tree[u].ls,push_down(u);
        splay(u);
        return u;
    }
    void split(int x,int y)
    {
        makeroot(x);
        access(y);
        splay(y);
        return;
    }
    bool link(int x,int y)
    {
        makeroot(x);
        if(findroot(y)==x) return false;
        tree[x].fa=y;
        return true;
    }
    bool cut(int x,int y)
    {
        if(findroot(x)!=findroot(y)) return false;
        split(x,y);
        if(tree[x].fa!=y||tree[x].rs) return false;
        tree[x].fa=tree[y].ls=0;
        push_up(y);
        return true;
    }
    pair<int,tuple<int,int,int>>query(int x,int y)
    {
        split(x,y);
        return tree[y].mx;
    }
}lct;
struct BIT
{
    int C[N];
    void clear()
    {
        for(int i=1;i<=n;i++)
            C[i]=0;
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]+=y;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res+=C[i];
        return res;
    }
}bit;
stack<tuple<int,int,int,int>>stk;
vector<pair<int,int>>query[N];
int ans[N];
struct Segment_Tree
{
    #define ls i*2
    #define rs i*2+1
    struct Node
    {
        int l,r;
        vector<tuple<int,int,int>>add;
    }tree[N<<2];
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].add.clear();
        if(l==r) return;
        int mid=(l+r)/2;
        build(ls,l,mid);
        build(rs,mid+1,r);
        return;
    }
    void add(int i,int l,int r,tuple<int,int,int> e)
    {
        if(l<=tree[i].l&&tree[i].r<=r)
        {
            tree[i].add.emplace_back(e);
            return;
        }
        if(l<=tree[ls].r) add(ls,l,r,e);
        if(r>=tree[rs].l) add(rs,l,r,e);
        return;
    }
    void solve(int i)
    {
        tuple<int,int,int,int> pre=make_tuple(-1,-1,-1,-1);
        if(!stk.empty()) pre=stk.top();
        for(auto [u,v,w]:tree[i].add)
        {
            if(lct.findroot(u)!=lct.findroot(v))
            {
                lct.link(u,w),lct.link(v,w);
                bit.add(max(u,v),1);
                stk.emplace(1,u,v,w);
            }
            else
            {
                auto [val,e]=lct.query(u,v);
                auto [uu,vv,ww]=e;
                if(max(u,v)<val)
                {
                    lct.cut(uu,ww),lct.cut(vv,ww);
                    bit.add(max(uu,vv),-1);
                    stk.emplace(-1,uu,vv,ww);
                    lct.link(u,w),lct.link(v,w);
                    bit.add(max(u,v),1);
                    stk.emplace(1,u,v,w);
                }
            }
        }
        if(tree[i].l==tree[i].r)
        {
            for(auto [p,id]:query[tree[i].l])
                ans[id]+=p-bit.getsum(p);
        }
        else
        {
            solve(ls);
            solve(rs);
        }
        while(!stk.empty()&&stk.top()!=pre)
        {
            auto [op,u,v,w]=stk.top();
            stk.pop();
            if(op==1) lct.cut(u,w),lct.cut(v,w),bit.add(max(u,v),-1);
            else if(op==-1) lct.link(u,w),lct.link(v,w),bit.add(max(u,v),1);
        }
        return;
    }
    #undef ls
    #undef rs
}st;
vector<int> simulateCollapse(int N,vector<int> T,vector<int> X,vector<int> Y,vector<int> W,vector<int> P)
{
    n=N,m=T.size(),q=W.size();
    for(int i=1;i<=m;i++)
        t[i]=T[i-1],x[i]=X[i-1]+1,y[i]=Y[i-1]+1;
    for(int i=1;i<=q;i++)
        w[i]=W[i-1]+1,p[i]=P[i-1]+1;
    for(int i=1;i<=m;i++)
        if(x[i]>y[i]) swap(x[i],y[i]);
    {
        lct.clear();
        lct.resize(n);
        for(int i=1;i<=n;i++)
            lct.tree[i].mx=lct.tree[i].val=make_pair(0,make_tuple(i,i,i));
        pos.clear();
        for(int i=1;i<=m;i++)
            if(!pos.count(make_pair(x[i],y[i])))
            {
                int now=lct.new_node();
                lct.tree[now].mx=lct.tree[now].val=make_pair(max(x[i],y[i]),make_tuple(x[i],y[i],now));
                pos[make_pair(x[i],y[i])]=now;
            }
        st.build(1,1,m);
        map<pair<int,int>,int>lst;
        for(int i=1;i<=m;i++)
            if(t[i]==0) lst[make_pair(x[i],y[i])]=i;
            else st.add(1,lst[make_pair(x[i],y[i])],i-1,make_tuple(x[i],y[i],pos[make_pair(x[i],y[i])])),lst.erase(make_pair(x[i],y[i]));
        for(auto [e,i]:lst)
            st.add(1,i,m,make_tuple(x[i],y[i],pos[make_pair(x[i],y[i])]));
        for(int i=1;i<=m;i++)
            query[i].clear();
        for(int i=1;i<=q;i++)
            query[w[i]].emplace_back(p[i],i);
        bit.clear();
        st.solve(1);
    }
    for(int i=1;i<=m;i++)
        x[i]=n-x[i]+1,y[i]=n-y[i]+1;
    for(int i=1;i<=q;i++)
        p[i]=n-(p[i]+1)+1;
    {
        lct.clear();
        lct.resize(n);
        for(int i=1;i<=n;i++)
            lct.tree[i].mx=lct.tree[i].val=make_pair(0,make_tuple(i,i,i));
        pos.clear();
        for(int i=1;i<=m;i++)
            if(!pos.count(make_pair(x[i],y[i])))
            {
                int now=lct.new_node();
                lct.tree[now].mx=lct.tree[now].val=make_pair(max(x[i],y[i]),make_tuple(x[i],y[i],now));
                pos[make_pair(x[i],y[i])]=now;
            }
        st.build(1,1,m);
        map<pair<int,int>,int>lst;
        for(int i=1;i<=m;i++)
            if(t[i]==0) lst[make_pair(x[i],y[i])]=i;
            else st.add(1,lst[make_pair(x[i],y[i])],i-1,make_tuple(x[i],y[i],pos[make_pair(x[i],y[i])])),lst.erase(make_pair(x[i],y[i]));
        for(auto [e,i]:lst)
            st.add(1,i,m,make_tuple(x[i],y[i],pos[make_pair(x[i],y[i])]));
        for(int i=1;i<=m;i++)
            query[i].clear();
        for(int i=1;i<=q;i++)
            query[w[i]].emplace_back(p[i],i);
        bit.clear();
        st.solve(1);
    }
    vector<int>D(q);
    for(int i=1;i<=q;i++)
        D[i-1]=ans[i];
    return D;
}
```

---

#### 木琴 / Xylophone

询问所有的 $(i,i+1)$ 和 $(i,i+2)$。如果 $(i,i+2)=(i,i+1)+(i+1,i+2)$，那么 $i\sim i+2$ 肯定是单调的，否则肯定不是单调的，然后一个个递推过去就可以了。

---

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include"xylophone.h"
using namespace std;
void solve(int N)
{
    int n=N;
    vector<int>a(n);
    vector<int>d1(n-1),d2(n-2);
    for(int i=0;i<n-1;i++)
        d1[i]=query(i+1,i+1+1);
    for(int i=0;i<n-2;i++)
        d2[i]=query(i+1,i+2+1);
    a[0]=0,a[1]=d1[0];
    for(int i=0;i<n-2;i++)
        if(d2[i]==d1[i]+d1[i+1])
        {
            if(a[i+1]>a[i]) a[i+2]=a[i+1]+d1[i+1];
            else a[i+2]=a[i+1]-d1[i+1];
        }
        else
        {
            if(a[i+1]>a[i]) a[i+2]=a[i+1]-d1[i+1];
            else a[i+2]=a[i+1]+d1[i+1];
        }
    int v=*min_element(a.begin(),a.end());
    for(int i=0;i<n;i++)
        a[i]+=-v+1;
    int mn=min_element(a.begin(),a.end())-a.begin(),mx=max_element(a.begin(),a.end())-a.begin();
    if(mn>mx)
    {
        for(int i=0;i<n;i++)
            a[i]=n-a[i]+1;
    }
    for(int i=0;i<n;i++)
        answer(i+1,a[i]);
    return;
}
```