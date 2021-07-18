#### 勇者ビ太郎 / Bitaro the Brave

直接后缀和一波带走。

---

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=3005;
int n,m;
char s[N][N];
int ci[N][N],co[N][N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int j=1;j<=m;j++)
        for(int i=n;i>=1;i--)
            ci[i][j]=ci[i+1][j]+(s[i][j]=='I');
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            co[i][j]=co[i][j+1]+(s[i][j]=='O');
    long long ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='J') ans+=ci[i+1][j]*co[i][j+1];
    printf("%lld",ans);
    return 0;
}
```

---

#### 展覧会 / Exhibition

将画框按 $C_i$ 从小到大排序，画按照 $S_i$ 从小到大排序。二分答案，用 `std::multiset` 维护当前的画，每次加入 $S_j\le C_i$ 的，找到 $V_i$ 尽可能小的，找不到即无解。

---

```cpp
#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
struct Paint
{
    int s,v;
}a[N];
int c[N];
bool check(int x)
{
    multiset<int>S;
    int pre=0;
    for(int i=m-x+1,j=0;i<=m;i++)
    {
        while(j+1<=n&&a[j+1].s<=c[i]) S.insert(a[j+1].v),j++;
        multiset<int>::iterator it=S.lower_bound(pre);
        if(it==S.end()) return false;
        pre=*it;
        S.erase(it);
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].s,&a[i].v);
    sort(a+1,a+n+1,[=](const Paint &x,const Paint &y){return x.s<y.s;});
    for(int i=1;i<=m;i++)
        scanf("%d",&c[i]);
    sort(c+1,c+m+1);
    int l=1,r=m,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}
```

---

#### たのしいたのしいたのしい家庭菜園 / Growing Vegetable is Fun 3

可以发现，相同颜色的花盆之间的相对位置是不会改变的。

对于一种确定的方案，原串中的字符的权值为在新串中的编号，它的最小步数即为原串中的权值逆序对数。

那么就可以 DP 了，令 $f_{i,j,k,0/1/2}$ 表示考虑前 $i$ 位，有 $j$ 个 `R`，$k$ 个 `G`，第 $i$ 位为 `R`/`G`/`B` 的最小操作次数。

---

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=405;
const int INF=1061109567;
int n;
char s[N];
int a[N];
int cnt[N][3];
int f[N][N][N][3];
vector<int>pos[3];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        if(s[i]=='R') a[i]=0;
        else if(s[i]=='G') a[i]=1;
        else if(s[i]=='Y') a[i]=2;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
            cnt[i][j]=cnt[i-1][j];
        cnt[i][a[i]]++;
    }
    for(int i=1;i<=n;i++)
        pos[a[i]].emplace_back(i);
    memset(f,63,sizeof(f));
    if(!pos[0].empty()) f[1][1][0][0]=pos[0][0]-1;
    if(!pos[1].empty()) f[1][0][1][1]=pos[1][0]-1;
    if(!pos[2].empty()) f[1][0][0][2]=pos[2][0]-1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=i;j++)
            for(int k=0;j+k<=i;k++)
            {
                int l=i-j-k;
                for(int x=0;x<3;x++)
                {
                    int v;
                    if(x==0) v=j;
                    else if(x==1) v=k;
                    else v=l;
                    if(v<=0) continue;
                    if((int)pos[x].size()<v) continue;
                    int p=pos[x][v-1];
                    int sum=0;
                    if(x!=0) sum+=max(cnt[p][0]-j,0);
                    if(x!=1) sum+=max(cnt[p][1]-k,0);
                    if(x!=2) sum+=max(cnt[p][2]-l,0);
                    for(int y=0;y<3;y++)
                        if(x!=y) f[i][j][k][x]=min(f[i][j][k][x],f[i-1][j-(x==0)][k-(x==1)][y]+sum);
                }
            }
    int ans=INF;
    for(int j=0;j<=n;j++)
        for(int k=0;j+k<=n;k++)
            for(int x=0;x<3;x++)
                ans=min(ans,f[n][j][k][x]);
    if(ans>=INF) printf("-1");
    else printf("%d",ans);
    return 0;
}
```

---

#### コイン集め / Coin Collecting

现将所有点塞到最近的点里去。从左往右扫 $i$，如果 $a_i\lt 1,b_i\gt 1$，就从 $b_i$ 移到 $a_i$ 一部分，$a_i\gt 1,b_i\lt 1$ 时同理。然后移动 $a_{i+1}$ 直到 $a_i=1$，$b_i$ 同理。

