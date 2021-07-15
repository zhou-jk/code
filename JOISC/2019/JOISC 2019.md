#### 試験 / Examination

直接三维偏序。

---

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=100005;
int n,Q;
int v[N*6],cnt;
struct Query
{
    int a,b,c;
    int v,id;
}q[N*2];
int tot;
int id[N*2];
struct BIT
{
    int C[N*6];
    BIT()
    {
        memset(C,0,sizeof(C));
        return;
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void add(int x,int y)
    {
        for(int i=x;i<=cnt;i+=lowbit(i))
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
    int query(int l,int r)
    {
        return getsum(r)-getsum(l-1);
    }
}T;
int ans[N];
void solve(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)/2;
    solve(l,mid);
    solve(mid+1,r);
    static int idl[N*2],totl;
    static int idr[N*2],totr;
    totl=0,totr=0;
    for(int i=l;i<=mid;i++)
        idl[++totl]=id[i];
    for(int i=mid+1;i<=r;i++)
        idr[++totr]=id[i];
    sort(idl+1,idl+totl+1,[=](const int &x,const int &y){return q[x].b>q[y].b;});
    sort(idr+1,idr+totr+1,[=](const int &x,const int &y){return q[x].b>q[y].b;});
    int i=0;
    for(int j=1;j<=totr;j++)
    {
        while(i+1<=totl&&q[idl[i+1]].b>=q[idr[j]].b) T.add(q[idl[i+1]].c,q[idl[i+1]].v),i++;
        if(q[idr[j]].id) ans[q[idr[j]].id]+=T.query(q[idr[j]].c,cnt);
    }
    for(int k=1;k<=i;k++)
        T.add(q[idl[k]].c,-q[idl[k]].v);
    return;
}
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        v[++cnt]=s,v[++cnt]=t,v[++cnt]=s+t;
        q[++tot]={s,t,s+t,1,0};
    }
    for(int i=1;i<=Q;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        v[++cnt]=a,v[++cnt]=b,v[++cnt]=c;
        q[++tot]={a,b,c,0,i};
    }
    sort(v+1,v+cnt+1);
    cnt=unique(v+1,v+cnt+1)-v-1;
    for(int i=1;i<=tot;i++)
    {
        q[i].a=lower_bound(v+1,v+cnt+1,q[i].a)-v;
        q[i].b=lower_bound(v+1,v+cnt+1,q[i].b)-v;
        q[i].c=lower_bound(v+1,v+cnt+1,q[i].c)-v;
    }
    iota(id+1,id+tot+1,1);
    sort(id+1,id+tot+1,[=](const int &x,const int &y)
    {
        if(q[x].a!=q[y].a) return q[x].a>q[y].a;
        if(q[x].b!=q[y].b) return q[x].b>q[y].b;
        if(q[x].c!=q[y].c) return q[x].c>q[y].c;
        return q[x].id<q[y].id;
    });
    solve(1,tot);
    for(int i=tot-1;i>=1;i--)
        if(q[id[i]].a==q[id[i+1]].a&&q[id[i]].b==q[id[i+1]].b&&q[id[i]].c==q[id[i+1]].c)
        {
            if(q[id[i]].id&&q[id[i+1]].id) ans[q[id[i]].id]=ans[q[id[i+1]].id];
        }
    for(int i=1;i<=Q;i++)
        printf("%d\n",ans[i]);
    return 0;
}
```

---

#### ビーバーの会合 / Meetings

可以发现 $\operatorname{Query}(x,y,z)$ 返回的是 $x,y,z$ 的 LCA 中深度最大的那个。

不妨令当前根节点为 $x$，我们在 $x$ 的子树中随机出一个点 $y$，然后对于 $x$ 的子树中的所有点 $z$ 分别进行询问 $(x,y,z)$，这样可以确定出 $z$ 是否在 $y$ 的链上，或者是在 $x\to y$ 的链上某个点的子树内。

对于链上的点我们可以用一次询问比较某两个的深度，直接排序下就好了。

对于在 $x\to y$ 的链上某个点的子树内的点递归解决即可。

---

```cpp
#include"meetings.h"
#include<iostream>
#include<cstdio>
#include<ctime>
#include<random>
#include<numeric>
#include<functional>
#include<algorithm>
using namespace std;
void Solve(int n)
{
    mt19937 rnd((unsigned)time(NULL));
    function<int(int,int)>rand=[&](int l,int r)
    {
        return rnd()%(r-l+1)+l;
    };
    function<void(int,const vector<int> &)>divide=[&](int x,const vector<int> &node)
    {
        if(node.size()==1)
        {
            if(x<node[0]) Bridge(x,node[0]);
            else Bridge(node[0],x);
            return;
        }
        vector<int>p=node;
        shuffle(p.begin(),p.end(),rnd);
        vector<int>id(n);
        for(int i=0;i<(int)p.size();i++)
            id[p[i]]=i;
        vector<vector<int>>son(p.size()+1);
        int y=p[0];
        vector<int>pos;
        for(int i=1;i<(int)p.size();i++)
        {
            int z=p[i];
            int l=Query(x,y,z);
            if(l!=z)
            {
                if(l==x) son.back().emplace_back(z);
                else son[id[l]].emplace_back(z);
            }
            else pos.emplace_back(z);
        }
        pos.emplace_back(y);
        for(int i=0;i<(int)p.size();i++)
            if(!son[i].empty()) divide(p[i],son[i]);
        if(!son.back().empty()) divide(x,son.back());
        sort(pos.begin(),pos.end(),[=](const int &a,const int &b){return Query(a,b,x)==a;});
        for(int i=0;i<(int)pos.size();i++)
            if(i==0)
            {
                if(pos[i]<x) Bridge(pos[i],x);
                else Bridge(x,pos[i]);
            }
            else
            {
                if(pos[i]<pos[i-1]) Bridge(pos[i],pos[i-1]);
                else Bridge(pos[i-1],pos[i]);
            }
        return;
    };
    int rt=rand(0,n-1);
    vector<int>pos;
    for(int i=0;i<n;i++)
        if(rt!=i) pos.emplace_back(i);
    divide(rt,pos);
    return;
}
```

---

#### ナン / Naan

我们可以对每个人求出他的快乐度的 $n$ 等分点的位置。第 $i$ 次找到还没有确定位置的人里面第 $i$ 个分割点最小的人，把他放在第 $i$ 个。这样子每个人拿到的段的右端点都是他的一个等分点，但左端点一定小于等于上一个等分点，所以一定满足条件。

---

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2005;
const int INF=1061109567;
int n,m;
int v[N][N]; 
struct Factor
{
    long long p,q;
    bool operator < (const Factor &b)const
    {
        return (long double)p/q<(long double)b.p/b.q;
    }
}pos[N][N];
bool vis[N];
Factor x[N];
int p[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&v[i][j]);
    for(int i=1;i<=n;i++)
    {
        long long sum=0;
        for(int j=1;j<=m;j++)
            sum+=v[i][j];
        long long now=0;
        long double avg=(long double)sum/n;
        for(int j=1,k=1;j<=n;j++)
        {
            while(k<m&&(long double)(now+v[i][k])/j<avg) now+=v[i][k],k++;
            pos[i][j]=(Factor){1LL*n*v[i][k]*(k-1)+sum*j-now*n,1LL*n*v[i][k]};
        }
    }
    for(int j=1;j<=n;j++)
    {
        int a=0;
        pos[a][j]=(Factor){INF,1};
        for(int i=1;i<=n;i++)
            if(!vis[i])
            {
                if(pos[i][j]<pos[a][j]) a=i;
            }
        vis[a]=true;
        x[j]=pos[a][j];
        p[j]=a;
    }
    for(int i=1;i<=n-1;i++)
        printf("%lld %lld\n",x[i].p,x[i].q);
    for(int i=1;i<=n;i++)
        printf("%d ",p[i]);
    return 0; 
}
```

