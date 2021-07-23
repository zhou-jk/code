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

阿拉丁题，具体可以看 zyy 的博客，不想写题解了。

---

```cpp
#include<iostream>
#include<cstdio>
#include<cassert>
#include<set>
#include<stack>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,k;
int l[N],d[N],r[N],u[N];
bool vis[N];
pair<int,int>p[5];
void dfs(int step)
{
    if(step>k)
    {
        for(int i=1;i<=n;i++)
            if(!vis[i]) return;
        for(int i=1;i<=k;i++)
            printf("%d %d\n",p[i].first,p[i].second);
        exit(0);
    }
    int maxl=0,minr=INF,maxd=0,minu=INF;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            maxl=max(maxl,l[i]);
            minr=min(minr,r[i]);
            maxd=max(maxd,d[i]);
            minu=min(minu,u[i]);
        }
    vector<int>pos;
    int x,y;
    x=maxl,y=maxd;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            if(l[i]<=x&&x<=r[i]&&d[i]<=y&&y<=u[i]) pos.emplace_back(i),vis[i]=true;
        }
    p[step]={x,y};
    dfs(step+1);
    for(int i:pos)
        vis[i]=false;
    x=maxl,y=minu;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            if(l[i]<=x&&x<=r[i]&&d[i]<=y&&y<=u[i]) pos.emplace_back(i),vis[i]=true;
        }
    p[step]={x,y};
    dfs(step+1);
    for(int i:pos)
        vis[i]=false;
    x=minr,y=maxd;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            if(l[i]<=x&&x<=r[i]&&d[i]<=y&&y<=u[i]) pos.emplace_back(i),vis[i]=true;
        }
    p[step]={x,y};
    dfs(step+1);
    for(int i:pos)
        vis[i]=false;
    x=minr,y=minu;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            if(l[i]<=x&&x<=r[i]&&d[i]<=y&&y<=u[i]) pos.emplace_back(i),vis[i]=true;
        }
    p[step]={x,y};
    dfs(step+1);
    for(int i:pos)
        vis[i]=false;
    return;
}
int c[N];
int id[N][2],cnt;
int pos[N][2];
vector<tuple<int,int,int,int>>L,R,D,U;
vector<int>G[N*10];
int dfn[N*10],low[N*10],Index;
int bel[N*10],tot;
void tarjan(int u)
{
    static bool vis[N*10];
    static stack<int>s;
    dfn[u]=low[u]=++Index;
    s.emplace(u);
    vis[u]=true;
    for(int v:G[u])
        if(!dfn[v])
        {
            tarjan(v);
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
int val[N];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&l[i],&d[i],&r[i],&u[i]);
    dfs(1);
    if(k==4)
    {
        int maxl=*max_element(l+1,l+n+1),minr=*min_element(r+1,r+n+1),maxd=*max_element(d+1,d+n+1),minu=*min_element(u+1,u+n+1);
        assert(minr<=maxl&&minu<=maxd);
        for(int i=1;i<=n;i++)
        {
            if(l[i]<=minr&&minr<=r[i]) c[i]++;
            if(l[i]<=maxl&&maxl<=r[i]) c[i]++;
            if(d[i]<=minu&&minu<=u[i]) c[i]++;
            if(d[i]<=maxd&&maxd<=u[i]) c[i]++;
            if(c[i]>=3) continue;
            assert(c[i]>0);
            id[i][0]=++cnt,id[i][1]=++cnt;
            if(c[i]==1)
            {
                G[id[i][1]].emplace_back(id[i][0]);
                if(l[i]<=minr&&minr<=r[i]) L.emplace_back(d[i],u[i],id[i][0],id[i][1]),pos[i][0]=1;
                else if(l[i]<=maxl&&maxl<=r[i]) R.emplace_back(d[i],u[i],id[i][0],id[i][1]),pos[i][0]=2;
                else if(d[i]<=minu&&minu<=u[i]) D.emplace_back(l[i],r[i],id[i][0],id[i][1]),pos[i][0]=3;
                else if(d[i]<=maxd&&maxd<=u[i]) U.emplace_back(l[i],r[i],id[i][0],id[i][1]),pos[i][0]=4;
                else assert(false);
            }
            if(c[i]==2)
            {
                for(int j=1;j<=4;j++)
                    for(int k=j+1;k<=4;k++)
                    {
                        bool fj=false;
                        if(j==1) fj=l[i]<=minr&&minr<=r[i];
                        else if(j==2) fj=l[i]<=maxl&&maxl<=r[i];
                        else if(j==3) fj=d[i]<=minu&&minu<=u[i];
                        else if(j==4) fj=d[i]<=maxd&&maxd<=u[i];
                        bool fk=false;
                        if(k==1) fk=l[i]<=minr&&minr<=r[i];
                        else if(k==2) fk=l[i]<=maxl&&maxl<=r[i];
                        else if(k==3) fk=d[i]<=minu&&minu<=u[i];
                        else if(k==4) fk=d[i]<=maxd&&maxd<=u[i];
                        if(fj&&fk)
                        {
                            if(j==1) L.emplace_back(d[i],u[i],id[i][0],id[i][1]),pos[i][0]=1;
                            else if(j==2) R.emplace_back(d[i],u[i],id[i][0],id[i][1]),pos[i][0]=2;
                            else if(j==3) D.emplace_back(l[i],r[i],id[i][0],id[i][1]),pos[i][0]=3;
                            else if(j==4) U.emplace_back(l[i],r[i],id[i][0],id[i][1]),pos[i][0]=4;
                            else assert(false);
                            if(k==1) L.emplace_back(d[i],u[i],id[i][1],id[i][0]),pos[i][1]=1;
                            else if(k==2) R.emplace_back(d[i],u[i],id[i][1],id[i][0]),pos[i][1]=2;
                            else if(k==3) D.emplace_back(l[i],r[i],id[i][1],id[i][0]),pos[i][1]=3;
                            else if(k==4) U.emplace_back(l[i],r[i],id[i][1],id[i][0]),pos[i][1]=4;
                            else assert(false);
                        }
                    }
            }
        }
        for(auto a:{L,R,D,U})
        {
            vector<int>to(a.size()),from(a.size());
            for(int i=0;i<(int)a.size();i++)
                to[i]=++cnt,from[i]=++cnt;
            sort(a.begin(),a.end(),[=](const tuple<int,int,int,int> &x,const tuple<int,int,int,int> &y){return get<1>(x)<get<1>(y);});
            for(int i=0;i<(int)a.size();i++)
            {
                G[to[i]].emplace_back(get<3>(a[i]));
                G[get<2>(a[i])].emplace_back(from[i]);
                if(i>0)
                {
                    G[to[i]].emplace_back(to[i-1]);
                    G[from[i-1]].emplace_back(from[i]);
                }
            }
            vector<int>posr(a.size());
            for(int i=0;i<(int)posr.size();i++)
                posr[i]=get<1>(a[i]);
            for(int i=0;i<(int)a.size();i++)
            {
                auto [li,ri,i1,i0]=a[i];
                if(i>0)
                {
                    int j=lower_bound(posr.begin(),posr.begin()+i,li)-posr.begin()-1;
                    if(j>=0)
                    {
                        G[i1].emplace_back(to[j]);
                        G[from[j]].emplace_back(i0);
                    }
                }
            }
        }
        for(int i=1;i<=cnt;i++)
            if(!dfn[i]) tarjan(i);
        for(int i=1;i<=n;i++)
            if(c[i]==1||c[i]==2) assert(bel[id[i][0]]!=bel[id[i][1]]);
        for(int i=1;i<=n;i++)
            if(c[i]==1||c[i]==2) val[i]=bel[id[i][1]]<bel[id[i][0]];
        int ld=0,lu=INF,rd=0,ru=INF;
        int dl=0,dr=INF,ul=0,ur=INF;
        for(int i=1;i<=n;i++)
            if(c[i]==1)
            {
                if(pos[i][0]==1) ld=max(ld,d[i]),lu=min(lu,u[i]);
                else if(pos[i][0]==2) rd=max(rd,d[i]),ru=min(ru,u[i]);
                else if(pos[i][0]==3) dl=max(dl,l[i]),dr=min(dr,r[i]);
                else if(pos[i][0]==4) ul=max(ul,l[i]),ur=min(ur,r[i]);
            }
            else if(c[i]==2)
            {
                if(pos[i][val[i]]==1) ld=max(ld,d[i]),lu=min(lu,u[i]);
                else if(pos[i][val[i]]==2) rd=max(rd,d[i]),ru=min(ru,u[i]);
                else if(pos[i][val[i]]==3) dl=max(dl,l[i]),dr=min(dr,r[i]);
                else if(pos[i][val[i]]==4) ul=max(ul,l[i]),ur=min(ur,r[i]);
            }
        assert(ld<=lu&&rd<=ru&&dl<=dr&&ul<=ur);
        printf("%d %d\n",minr,ld);
        printf("%d %d\n",maxl,rd);
        printf("%d %d\n",dl,minu);
        printf("%d %d",ul,maxd);
    }
    return 0;
}
```

