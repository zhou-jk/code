#### A - Painting

------------

每次取 $H,W$ 中较大者涂就是了，输出 $\lceil \frac{n}{\max(H,W)}\rceil$。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int h,w,n;
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	if(h<w) swap(h,w);
	printf("%d",(n+h-1)/h);
	return 0;
}
```

------------

#### B - Robot Arms
考虑贪心，按照左端点从大到小排序，然后每次贪心的如果能将当前线段加入答案就加入答案，因为如果选后面的线段的话左端点只会更小，答案不会更优。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
const int INF=1061109567;
int n;
struct Node
{
	int l,r;
}a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,l;
		scanf("%d%d",&x,&l);
		a[i].l=x-l,a[i].r=x+l;
	}
	sort(a+1,a+n+1,[=](const Node &a,const Node &b){return a.l==b.l?a.r<b.r:a.l>b.l;});
	int ans=0,now=INF+INF;
	for(int i=1;i<=n;i++)
		if(a[i].r<=now) ans++,now=min(now,a[i].l);
	printf("%d",ans);
	return 0;
}
```

------------

#### C - Subarray Sum
构造连续的 $k$ 个 $S$，其他的都填 $10^9$，当 $S=10^9$ 时特判一下就好了。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int n,k,s;
int main()
{
	scanf("%d%d%d",&n,&k,&s);
	for(int i=1;i<=k;i++)
		printf("%d ",s);
	for(int i=1;i<=n-k;i++)
		printf("%d ",s==1000000000?1000000000-1:1000000000); 
	return 0;
}
```

------------

#### D - Swap and Flip
可以发现，对于一个点 $i$，如果它最后到了 $p_i$，那么它为正面的条件为 $2|i-p_i$，否则为反面。

考虑状压 DP，令 $f_{s,i}$ 表示当前已经确定了结果序列前 $t$ 个（$t$ 表示 $s$ 二进制中 $1$ 的个数）放 $s$ 这个集合的数，最后一个放的点为 $i$ 的最小步数。可以知道当前放的点的位置为 $t$ 这个位置，就可以判断出当前点是否为正面。枚举上一个放的位置 $j$，每次将新产生的逆序对加入贡献就好了。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20;
const int INF=1061109567;
int n;
int a[N],b[N];
int f[1<<N][N];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	memset(f,63,sizeof(f));
	f[0][0]=0;
	for(int s=1;s<(1<<n);s++)
	{
		int t=__builtin_popcount(s);
		for(int i=0;i<n;i++)
			if(s&(1<<i))
			{
				int v=(abs(t-(i+1))&1)?b[i]:a[i];
				int num=0;
				for(int j=i+1;j<n;j++)
					if(s&(1<<j)) num++;
				for(int j=0;j<n;j++)
					if((s^(1<<i))==0)
					{
						f[s][i]=min(f[s][i],f[s^(1<<i)][j]+num);
						continue;
					}
					else if((s^(1<<i))&(1<<j))
					{
						int vt=(abs(t-1-(j+1))&1)?b[j]:a[j];
						if(vt<=v) f[s][i]=min(f[s][i],f[s^(1<<i)][j]+num);
					}
			}
	}
	int ans=INF;
	for(int i=0;i<n;i++)
		ans=min(ans,f[(1<<n)-1][i]);
	if(ans>=INF) printf("-1");
	else printf("%d",ans);
	return 0;
}
```

------------

#### E - Bichromization
可以发现，对于有解的情况，我们肯定可以将每个 $d_i$ 对应一条边的权值。

考虑一种匹配的过程，如果对于一个点 $u$，如果它与另一个点 $v$ 匹配，点 $v$ 可以选择与 $u$ 配对或者选另一个点配对，这种情况下肯定有 $d_v\ge d_u$。