---

#### ふたつのアンテナ / Two Antennas

不妨令 $i\lt j,h_i\gt h_j$，$h_i\le h_j$ 的情况同理。

考虑扫描线，把询问离线，将 $h_i$ 在 $i+a_i$ 的时候加入，$i+b_i+1$ 时删除。

定义 $c_i$，如果 $h_i$ 被加入，则 $c_i=h_i$，否则 $c_i=-\infty$。

令 $d_i$ 表示包含 $i$ 的天线对的最大代价，考虑加入某个 $j$ 相当于是将 $[j-b_i,j-a_i]$ 的 $d_i$ 对 $c_i-h_j$ 取 $\max$，询问相当于是询问一段区间的 $\max$。

---

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,Q;
int h[N],a[N],b[N];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        int minc;
        int maxc,maxd;
        int tagmin,tagmax;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].minc=min(tree[i*2].minc,tree[i*2+1].minc);
        tree[i].maxc=max(tree[i*2].maxc,tree[i*2+1].maxc);
        tree[i].maxd=max(tree[i*2].maxd,tree[i*2+1].maxd);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tagmin=INF,tree[i].tagmax=-INF;
        if(l==r)
        {
            tree[i].minc=INF;
            tree[i].maxc=-INF;
            tree[i].maxd=-INF;
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void add(int i,int h)
    {
        if(tree[i].minc!=INF) tree[i].maxd=max(tree[i].maxd,-tree[i].minc+h);
        if(tree[i].maxc!=-INF) tree[i].maxd=max(tree[i].maxd,tree[i].maxc-h);
        tree[i].tagmin=min(tree[i].tagmin,h);
        tree[i].tagmax=max(tree[i].tagmax,h);
        return;
    }
    void push_down(int i)
    {
        if(tree[i].tagmin!=INF)
        {
            add(i*2,tree[i].tagmin);
            add(i*2+1,tree[i].tagmin);
            tree[i].tagmin=INF;
        }
        if(tree[i].tagmax!=-INF)
        {
            add(i*2,tree[i].tagmax);
            add(i*2+1,tree[i].tagmax);
            tree[i].tagmax=-INF;
        }
        return;
    }
    void modify(int i,int l,int r,int h)
    {
        if(l>r) return;
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,h);
        push_down(i);
        if(l<=tree[i*2].r) modify(i*2,l,r,h);
        if(r>=tree[i*2+1].l) modify(i*2+1,l,r,h);
        push_up(i);
        return;
    }
    void modify(int i,int u,int c)
    {
        if(tree[i].l==tree[i].r)
        {
            if(c==0) tree[i].minc=INF,tree[i].maxc=-INF;
            else tree[i].minc=tree[i].maxc=c;
            return;
        }
        push_down(i);
        if(u<=tree[i*2].r) modify(i*2,u,c);
        else modify(i*2+1,u,c);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].maxd;
        push_down(i);
        int res=-INF;
        if(l<=tree[i*2].r) res=max(res,query(i*2,l,r));
        if(r>=tree[i*2+1].l) res=max(res,query(i*2+1,l,r));
        return res;
    }
}T;
vector<pair<int,int>>q[N];
vector<pair<int,int>>pos[N];
int ans[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&h[i],&a[i],&b[i]);
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        q[r].emplace_back(l,i);
    }
    for(int i=1;i<=n;i++)
    {
        if(i+a[i]<=n) pos[i+a[i]].emplace_back(i,h[i]);
        if(i+b[i]+1<=n) pos[i+b[i]+1].emplace_back(i,0);
    }
    T.build(1,1,n);
    for(int j=1;j<=n;j++)
    {
        for(auto [i,hi]:pos[j])
            T.modify(1,i,hi);
        if(j-a[j]>=1) T.modify(1,j-b[j],j-a[j],h[j]);
        for(auto [l,i]:q[j])
            ans[i]=T.query(1,l,j);
    }
    for(int i=1;i<=Q;i++)
        if(ans[i]<=-INF) printf("-1\n");
        else printf("%d\n",ans[i]);
    return 0;
}
```

---

#### ふたつの料理 / Two Dishes

令 $y_i=\max\left\{j\mid \left(\sum\limits_{k=1}^ia_k+\sum\limits_{k=1}^jb_k\right)\le s_i\right\}$，$x_j=\max\left\{i|\left(\sum\limits_{k=1}^ia_k+\sum\limits_{k=1}^jb_k\right)\le t_j\right\}$。

可以把做菜看做是在一个在 $(n+1)\times (m+1)$ 方格图上从 $(0,0)$ 走到 $(n,m)$，每次可以向上走或向右走一格，每走相当于做了一道菜。

可以发现，当 $(i,y_i)$ 在路径的上方或者在路径上时，可以产生 $p_i$ 的贡献。当 $(x_j,j)$ 在路径的下方或者在路径上时，可以产生 $q_j$ 的贡献。

这样的贡献比较难处理，一个点 $(x,y)$ 不在路径的上方或在路径上当且仅当 $(x+1,y−1)$ 在路径的下方或在路径上，我们可以将问题转化成求 $(0,0)$ 到 $(n,m)$ 经过的路径下方以及路径上的点的最大权值和。令 $f_{i,j}$ 表示从 $(0,0)$ 走到 $(i,j)$ 路径下方以及路径上的点的最大权值和，令 $sum_{i,j}$ 表示第 $j$ 列在 $(i,j)$ 下面的点的权值和。转移为：

$$f_{i,j}=\max(f_{i,j-1},f_{i-1,j}+sum_{i,j})$$

这个 DP 其实在做这样一件事情，先进行后缀加上某些数，然后在做一遍前缀和。考虑维护 DP 的差分数组，每次修改变成了单点加，做一遍前缀最大值相当于是将差分数组中的负数和后面的正数相抵，用 `std::set` 维护一下就好了。

---

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int N=2000005;
int n,m;
int a[N];
long long s[N];
int p[N];
int b[N];
long long t[N];
int q[N];
int x[N],y[N];
long long suma[N],sumb[N];
struct Seg
{
    int x,y,v;
}seg[N];
int cnt;
long long val[N];
set<pair<int,long long>>S;
long long f[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%lld%d",&a[i],&s[i],&p[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%lld%d",&b[i],&t[i],&q[i]);
    for(int i=1;i<=n;i++)
        suma[i]=suma[i-1]+a[i];
    for(int i=1;i<=m;i++)
        sumb[i]=sumb[i-1]+b[i];
    for(int i=1;i<=n;i++)
        y[i]=upper_bound(sumb,sumb+m+1,s[i]-suma[i])-sumb-1;
    for(int j=1;j<=m;j++)
        x[j]=upper_bound(suma,suma+n+1,t[j]-sumb[j])-suma-1;
    for(int i=1;i<=n;i++)
        if(i-1>=0&&y[i]+1<=m) seg[++cnt]=(Seg){i-1,y[i]+1,-p[i]};
    for(int j=1;j<=m;j++)
        if(x[j]>=0&&j<=m) seg[++cnt]=(Seg){x[j],j,q[j]};
    sort(seg+1,seg+cnt+1,[=](const Seg &a,const Seg &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
    int j=1;
    for(int i=1;i<=n;i++)
    {
        vector<int>pos;
        long long add=0;
        while(j<=cnt&&seg[j].x==i-1)
        {
            if(seg[j].y==0) add+=seg[j].v;
            else
            {
                auto it=S.find({seg[j].y,val[seg[j].y]});
                if(it!=S.end()) S.erase(it);
                pos.push_back(seg[j].y),val[seg[j].y]+=seg[j].v;
                if(val[seg[j].y]!=0) S.insert({seg[j].y,val[seg[j].y]});
            }
            j++;
        }
        f[i]=f[i-1]+add;
        for(int y:pos)
            while(val[y]<0)
            {
                auto it=S.upper_bound({y,val[y]});
                if(it==S.end())
                {
                    S.erase(S.find({y,val[y]}));
                    val[y]=0;
                    continue;
                }
                int u=it->first;
                S.erase(it);
                if(val[u]<0)
                {
                    val[u]+=val[y];
                    if(val[u]!=0) S.insert({u,val[u]});
                    S.erase({y,val[y]});
                    val[y]=0;
                }
                else
                {
                    long long tmp=val[y];
                    long long d=min(-val[y],val[u]);
                    val[y]+=d,val[u]-=d;
                    if(val[u]!=0) S.insert({u,val[u]});
                    S.erase(S.find({y,tmp}));
                    if(val[y]!=0) S.insert({y,val[y]});
                }
            }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        ans+=p[i];
    ans+=f[n];
    while(j<=cnt&&seg[j].x==n)
        ans+=seg[j].v,j++;
    for(auto [y,v]:S)
        ans+=v;
    printf("%lld",ans);
    return 0;
}
```