---

#### 掃除 / Sweeping

又是阿拉丁题

---

#### カメレオンの恋 / Chameleon’s Love

对于两只变色龙，如果将他们两个开一次会议时只有一种颜色，只可能是一只变色龙和它喜欢的变色龙，一只变色龙和喜欢它的变色龙，一只变色龙和它颜色相同的变色龙。

将这两个点之间连边，如果两只变色龙相互喜欢，那么我们把他们之间的边删去，这样对答案是没有影响的。

那么这张图的点的度数要么是一要么是三，度数为一那些点和它颜色相同的点已经确定，剩下度数为三的点。

对于度数为三的点，我们可以将它和它相邻的两个点两两询问一下，如果这两个点分别为喜欢它的点和和它颜色相同的点，那么颜色只有一种，否则颜色为两种，重复这一过程直到找到它喜欢的点。通过这样，我们可以确定出所有它喜欢的点和喜欢它的点，剩下的那一个一定就是和它颜色相同的点。

问题在于如何确定图上的边，我们可以每次删去一个极大的独立集，每次找到剩下的点和独立集之间的边，递归处理剩下的点。因为这是一个二分图，所以复杂度是对的。

松一松就过了（

---

```cpp
#include"chameleon.h"
#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
#include<functional>
using namespace std;
void Solve(int n)
{
    function<vector<int>(const vector<int> &,int)>addback=[=](const vector<int> &p,int u)
    {
        vector<int>S=p;
        S.emplace_back(u);
        return S;
    };
    vector<int>deg(n*2+1);
    vector<vector<int>>G(n*2+1);
    function<void(const vector<int> &,int)>findedge=[&](const vector<int> &S,int u)
    {
        if(S.empty()) return;
        if(S.size()==1)
        {
            G[S[0]].emplace_back(u);
            G[u].emplace_back(S[0]);
            deg[u]++,deg[S[0]]++;
            return;
        }
        int mid=max((int)(S.size()/2.8),1);
        vector<int>l,r;
        for(int i=0;i<mid;i++)
            l.emplace_back(S[i]);
        for(int i=mid;i<(int)S.size();i++)
            r.emplace_back(S[i]);
        if(Query(addback(l,u))==(int)l.size()+1) return findedge(r,u);
        else if(Query(addback(r,u))==(int)r.size()+1) return findedge(l,u);
        else findedge(l,u),findedge(r,u);
        return;
    };
    function<void(const vector<int> &)> divide=[&](const vector<int> &p)
    {
        if(p.empty()) return;
        int lst=0;
        vector<int>S,ret;
        for(int u:p)
        {
            if(lst==0)
            {
                S.emplace_back(u),lst++;
                continue;
            }
            if(deg[u]==3) continue;
            bool flag=true;
            for(int v:S)
            {
                for(int t:G[u])
                    if(v==t)
                    {
                        flag=false;
                        break;
                    }
                if(!flag) break;
            }
            if(!flag) ret.emplace_back(u);
            else
            {
                int now=Query(addback(S,u));
                if(now>lst) S.emplace_back(u),lst=now;
                else ret.emplace_back(u);
            }
        }
        for(int u:ret)
        {
            findedge(S,u);
            vector<int>nxt;
            for(int v:S)
                if(deg[v]<3) nxt.emplace_back(v);
            S=nxt; 
        }
        divide(ret);
        return;
    };
    vector<int>S(n*2);
    iota(S.begin(),S.end(),1);
    divide(S);
    vector<int>to(n*2+1);
    for(int u=1;u<=n*2;u++)
        if(deg[u]==3)
        {
            if(Query({u,G[u][0],G[u][1]})==1) to[u]=G[u][2];
            else if(Query({u,G[u][0],G[u][2]})==1) to[u]=G[u][1];
            else to[u]=G[u][0];
        }
    vector<int>from(n*2+1);
    for(int u=1;u<=n*2;u++)
        if(deg[u]==3) from[to[u]]=u;
    vector<int>match(n*2+1);
    for(int u=1;u<=n*2;u++)
        if(!match[u])
        {
            if(deg[u]==1)
            {
                int v=G[u][0];
                match[u]=v;
                match[v]=u;
                Answer(u,v);
            }
            else if(deg[u]==3)
            {
                int v;
                if(G[u][0]!=from[u]&&G[u][0]!=to[u]) v=G[u][0];
                else if(G[u][1]!=from[u]&&G[u][1]!=to[u]) v=G[u][1];
                else v=G[u][2];
                match[u]=v;
                match[v]=u;
                Answer(u,v);
            }
        }
    return;
}
```

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

