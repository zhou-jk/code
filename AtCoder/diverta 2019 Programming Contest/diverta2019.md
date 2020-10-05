#### A - Consecutive Integers
答案为 $n-k+1$。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	printf("%d",n-k+1);
	return 0;
}
```

------------

#### B - RGB Boxes
枚举 $r,g$，判断一下对应的 $b$ 是否合法即可。

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=3005;
int R,G,B,n;
int main()
{
	scanf("%d%d%d%d",&R,&G,&B,&n);
	int ans=0;
	for(int r=0;r*R<=n;r++)
		for(int g=0;r*R+g*G<=n;g++)
		{
			int ret=n-r*R-g*G;
			if(ret%B==0) ans++;
		}
	printf("%d",ans);
	return 0;
}
```

------------

#### C - AB Substrings
分成三类：

- 以 `B` 开头的以 `A` 结尾的；
- 以 `B` 开头的不以 `A` 结尾的；
- 不以 `B` 开头的以 `A` 结尾的。

首先将第一类的串头尾相接，令其数量为 $x$，如果有第二种和第三种的串，接上去贡献即为 $x+2$。否则分别判下有第二种串或第三种串的情况，贡献为 $x+1$，否则为贡献 $x$。

剩下的情况再加上即可，具体看代码。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=10005;
int n;
string s[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	int ans=0;
	int A=0,B=0,BA=0;
	for(int i=1;i<=n;i++)
	{
		for(size_t j=1;j<s[i].size();j++)
			if(s[i][j-1]=='A'&&s[i][j]=='B') ans++;
		if(s[i].front()=='B'&&s[i].back()=='A') BA++;
		else if(s[i].front()=='B') B++;
		else if(s[i].back()=='A') A++;
	}
	if(BA>0)
	{
		if(A>0&&B>0) A--,B--,BA--,ans+=2;
		else if(A>0) A--,BA--,ans++;
		else if(B>0) B--,BA--,ans++;
		else BA--;
	}
	ans+=min(A,B)+BA;
	printf("%d",ans);
	return 0;
}
```

------------

#### D - DivRem Number
$$\lfloor \frac{N}{m} \rfloor = N \bmod m = N- \lfloor \frac{N}{m} \rfloor \cdot m$$

$$\lfloor \frac{N}{m} \rfloor (m+1)=N$$

暴力枚举 $(m+1)$，判断一下是否合法。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n;
bool check(long long x)
{
	long long m=x-1;
	return (m+1)*(n/m)==n;
}
int main()
{
	scanf("%lld",&n);
	long long ans=0;
	for(long long i=2;i<=sqrt(n);i++)
		if(n%i==0)
		{
			if(check(i)) ans+=i-1;
			if(i*i!=n&&check(n/i)) ans+=n/i-1;
		}
	if(n!=1&&check(n)) ans+=n-1;
	printf("%lld",ans);
	return 0;
}
```

------------

#### E - XOR Partitioning
令 $s$ 为 $a$ 的前缀异或和，则一种合法的划分方案 $x_1,x_2,\ldots x_n$ 一定满足 $s_{x_1}=s_{x_3}=\cdots$，$s_{x_2}=s_{x_4}=\cdots =0$。

那么就可以 DP，令 $f_i$ 表示选了第 $i$ 位的方案数，转移时枚举上一个位置 $j$，需要在 $[j+1,i-1]$ 中选出一个 $0$。

需要对 $f_n\neq 0$ 和 $f_n=0$ 的情况分类讨论。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=500005,M=(1<<20)+5;
const int MOD=1000000007;
int n;
int a[N],s[N];
vector<int>pos[M];
long long dp[N];
long long f[M],g[M];
int sum[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sum[0]=1;
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]^a[i];
		pos[s[i]].push_back(i);
		sum[i]=sum[i-1];
		if(s[i]==0) sum[i]++;
	}
	for(int i=1;i<=n;i++)
		if(s[i])
		{
			dp[i]=1;
			dp[i]=(dp[i]+f[s[i]]*sum[i]%MOD-g[s[i]]+MOD)%MOD;
			f[s[i]]=(f[s[i]]+dp[i])%MOD,g[s[i]]=(g[s[i]]+dp[i]*sum[i]%MOD)%MOD;
		}
		else
		{
			dp[i]=1;
			dp[i]=(dp[i]+f[s[i]])%MOD;
			f[s[i]]=(f[s[i]]+dp[i])%MOD,g[s[i]]=(g[s[i]]+dp[i]*sum[i]%MOD)%MOD;
		}
	long long ans=dp[n];
	if(!s[n]) 
	{
		for(int i=1;i<=n;i++)
			if(s[i]) ans=(ans+dp[i])%MOD;
	}
	printf("%lld",ans);
	return 0;
}
```

------------

#### F - Edge Ordering
可以看 myh 的题解：[link](https://autumnkite.github.io/atcoder-diverta2019/)

------------

```cpp
#include<iostream>
#include<cstdio>
#include<tuple>
using namespace std;
const int N=25;
const int MOD=1000000007;
int n,m;
int x[N*N],y[N*N];
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
long long fac[N*N],inv[N*N];
void init(int n=400)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%MOD;
	return;
}
struct Union_Set
{
	int fa[N];
	void init()
	{
		for(int i=0;i<n;i++)
			fa[i]=i;
		return;
	}
	int getf(int v)
	{
		if(v==fa[v]) return v;
		fa[v]=getf(fa[v]);
		return fa[v];
	}
	void merge(int u,int v)
	{
		int f1=getf(u),f2=getf(v);
		if(f1!=f2) fa[f2]=f1;
		return;
	}
};
tuple<int,int,long long,long long> f[1<<N]; 
int main()
{
	init();
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		x[i]--,y[i]--;
	}
	for(int S=0;S<(1<<(n-1));S++)
	{
		Union_Set D;
		D.init();
		int b=n-1,num=m;
		for(int i=0;i<n-1;i++)
			if(S&(1<<i))
			{
				D.merge(x[i],y[i]);
				b--,num--;
			}
		for(int i=n-1;i<m;i++)
			if(D.getf(x[i])==D.getf(y[i])) num--;
		f[S]=make_tuple(num,b,0,0);
	}
	f[(1<<(n-1))-1]=make_tuple(0,0,1,0);
	for(int S=(1<<(n-1))-1-1;S>=0;S--)
		for(int i=0;i<n-1;i++)
			if(!(S&(1<<i)))
			{
				int T=S|(1<<i);
				int &n=get<0>(f[T]),&sn=get<0>(f[S]);
				int k=sn-n-1;
				long long &c=get<2>(f[T]),&sc=get<2>(f[S]);
				sc=(sc+fac[n+k]*inv[n]%MOD*c%MOD)%MOD;
				int &sb=get<1>(f[S]);
				long long &s=get<3>(f[T]),&st=get<3>(f[S]);
				st=((st+fac[n+k+1]%MOD*inv[n+1]%MOD*s%MOD)%MOD+sb*fac[n+k]%MOD*inv[n]%MOD*c%MOD)%MOD;
			}
	printf("%lld",get<3>(f[0]));
	return 0;
}
```