---

#### ふたつの交通機関 / Two Transportations

咕咕咕

---

#### 指定都市 / Designated Cities

不妨看做是免费的权值尽可能大。

$E_i=1$ 时可以直接换根 DP。

$E_i=2$ 时相当于是选两个点，这两个点路径上的边两种权值都免费，以其中一个点为根，剩下的边由儿子连向父亲的权值免费。

这里有一个结论，就是令 $S_i$ 表示选了 $i$ 个点作为关键点时最优方案点的集合，则 $S_i\in S_{i+1}$。所以可以每次贪心地选择贡献最大的点加入。

具体的，我们将 $E_i=2$ 时的一个点作为树的根，我们可以用线段树维护每个点的贡献大小，每次选择一个点后需要将它到根的路径上的边的权值的贡献去掉，因为每条边最多被去掉一次，所以可以暴力搞。

---

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,Q;
int h[N],a[N],b[N];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        int minc;
        int maxc,maxd;
        int tagmin,tagmax;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].minc=min(tree[i*2].minc,tree[i*2+1].minc);
        tree[i].maxc=max(tree[i*2].maxc,tree[i*2+1].maxc);
        tree[i].maxd=max(tree[i*2].maxd,tree[i*2+1].maxd);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        tree[i].tagmin=INF,tree[i].tagmax=-INF;
        if(l==r)
        {
            tree[i].minc=INF;
            tree[i].maxc=-INF;
            tree[i].maxd=-INF;
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void add(int i,int h)
    {
        if(tree[i].minc!=INF) tree[i].maxd=max(tree[i].maxd,-tree[i].minc+h);
        if(tree[i].maxc!=-INF) tree[i].maxd=max(tree[i].maxd,tree[i].maxc-h);
        tree[i].tagmin=min(tree[i].tagmin,h);
        tree[i].tagmax=max(tree[i].tagmax,h);
        return;
    }
    void push_down(int i)
    {
        if(tree[i].tagmin!=INF)
        {
            add(i*2,tree[i].tagmin);
            add(i*2+1,tree[i].tagmin);
            tree[i].tagmin=INF;
        }
        if(tree[i].tagmax!=-INF)
        {
            add(i*2,tree[i].tagmax);
            add(i*2+1,tree[i].tagmax);
            tree[i].tagmax=-INF;
        }
        return;
    }
    void modify(int i,int l,int r,int h)
    {
        if(l>r) return;
        if(l<=tree[i].l&&tree[i].r<=r) return add(i,h);
        push_down(i);
        if(l<=tree[i*2].r) modify(i*2,l,r,h);
        if(r>=tree[i*2+1].l) modify(i*2+1,l,r,h);
        push_up(i);
        return;
    }
    void modify(int i,int u,int c)
    {
        if(tree[i].l==tree[i].r)
        {
            if(c==0) tree[i].minc=INF,tree[i].maxc=-INF;
            else tree[i].minc=tree[i].maxc=c;
            return;
        }
        push_down(i);
        if(u<=tree[i*2].r) modify(i*2,u,c);
        else modify(i*2+1,u,c);
        push_up(i);
        return;
    }
    int query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].maxd;
        push_down(i);
        int res=-INF;
        if(l<=tree[i*2].r) res=max(res,query(i*2,l,r));
        if(r>=tree[i*2+1].l) res=max(res,query(i*2+1,l,r));
        return res;
    }
}T;
vector<pair<int,int>>q[N];
vector<pair<int,int>>pos[N];
int ans[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&h[i],&a[i],&b[i]);
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        q[r].emplace_back(l,i);
    }
    for(int i=1;i<=n;i++)
    {
        if(i+a[i]<=n) pos[i+a[i]].emplace_back(i,h[i]);
        if(i+b[i]+1<=n) pos[i+b[i]+1].emplace_back(i,0);
    }
    T.build(1,1,n);
    for(int j=1;j<=n;j++)
    {
        for(auto [i,hi]:pos[j])
            T.modify(1,i,hi);
        if(j-a[j]>=1) T.modify(1,j-b[j],j-a[j],h[j]);
        for(auto [l,i]:q[j])
            ans[i]=T.query(1,l,j);
    }
    for(int i=1;i<=Q;i++)
        if(ans[i]<=-INF) printf("-1\n");
        else printf("%d\n",ans[i]);
    return 0;
}
```

---

#### ランプ / Lamps

可以发现，一个点不会被两个赋值操作同时覆盖，也就是说一个点最多被覆盖两次。

如果只有翻转操作，令起始序列和目标序列分别为 $a,b$，则答案为 $a\oplus b$ 的极长 $1$ 段的个数。

所以我们只考虑赋值操作，在加上翻转操作的次数就可以了。令 $f_{i,j,0/1,0/1}$ 表示到第 $i$ 位，$a_i\oplus b_i=j$，是否有赋值为 $0$ 的操作，是否有赋值为 $1$ 的操作，直接转移即可。

---

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000005;
const int INF=1061109567;
int n;
char s[N],t[N];
int a[N],b[N];
int f[N][2][2][2];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%s",t+1);
    for(int i=1;i<=n;i++)
        a[i]=s[i]-'0',b[i]=t[i]-'0';
    memset(f,63,sizeof(f));
    f[0][0][0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=1;j++)
            for(int k=0;k<=1;k++)
                for(int l=0;l<=1;l++)
                    if(f[i-1][j][k][l]<INF)
                    {
                        int d;
                        d=b[i]==0;
                        f[i][d][1][0]=min(f[i][d][1][0],f[i-1][j][k][l]+(d&&j==0)+(k==0));
                        d=b[i]==1;
                        f[i][d][0][1]=min(f[i][d][0][1],f[i-1][j][k][l]+(d&&j==0)+(l==0));
                        d=a[i]!=b[i];
                        f[i][d][0][0]=min(f[i][d][0][0],f[i-1][j][k][l]+(d&&j==0));
                    }
    int ans=INF;
    for(int j=0;j<=1;j++)
        for(int k=0;k<=1;k++)
            for(int l=0;l<=1;l++)
                ans=min(ans,f[n][j][k][l]);
    printf("%d",ans);
    return 0;
}
```