---

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100005;
int n;
struct Point
{
    int x,y;
}p[N*2];
int a[N],b[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    long long ans=0;
    for(int i=1;i<=2*n;i++)
        if(p[i].y>=2)
        {
            if(1<=p[i].x&&p[i].x<=n) a[p[i].x]++,ans+=p[i].y-2;
            else if(p[i].x<1) a[1]++,ans+=p[i].y-2+1-p[i].x;
            else if(p[i].x>n) a[n]++,ans+=p[i].y-2+p[i].x-n;
        }
        else
        {
            if(1<=p[i].x&&p[i].x<=n) b[p[i].x]++,ans+=1-p[i].y;
            else if(p[i].x<1) b[1]++,ans+=1-p[i].y+1-p[i].x;
            else if(p[i].x>n) b[n]++,ans+=1-p[i].y+p[i].x-n;
        }
    for(int i=1;i<=n;i++)
        a[i]--,b[i]--;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0&&b[i]<0)
        {
            int v=min(a[i],-b[i]);
            ans+=v,a[i]-=v,b[i]+=v;
        }
        if(a[i]<0&&b[i]>0)
        {
            int v=min(-a[i],b[i]);
            ans+=v,a[i]+=v,b[i]-=v;
        }
        ans+=abs(a[i]),a[i+1]+=a[i],a[i]=0;
        ans+=abs(b[i]),b[i+1]+=b[i],b[i]=0;
    }
    printf("%lld",ans);
    return 0;
}
```

---

#### 珍しい都市 / Unique Cities

可以发现，一个点的独特的城市一定在以这个点为端点的直径上，也就是到某个直径端点的路径上。

那么就可以以直径的端点为根 `dfs`，维护出它到根的路径上那些点目前还满足条件，每次加入一个子树相当于是弹出深度在一个区间内的点，因为每次还要撤销，复杂度较高。

因为限制跟子树中最大的深度有关系，这启示了我们可以长链剖分，先走重儿子，再走轻儿子，因为重儿子的限制是次长链，肯定比最长链要小，所以就不需要撤销了。

---

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m;
vector<int>G[N];
int c[N];
int dep[N];
int s,t;
void dfs1(int u,int father)
{
    dep[u]=dep[father]+1;
    if(dep[u]>dep[s]) s=u;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs1(v,u);
    }
    return;
}
void dfs2(int u,int father)
{
    dep[u]=dep[father]+1;
    if(dep[u]>dep[t]) t=u;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs2(v,u);
    }
    return;
}
int Max[N],son[N],sson[N];
void dfs3(int u,int father)
{
    dep[u]=dep[father]+1;
    Max[u]=dep[u];
    son[u]=sson[u]=0;
    for(int v:G[u])
    {
        if(v==father) continue;
        dfs3(v,u);
        Max[u]=max(Max[u],Max[v]);
        if(Max[v]>Max[son[u]]) son[u]=v;
    }
    for(int v:G[u])
    {
        if(v==father) continue;
        if(v==son[u]) continue;
        if(Max[v]>Max[sson[u]]) sson[u]=v;
    }
    return;
}
int tot;
int cnt[N];
void add(int u)
{
    if(cnt[c[u]]==0) tot++;
    cnt[c[u]]++;
    return;
}
void del(int u)
{
    cnt[c[u]]--;
    if(cnt[c[u]]==0) tot--;
    return;
}
stack<int>stk;
int ans[N];
void dfs4(int u,int father)
{
    if(son[u])
    {
        vector<int>tss,ts;
        while(!stk.empty()&&dep[u]-dep[stk.top()]<=Max[sson[u]]-dep[u]) tss.emplace_back(stk.top()),del(stk.top()),stk.pop();
        add(u),stk.emplace(u);
        dfs4(son[u],u);
        while(!stk.empty()&&dep[u]-dep[stk.top()]<=Max[son[u]]-dep[u]) ts.emplace_back(stk.top()),del(stk.top()),stk.pop();
        ans[u]=max(ans[u],tot);
        for(int v:G[u])
        {
            if(v==father||v==son[u]) continue;
            if(stk.empty()||stk.top()!=u) add(u),stk.emplace(u);
            dfs4(v,u);
        }
        if(!stk.empty()&&stk.top()==u)
        {
            del(u);
            stk.pop();
        }
    }
    else ans[u]=max(ans[u],tot);
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    dfs1(1,0);
    dfs2(s,0);
    dfs3(s,0);
    dfs4(s,0);
    dfs3(t,0);
    dfs4(t,0);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
```