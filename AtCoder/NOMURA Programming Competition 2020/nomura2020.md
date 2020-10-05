#### A - Study Scheduling
先算出总时间，然后在减去 $K$ 就好了。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int h1,m1,h2,m2,k;
int main()
{
	scanf("%d%d%d%d%d",&h1,&m1,&h2,&m2,&k);
	int ansh=h2-h1,ansm=m2-m1;
	if(ansm<0) ansm+=60,ansh--;
	if(ansh<0) ansh+=24;
	int t=ansh*60+ansm;
	t-=k;
	printf("%d",max(t,0));
	return 0;
}
```

------------

#### B - Postdocs
可以发现，将所有的 `P` 换成 `D` 答案肯定不会更劣，将所有 `?` 换成 `D` 就好了。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
int n;
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='?') s[i]='D';
	printf("%s",s+1);
	return 0;
}
```

------------

#### C - Lamps
考虑从下往上做，预处理出第 $i$ 层满足第 $n$ 行肯定有 $a_n$ 个点的最大值 $g_i$；再从上往下做，第 $1$ 行有 $1$ 个点，预处理出第 $i$ 层满足第 $1$ 行有 $1$ 个点的最大值 $f_i$，每层的答案就是取个最小值。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100005;
int n;
int a[N];
long long f[N],g[N];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		scanf("%d",&a[i]);
	if(a[0]>1)
	{
		printf("-1");
		return 0;
	}
	g[n]=a[n];
	for(int i=n-1;i>=0;i--)
		g[i]=g[i+1]+a[i];
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=min((f[i-1]-a[i-1])*2,g[i]);
		if(a[i]>f[i])
		{
			printf("-1");
			return 0;
		}
	}
	long long ans=0;
	for(int i=0;i<=n;i++)
		ans+=f[i];
	printf("%lld",ans);
	return 0;
}
```

------------

#### D - Urban Planning
考虑如果 $p_i\neq -1$，将 $i$ 向 $p_i$ 连边，可以发现，最后的肯定是基环树森林，答案就是 $n$ 减环数。考虑计算所有的环数，然后再用总数 $n(n-1)^k$ 减去就是答案，一个环的贡献就是 $(n-1)^k$。

考虑加入了 $p_i=-1$，图中多出了树的情况。我们考虑一个环，它的大小为 $a_1,a_2,\cdots a_m$ 的树构成的，它对答案的贡献即为 $(\prod a_i)(m-1)!(n-1)^{k-m}$（注意特判 $1$ 的情况）。

考虑计算贡献，令 $f_{i,j}$ 表示前 $i$ 棵树，选了 $j$ 个树的 $\sum (\prod a_k)$，然后枚举选的树的数量加入答案中就好了。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=5005;
const int MOD=1000000007;
int n,k;
int p[N];
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
vector<int>G[N];
bool vis[N];
int cnt,tot;
bool flag;
int a[N],m;
void dfs(int u,int father)
{
	if(vis[u])
	{
		if(!flag) cnt++;
		flag=true;
		return;
	}
	vis[u]=true;
	tot++;
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
	}
	return;
}
long long fac[N];
void init(int n=5000)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	return;
}
long long dp[N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if(p[i]==-1) k++;
		else G[i].push_back(p[i]),G[p[i]].push_back(i);
	}
	for(int u=1;u<=n;u++)
		if(!vis[u])
		{
			flag=false;
			tot=0;
			dfs(u,0);
			if(!flag) a[++m]=tot;
		}
	long long ans=n*ksm(n-1,k)%MOD;
	ans=(ans-cnt*ksm(n-1,k)%MOD+MOD)%MOD;
	dp[0][0]=1;
	for(int i=1;i<=k;i++)
	{
		dp[i][0]=1;
		for(int j=1;j<=i;j++)
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*a[i]%MOD)%MOD;
	}
	init();
	if(k>=1) ans=(ans-(dp[k][1]-k)*ksm(n-1,k-1)%MOD+MOD)%MOD;
	for(int i=2;i<=k;i++)
		ans=(ans-dp[k][i]*fac[i-1]%MOD*ksm(n-1,k-i)%MOD+MOD)%MOD;
	printf("%lld",ans);
	return 0;
}
```