---

#### 時をかけるビ太郎 / Bitaro, who Leaps through Time

不妨令 $a\lt c$，$a\gt c$ 的情况同理。

首先可以令第 $i$ 条道路的 $l_i=l_i-(i-1),r_i=r_i-i$，询问的时候同样减去，问题就变成了第 $i$ 条道路需要在 $[l_i,r_i]$ 的时刻进入，经过一条道路不需要时间。

可以发现一个性质，如果一段区间内的 $\max\{l_i\}\gt \min\{r_i\}$，那么这条路径就是唯一的。

我们可以维护一个四元组 $(op,L,R,w)$ 表示这个四元组代表的区间的最小路径是否唯一，如果唯一则 $L,R$ 表示从 $L$ 进入，$R$ 出来的最小代价为 $w$，不唯一则从 $[L,R]$ 进入代价都是 $w$。

可以分类讨论合并这个东西，可以发现这是满足结合律的，可以用线段树维护。

---


```cpp
#include<iostream>
#include<cstdio>
#include<tuple>
#include<algorithm>
using namespace std;
const int N=300005;
int n,Q;
int L[N],R[N];
tuple<bool,int,int,long long>merge(const tuple<bool,int,int,long long> &a,const tuple<bool,int,int,long long> &b)
{
    auto [ba,la,ra,wa]=a;
    auto [bb,lb,rb,wb]=b;
    if(ba&&bb) return {true,la,rb,wa+wb+max(ra-lb,0)};
    else if(ba)
    {
        if(lb<=ra&&ra<=rb) return {true,la,ra,wa+wb};
        else if(ra<lb) return {true,la,lb,wa+wb};
        else return {true,la,rb,wa+wb+ra-rb};
    }
    else if(bb)
    {
        if(la<=lb&&lb<=ra) return {true,lb,rb,wa+wb};
        else if(ra<lb) return {true,ra,rb,wa+wb};
        else return {true,la,rb,wa+wb+la-lb};
    }
    else
    {
        int L=max(la,lb),R=min(ra,rb);
        if(L<=R) return {false,L,R,wa+wb};
        else if(ra<lb) return {true,ra,lb,wa+wb};
        else return {true,la,rb,wa+wb+la-rb};
    }
}
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        tuple<bool,int,int,long long>w;
    }tree[N<<2];
    void push_up(int i)
    {
        tree[i].w=merge(tree[i*2].w,tree[i*2+1].w);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].w={false,L[l],R[l],0};
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,int L,int R)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].w={false,L,R,0};
            return;
        }
        if(u<=tree[i*2].r) modify(i*2,u,L,R);
        else modify(i*2+1,u,L,R);
        push_up(i);
        return;
    }
    tuple<bool,int,int,long long>query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].w;
        if(r<=tree[i*2].r) return query(i*2,l,r);
        else if(l>=tree[i*2+1].l) return query(i*2+1,l,r);
        else return merge(query(i*2,l,r),query(i*2+1,l,r));
    }
}T1,T2;
int main()
{
    scanf("%d%d",&n,&Q);
    if(n==1)
    {
        while(Q--)
        {
            int t;
            scanf("%d",&t);
            if(t==2)
            {
                int a,b,c,d;
                scanf("%d%d%d%d",&a,&b,&c,&d);
                if(a==c) printf("%d\n",max(b-d,0));
            }
        }
        return 0;
    }
    for(int i=1;i<n;i++)
        scanf("%d%d",&L[i],&R[i]);
    for(int i=1;i<n;i++)
        L[i]-=i-1,R[i]-=i;
    T1.build(1,1,n-1);
    for(int i=1;i<n;i++)
        L[i]+=i-1,R[i]+=i;
    reverse(L+1,L+n);
    reverse(R+1,R+n);
    for(int i=1;i<n;i++)
        L[i]-=i-1,R[i]-=i;
    T2.build(1,1,n-1);
    while(Q--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int p,s,e;
            scanf("%d%d%d",&p,&s,&e);
            s-=p-1,e-=p;
            T1.modify(1,p,s,e);
            s+=p-1,e+=p;
            p=n-p;
            s-=p-1,e-=p;
            T2.modify(1,p,s,e);
        }
        else if(t==2)
        {
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a==c)
            {
                printf("%d\n",max(b-d,0));
                continue;
            }
            if(a<c)
            {
                b-=a-1,d-=c-1;
                auto [op,l,r,w]=merge(merge({false,b,b,0},T1.query(1,a,c-1)),{false,d,d,0});
                printf("%lld\n",w);
            }
            if(a>c)
            {
                a=n-a+1,c=n-c+1;
                b-=a-1,d-=c-1;
                auto [op,l,r,w]=merge(merge({false,b,b,0},T2.query(1,a,c-1)),{false,d,d,0});
                printf("%lld\n",w);
            }
        }
    }
    return 0;
}
```

