#### A - Reachable Towns

现把城市按照 $x_i$ 排序将第一维去掉。

对于每个联通块，将单调栈将每个联通块中 $y_i$ 最小的那个存下来。每次新加入一个点 $i$ 相当于前面的 $\lt y_i$ 的位置合并成一个联通块。具体地，将单调栈中所有 $\lt y_i$ 的点弹出，并查集合并一下，加入弹出点里面 $y$ 最小的那个。

---

```cpp
#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int x[N],y[N];
int id[N];
struct Union_Set
{
    int n;
    int fa[N],siz[N];
    Union_Set(int _n=0)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            fa[i]=i,siz[i]=1;
        return;
    }
    void reset(int _n=0)
    {
        n=_n;
        for(int i=1;i<=n;i++)
            fa[i]=i,siz[i]=1;
        return;
    }
    int getf(int v)
    {
        if(v==fa[v]) return v;
        else return fa[v]=getf(fa[v]);
    }
    int getsize(int v)
    {
        return siz[getf(v)];
    }
    bool merge(int u,int v)
    {
        int f1=getf(u),f2=getf(v);
        if(f1!=f2)
        {
            fa[f2]=f1;
            siz[f1]+=siz[f2];
            return true;
        }
        else return false;
    }
}F;
stack<int>S;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        id[i]=i;
    sort(id+1,id+n+1,[=](const int &a,const int &b){return x[a]!=x[b]?x[a]<x[b]:y[a]<y[b];});
    F.reset(n);
    for(int i=1;i<=n;i++)
    {
        if(S.empty()||y[id[i]]<y[S.top()]) S.emplace(id[i]);
        else
        {
            int u=S.top();
            while(!S.empty()&&y[id[i]]>y[S.top()])
            {
                F.merge(id[i],S.top());
                S.pop();
            }
            S.emplace(u);
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",F.getsize(i));
    return 0;
}
```

---

#### B - Sum is Multiple

问题相当于是求最小的 $k$ 满足 $2n\mid k(k+1)$。

令 $n$ 的质因子集合为 $P_n$，$k$ 的质因子集合为 $P_k$，$k+1$ 的质因子集合为 $P_{k+1}$。则 $P_n \subseteq P_k \cup P_{k+1}$。

令 $A=\prod\limits_{x\in P_n\cap P_k}x,B=\prod\limits_{x\in P_n\cap P_{k+1}}x$，则有 $k=a\cdot A,k+1=b\cdot B$，故 $a\cdot A+1=b\cdot B$，即 $-a\cdot A+b\cdot B=1$。

枚举 $A,B$，exgcd 求出满足 $a\gt 0,b\gt 0$ 的最小 $a$ 即可。

---

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n;
long long ex_gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    long long d=ex_gcd(b,a%b,x,y);
    long long tmp=x;
    x=y,y=tmp-a/b*y;
    return d;
}
int main()
{
    scanf("%lld",&n);
    n=n*2; 
    long long res=n-1; 
    for(long long a=1;a*a<=n;a++)
        if(n%a==0)
        {
            long long b=n/a;
            if(__gcd(a,b)!=1) continue;
            long long x,y;
            long long d=ex_gcd(a,b,x,y);
            if(x>=0)
            {
                long long t=(x+b)/b;
                x-=t*b,y+=t*a;
            }
            if(y<=0)
            {
                long long t=(-y+b)/b;
                x-=t*b,y+=t*a;
            }
            res=min(res,-a*x);
            swap(a,b);
            d=ex_gcd(a,b,x,y);
            if(x>=0)
            {
                long long t=(x+b)/b;
                x-=t*b,y+=t*a;
            }
            if(y<=0)
            {
                long long t=(-y+b)/b;
                x-=t*b,y+=t*a;
            }
            res=min(res,-a*x);
            swap(a,b);
        }
    printf("%lld",res);
    return 0;
}
```

---

#### C - Moving Pieces

考虑网络流建图。

对于每个 `o`，连一条源点到这个点的流量为 $1$，费用为 $0$ 边。

对于每个 `.` 或者 `o`，如果右边的点不为 `#`，加入一条这个点到右边的点流量为 $\infty$，费用为 $1$ 的边，下边同理。

跑最大费用最大流即可。

