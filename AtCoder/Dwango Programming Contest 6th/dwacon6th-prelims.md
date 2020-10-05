#### A - Falling Asleep
找到第一个相等的位置，然后暴力往后加就是了。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=55;
int n; 
string s[N];
string t;
int a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i]>>a[i];
	cin>>t;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(s[i]==t)
		{
			for(int j=i+1;j<=n;j++)
				ans+=a[j];
			printf("%d",ans);
			return 0;
		}
	return 0;
}
```

------------

#### B - Fusing Slimes
令 $f_i$ 表示将前 $i$ 个石子合并，第 $i$ 条线段被经过的期望次数，因为 $i-1$ 左边的点要经过第 $i$ 条线段必然要经过 $i-1$ 条线段，加上第一次就选了第 $i$ 个点的概率 $\frac{1}{i}$ 可以得出：

$$f_i=f_{i-1}+\frac{1}{i}$$

直接递推即可。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
const int MOD=1000000007;
int n;
int x[N];
long long inv[N];
void init(int n=100000)
{
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	return;
}
long long f[N];
int main()
{
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+inv[i];
	long long ans=0;
	for(int i=1;i<n;i++)
		ans=(ans+(x[i+1]-x[i])*f[i]%MOD)%MOD;
	for(int i=1;i<n;i++)
		ans=ans*i%MOD;
	printf("%lld",ans);
	return 0;
}
```

------------

#### C - Cookie Distribution
考虑 $c_1 \times c_2 \times \ldots \times c_N$ 的组合意义，就是从每个盒子里面取出一个小球的方案数。

可以将问题转化一下，转化成有 $K\times N$ 的矩阵，第 $i$ 行有 $a_i$ 个位置被染成了红色，每列里面选一个红色的位置染成蓝色的方案数。

考虑 DP，令 $f_{i,j}$ 表示前 $i$ 行已经有 $j$ 列已经染过蓝色了的方案数，其中 $j$ 的转移是单调不减的。那么可以枚举当前行填的蓝色格的数量，剩下的位置可以随便填，可以得出转移：

$$f_{i,j}=\sum f_{i-1,j-l}\cdot C_{i-(j-l)}^l\cdot C_{n-l}^{a_i-l}$$

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1005,K=25;
const int MOD=1000000007;
int n,k;
int a[K];
long long C[N][N];
void init(int n=1000)
{
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=n;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	return;
}
long long dp[K][N];
int main()
{
	init();
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	dp[0][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			for(int l=0;l<=min(j,a[i]);l++)
				dp[i][j]=(dp[i][j]+dp[i-1][j-l]*C[n-(j-l)][l]%MOD*C[n-l][a[i]-l]%MOD)%MOD;
	printf("%lld",dp[k][n]);
	return 0;
}
```

------------

#### D - Arrangement
可以发现，只有当 $n=2$ 时不合法。

考虑贪心，不妨将 $i\to a_i$ 连边，一种简单的想法是按照字典序从小往大填，如果当前点是上一个点的后继，那么选字典序次小的。但是这种方法有可能会出现无解的情况，主要是两种情况：

- 当前的所有点都指向了某个点，那么我们需要先选这个点，否则这个点到最后都没法选；
- 最后只剩下了一个大小为 $2$ 的环，需要特判一下最后三个点，先选一个环内的然后选一个环外再选环内的；

这样构造出的方案就是合法了的。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
const int N=100005;
int n;
int a[N];
int deg[N];
set<int>S;
set<pair<int,int> >e;
bool book[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),deg[a[i]]++;
	if(n==2) return printf("-1"),0;
	for(int i=1;i<=n;i++)
		S.insert(i),e.insert(make_pair(-deg[i],i));
	int pre=0;
	vector<int>ans;
	for(int i=1;i<=n-3;i++)
	{
		int u;
		if(-(e.begin()->first)==n-i) u=e.begin()->second;
		else if(*S.begin()!=pre) u=*S.begin();
		else if(S.size()>=2) u=*(++S.begin());
		else return printf("-1"),0;
		S.erase(u);
		e.erase(make_pair(-deg[u],u));
		book[u]=true;
		if(!book[a[u]])
		{
			e.erase(make_pair(-deg[a[u]],a[u]));
			deg[a[u]]--;
			e.insert(make_pair(-deg[a[u]],a[u]));
		}
		pre=a[u];
		ans.push_back(u);
	}
	vector<int>d;
	for(int u:S)
		d.push_back(u);
	bool flag=false;
	for(int i=0;i<d.size();i++)
		for(int j=i+1;j<d.size();j++)
			if(a[d[i]]==d[j]&&a[d[j]]==d[i]&&!flag)
			{
				flag=true;
				int k;
				for(k=0;k<d.size();k++)
					if(k!=i&&k!=j) break;
				if(pre!=d[i]&&a[d[i]]!=d[k]&&a[d[k]]!=d[j]) ans.push_back(d[i]);
				else if(pre!=d[j]&&a[d[j]]!=d[k]&&a[d[k]]!=d[i]) ans.push_back(d[j]);
				else return printf("-1"),0;
				ans.push_back(d[k]);
				if(pre!=d[i]&&a[d[i]]!=d[k]&&a[d[k]]!=d[j]) ans.push_back(d[j]);
				else if(pre!=d[j]&&a[d[j]]!=d[k]&&a[d[k]]!=d[i]) ans.push_back(d[i]);
				else return printf("-1"),0;
				break;
			}
	if(!flag)
	{
		for(int i=n-2;i<=n;i++)
		{
			int u;
			if(-(e.begin()->first)==n-i) u=e.begin()->second;
			else if(*S.begin()!=pre) u=*S.begin();
			else if(S.size()>=2) u=*(++S.begin());
			else return printf("-1"),0;
			S.erase(u);
			e.erase(make_pair(-deg[u],u));
			book[u]=true;
			if(!book[a[u]])
			{
				e.erase(make_pair(-deg[a[u]],a[u]));
				deg[a[u]]--;
				e.insert(make_pair(-deg[a[u]],a[u]));
			}
			pre=a[u];
			ans.push_back(u);
		}
	}
	for(int u:ans)
		printf("%d ",u);
	return 0;
}
```

------------

#### E - Span Covering
考虑容斥，考虑计算至少有 $k$ 个位置没有放的方案数。

可以发现，这些点可以把整个区间分割成若干段。不妨设 $a_i$ 表示长度为 $i$ 的段的数量。对于一个长度为 $L_i$ 的段，如果线段长度为 $k$，则方案数为 $k-L_i+1$。

可以知道对于当前情况的方案数为：

$$\prod\limits_{i = 1}^N \left(\sum\limits_{j \ge L_i} a_j (j + 1 - L_i)\right) $$

那么就可以容斥了。但是时间复杂度爆炸，考虑优化：

令 $c_i$ 表示长度为 $i$ 的线段个数，考虑计算如果所有 $a_i$ 为固定的方案数，令 $S_1=\sum\limits_{i=1}^X a_i$，$S_2=\sum\limits_{i=1}^X i a_i$，则有：

$$\left(\prod\limits_{i = 1}^{X} \left(\sum\limits_{j \ge i} a_j (j + 1 - i))^{c_i}\right)\right) \cdot \left(\prod\limits_{i=1}^X\frac{1}{a_i!}\right) \cdot  S_1! \cdot (-1)^{X - S_2} \cdot C_{X - S_2 + 1} ^{S_1}$$

