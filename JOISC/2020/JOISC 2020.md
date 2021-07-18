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

#### 