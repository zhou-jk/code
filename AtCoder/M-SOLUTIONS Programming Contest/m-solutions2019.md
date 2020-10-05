#### A - Sum of Interior Angles
答案为 $180(n-2)$。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	printf("%d",180*(n-2));
	return 0;
}
```

------------

#### B - Sumo
判断一下 `x` 的个数是否小于等于 $7$。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=20;
int n;
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='x') cnt++;
	if(15-cnt>=8) printf("YES");
	else printf("NO");
	return 0;
}
```

------------

#### C - Best-of-(2n-1)
令 $a=\frac{A}{100}$，$b=\frac{B}{100}$。

先不考虑 $c$，最后再将 $c$ 加入。考虑确定了 $A,B$ 的顺序以后，如果在第 $n$ 局停止，我们有 $n$ 个位置可以插入 $c$。则插入的 $c$ 的期望个数为：

$$\sum\limits_{i=0}^{n} C_{n}^{i}\cdot i\sum\limits_{k=0}^{\infty}(1-a-b)^k=\frac{1}{a+b}$$

考虑计算没有平局的情况。枚举在第 $i$ 局停止，则概率为

$$a^{n}b^{i-n}C_{i-1}^{n-1}+b^{n}a^{i-n}C_{i-1}^{n-1}$$

直接计算即可。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const int MOD=1000000007;
int n;
int A,B,c;
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
void init(int n=200000)
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
int main()
{
	init();
	scanf("%d",&n);
	scanf("%d%d%d",&A,&B,&c);
	int a=1LL*A*ksm(A+B,MOD-2)%MOD,b=1LL*B*ksm(A+B,MOD-2)%MOD;
	long long ans=0;
	for(int i=n;i<n*2;i++)
	{
		long long res=(ksm(a,n)*ksm(b,i-n)%MOD*C(i-1,n-1)%MOD+ksm(b,n)*ksm(a,i-n)%MOD*C(i-1,n-1)%MOD)%MOD*i%MOD;
		ans=(ans+res)%MOD;
	}
	ans=ans*100%MOD*ksm(A+B,MOD-2)%MOD;
	printf("%lld",ans);
	return 0;
}
```

------------

#### D - Maximum Sum of Minimum
考虑贪心，每次贪心将最小的给叶子节点，这样子的答案即为前 $n-1$ 小的元素之和，可以证明这是最优的。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=10005;
int n;
int c[N];
int d[N],tot;
vector<int>G[N];
void dfs(int u,int father)
{
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
	}
	d[u]=c[++tot];
	return;
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
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	dfs(1,0);
	int sum=0;
	for(int i=1;i<n;i++)
		sum+=c[i];
	printf("%d\n",sum);
	for(int i=1;i<=n;i++)
		printf("%d ",d[i]);
	return 0;
}
```

------------

#### E - Product of Arithmetic Progression
考虑 $d=1$ 时用两个阶乘除一下就好了。$d> 1$ 的情况将每一项都除以 $d$，问题就变成了 $d=1$ 的情况。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000003;
int Q;
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
long long fac[MOD],inv[MOD];
void init(int n=1000002)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%MOD;
	return;
}
void solve()
{
	int x,d,n;
	scanf("%d%d%d",&x,&d,&n);
	if(d==0)
	{
		printf("%lld\n",ksm(x,n));
		return;
	}
	x=x*ksm(d,MOD-2)%MOD;
	if(x==0||x+n-1>=MOD)
	{
		printf("0\n");
		return;
	}
	long long ans=fac[x+n-1]*inv[x-1]%MOD;
	printf("%lld\n",ans*ksm(d,n)%MOD);
	return;
}
int main()
{
	init();
	scanf("%d",&Q);
	while(Q--)
		solve();
	return 0;
}
```

------------

#### F - Random Tournament
考虑 DP，令 $fl_{l,r}$ 表示 $l$ 能否打败 $[l,r]$，$fr_{l,r}$ 表示 $r$ 能否打败 $[l,r]$。

以 $fl$ 的转移为例，枚举 $l$ 最后打败的人 $k$。合法的条件即为存在一个 $u$ 使得 $i$ 能打败 $[i+1,u]$ 且 $k$ 能打败 $[u+1,j]$，可以发现 $u$ 有用的只有 $i+1$。因为如果 $u$ 能够打败 $k$，这种情况应该在 $k=u$ 时已经计算过了，否则 $k$ 显然是可以再往前拓展一格的。这种情况下 $i$ 想要获胜的条件即为 $i$ 能够打败 $k$ 且 $fr_{i+1,k}$ 和 $fl_{k,r}$ 均为真。$fr$ 同理。

这个可以用 bitset 优化，或者说跟我一样大力卡常就可以通过此题。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2005;
int n;
int a[N][N];
bool fl[N][N],fr[N][N];
vector<int>pos[N];
int main()
{
	freopen("114.in","r",stdin);
	freopen("114.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i-1;j++)
			scanf("%1d",&a[i][j]),a[j][i]=a[i][j]^1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]) pos[i].push_back(j);
	for(int i=1;i<=n;i++)
		fl[i][i]=fr[i][i]=true;
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			int l=lower_bound(pos[i].begin(),pos[i].end(),i+1)-pos[i].begin(),r=upper_bound(pos[i].begin(),pos[i].end(),j)-pos[i].begin()-1;
			for(int p=l;p<=r;p++)
			{
				int k=pos[i][p];
				fl[i][j]|=fr[i+1][k]&fl[k][j];
				if(fl[i][j]) break;
			}
			l=lower_bound(pos[j].begin(),pos[j].end(),i)-pos[j].begin(),r=upper_bound(pos[j].begin(),pos[j].end(),j-1)-pos[j].begin()-1;
			for(int p=l;p<=r;p++)
			{
				int k=pos[j][p];
				fr[i][j]|=fr[i][k]&fl[k][j-1];
				if(fr[i][j]) break;
			}
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(fr[1][i]&&fl[i][n]) ans++;
	printf("%d",ans);
	return 0;
}
```