#### 収穫 / Harvest

由于此题过于阿拉丁，所以就不写题解了。

---

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005*2;
const long long INF=4557430888798830399;
int n,m,L,C,Q;
int a[N],b[N];
int ida[N],idb[N],tot;
bool isb[N];
vector<pair<int,int>>G[N];
int dfn[N],low[N],Index;
int bel[N],cnt;
vector<int>block[N];
bool book[N];
void tarjan(int u)
{
    static bool vis[N];
    static stack<int>s;
    dfn[u]=low[u]=++Index;
    s.emplace(u);
    vis[u]=true;
    for(auto [v,w]:G[u])
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    if(dfn[u]==low[u])
    {
        cnt++;
        while(s.top()!=u)
        {
            bel[s.top()]=cnt;
            block[cnt].emplace_back(s.top());
            vis[s.top()]=false;
            s.pop();
        }
        bel[u]=cnt;
        block[cnt].emplace_back(u);
        vis[u]=false;
        s.pop();
    }
    return;
}
vector<pair<int,int>>GT[N];
int siz[N];
long long sumt[N];
void dfs(int u,int father,int col)
{
    bel[u]=col;
    dfn[u]=++Index;
    siz[u]=1;
    for(auto [v,w]:GT[u])
    {
        if(v==father) continue;
        sumt[v]=sumt[u]+w; 
        dfs(v,u,col);
        siz[u]+=siz[v];
    }
    return;
}
int rt[N];
long long dis1[N],dis2[N];
long long len[N];
void getdis1(int s)
{
    queue<int>q;
    q.emplace(s);
    dis1[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto [v,w]:GT[u])
            if(dis1[v]>dis1[u]+w)
            {
                dis1[v]=dis1[u]+w;
                q.emplace(v);
            }
    }
    return;
}
void getdis2(int s)
{
    queue<int>q;
    q.emplace(s);
    dis2[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto [v,w]:G[u])
            if(dis2[v]>dis2[u]+w)
            {
                dis2[v]=dis2[u]+w;
                q.emplace(v);
            }
    }
    return;
}
void rebuild()
{
    for(int i=1;i<=tot;i++)
        if(!dfn[i]) tarjan(i);
    map<tuple<int,int,int>,bool>ban;
    for(int i=1;i<=cnt;i++)
        if(bel[G[block[i][0]][0].first]==i)
        {
            for(int u:block[i])
                book[u]=true;
            int now=block[i][0],to=G[now][0].first,val=G[now][0].second;
            ban[{now,to,val}]=true;
            do
            {
                len[i]+=val;
                now=to,to=G[now][0].first,val=G[now][0].second;
            }
            while(now!=block[i][0]);
        }
        else block[i].clear();
    static int deg[N];
    fill(deg+1,deg+tot+1,0);
    for(int u=1;u<=tot;u++)
        for(auto [v,w]:G[u])
            if(!ban[{u,v,w}]) GT[v].emplace_back(u,w),deg[u]++;
    Index=0;
    for(int i=1;i<=tot;i++)
        if(deg[i]==0) dfs(i,0,bel[i]);
    for(int i=1;i<=cnt;i++)
        if(bel[G[block[i][0]][0].first]==i)
        {
            int now=block[i][0],to=G[now][0].first,val=G[now][0].second;
            GT[to].emplace_back(now,val);
        }
    fill(dis1+1,dis1+tot+1,INF);
    fill(dis2+1,dis2+tot+1,INF);
    for(int i=1;i<=tot;i++)
        if(deg[i]==0) rt[bel[i]]=G[i][0].first,getdis1(G[i][0].first),getdis2(G[i][0].first);
    for(int i=1;i<=tot;i++)
        block[bel[i]].emplace_back(i);
    for(int i=1;i<=cnt;i++)
    {
        sort(block[i].begin(),block[i].end());
        block[i].erase(unique(block[i].begin(),block[i].end()),block[i].end());
    }
    return;
}
struct BIT
{
    int n;
    int C[N];
    BIT()
    {
        memset(C,0,sizeof(C));
        return;
    }
    void init(int _n)
    {
        n=_n;
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
    int query(int l,int r)
    {
        return getsum(r)-getsum(l-1);
    }
}T1,T2;
struct Query
{
    int v;
    long long t;
    int id;
}query[N];
long long ans[N];
vector<Query>q[N];
void solve()
{
    for(int i=1;i<=Q;i++)
        q[bel[query[i].v]].emplace_back(query[i]);
    for(int i=1;i<=cnt;i++)
    if(!block[i].empty())
    {
        vector<Query>nquery;
        for(auto [v,t,id]:q[i])
            nquery.emplace_back((Query){v,t,id});
        sort(nquery.begin(),nquery.end(),[=](const Query &a,const Query &b){return a.t+sumt[a.v]<b.t+sumt[b.v];});
        sort(block[i].begin(),block[i].end(),[=](const int &x,const int &y){return sumt[x]<sumt[y];});
        T1.init(tot);
        int j=-1;
        for(auto [v,t,id]:nquery)
            if(!book[v])
            {
                while(j+1<(int)block[i].size()&&sumt[block[i][j+1]]<=t+sumt[v])
                {
                    if(isb[block[i][j+1]]) T1.add(dfn[block[i][j+1]],1);
                    j++;
                }
                ans[id]+=T1.query(dfn[v],dfn[v]+siz[v]-1);
            }
        for(int k=0;k<=j;k++)
            if(isb[block[i][k]]) T1.add(dfn[block[i][k]],-1);
        j=-1;
        for(auto [v,t,id]:nquery)
            if(book[v])
            {
                while(j+1<(int)block[i].size()&&sumt[block[i][j+1]]<=t+sumt[v])
                {
                    if(isb[block[i][j+1]]&&!(dfn[rt[i]]<=dfn[block[i][j+1]]&&dfn[block[i][j+1]]<=dfn[rt[i]]+siz[rt[i]]-1)) T1.add(dfn[block[i][j+1]],1);
                    j++;
                }
                ans[id]+=T1.query(dfn[v],dfn[v]+siz[v]-1);
            }
        for(int k=0;k<=j;k++)
            if(!(dfn[rt[i]]<=dfn[block[i][k]]&&dfn[block[i][k]]<=dfn[rt[i]]+siz[i]-1)) T1.add(dfn[block[i][k]],-1);
        int num=0;
        long long sum=0;
        sort(nquery.begin(),nquery.end(),[=](const Query &a,const Query &b){return a.t<b.t;});
        sort(block[i].begin(),block[i].end(),[=](const int &x,const int &y){return dis1[x]<dis1[y];});
        static long long bv[N];
        static long long tl[N];
        int c=0;
        for(int j=0;j<(int)block[i].size();j++)
            if(isb[block[i][j]]) tl[j]=dis1[block[i][j]]%len[i],bv[++c]=tl[j];
        sort(bv+1,bv+c+1);
        c=unique(bv+1,bv+c+1)-bv-1;
        for(int j=0;j<(int)block[i].size();j++)
            if(isb[block[i][j]]) tl[j]=lower_bound(bv+1,bv+c+1,tl[j])-bv;
        T2.init(c);
        j=-1;
        for(auto [v,t,id]:nquery)
            if(book[v])
            {
                while(j+1<(int)block[i].size()&&dis1[block[i][j+1]]<=t)
                {
                    if(isb[block[i][j+1]]) num++,sum+=dis1[block[i][j+1]]/len[i],T2.add(tl[j+1],1);
                    j++;
                }
                long long x=t+len[i]-dis2[v];
                int xl=upper_bound(bv+1,bv+c+1,x%len[i])-bv;
                ans[id]+=x/len[i]*num-sum-T2.query(xl,c);
            }
        for(int k=0;k<=j;k++)
            if(isb[block[i][k]]) T2.add(tl[k],-1);
    }
    return;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&L,&C);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        ida[i]=ida[i+n]=++tot,a[i+n]=a[i]+L;
    for(int i=1;i<=m;i++)
        idb[i]=idb[i+m]=++tot,b[i+m]=b[i]+L,isb[idb[i]]=true;
    for(int i=n+1,j=1;i<=n+n;i++)
    {
        while(j+1<=n+n&&a[i]-a[j+1]>=C%L) j++;
        if(a[i]-a[j]>=C%L) G[ida[i]].emplace_back(ida[j],C/L*L+a[i]-a[j]);
    }
    for(int i=m+1,j=1;i<=m+m;i++)
    {
        while(j+1<=n+n&&b[i]>a[j+1]) j++;
        if(b[i]>a[j]) G[idb[i]].emplace_back(ida[j],b[i]-a[j]);
    }
    rebuild();
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        int v;
        long long t;
        scanf("%d%lld",&v,&t);
        query[i]={ida[v],t,i};
    }
    solve();
    for(int i=1;i<=Q;i++)
        printf("%lld\n",ans[i]);
    return 0;
}
```

---

#### 迷い猫 / Stray Cat

咕咕咕

---

#### 首都 / Capital City

考虑点分治，每次用 BFS 计算以当前的根为首都的最小代价，如果访问的过程中出现一种颜色在根的上面那些点，那么以当前的根为首都显然不如以它的父亲优。

---

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,k;
vector<int>G[N];
int c[N];
vector<int>pos[N];
int root,tot;
int siz[N],Max[N];
bool vis[N];
void getroot(int u,int father)
{
    siz[u]=1,Max[u]=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        if(vis[v]) continue;
        getroot(v,u);
        siz[u]+=siz[v];
        Max[u]=max(Max[u],siz[v]);
    }
    Max[u]=max(Max[u],tot-siz[u]);
    if(Max[u]<Max[root]) root=u;
    return;
}
int dep[N];
int fa[N];
void getdep(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u]=father;
    for(int v:G[u])
    {
        if(v==father) continue;
        if(vis[v]) continue;
        getdep(v,u);
    }
    return;
}
int cnt[N];
void addcnt(int u,int father,int val)
{
    cnt[c[u]]+=val;
    for(int v:G[u])
    {
        if(v==father) continue;
        if(vis[v]) continue;
        addcnt(v,u,val);
    }
    return;
}
int calc(int rt)
{
    if(cnt[c[rt]]>0) return INF;
    static bool inq[N],inc[N];
    vector<int>pu,pc;
    inc[c[rt]]=true;
    pc.emplace_back(c[rt]);
    queue<int>q;
    for(int u:pos[c[rt]])
        if(u!=rt) inq[u]=true,pu.emplace_back(u),q.emplace(u);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int v=fa[u];
        if(v==rt) continue;
        if(inq[v]) continue;
        if(cnt[c[v]]>0)
        {
            for(int u:pu)
                inq[u]=false;
            for(int c:pc)
                inc[c]=false;
            return INF;
        }
        inq[v]=true,pu.emplace_back(v),q.emplace(v);
        if(!inc[c[v]])
        {
            inc[c[v]]=true;
            pc.emplace_back(c[v]);
            for(int x:pos[c[v]])
                if(!inq[x]&&x!=rt) inq[x]=true,pu.emplace_back(x),q.emplace(x);
        }
    }
    for(int u:pu)
        inq[u]=false;
    for(int c:pc)
        inc[c]=false;
    int res=pc.size()-1;
    return res;
}
int ans=INF;
void solve(int u)
{
    int v=calc(u);
    ans=min(ans,v);
    addcnt(u,0,1);
    vis[u]=true;
    for(int v:G[u])
    {
        if(vis[v]) continue;
        tot=siz[v],root=0;
        getroot(v,0);
        getdep(root,0);
        addcnt(v,0,-1);
        solve(root);
        addcnt(v,0,1);
    }
    return;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        pos[c[i]].emplace_back(i);
    Max[0]=INF,tot=n;
    getroot(1,0);
    getdep(root,0);
    solve(root);
    printf("%d",ans);
    return 0;
}
```

