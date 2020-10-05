#### A - Hitachi String
满足条件的串即为串长为偶数且相邻两个均为为 `hi`，直接判断即可。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=15;
int n;
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n&1)
	{
		printf("No");
		return 0;
	}
	for(int i=1;i<=n;i+=2)
		if(s[i]!='h'||s[i+1]!='i')
		{
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}
```

------------

#### B - Nice Shopping
考虑如果没有优惠券，那么答案就是 $\min\{a_i\}+\min\{b_i\}$。

考虑如果有了优惠券，答案就是每张优惠券用了以后的最小值，取个 $\min$ 就好了。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int A,B,n;
int a[N],b[N];
int x[N],y[N],c[N];
int main()
{
	scanf("%d%d%d",&A,&B,&n);
	for(int i=1;i<=A;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=B;i++)
		scanf("%d",&b[i]);
	int ans=(*min_element(a+1,a+A+1))+(*min_element(b+1,b+B+1));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&c[i]);
		ans=min(ans,a[x[i]]+b[y[i]]-c[i]);
	}
	printf("%d",ans);
	return 0;
}
```

------------

#### C - ThREE
不妨将原序列的点按照对 $3$ 取模的结果分成 $3$ 类，每种的个数分别为 $c_1,c_2,c_3$ 不合法的情况为距离为 $3$ 的两个点同时选了 $1$ 或者 $2$。

可以发现，如果两个点的距离为 $3$，这两个点的深度之差肯定为 $1$ 或 $3$。

那么可以将所有点根据深度对 $2$ 取模的结果分成两类点，不合法的情况仅当两种点同时选了 $1$ 和 $2$，否则一定合法。

考虑构造，不妨令两类点的个数为 $x,y$，可以分成几种情况讨论：

