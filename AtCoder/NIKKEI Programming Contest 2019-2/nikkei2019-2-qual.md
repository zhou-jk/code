#### A - Sum of Two Integers
分奇偶讨论一下就好了，答案为 $\lfloor \frac{n-1}\{2\}\rfloor$。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	printf("%d",(n-1)/2);
	return 0;
}
```

------------

#### B - Counting of Trees
深度为 $i+1$ 的点肯定是挂在深度为 $i$ 的点下面，令 $cnt_i$ 表示深度为 $i$ 的点。对于深度为 $i+1$ 的一个点，它有 $cnt_i$ 种不同的选择，有 $cnt_{i+1}$ 个不同的点，方案数为 $\prod cnt_i^{cnt_{i+1}}$。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=998244353;
int n;
int d[N];
int cnt[N];
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%MOD;
		a=a*a%MOD,b>>=1;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		cnt[d[i]]++;
	}
	if(cnt[0]!=1||d[1]!=0)
	{
		printf("0");
		return 0;
	}
	long long ans=1;
	for(int i=1;i<=n-1;i++)
	{
		if(cnt[i]&&!cnt[i-1])
		{
			printf("0");
			return 0;
		}
		ans=ans*ksm(cnt[i-1],cnt[i])%MOD;
	}
	printf("%lld",ans);
	return 0;
}
```

------------

#### C - Swaps
不妨看做交换 $B$，这样是等价的。

从大到小确定每个位置的 $B_i$，如果当前点对应的 $A_i\leq B_i$，则不用动它，再将 $i$ 这个位置删去；否则选一个还没有确定的位置 $j$ 使得 $A_i\leq B_j$ 跟它交换，将 $i$ 删去。算下次数是否小于等于 $n-2$ 即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N],b[N];
pair<int,int> p[N];
int q[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[i]=make_pair(a[i],i);
	sort(p+1,p+n+1,greater<pair<int,int> >());
	set<pair<int,int> >S;
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),q[i]=i,S.insert(make_pair(b[i],i));
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int u=p[i].second;
		if(a[u]<=b[q[u]])
		{
			S.erase(S.lower_bound(make_pair(b[q[u]],u)));
			continue;
		}
		set<pair<int,int> >::iterator A=S.lower_bound(make_pair(b[q[u]],u)),B=S.lower_bound(make_pair(a[u],0));
		if(B==S.end())
		{
			printf("No");
			return 0;
		}
		int v=B->second;
		S.erase(A);
		S.erase(B);
		swap(q[u],q[v]);
		S.insert(make_pair(b[q[v]],v));
		ans++;
	}
	if(ans<=n-2) printf("Yes");
	else printf("No");
	return 0;
}
```

------------

#### D - Shortest Path on a Line
考虑 DP，令 $f_i$ 表示到 $i$ 的最小花费。可以发现，我们当前如果在一个区间内，肯定尽量走到右端点是最优的。那么就可以对于每个 $r$，我们将整段区间转移过来：

$$f_{r}=\min\limits_{i=l}^{r-1}\{a_i\}+c$$

用线段树优化即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=100005;
const long long INF=4557430888798830399;
int n,m;
vector<pair<int,int> >pre[N];
struct Node
{
	int l,r;
	long long Min;
}tree[N<<2];
long long f[N];
void push_up(int i)
{
	tree[i].Min=min(tree[i*2].Min,tree[i*2+1].Min);
	return;
}
void build(int i,int l,int r)
{
	tree[i].l=l,tree[i].r=r;
	if(l==r)
	{
		tree[i].Min=f[l];
		return;
	}
	int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	push_up(i);
	return;
}
long long query(int i,int l,int r)
{
	if(l>r) return INF;
	if(l<=tree[i].l&&tree[i].r<=r) return tree[i].Min;
	long long res=INF;
	if(l<=tree[i*2].r) res=min(res,query(i*2,l,r));
	if(r>=tree[i*2+1].l) res=min(res,query(i*2+1,l,r));
	return res;
}
void modify(int i,int u,long long val)
{
	if(tree[i].l==tree[i].r)
	{
		tree[i].Min=val;
		return;
	}
	if(u<=tree[i*2].r) modify(i*2,u,val);
	else modify(i*2+1,u,val);
	push_up(i);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		pre[r].push_back(make_pair(l,c));
	}
	memset(f,63,sizeof(f));
	f[1]=0;
	build(1,1,n);
	for(int r=1;r<=n;r++)
	{
		for(auto [l,c]:pre[r])
			f[r]=min(f[r],query(1,l,r-1)+c);
		modify(1,r,f[r]);
	}
	if(f[n]>=INF) printf("-1");
	else printf("%lld",f[n]);
	return 0;
}
```