---

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=505,M=100005;
const int INF=1061109567;
const long long LINF=4557430888798830399;
struct Edge
{
    int to,next;
    long long cost,flow;
}edge[M<<1];
int cur[N*N],head[N*N],cnt=1;
int S,T;
void add_edge(int u,int v,int f,int c)
{
    cnt++;
    edge[cnt].to=v;
    edge[cnt].flow=f;
    edge[cnt].cost=c;
    edge[cnt].next=head[u];
    head[u]=cnt;
    return;
}
void add(int u,int v,int f,int c)
{
    add_edge(u,v,f,c);
    add_edge(v,u,0,-c);
    return;
}
long long dis[N*N];
bool spfa()
{
    static bool vis[N*N];
    memset(vis,false,sizeof(vis));
    for(int i=0;i<N*N;i++)
        dis[i]=-LINF;
    queue<int>q;
    dis[S]=0;
    vis[S]=true;
    q.push(S);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].flow<=0) continue;
            if(dis[v]<dis[u]+edge[i].cost)
            {
                dis[v]=dis[u]+edge[i].cost;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return dis[T]!=-LINF;
}
bool book[N*N];
pair<long long,long long> dfs(int u,long long flow)
{
    if(u==T||flow==0) return make_pair(flow,0LL);
    book[u]=true;
    long long used=0,res=0;
    for(int &i=cur[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(book[v]||dis[v]!=dis[u]+edge[i].cost||edge[i].flow<=0) continue;
        pair<long long,long long>T=dfs(v,min(flow,edge[i].flow));
        long long now=T.first;
        res+=T.second+now*edge[i].cost;
        flow-=now;
        edge[i].flow-=now;
        edge[i^1].flow+=now;
        used+=now;
        if(flow==0) break;
    }
    book[u]=false;
    return make_pair(used,res);
}
pair<long long,long long> dinic()
{
    int flow=0,cost=0;
    while(spfa())
    {
        memcpy(cur,head,sizeof(head));
        pair<long long,long long> res=dfs(S,INF);
        flow+=res.first,cost+=res.second;
    }
    return make_pair(flow,cost);
}
int n,m;
char s[N][N];
int id[N][N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)  
        scanf("%s",s[i]+1);
    int tot=-1;
    S=++tot;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            id[i][j]=++tot;
    T=++tot;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]!='#')
            {
                if(i+1<=n&&s[i+1][j]!='#') add(id[i][j],id[i+1][j],INF,1);
                if(j+1<=n&&s[i][j+1]!='#') add(id[i][j],id[i][j+1],INF,1);
                if(s[i][j]=='o') add(S,id[i][j],1,0);
                add(id[i][j],T,1,0);
            }
    pair<long long,long long> ans=dinic();
    printf("%lld",ans.second);
    return 0;
}
```

---

#### D - Keep Distances

设 $a_1\lt a_2\lt \cdots \lt a_m$ 为一组字典序最小的解，$b_1\lt b_2\lt \cdots \lt b_m$ 为字典序最大的一组解。则 $a_1\le b_1\lt a_2\le b_2\lt a_3\le b_3\lt \cdots \lt a_m\le b_m$。

如果 $\exists i\in [1,m),b_i\ge a_{i+1}$，那么就存在 $(a_1,a_2,\cdots ,a_{i+1},b_{i+1},\cdots ,b_m)$ 的大小为 $m+1$ 的解，矛盾。

由 $b_{i+1}-b_i\ge k,a_{i+1}\le b_{i+1}$ 可得 $a_{i+1}-b_i\le k$。

可以发现步数最大的时候显然不会经过 $(b_i,a_{i+1})$，因为左边最多走 $i−1$，右边最多走 $m−i−1$，只能取到 $m-1$。

所以答案即为 $\sum\limits_{i=1}^m b_i-a_i+1=\sum\limits_{i=1}^mb_i-\sum\limits_{i=1}^m a_i+m$，倍增优化即可。

---

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=200005;
int n,k;
int x[N];
int Q;
int pre[N][20],nxt[N][20];
long long sp[N][20],sn[N][20];
void solve()
{
    int l,r;
    scanf("%d%d",&l,&r);
    int cnt=1;
    for(int i=log2(n),u=l;i>=0;i--)
        if(nxt[u][i]<=r) cnt+=1<<i,u=nxt[u][i];
    long long sum=cnt+r-l;
    for(int i=log2(n),u=l;i>=0;i--)
        if((cnt-1)&(1<<i)) sum-=sn[u][i],u=nxt[u][i];
    for(int i=log2(n),u=r;i>=0;i--)
        if((cnt-1)&(1<<i)) sum+=sp[u][i],u=pre[u][i];
    printf("%lld\n",sum);
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    pre[0][0]=0;
    for(int i=n,j=n;i>=1;i--)
    {
        while(j>=1&&x[i]-x[j]<k) j--;
        pre[i][0]=j;
    }
    nxt[n+1][0]=n+1;
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n&&x[j]-x[i]<k) j++;
        nxt[i][0]=j;
    }
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
            pre[i][j]=pre[pre[i][j-1]][j-1],nxt[i][j]=nxt[i][j-1]<=n?nxt[nxt[i][j-1]][j-1]:n+1;
    for(int i=1;i<=n;i++)
        sp[i][0]=pre[i][0],sn[i][0]=nxt[i][0];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
            sp[i][j]=sp[pre[i][j-1]][j-1]+sp[i][j-1],sn[i][j]=sn[nxt[i][j-1]][j-1]+sn[i][j-1];
    scanf("%d",&Q);
    while(Q--)
        solve();
    return 0;
}
```