- $y\leq c_3$，将 $y$ 中填满 $3$，剩下的随便填；
- $x\leq c_3$ 时同理；
- $x> c_3$ 且 $y> c_3$，我们可以将 $1$ 全部填入 $x$ 中，$2$ 全部填入 $y$，剩下的 $3$ 随便填。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n;
vector<int>G[N];
int dep[N];
vector<int>pos[2];
void dfs(int u,int father)
{
	dep[u]=dep[father]+1;
	pos[dep[u]&1].push_back(u);
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
	}
	return;
}
vector<int>col[3];
int ans[N];
int main()
{
	scanf("%d",&n);
	int num[3]={n/3,(n+2)/3,(n+1)/3};
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	int x=pos[0].size(),y=pos[1].size();
	if(x<=num[0])
	{
		for(int u:pos[0])
			col[0].push_back(u),num[0]--;
		for(int u:pos[1])
		{
			if(num[0]>0) col[0].push_back(u),num[0]--;
			else if(num[1]>0) col[1].push_back(u),num[1]--;
			else if(num[2]>0) col[2].push_back(u),num[2]--;
		}
	}
	else if(y<=num[0])
	{
		for(int u:pos[1])
			col[0].push_back(u),num[0]--;
		for(int u:pos[0])
		{
			if(num[0]>0) col[0].push_back(u),num[0]--;
			else if(num[1]>0) col[1].push_back(u),num[1]--;
			else if(num[2]>0) col[2].push_back(u),num[2]--;
		}
	}
	else
	{
		for(int u:pos[0])
		{
			if(num[1]>0) col[1].push_back(u),num[1]--;
			else if(num[0]>0) col[0].push_back(u),num[0]--;
		}
		for(int u:pos[1])
		{
			if(num[2]>0) col[2].push_back(u),num[2]--;
			else if(num[0]>0) col[0].push_back(u),num[0]--;
		}
	}
	int now=1;
	for(int u:col[1])
		ans[u]=now,now+=3;
	now=2;
	for(int u:col[2])
		ans[u]=now,now+=3;
	now=3;
	for(int u:col[0])
		ans[u]=now,now+=3;
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
```

------------

#### D - Manga Market
考虑对于两个商店 $i,j$，先走 $i$ 优还是先走 $j$ 优，不妨令当前时间为 $t$，则如果先走 $j$ 再到 $i$ 更优的话需要满足：

$$\begin{aligned}1+a_{i}(t+1)+b_{i}+1+a_{j}(t+1+a_{i}(t+1)+b_{i}+1)+b_{j} &\leq 1+a_{j}(t+1)+b_{j}+1+a_{i}(t+1+a_{j}(t+1)+b_{j}+1)+b_{i} \\ 1+a_{i}(t+1)+b_{i}+1+a_{j}(t+1)+a_{i}a_{j}(t+1)+a_j(b_{i}+1)+b_{j} &\leq 1+a_{j}(t+1)+b_{j}+1+a_{i}(t+1)+a_{i}a_{j}(t+1)+a_{i}(b_{j}+1)+b_{i} \\ a_j(b_{i}+1) &\leq a_{i}(b_{j}+1) \\ \frac{a_{i}}{b_{i}+1}&\leq \frac{a_{j}}{b_{j}+1} \end{aligned}$$

可以将所有的商店按照 $\frac{a_{i}}{b_{i}+1}$ 从大到小排序，这就变成了一个线性的问题。

考虑 DP，令 $f_{i,j}$ 表示到第 $i$ 个点，选了 $j$ 个商店的最小时间 $t$，其中时间 $t$ 是指数级增长的，则 $j$ 是 $\log t$ 级别的。

注意我们需要将所有的 $a_i=0$ 的点拉出来单独处理。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200005,M=35;
const int INF=1000000001;
int n,T;
struct Node
{
	int a,b;
}s[N];
int f[N][M];
vector<int>d;
long long sum[N];
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&s[i].a,&s[i].b);
		if(s[i].a==0)
		{
			d.push_back(s[i].b);
			n--,i--;
		}
	}
	sort(s+1,s+n+1,[](const Node &x,const Node &y){return (double)x.a/(x.b+1)>(double)y.a/(y.b+1);});
	memset(f,63,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=min(i,30);j++)
		{
			if(f[i-1][j]<INF) f[i][j]=f[i-1][j];
			if(j>=1)
			{
				if(f[i-1][j-1]+(1+1LL*s[i].a*(f[i-1][j-1]+1)+s[i].b)<INF) f[i][j]=min(f[i][j],f[i-1][j-1]+(1+s[i].a*(f[i-1][j-1]+1)+s[i].b));
			}
		}
	sort(d.begin(),d.end());
	for(int i=1;i<=d.size();i++)
		sum[i]=sum[i-1]+d[i-1]+1;
	int res=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=min(i,30);j++)
			if(f[i][j]<=T)
			{
				int t=T-f[i][j];
				int l=1,r=d.size(),ans=0;
				while(l<=r)
				{
					int mid=(l+r)/2;
					auto check=[=](int x){return sum[x]<=t;};
					if(check(mid)) ans=mid,l=mid+1;
					else r=mid-1;
				}
				res=max(res,j+ans);
			}
	printf("%d",res);
	return 0;
}
```

------------

#### E - Odd Sum Rectangles
不妨设 $n\ge m$，$n< m$ 时同理。

对于一个矩形 $(i_1,i_2,j_1,j_2)$，考虑枚举 $j_1,j_2$。将原矩形差分一下，令 $f(i)$ 表示 $S(1,i,j_1,j_2)$，那么问题就变成了有多少个二元组 $(i_1,i_2)$ 使得 $f(i_2)-f(i_1-1)$ 为偶数。

令 $H=2^n,W=2^m$，令 $cnt_0$ 表示所有 $f(i)$ 中 $0$ 的个数，$cnt_1$ 表示 $1$ 的个数。可以发现，$(i_1,i_2)$ 的个数为 $cnt_0\cdot cnt_1=cnt_0\cdot (H-cnt_0)$，当 $cnt_0=\frac{H}{2}$ 时，有最大值 $\frac{H^2}{4}$，乘上 $(j_1,j_2)$ 的对数 $\frac{W(W-1)}{2}$ 可以得出题目的矩形个数即为 $\frac{H^2\cdot W(W-1)}{8}$。

考虑如何构造出这个最大值。

当 $n=m$ 时，先构造出左上，右上，左下，右下的矩形，然后在将中间的一行和竖着的一行的交点置为 $1$，其他点置为 $0$。

证明的话大概是如果在左上，右上，左下，右下的矩形中一定是最大的，只需要考虑跨过中间行或列的情况，中间上下的零一个数是相等的。

当 $n> m$ 时，先构造出 $(2^n-1)\times (2^n-1)$ 的情况，然后再从右边截掉一部分就是了。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=12;
int n,m;
int a[1<<N][1<<N];
void dfs(int x,int y,int k)
{
	if(k==1)
	{
		a[x][y]=1;
		return;
	}
	dfs(x,y,k-1);
	dfs(x+(1<<(k-1)),y,k-1);
	dfs(x,y+(1<<(k-1)),k-1);
	dfs(x+(1<<(k-1)),y+(1<<(k-1)),k-1);
	for(int i=1;i<=(1<<k)-1;i++)
		a[x+(1<<(k-1))-1][y+i-1]=a[x+i-1][y+(1<<(k-1))-1]=0;
	a[x+(1<<(k-1))-1][y+(1<<(k-1))-1]=1;
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	dfs(1,1,max(n,m));
	for(int i=1;i<=(1<<n)-1;i++)
	{
		for(int j=1;j<=(1<<m)-1;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
	return 0;
}
```

------------

#### F - Preserve Diameter
因为 $G$ 和 $H$ 的直径是相等的。不妨设 $H$ 的直径的端点为 $s,t$，以 $s$ 为根建出 BFS 树。令 $dep_u$ 表示 $u$ 在树中的深度，那么两个点 $(u,v)$ 如果在 $H$ 有边当且仅当 $|dep_u-dep_v|\leq 1$，且所有的 $|dep_u-dep_v|\leq 1$ 的点对必然在 $H$ 中有边，不然就可以加再加一条边使得直径不变。

令 $G$ 的直径长度为 $L$。分两种情况：

- $L$ 为偶数。

如果 $G$ 中有多条直径的话，我们需要确定一个 $x$，很难计数，不妨令直径的中点为 $c$，则 $G$ 的所有直径一定经过 $c$。

考虑去确定 $G$ 中的每一条边 $(u,v)$ 的 $dep_u-dep_v$ 的值，考虑 $dep$ 在以 $c$ 为根的 BFS 树中的值：

- $dep_c=\frac{L}{2}$；
- 只有一个 $s$ 满足 $dep_s=0$；
- 只有一个 $t$ 满足 $dep_t=0$；
- 对于 $(u,v)\in G$，有 $|dep_u-dep_v|\leq 1$。

令 $d_u$ 表示 $c$ 到 $u$ 的距离。

考虑 DP，令 $f_{u,0/1/2,0/1/2}$ 表示 $u$ 子树中，满足 $dep_v-dep_u=\frac{L}{2}-d_u$ 的 $v$ 的个数为 $0,1,\ge 2$ 且 $dep_v-dep_u=-\frac{L}{2}+d_u$ 的个数为 $0,1,\ge 2$ 时方案数。

因为 $\ge 2$ 时跟 $=2$ 时对答案的贡献是相同的，故可以一起处理。

注意同一种 $H$ 会被算 $s,t$ 分别算两遍，最后除以 $2$ 就好了。

- $L$ 为奇数。
可以将中间的那条边的两端分别 DP，最后合并一下就好了。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
const int MOD=998244353;
int n;
vector<int>G[N];
int s,t;
int Max,p;
int dep[N];
int fa[N];
void dfs(int u,int father)
{
	fa[u]=father;
	dep[u]=dep[father]+1;
	if(dep[u]>Max) Max=dep[u],p=u;
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
	}
	return;
}
vector<int>pos;
int len;
long long f[N][3][3];
long long g[3][3];
void DP(int u,int father,int d)
{
	if(d==len/2) f[u][1][1]=1;
	else f[u][0][0]=1;
	for(int v:G[u])
	{
		if(v==father) continue;
		DP(v,u,d+1);
		for(int i=0;i<=2;i++)
			for(int j=0;j<=2;j++)
				for(int x=0;x<=2;x++)
					for(int y=0;y<=2;y++)
						for(int k=-1;k<=1;k++)
						{
							int p=min(2,i+x*(k==-1)),q=min(2,j+y*(k==1));
							g[p][q]=(g[p][q]+f[u][i][j]*f[v][x][y]%MOD)%MOD;
						}
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				f[u][i][j]=g[i][j],g[i][j]=0;
	}
	return;
}
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
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	s=p;
	Max=0;
	dfs(s,0);
	t=p;
	for(int u=t;u!=s;u=fa[u])
		pos.push_back(u);
	pos.push_back(s);
	len=pos.size()-1;
	if(len%2==0)
	{
		int x=pos[len/2];
		DP(x,0,0);
		printf("%lld",f[x][1][1]*ksm(2,MOD-2)%MOD);
	}
	else
	{
		int x=pos[(len-1)/2],y=pos[(len+1)/2];
		DP(x,y,0);
		DP(y,x,0);
		long long fx=(f[x][1][0]+f[x][1][1]+f[x][1][2])%MOD,fy=(f[y][0][1]+f[y][1][1]+f[y][2][1])%MOD;
		printf("%lld",fx*fy%MOD);
	}
	return 0;
}
```