考虑贪心，每次按照 $d_i$ 从小到大枚举。对于每个点 $u$，如果它有与其相邻的 $d_u=d_v$，那么就将两个点匹配；否则找一个已经染过色的点匹配，如果找不到的话说明无解。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int d[N];
int id[N];
vector<pair<int,int> >G[N];
int col[N];
int ans[N<<1];
void draw(int u)
{
	if(col[u]) return;
	for(auto [v,i]:G[u])
		if(col[v]==0&&d[u]==d[v])
		{
			col[u]=1,col[v]=2;
			ans[i]=d[u];
			return;
		}
	for(auto [v,i]:G[u])
		if(col[v])
		{
			col[u]=col[v]==1?2:1;
			ans[i]=d[u];
			return;
		}
	printf("-1");
	exit(0);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&d[i]),id[i]=i;
	sort(id+1,id+n+1,[=](const int &x,const int &y){return d[x]<d[y];});
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(make_pair(y,i));
		G[y].push_back(make_pair(x,i));
	}
	for(int i=1;i<=n;i++)
		draw(id[i]);
	for(int i=1;i<=m;i++)
		if(!ans[i]) ans[i]=1e9;
	for(int i=1;i<=n;i++)
		if(col[i]==1) printf("W");
		else if(col[i]==2) printf("B");
	printf("\n");
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}
```

------------

#### F - Monochromization
考虑一个最终的矩阵，我们考虑从后往前操作。

我们称一行或一列为可移除的当且仅当这行或这列的颜色相同，我们可以定义两种与题意中等价的操作：

- 将所有可移除行删除（剩下的行形成一个新的矩阵）；
- 将所有可移除列删除（剩下的列形成一个新的矩阵）。

可以发现，我们每次交替的进行两种操作，一个最终的矩形所对应的操作序列是唯一的。我们只需要计算合法的操作序列即可。

可以发现，我们并不需要考虑具体的矩形长什么样子，我们只需要考虑它的行数和列数还有每次移除的颜色种类。

令 $f_{i,j,k}$ 表示上一次移除的是行，还有 $i$ 行 $j$ 列没有移除，上次移除的行有 $k$ 种不同的颜色；$g_{i,j,k}$ 表示上一次移除的是列，还有 $i$ 行 $j$ 列没有移除，上次移除的列有 $k$ 种不同的颜色。

可以发现，如果上次移除的列都是黑色，我们当前移除了黑色的行，那么我们显然可以在上一次删行时把这一行删掉。所以我们当前移除的行必然都是白色的。

那么我们可以得出转移：

$(2\cdot f_{i,j,2}+f_{i,j,1})\cdot C(i,i-k)\to g_{k,j,1} (k< i)$

$f_{i,j,2}\cdot C(i,i-k)\cdot (2^{i-k}-2)\to g_{k,j,1} (k< i)$

DP 完成后，枚举最后保留的行和列，合法的条件即为是保留的行和列组成的矩阵不存在可移除行和可移除列，需要除以两个组合数。

实现时注意边界问题就可以了。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=15;
const int MOD=998244353;
int n,m;
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
long long fac[N],inv[N];
long long Pw[N];
void init(int n=10)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%MOD;
	Pw[0]=1;
	for(int i=1;i<=n;i++)
		Pw[i]=Pw[i-1]*2%MOD;
	return;
}
long long C(int n,int m)
{
	if(m>n) return 0;
	else return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int r[N],c[N];
char s[N][N];
long long f[N][N][3],g[N][N][3];
int main()
{
	init();
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			 if(s[i][j]=='.') r[i]|=1<<j,c[j]|=1<<i;
	for(int j=1;j<=m;j++)
		g[n][j][2]=C(m,j)*Pw[m-j]%MOD;
	long long ans=Pw[m];
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
		{
			g[i][j][0]=(g[i][j][1]+g[i][j][2])%MOD;
			for(int k=1;k<i;k++)
			{
				int d=i-k;
				f[k][j][1]=(f[k][j][1]+C(i,d)*(g[i][j][2]*2+g[i][j][1])%MOD)%MOD;
				f[k][j][2]=(f[k][j][2]+C(i,d)*(Pw[d]-2)%MOD*g[i][j][2]%MOD)%MOD;
			}
			ans=(ans+g[i][j][2]*(Pw[i]-2)%MOD)%MOD;
			f[i][j][0]=(f[i][j][1]+f[i][j][2])%MOD;
			for(int k=1;k<j;k++)
			{
				int d=j-k;
				g[i][k][1]=(g[i][k][1]+C(j,d)*(f[i][j][2]*2+f[i][j][1])%MOD)%MOD;
				g[i][k][2]=(g[i][k][2]+C(j,d)*(Pw[d]-2)%MOD*f[i][j][2]%MOD)%MOD;
			}
			ans=(ans+f[i][j][2]*(Pw[j]-2)%MOD)%MOD;
		}
	for(int i=1;i<(1<<n);i++)
		for(int j=1;j<(1<<m);j++)
		{
			bool flag=true;
			for(int k=0;k<n;k++)
				if(i&(1<<k))
				{
					int w=r[k]&j;
					if(w==j||w==0)
					{
						flag=false;
						break;
					}
				}
			if(!flag) continue;
			for(int k=0;k<m;k++)
				if(j&(1<<k))
				{
					int w=c[k]&i;
					if(w==i||w==0)
					{
						flag=false;
						break;
					}
				}
			if(!flag) continue;
			int x=__builtin_popcount(i),y=__builtin_popcount(j);
			ans=(ans+(f[x][y][0]+g[x][y][0])%MOD*ksm(C(n,x),MOD-2)%MOD*ksm(C(m,y),MOD-2)%MOD)%MOD;
		}
	printf("%lld",ans);
	return 0;
}
```