考虑计算：

$$\left(\prod\limits_{i = 1}^{X} \left(\sum\limits_{j \ge i} a_j (j + 1 - i))^{c_i}\right)\right) \cdot \left(\prod\limits_{i=1}^X\frac{1}{a_i!}\right)=\prod\limits_{i = 1}^{X} \frac{1}{a_i!}\left(\sum\limits_{j \ge i} a_j (j + 1 - i))^{c_i}\right)$$

令 $f_{i,j,k}$ 表示从大到小填 $a_i$，$j=\sum\limits_{l=i}^X a_i$，$k=\sum\limits_{l=i}^X ia_i$ 时的方案数。考虑枚举当前的填的数 $l$ 转移：

$$f_{i, j, k} = \sum\limits_{l = 0}^{\min(j,\lfloor \frac{k}{i}\rfloor )} (f_{i + 1, j - l, k - i\cdot l} \cdot \frac{1}{l!} \cdot (k - (i - 1) \cdot j)^{c_i})$$

最后的答案即为

$$\sum_{j = 0}^{X} \sum_{k = j}^X ((-1)^{X - j} C_{X - j + 1}^i \cdot i! \cdot f_{1, i, j})$$

可以证明这样的时间复杂度约为 $O(\frac{\pi^2}{6} X^3)$ 的。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=505;
const int MOD=1000000007;
int n,m;
int c[N];
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
void init(int n=500)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%MOD;
	return;
}
long long C(int n,int m)
{
	if(m>n) return 0;
	else return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
long long f[N][N][N];
int main()
{
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		c[x]++;
	}
	f[m+1][0][0]=1;
	for(int i=m;i>=1;i--)
		for(int j=0;j<=m;j++)
			for(int k=i*j;k<=m;k++)
			{
				long long mul=ksm(k-(i-1)*j,c[i])%MOD;
				for(int l=0;l<=min(j,k/i);l++)
					f[i][j][k]=(f[i][j][k]+f[i+1][j-l][k-i*l]*inv[l]%MOD*mul%MOD)%MOD;
			}
	long long ans=0;
	for(int j=0;j<=m;j++)
		for(int k=j;k<=m;k++)
		{
			long long res=C(m-k+1,j)*fac[j]%MOD*f[1][j][k]%MOD;
			if((m-k)&1) ans=(ans-res+MOD)%MOD;
			else ans=(ans+res)%MOD;
		}
	printf("%lld",ans);
	return 0;
}
```