---

#### 伝説の団子職人 / Legendary Dango Maker

咕咕咕。。。

---

#### 治療計画 / Treatment Project

令 $f_i$ 表示把 $[1,r_i]$ 都治好的最小代价，这里对时间没有限制，考虑用 $f_i$ 更新 $f_j$：

$$f_j=f_i+C_j(R_i-L_j + 1\geq |T_i-T_j|)$$

这个东西相当于一个最短路，可以发现边权只和目标点有关，所以我们跑 Dijkstra 的时候第一个能更新它的点一定就是最短的。用线段树维护还没有松弛的点，堆维护松弛过的点，直接暴力复杂度是对的，因为每个点只会被松弛一次。

---

```cpp
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int M=100005;
const int INF=1061109567*2;
const long long LINF=4557430888798830399;
int n,m;
struct Seg
{
    int t,l,r,c;
}s[M];
struct Segment_Tree
{
    struct Node
    {
        int l,r;
        pair<int,int>mi;
    }tree[M<<2];
    void push_up(int i)
    {
        tree[i].mi=min(tree[i*2].mi,tree[i*2+1].mi);
        return;
    }
    void build(int i,int l,int r)
    {
        tree[i].l=l,tree[i].r=r;
        if(l==r)
        {
            tree[i].mi={INF,l};
            return;
        }
        int mid=(l+r)/2;
        build(i*2,l,mid);
        build(i*2+1,mid+1,r);
        push_up(i);
        return;
    }
    void modify(int i,int u,int v)
    {
        if(tree[i].l==tree[i].r)
        {
            tree[i].mi.first=v;
            return;
        }
        if(u<=tree[i*2].r) modify(i*2,u,v);
        else modify(i*2+1,u,v);
        push_up(i);
        return;
    }
    pair<int,int>query(int i,int l,int r)
    {
        if(l<=tree[i].l&&tree[i].r<=r) return tree[i].mi;
        pair<int,int> res={INF,0};
        if(l<=tree[i*2].r) res=min(res,query(i*2,l,r));
        if(r>=tree[i*2+1].l) res=min(res,query(i*2+1,l,r));
        return res;
    }
}T1,T2;
long long f[M];
bool vis[M];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int t,l,r,c;
        scanf("%d%d%d%d",&t,&l,&r,&c);
        s[i]={t,l,r,c};
    }
    sort(s+1,s+m+1,[=](const Seg &a,const Seg &b){return a.t<b.t;});
    T1.build(1,1,m),T2.build(1,1,m);
    fill(f+1,f+m+1,LINF);
    for(int i=1;i<=m;i++)
        T1.modify(1,i,s[i].l-s[i].t-1),T2.modify(1,i,s[i].l+s[i].t-1);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    for(int i=1;i<=m;i++)
        if(s[i].l==1) f[i]=s[i].c,q.emplace(f[i],i);
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        T1.modify(1,u,INF);
        T2.modify(1,u,INF);
        while(true)
        {
            auto [rt,v]=T1.query(1,1,u);
            if(rt<=s[u].r-s[u].t)
            {
                T1.modify(1,v,INF);
                T2.modify(1,v,INF);
                if(f[v]>f[u]+s[v].c)
                {
                    f[v]=f[u]+s[v].c;
                    q.emplace(f[v],v);
                }
            }
            else break;
        }
        while(true)
        {
            auto [rt,v]=T2.query(1,u,m);
            if(rt<=s[u].r+s[u].t)
            {
                T1.modify(1,v,INF);
                T2.modify(1,v,INF);
                if(f[v]>f[u]+s[v].c)
                {
                    f[v]=f[u]+s[v].c;
                    q.emplace(f[v],v);
                }
            }
            else break;
        }
    }
    long long ans=LINF;
    for(int i=1;i<=m;i++)
        if(s[i].r==n) ans=min(ans,f[i]);
    if(ans>=LINF) printf("-1");
    else printf("%lld",ans);
    return 0;
}
```