------------

#### E - Binary Programming
考虑一种贪心，肯定是先删 $0$ 再删 $1$，显然奇数位置的 $0$，然后再从后往前删。

考虑将连续的一段缩起来一起考虑，对于一段长度为偶数的连续的 $1$，可以发现贡献是固定的，对于一段长度为奇数的连续的 $1$，我们只需要考虑多出来的那个 $1$ 的贡献，这个贪心一下就好了。

这时候只剩下了 $1$，这个直接算一下就好了。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
int n;
char s[N];
char a[N];
int len[N],l[N];
int m;
int sum[N][2];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1,j=1;i<=n;i=j)
	{
		while(j<=n&&s[i]==s[j]) j++;
		m++,a[m]=s[i],len[m]=j-i;
	}
	for(int i=1;i<=m;i++)
	{
		sum[i][0]+=sum[i-1][0];
		sum[i][1]+=sum[i-1][1];
		sum[i][a[i]-'0']+=len[i];
		l[i]=l[i-1]+len[i];
	}
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i]=='1')
		{
			if(len[i]&1)
			{
				ans+=(sum[i][0]+l[i]%2)/2;
				ans+=sum[m][0]-sum[i][0];
				int t=len[i]/2;
				ans+=sum[i][0]*t;
				ans+=(sum[m][0]-sum[i][0])*t;
			}
			else
			{
				int t=len[i]/2;
				ans+=sum[i][0]*t;
				ans+=(sum[m][0]-sum[i][0])*t;
			}
		}
	}
	for(int i=0;i<=sum[m][1];i++)
	{
		int s=sum[m][1]-i;
		ans+=(s+1)/2;
	}
	printf("%lld",ans);
	return 0;
}
```

------------

#### F - Sorting Game
可以发现，如果 $a$ 合法，对于某一位，如果**这一位**上 $a_i=1,a_j=0$，则 $a_i,a_j$ 的更低位肯定相同。

令 $f_{i,j}$ 表示当前填到第 $i$ 层，总共有 $j$ 个数的方案数。

考虑当前层填什么，

1. 如果填 $0\ldots 01 \ldots1$，这层的填数方案有 $j+1$ 种，转移为：$f_{i-1,j}\cdot j\to f_{i,j}$。
2. 如果填 $0\ldots 0 \mathbf{1x\ldots x0} 1\ldots 1$，不妨看成是在 $0\ldots 01\ldots 1$ 中插入 $\mathbf{x\ldots x0}$，这个的方案数即为 $\sum\limits_{k=1}^{j-1} f_{i-1,k}\cdot k\cdot 2^{j-k-1}$。

直接转移是 $O(NM^2)$ 的，前缀和优化一波就是 $O(NM)$ 的了。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=5005;
const int MOD=1000000007;
int n,m;
long long dp[N][N];
long long sum[N][N];
long long Pw[N],inP[N];
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
void init(int n=5000)
{
	Pw[0]=1;
	for(int i=1;i<=n;i++)
		Pw[i]=Pw[i-1]*2%MOD;
	inP[n]=ksm(Pw[n],MOD-2);
	for(int i=n;i>=1;i--)
		inP[i-1]=inP[i]*2%MOD;
	return;
}
int main()
{
	init();
	scanf("%d%d",&n,&m);
	for(int j=1;j<=m;j++)
		dp[0][j]=1,sum[0][j]=(sum[0][j-1]+dp[0][j]*j%MOD*inP[j]%MOD)%MOD;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=dp[i-1][j]*(j+1)%MOD;
			dp[i][j]=(dp[i][j]+sum[i-1][j-1]*Pw[j-1]%MOD)%MOD;
			sum[i][j]=(sum[i][j-1]+dp[i][j]*j%MOD*inP[j]%MOD)%MOD;
		}
	printf("%lld",dp[n][m]);
	return 0;
}
```