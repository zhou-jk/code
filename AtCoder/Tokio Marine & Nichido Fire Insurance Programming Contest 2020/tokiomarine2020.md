#### A - Nickname
直接输出前三个字符。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=25;
char s[N];
int main()
{
	scanf("%s",s+1);
	printf("%c%c%c",s[1],s[2],s[3]);
	return 0;
}
```

------------

#### B - Tag
如果 $v\leq w$，则显然不可能。
如果 $v> w$，计算一下两者相遇需要多少时间就好了。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a,b,v,w;
int t;
int main()
{
	scanf("%d%d",&a,&v);
	scanf("%d%d",&b,&w);
	scanf("%d",&t);
	if(v<=w) printf("NO");
	else if(ceil((double)abs(a-b)/(v-w))>t) printf("NO");
	else printf("YES");
	return 0;
}
```

------------

#### C - Lamps
每次暴力更新，大概是一个区间加单点求和，树状数组维护就好了。直到每个位置的 $a_i$ 都为 $n$ 时退出。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=200005;
int n,k;
int a[N];
struct BIT
{
	int C[N];
	int lowbit(int x)
	{
		return x&-x;
	}
	void clear()
	{
		memset(C,0,sizeof(C));
		return;
	}
	void add(int x,int y)
	{
		if(x>n) return;
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
	void modify(int l,int r,int v)
	{
		l=max(l,1);
		r=min(r,n);
		add(l,v);
		add(r+1,-v);
		return;
	}
};
BIT T;
bool check()
{
	for(int i=1;i<=n;i++)
		if(a[i]<n) return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)
	{
		T.clear();
		for(int i=1;i<=n;i++)
			T.modify(i-a[i],i+a[i],1);
		for(int i=1;i<=n;i++)
			a[i]=T.getsum(i);
		if(check()) break;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
```

------------

#### D - Knapsack Queries on a tree
可以将询问分成两个部分，分成 $\sqrt{n}$ 的两块，将 $\sqrt{n}$ 的块做一个背包，其余的部分暴搜合并一下答案就好了。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=(1<<9)+5,M=100005;
int n,m,Q;
int v[N*N],w[N*N];
long long f[N][M];
bool book[N*N];
long long ans;
void dfs(int u,long long ret,long long sum)
{
	if(ret<0) return;
	if(u<=(1<<9))
	{
		ans=max(ans,sum+f[u][ret]);
		return;
	}
	book[u]=true;
	dfs(u/2,ret-w[u],sum+v[u]);
	book[u]=false;
	dfs(u/2,ret,sum);
	return;
}
void solve()
{
	int u,L;
	scanf("%d%d",&u,&L);
	ans=0;
	dfs(u,L,0);
	printf("%lld\n",ans);
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&v[i],&w[i]);
	m=100000;
	for(int i=1;i<=min(1<<9,n);i++)
	{
		int p=i/2;
		for(int j=0;j<=m;j++)
			if(j>=w[i]) f[i][j]=max(f[p][j],f[p][j-w[i]]+v[i]);
			else f[i][j]=f[p][j];
	}
	scanf("%d",&Q);
	while(Q--)
		solve();
	return 0;
}
```

------------

#### E - O(rand)
对于 $S,T$ 二进制下的第 $i$ 位 $s_i,t_i$，分成几种情况讨论：

- $s_i=1,t_i=0$ 时显然无解；
- $s_i=1,t_i=1$ 时可以将 $a$ 中第 $i$ 位为 $0$ 的数去掉；
- $s_i=0,t_i=0$ 时同理；
- $s_i=0,t_i=1$ 时至少要取一个第 $i$ 位为 $0$ 的数和一个第 $i$ 位为 $1$ 的数。

合法的情况数很难算，考虑计算不合法的情况数然后容斥。对于一位，它不合法的情况大概是全取了同一种数。那么就有一种暴力的想法，$3^{18}$ 暴力容斥当前位全取是 $0$ 还是 $1$ 或者说没有限制。

考虑优化，可以 $2^{18}$ 枚举哪些点是有限制的。考虑一种情况选了 $a_i$，我们就可以确定下每个位置可以填什么，然后再乘上一个组合数就好了。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int N=55,M=(1<<18)+5;
int n,m,k,s,t;
int a[N];
bool book[N];
long long C[N][N];
long long sum[N][N];
void init(int n=50)
{
	for(int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	for(int i=0;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=sum[i][j-1]+C[i][j];
	return;
}
int main()
{
	scanf("%d%d%d%d",&n,&k,&s,&t);
	init();
	m=18;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=m-1;i>=0;i--)
	{
		if((s&(1<<i))==1&&(t&(1<<i))==0)
		{
			printf("0");
			return 0;
		}
		if((s&(1<<i))==(t&(1<<i)))
		{
			for(int j=1;j<=n;j++)
				if((s&(1<<i))!=(a[j]&(1<<i))) book[j]=true;
		}
	}
	vector<int>v;
	for(int i=1;i<=n;i++)
		if(!book[i]) v.push_back(a[i]);
	n=0;
	for(int u:v)
		a[++n]=u;
	long long ans=0;
	for(int state=0;state<(1<<m);state++)
	{
		bool flag=false;
		for(int i=0;i<m;i++)
			if((state&(1<<i))&&(s&(1<<i))==(t&(1<<i)))
			{
				flag=true;
				break;
			}
		if(flag) continue;
		map<int,int>cnt;
		for(int i=1;i<=n;i++)
			cnt[a[i]&state]++;
		long long res=0;
		for(auto [val,num]:cnt)
			res+=sum[num][k];
		if(__builtin_popcount(state)&1) ans-=res;
		else ans+=res;
	}
	printf("%lld",ans);
	return 0;
}
```

------------

#### F - Triangles
令三个点的坐标为 $(a,0),(0,b),(c,w)$ 其他的情况同理；

根据皮克定理，令三角形面积为 $S$，内部格点数为 $i$，边和顶点上格点数为 $b$，有 $2S=2i+b-2$，即 $2S-b+2=2i$。

将问题带入，可得：

$$a\cdot (c-b)+w\cdot b-\gcd(w-a,c)-\gcd(a,b)-\gcd(c-b,w)+2\leq 2k$$

移下项，可得：

$$w\cdot b-\gcd(w-a,c)-\gcd(a,b)\leq 2k-a\cdot (c-b)+\gcd(c-b,w)-2$$

令 $A=w\cdot b-\gcd(w-a,c)-\gcd(a,b),B=2k-a\cdot (c-b)+\gcd(c-b,w)-2$，则 $A\leq B$。

因为 $\gcd(w-a,c)+\gcd(a,b)\leq w-a+a=w$，则 $w\cdot (b-1)\leq A\leq w\cdot b$。

又 $A\leq B$，则 $B\ge A \ge w\cdot (b-1)\ge 0$，那么可以考虑枚举 $d=c-b$，则 $a\leq \frac{2k+\gcd(c-b,w)-2}{c-b}$，枚举 $a$。

考虑如何计算 $b$ 的个数，分为几种情况：

- $R\ge w\cdot b$，即 $b\ge \frac{R}{w}$，显然合法；
- $R< (w-1)\cdot b$，即 $b> \frac{R}{w-1}$，显然不合法；
- $(w-1)\cdot b\leq R\leq w\cdot b$，即 $\frac{R}{w}< b\leq \frac{R}{w-1}$，判断一下合法。

------------

代码：
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int w,h,k;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
long long solve(int w,int h)
{
	long long res=0;
	for(int d=0;d<h;d++)
		for(int a=1;a<w;a++)
		{
			int R=2*k-a*d+gcd(d,w)-2;
			if(R<0) break;
			int b=min(h-1-d,R/w);
			int tmp=b;
			b++;
			if(b+d<h&&w*b-gcd(w-a,b+d)-gcd(a,b)<=R) tmp++;
			if(d==0) res+=tmp;
			else res+=tmp*2;
		}
	return res*2;
}
int main()
{
	scanf("%d%d%d",&w,&h,&k);
	printf("%lld",solve(w,h)+solve(h,w));
	return 0;
}
```