---

#### E - Shuffle Window

问题可以转化成：

维护一个大小为 $k$ 的多重集 $S$，初始 $S=\{p_1,p_2....p_k\}$，对于每一个 $i\le n-k+1$，从 $S$ 中删去一个数，然后加入 $p_{i+k}$。最后乱排 $S$ 放入序列的最后 $k$ 个。

令 $f_i=\max(i-k,0)$ 表示最早加入集合的时间。

我们考虑计算 $i\lt j$ 的位置相对变化的概率。

设 $p=\frac{k-1}{k}$ 表示一个 $S$ 内的数活一轮的概率。

那么我们要先使 $i$ 存活到到 $j$ 加入 $S$ 的时候，总概率为 $p^{f_j-f_i}$。在 $i,j$ 同时在 $S$ 中的时候，有 $\frac{1}{2}$ 的概率先后顺序发生改变。

所以对于 $i\lt j$，最后发生位置相对变化的概率为 $\frac {p^{f_j-f_i}}{2}$。

对于 $j$，它的逆序对期望个数即为 $\sum\limits_{i=1}^{j-1} [a_i>a_j](1-\frac {p^{f_j-f_i}}2)+[a_i<a_j]\frac {p^{f_j-f_i}}2$。树状数组优化即可。

---

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
const int MOD=998244353;
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
int n,k;
int p[N];
int c[N],invc[N];
void init(int n=200000)
{
    int q=1LL*(k-1)*getinv(k)%MOD,invq=getinv(q);
    c[0]=invc[0]=1;
    for(int i=1;i<=n;i++)
        c[i]=1LL*c[i-1]*q%MOD,invc[i]=1LL*invc[i-1]*invq%MOD;
    return;
}
struct Binary_Indexed_Tree
{
    int C[N];
    Binary_Indexed_Tree()
    {
        memset(C,0,sizeof(C));
        return;
    }
    void clear()
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
        for(int i=x;i<=n;i+=lowbit(i))
            C[i]=(C[i]+y)%MOD;
        return;
    }
    int getsum(int x)
    {
        int res=0;
        for(int i=x;i>0;i-=lowbit(i))
            res=(res+C[i])%MOD;
        return res;
    }
    int query(int l,int r)
    {
        return ((long long)getsum(r)-getsum(l-1)+MOD)%MOD;
    }
}T,Tp;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    init();
    Tp.clear();
    int inv2=getinv(2);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int f=max(i-k,0);
        ans=(ans+1LL*c[f]*Tp.query(1,p[i]-1)%MOD*inv2%MOD+(T.query(p[i]+1,n)-1LL*c[f]*Tp.query(p[i]+1,n)%MOD*inv2%MOD+MOD)%MOD)%MOD;
        Tp.add(p[i],invc[f]);
        T.add(p[i],1);
    }
    printf("%d",ans);
    return 0;
}
```

---

#### F - Center Rearranging

首先可以将 $B$ 分成三段：第一段最后一次操作是移到左边，记为 `L`；第二段是没被动过的，将它们称为 `M`；第三段最后一次操作是移到右边，记为 `R`。

枚举分界点，则 $B$ 的来源序列也就相应确定了。对于每一种数，考虑它在 $B$ 中三个位置的来源。其中 `LLL` 和 `RRR` 显然是不可能的。可以发现，除了 `LMR` 之外，所有 `M` 的来源位置其实是确定的。

第一组

```plain
M** ***
LMR LLR 
```

第二组

```plain
**M ***
LMR LRR 
```

第三组

```plain
M** **M
MRR LLM
 
MMM
MMM
 