---

#### ケーキの貼り合わせ / Cake 3

可以发现，对于一种选蛋糕的方案，它的最大美观程度为 $\sum\limits_{j=1}^M V_{k_j}-2\cdot \left(\max\limits_{j=1}^M C_{k_j}-\min\limits_{j=1}^M C_{k_{j+1}}\right)$。

考虑将蛋糕按照 $C_i$ 排序，相当于求一个区间使得前 $m$ 大的 $V$ 之和减 $2\cdot (C_r−C_l)$ 的权值之和最大。

可以发现对于 $l_1\lt l_2$，在右边加入一个新的点，$l_1$ 增加的权值肯定小于等于 $l_2$。换句话说，如果对于某一个 $r_1$，$l_2$ 比 $l_1$ 更优时，对于所有 $r\ge r_0$，$l_2$ 都比 $l_1$ 更优。

直接决策单调性优化，分治+主席树搞搞。

---

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
const long long INF=4557430888798830399;
int n,m;
int b[N],cnt;
struct Chairman_Tree
{
    struct Node
    {
        int ls,rs;
        int cnt;
        long long sum;
    }tree[N*22];
    int rt[N],tot;
    int new_node()
    {
        int now=++tot;
        tree[now].ls=tree[now].rs=0;
        tree[now].cnt=0;
        tree[now].sum=0;
        return now;
    }
    void push_up(int i)
    {
        tree[i].cnt=tree[tree[i].ls].cnt+tree[tree[i].rs].cnt;
        tree[i].sum=tree[tree[i].ls].sum+tree[tree[i].rs].sum;
        return;
    }
    void build(int &i,int l,int r)
    {
        if(!i) i=new_node();
        if(l==r) return;
        int mid=(l+r)/2;
        build(tree[i].ls,l,mid);
        build(tree[i].rs,mid+1,r);
        return;
    }
    int modify(int i,int l,int r,int u)
    {
        int now=new_node();
        tree[now]=tree[i];
        if(l==r)
        {
            tree[now].cnt++;
            tree[now].sum+=b[u];
            return now;
        }
        int mid=(l+r)/2;
        if(u<=mid) tree[now].ls=modify(tree[now].ls,l,mid,u);
        else tree[now].rs=modify(tree[now].rs,mid+1,r,u);
        push_up(now);
        return now;
    }
    long long query(int u,int v,int l,int r,int k)
    {
        if(l==r) return (long long)k*b[l];
        int mid=(l+r)/2;
        if(k<=tree[tree[v].rs].cnt-tree[tree[u].rs].cnt) return query(tree[u].rs,tree[v].rs,mid+1,r,k);
        else return tree[tree[v].rs].sum-tree[tree[u].rs].sum+query(tree[u].ls,tree[v].ls,l,mid,k-(tree[tree[v].rs].cnt-tree[tree[u].rs].cnt));
    }
}T;
struct Cake
{
    int v,c;
}a[N];
long long ans[N];
void solve(int l,int r,int L,int R)
{
    if(l==r)
    {
        ans[l]=-INF;
        for(int i=L;i+m-1<=l&&i<=R;i++)
            ans[l]=max(ans[l],T.query(T.rt[i-1],T.rt[l],1,cnt,m)-2LL*(a[l].c-a[i].c));
        return;
    }
    int mid=(l+r)/2;
    int k=0;
    ans[mid]=-INF;
    for(int i=L;i+m-1<=mid&&i<=R;i++)
    {
        long long v=T.query(T.rt[i-1],T.rt[mid],1,cnt,m)-2LL*(a[mid].c-a[i].c);
        if(v>ans[mid]) ans[mid]=v,k=i;
    }
    if(k==0)
    {
        for(int i=L;i<=mid;i++)
            ans[i]=-INF;
        solve(mid+1,r,k,R);
        return;
    }
    solve(l,mid,L,k);
    solve(mid+1,r,k,R);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].v,&a[i].c);
    sort(a+1,a+n+1,[=](const Cake &x,const Cake &y){return x.c<y.c;});
    for(int i=1;i<=n;i++)
        b[++cnt]=a[i].v;
    sort(b+1,b+cnt+1);
    cnt=unique(b+1,b+cnt+1)-b-1;
    for(int i=1;i<=n;i++)
        a[i].v=lower_bound(b+1,b+cnt+1,a[i].v)-b;
    T.build(T.rt[0],1,cnt);
    for(int i=1;i<=n;i++)
        T.rt[i]=T.modify(T.rt[i-1],1,cnt,a[i].v);
    solve(1,n,1,n);
    long long res=*max_element(ans+1,ans+n+1);
    printf("%lld",res);
    return 0;
}
```

---

#### 合併 / Mergers

一棵树满足条件当且仅当对于每条边，把这条边断掉形成的两个联通块中有属于同个洲的点。

我们可以先将属于同个洲的点两两路径上的点缩成一个点，树上就没有相同颜色的点了。每次可以把两个点路径上的边变成合法的，答案即为最小路径覆盖，令 $l$ 表示叶子个数，则答案为 $\lceil \frac{l}{2}\rceil$。

---

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=500005;
int n,k;
struct Edge
{
    int to,next;
}edge[N<<2];
int head[N],cnt=1;
void add_edge(int u,int v)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
int dfn[N],low[N],Index;
bool book[N<<2];
void tarjan(int u,int pre)
{
    dfn[u]=low[u]=++Index;
    for(int i=head[u];i;i=edge[i].next)
    {
        if((i^1)==pre) continue;
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v,i);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v]) book[i]=book[i^1]=true;
        }
        else low[u]=min(low[u],dfn[v]);
    }
    return;
}
vector<int> e[N];
int fa[N],d[N];
int getf(int v)
{
    if(v==fa[v]) return v;
    fa[v]=getf(fa[v]);
    return fa[v];
}
void merge(int u,int v)
{
    int f1=getf(u),f2=getf(v);
    if(f1!=f2) fa[f2]=f1;
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        e[x].push_back(i);
    }
    for(int i=1;i<=k;i++)
        for(int j=0;j<(int)e[i].size();j++)
            add_edge(e[i][j],e[i][(j+1)%e[i].size()]),add_edge(e[i][(j+1)%e[i].size()],e[i][j]);
    tarjan(1,0);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=edge[i].next)
        {
            if(book[i]) continue;
            int v=edge[i].to;
            merge(u,v);
        }
    for(int u=1;u<=n;u++)
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(getf(u)==getf(v)||u>=v) continue;
            d[getf(u)]++,d[getf(v)]++;
        }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(getf(i)==i&&d[i]==1) ans++;
    printf("%d",(ans+1)/2);
    return 0;
}
```

