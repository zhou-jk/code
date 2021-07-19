#### ビルの飾り付け 4 / Building 4

令 $f_{i,0/1,j}$ 表示到第 $i$ 位，第 $i$ 位选的是 $A_i/B_i$，$1\sim i$ 选了 $j$ 个 $A_i$ 是否合法。

可以发现，对于一个 $f_{i,0/1,j}$，合法的 $j$ 一定是一段区间，那么就完了。

---

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=500005;
int n;
int a[N*2],b[N*2];
int f[N*2][2],g[N*2][2];
void print(int i,int j,int k)
{
    if(i==0) return;
    int v=j==0?a[i]:b[i];
    if(j==0) k--;
    if(v>=a[i-1]&&f[i-1][0]<=k&&k<=g[i-1][0]) print(i-1,0,k);
    else if(v>=b[i-1]&&f[i-1][1]<=k&&k<=g[i-1][1]) print(i-1,1,k);
    else exit(1);
    if(j==0) printf("A");
    else printf("B");
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n*2;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n*2;i++)
        scanf("%d",&b[i]);
    memset(f,63,sizeof(f));
    memset(g,0,sizeof(g));
    f[0][0]=g[0][0]=0;
    for(int i=1;i<=n*2;i++)
    {
        if(a[i]>=a[i-1]) f[i][0]=min(f[i][0],f[i-1][0]+1),g[i][0]=max(g[i][0],g[i-1][0]+1);
        if(a[i]>=b[i-1]) f[i][0]=min(f[i][0],f[i-1][1]+1),g[i][0]=max(g[i][0],g[i-1][1]+1);
        if(b[i]>=a[i-1]) f[i][1]=min(f[i][1],f[i-1][0]),g[i][1]=max(g[i][1],g[i-1][0]);
        if(b[i]>=b[i-1]) f[i][1]=min(f[i][1],f[i-1][1]),g[i][1]=max(g[i][1],g[i-1][1]);
    }
    if(f[n*2][0]<=n&&n<=g[n*2][0]) print(n*2,0,n);
    else if(f[n*2][1]<=n&&n<=g[n*2][1]) print(n*2,1,n);
    else printf("-1");
    return 0;
}
```

---

#### 美味しい美味しいハンバーグ / Hamburg Steak

阿拉丁题

---

#### 掃除 / Sweeping

又是阿拉丁题

---

#### カメレオンの恋 / Chameleon’s Love

---

#### ジョイッターで友達をつくろう / Making Friends on Joitter is Fun

将 $x$ 关注了 $y$ 视为 $x$ 有一条 $x\to y$ 的边。

那么将两两之间可以互相到达的点缩成一个点。对于一个点 $u$，它的贡献即为 $\operatorname{size}(u)\times(\operatorname{size}(u)-1)$，对于一条边 $u\to v$，它的贡献即为 $\operatorname{size}(v)$。

暴力启发式合并即可。

---

```cpp
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int N=100005;
int n,m;
int fa[N],siz[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    else return fa[v]=getf(fa[v]);
}
set<pair<int,int>>to[N],from[N];
long long ans;
void del(set<pair<int,int>> &S,int x)
{
    while(true)
    {
        set<pair<int,int>>::iterator it=S.lower_bound({x,0});
        if(it==S.end()||it->first!=x) break;
        S.erase(it);
    }
    return;
}
bool find(set<pair<int,int>> &S,int x)
{
    set<pair<int,int>>::iterator it=S.lower_bound({x,0});
    return it!=S.end()&&it->first==x;
}
void merge(int u,int v)
{
    if(getf(u)==getf(v)) return;
    if(from[u].size()+to[u].size()<from[v].size()+to[v].size()) swap(u,v);
    ans-=1LL*siz[u]*(siz[u]-1);
    ans-=1LL*siz[v]*(siz[v]-1);
    ans-=1LL*from[u].size()*siz[u]; 
    ans-=1LL*from[v].size()*siz[v];
    siz[u]+=siz[v],siz[v]=0;
    fa[v]=u;
    del(from[u],v);
    del(from[v],u);
    set<int>pos;
    for(auto it:from[v])
    {
        int x=it.first,y=it.second;
        to[x].erase(to[x].find({v,y}));
        to[x].insert({u,y});
        from[u].insert(it);
        if(find(to[u],x)) pos.insert(x);
    }
    ans+=1LL*from[u].size()*siz[u];
    from[v].clear();
    del(to[u],v);
    del(to[v],u);
    for(auto it:to[v])
    {
        int x=it.first,y=it.second;
        from[x].erase(from[x].find({v,y}));
        from[x].insert({u,y});
        to[u].insert(it);
        if(find(from[u],x)) pos.insert(x);
    }
    to[v].clear();
    ans+=1LL*siz[u]*(siz[u]-1);
    for(int x:pos)
        merge(x,u);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        fa[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int u=getf(a),v=getf(b);
        if(u!=v)
        {
            if(to[u].find({v,a})==to[u].end()) ans+=siz[v];
            to[u].insert({v,a}),from[v].insert({u,a});
            if(from[u].lower_bound({v,0})!=from[u].end()&&from[u].lower_bound({v,0})->first==v) merge(u,v);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
```

---

#### 最古の遺跡 3 / Ruins 3

可以看 dy 的题解：https://www.cnblogs.com/dysyn1314/p/12877113.html

---

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=605;
const int MOD=1000000007;
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=1LL*res*a%MOD;
        a=1LL*a*a%MOD,b>>=1; 
    }
    return res;
}
int getinv(int x)
{
    return ksm(x,MOD-2);
}
int n;
int a[N];
bool c[N*2];
int suf0[N*2],suf1[N*2];
int C[N][N];
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD; 
    }
    return;
}
int g[N][N];
int f[N*2][N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        c[a[i]]=true;
    for(int i=n*2;i>=1;i--)
        suf1[i]=suf1[i+1]+c[i],suf0[i]=suf0[i+1]+(!c[i]);
    init(n);
    g[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
        {
            g[i][j]=g[i-1][j];
            if(j-1>=0) g[i][j]=(g[i][j]+1LL*g[i-1][j-1]*j%MOD*2)%MOD;
            if(j-2>=0) g[i][j]=(g[i][j]+1LL*g[i-1][j-2]*(j-1)%MOD*j)%MOD;
        }
    f[n*2+1][0]=1;
    for(int i=n*2;i>=1;i--)
        if(c[i])
        {
            for(int j=0;j<=suf1[i+1];j++)
            {
                f[i][j]=(f[i][j]+f[i+1][j])%MOD; 
                for(int k=1;k-1<=suf1[i+1]-j;k++)
                    f[i][j+k]=(f[i][j+k]+1LL*f[i+1][j]*(k+1)%MOD*C[suf1[i+1]-j][k-1]%MOD*g[k-1][k-1])%MOD;
            }
        }
        else
        {
            for(int j=suf0[i+1];j<=suf1[i+1];j++)
                f[i][j]=(f[i][j]+1LL*f[i+1][j]*(j-suf0[i+1]))%MOD;
        }
    int ans=1LL*f[1][n]*getinv(ksm(2,n))%MOD;
    printf("%d",ans);
    return 0;
}
```

---

#### 星座 3 / Constellation 3

现将问题转化成保留的点权值最大。

对于每栋楼建出笛卡尔树，可以发现，对于某个笛卡尔树上的节点 $u$，在它所代表的区间和 $[a_u+1,n]$ 最多有一颗星星。

令 $f_{u,i}$ 表示当前节点为 $u$，它上方的那个星星的纵坐标为 $i$ 的最大权值和，$g_u$ 表示它上方没有星星的最大权值和，直接转移。

线段树合并优化一波即可。

---

```cpp
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
```

---