M*M M*M
LMM MMR
```

对于所有 `M`，在 $A$ 中原位置和 $B$ 中新位置连一条边，如果这些边不能相交则说明不合法。

对于第一组，`R` 的生成时间一定要比第一个 `L` 更早。对于第二组，`L` 的生成时间一定要比最后一个 `R` 更早。

对于第一组，第三个位置向第一个位置连一条边；对于第二组，第一个位置向第三个位置连一条边。右边的 `L` 元素向左边的 `L` 连边，左边的 `R` 向右边的 `R` 连边。这些边构成一个拓扑图。如果没有环就可以按照拓扑序做操作。

可以发现，如果这个图存在环，肯定是一个属于第一组的第一个和第三个位置都比另一个属于第二组的第一个和第三个位置更小。

`LMR` 的取值只有两种情况，可以用 two-sat 求解。

---

```cpp
#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
const int N=35;
const int INF=1061109567;
int n;
int a[N*3],b[N*3];
int p[N][2];
vector<int>posa[N],posb[N];
vector<int>G[N*2];
int dfn[N*2],low[N*2],Index;
bool vis[N*2];
int bel[N*2],tot;
stack<int>s;
void dfs(int u)
{
    dfn[u]=low[u]=++Index;
    vis[u]=true;
    s.emplace(u);
    for(int v:G[u])
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        tot++;
        while(s.top()!=u)
        {
            bel[s.top()]=tot;
            vis[s.top()]=false;
            s.pop();
        }
        bel[u]=tot;
        vis[u]=false;
        s.pop();
    }
    return;
}
bool circle(int l,int r)
{
    static int type[N];
    vector<pair<int,int>>match;
    for(int i=1;i<=n;i++)
    {
        auto gettype=[=](int p)
        {
            if(p<=l) return "L";
            else if(p>=r) return "R";
            else return "M";
        };
        type[i]=0;
        string Type=(string)gettype(posb[i][0])+gettype(posb[i][1])+gettype(posb[i][2]);
        if(Type=="LLL"||Type=="RRR") return false;
        if(Type=="LLR") type[i]=1;
        if(Type=="LRR") type[i]=2;
        if(Type=="LMR") type[i]=3;
        if(Type=="MMR") match.emplace_back(posa[i][0],posb[i][0]),match.emplace_back(posa[i][2],posb[i][1]);
        if(Type=="LMM") match.emplace_back(posa[i][0],posb[i][1]),match.emplace_back(posa[i][2],posb[i][2]);
        if(Type=="MMM") match.emplace_back(posa[i][0],posb[i][0]),match.emplace_back(posa[i][1],posb[i][1]),match.emplace_back(posa[i][2],posb[i][2]);
        if(Type=="LLM") match.emplace_back(posa[i][2],posb[i][2]);
        if(Type=="MRR") match.emplace_back(posa[i][0],posb[i][0]);
    }
    auto circle=[=](int a,int b){return posb[a][0]<posb[b][0]||posb[a][2]<posb[b][2];};
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(type[i]==1&&type[j]==2&&!circle(i,j)) return false;
    for(int i=1;i<=n*2;i++)
        dfn[i]=low[i]=bel[i]=0,vis[i]=false,G[i].clear();
    Index=tot=0;
    sort(match.begin(),match.end());
    for(size_t i=1;i<match.size();i++)
        if(match[i].second<match[i-1].second) return false;
    for(int i=1;i<=n;i++)
    {
        if(type[i]!=3) continue;
        bool f1=false,f2=false;
        auto cross=[=](int a,int b,int c,int d){return (a<c&&b>d)||(a>c&&b<d);};
        for(auto [a,b]:match)
        {
            if(cross(a,b,posa[i][0],posb[i][1])) f2=true;
            if(cross(a,b,posa[i][2],posb[i][1])) f1=true;
        }
        for(int j=1;j<=n;j++)
            if(type[j]==1)
            {
                if(!circle(j,i)) f1=true;
            }
            else if(type[j]==2)
            {
                if(!circle(i,j)) f2=true;
            }
            else if(i<j&&type[j]==3)
            {
                if(!circle(i,j)||cross(posa[i][0],posb[i][1],posa[j][2],posb[j][1])) G[p[i][1]].emplace_back(p[j][1]),G[p[j][0]].emplace_back(p[i][0]);
                if(!circle(j,i)||cross(posa[i][2],posb[i][1],posa[j][0],posb[j][1])) G[p[i][0]].emplace_back(p[j][0]),G[p[j][1]].emplace_back(p[i][1]);
                if(cross(posa[i][0],posb[i][1],posa[j][0],posb[j][1])) G[p[i][1]].emplace_back(p[j][0]),G[p[j][1]].emplace_back(p[i][0]);
                if(cross(posa[i][2],posb[i][1],posa[j][2],posb[j][1])) G[p[i][0]].emplace_back(p[j][1]),G[p[j][0]].emplace_back(p[i][1]);
            }
        if(f1&&f2) return false;
        if(f1) G[p[i][0]].emplace_back(p[i][1]);
        if(f2) G[p[i][1]].emplace_back(p[i][0]);
    }
    for(int i=1;i<=n*2;i++)
        if(!dfn[i]) dfs(i);
    for(int i=1;i<=n;i++)
        if(bel[i]==bel[i+n]) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=3*n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=3*n;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=3*n;i++)
        posa[a[i]].emplace_back(i),posb[b[i]].emplace_back(i);
    for(int i=1;i<=n;i++)
        p[i][0]=i,p[i][1]=i+n;
    int ans=INF;
    for(int i=0;i<=3*n;i++)
        for(int j=i+1;j<=3*n+1;j++)
            if(circle(i,j)) ans=min(ans,i+3*n-j+1);
    if(ans>=INF) printf("-1");
    else printf("%d",ans);
    return 0;
}
```