---

#### 鉱物 / Minerals

先将所有点分成两个集合，使得每一对点的两个点分别在不同的集合内。

考虑分治，每次把一个集合的一部分的点塞进去，然后询问另外一个集合中和塞进去的点匹配的点，将这个两个匹配的集合递归下去就好了。

可能需要卡卡常。

---

```cpp
#include"minerals.h"
#include<iostream>
#include<cstdio>
#include<vector>
#include<functional>
using namespace std;
void Solve(int n)
{
    function<bool(int)>Ask=[&](int x)
    {
        static int lst=0;
        int now=Query(x);
        bool f=lst!=now;
        lst=now;
        return f;
    };
    vector<int>a,b;
    for(int i=1;i<=2*n;i++)
        if(Ask(i)) a.emplace_back(i);
        else b.emplace_back(i);
    function<void(const vector<int> &,const vector<int> &,bool)>solve=[&](const vector<int> &l,const vector<int> &r,bool op)
    {
        if(l.size()==1&&r.size()==1)
        {
            Answer(l[0],r[0]);
            return;
        }
        else
        {
            int mid;
            if(!op) mid=(int)(r.size()/3);
            else mid=(int)(r.size()/3*2);
            mid=max(mid,1);
            vector<int>rl,rr;
            for(int i=0;i<mid;i++)
                rl.emplace_back(r[i]);
            for(int i=mid;i<(int)r.size();i++)
                rr.emplace_back(r[i]);
            vector<int>ll,lr;
            if(!op)
                for(int i=0;i<mid;i++)
                    Ask(r[i]);
            else
                for(int i=mid;i<(int)r.size();i++)
                    Ask(r[i]);
            for(int u:l)
            {
                if(ll.size()==rl.size())
                {
                    lr.emplace_back(u);
                    continue; 
                }
                if(lr.size()==rr.size())
                {
                    ll.emplace_back(u);
                    continue;
                }
                if(Ask(u)) lr.emplace_back(u);
                else ll.emplace_back(u);
            }
            solve(ll,rl,true);
            solve(lr,rr,false);
        }
        return;
    };
    solve(a,b,1);
    return;
}
```