------------

#### E - Non-triangular Triplets
可以发现有解的条件即为 $2k\leq n+1$。

一种构造方法为：考虑将 $k+2n\sim k+3n-1$ 的数作为 $c_i$，其余的数作为 $a_i,b_i$。可以将 $c_i$ 按照从小到大分成两段，前一段如果当前的位置为 $(x,y)$，则下一个位置可以为 $(x-2,y+1)$，直到 $x-2< n$ 或 $y+1\ge n$，后一段同理。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=205;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	if(2*k>n+1)
	{
		printf("-1");
		return 0;
	}
	int l=n/2,r=2*n-1;
	for(int i=3*n-1;i>=2*n;i--)
	{
		printf("%d %d %d\n",l+k,r+k,i+k);
		r-=2;
		if(r<n) r=2*n-2;
		l++;
		if(l==n) l=0;
	}
	return 0;
}
```

------------

#### F - Mirror Frame
考虑一个点向某个方向前进，最后肯定会回到起点，这个就是一个环。整个图中环的个数为 $N+1$。

不妨将图中的环看做点，灯泡看做边，问题就转化成了两个完全图上的问题。对于两个环的交点处的灯泡的状态肯定是相同的，即如果有多条边的权值肯定是相同的。某些边的权值是不确定的，某些边的权值是确定的。每次操作可以看做翻转某条边 $(u,v)$ 和所有与 $u,v$ 相连的边翻转。

对于某个完全图：

- 点数为偶数时无论怎么确定边的颜色我们肯定都可以找到一种方法使得它合法，因为点数为偶数时，翻转 $(u,v),(u,w),(v,w)$ 相当于是只改变了 $(u,v)$ 的颜色。
- 点数为奇数时需要满足每个点白色的度为偶数个，因为可以发现每个操作不会改变每个点白色的度的奇偶性，选择欧拉回路上的边翻转即可。

对于奇数的情况，我们可以搞出一个生成树。我们可以根据生成树外的边的颜色确定生成树上边的颜色。且无论怎么确定生成树外的边的颜色，肯定是合法的。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1505;
const int MOD=998244353;
int n;
char s[N][N];
struct Graph
{
	int n;
	int G[N][N];
	int fa[N];
	int d[N];
	int getf(int v)
	{
		if(v==fa[v]) return v;
		fa[v]=getf(fa[v]);
		return fa[v];
	}
	bool merge(int u,int v)
	{
		int f1=getf(u),f2=getf(v);
		if(f1!=f2)
		{
			fa[f2]=f1;
			d[f1]+=d[f2];
			d[f2]=0;
			return true;
		}
		else return false;
	}
	void init(int _n)
	{
		n=_n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[i][j]=-1;
		for(int i=1;i<=n;i++)
			fa[i]=i,d[i]=0;
		return;
	}
	bool add(int u,int v,int w)
	{
		if(w==-1) return true;
		if(G[u][v]!=-1) return G[u][v]==w;
		else
		{
			G[u][v]=G[v][u]=w;
			return true;
		}
	}
	long long solve()
	{
		int tot=0;
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++)
				if(G[u][v]==-1) tot++;
				else d[u]+=G[u][v],d[v]+=G[u][v];
		if(n%2==0)
		{
			long long ans=1;
			for(int i=1;i<=tot;i++)
				ans=ans*2%MOD;
			return ans;
		}
		for(int u=1;u<=n;u++)
			for(int v=u+1;v<=n;v++)
				if(G[u][v]==-1)
				{
					if(merge(u,v)) tot--;
				}
		for(int i=1;i<=n;i++)
			if(getf(i)==i&&d[i]%2==1) return 0;
		long long ans=1;
		for(int i=1;i<=tot;i++)
			ans=ans*2%MOD;
		return ans;
	}
};
Graph g[2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%s",s[i]+1);
	g[0].init(n/2+1),g[1].init((n+1)/2);
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
		{
			int u=(min(i+j,n-i+n-j)/2)+1,v=(max(i-j,j-i)/2)+1;
			int w=(s[i][j]=='o'?1:(s[i][j]=='w'?0:-1));
			if(!g[(i+j)&1].add(u,v,w))
			{
				printf("0");
				return 0;
			}
		}
	printf("%lld",g[0].solve()*g[1].solve()%MOD);
	return 0;
}
```