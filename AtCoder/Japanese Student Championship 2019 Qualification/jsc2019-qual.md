#### A - Takahashi Calendar
枚举 $m$，再枚举 $d_1$，判断一下是否合法即可。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int m,d;
int main()
{
	scanf("%d%d",&m,&d);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		for(int d10=2;d10<=d/10;d10++)
			if(i%d10==0)
			{
				int d1=i/d10;
				if(d1>=2&&d1<=9&&d10*10+d1<=d) ans++;
			}
	}
	printf("%d",ans);
	return 0;
}
```

------------

#### B - Kleene Inversion
对于每个序列 $A$，它内部的贡献即为逆序对的数量；对于一个元素 $a_i$，不妨令它前面有 $k$ 个块，前面的块的贡献即为 $\left(\sum\limits_{j=1}^n [a_j\ge a_i]\right) \cdot k$，分开讨论计算即可。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=2005;
const int MOD=1000000007;
int n,k;
int a[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	long long ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]>a[j]) ans++;
	ans=ans*k%MOD;
	long long sn=0;
	for(int i=1;i<=n;i++)
	{
		int num=0;
		for(int j=1;j<=n;j++)
			if(a[j]>a[i]) num++;
		sn+=num;
	}
	sn%=MOD;
	long long sk=1LL*(k-1)*k/2%MOD;
	ans=(ans+sn*sk%MOD)%MOD;
	printf("%lld",ans);
	return 0;
}
```

------------

#### C - Cell Inversion
可以发现，因为每个点都必须只被选一次，我们可以知道每个位置为左端点还是右端点。

可以发现，对于 $l_1\leq l_2\leq r_1\leq r_2$，操作 $(l_1,r_1),(l_2,r_2)$ 是等价的，即一个右端点可以与它的左边任意一个左端点匹配。

可以将左端点看做左括号，右端点看做右括号，每个点的选择即为左边还没有匹配的左括号数量，从左到右扫一遍即可，最后乘上 $n!$ 即可。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const int MOD=1000000007;
int n;
char s[N];
int a[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	if(s[1]=='W')
	{
		printf("0");
		return 0;
	}
	a[0]=1;
	for(int i=1;i<=n*2;i++)
		if(s[i]==s[i-1]) a[i]=a[i-1]^1;
		else a[i]=a[i-1];
	int num=0;
	long long ans=1;
	for(int i=1;i<=n*2;i++)
	{
		if(a[i]==1) num++;
		else ans=ans*num%MOD,num--;
		if(num<0)
		{
			printf("0");
			return 0;
		}
	}
	if(num!=0)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		ans=ans*i%MOD;
	printf("%lld",ans);
	return 0;
}
```

------------

#### D - Classified
对于考虑每个权值 $x$ 的图，肯定是一个二分图，那么我们肯定让它越满越好。

二分图中的两个部分分别填 $x+1$ 的二分图，递归下去填即可，可以证明这是上界。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=505;
int n;
int e[N][N];
void solve(int l,int r,int dep)
{
	if(l==r) return;
	int mid=(l+r)/2;
	for(int i=l;i<=mid;i++)
		for(int j=mid+1;j<=r;j++)
			e[i][j]=e[j][i]=dep;
	solve(l,mid,dep+1);
	solve(mid+1,r,dep+1);
	return;
}
int main()
{
	scanf("%d",&n);
	solve(1,n,1);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
			printf("%d ",e[i][j]);
		printf("\n");
	}
	return 0;
}
```

------------

#### E - Card Collector
考虑按权值从大到小贪心加入，我们只需要判断某个点是否能被加入。

将行和列看做点，卡片看做边，可以发现需要每个连通块内的边数小于等于点数，即每个联通块内最多只能有一个环，用并查集维护即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
const int N=200005;
int n,m,h,w;
int fa[N];
vector<tuple<int,int,int> >G;
bool isc[N];
int getf(int v)
{
	if(v==fa[v]) return v;
	fa[v]=getf(fa[v]);
	return fa[v];
}
int merge(int u,int v)
{
	int f1=getf(u),f2=getf(v);
	if(f1!=f2)
	{
		if(isc[f1]&&isc[f2]) return -1;
		else
		{
			fa[f2]=f1;
			isc[f1]|=isc[f2];
			return 1;
		}
	}
	else if(!isc[f1])
	{
		isc[f1]=true;
		return 0;
	}
	else return -1;
}
int main()
{
	scanf("%d%d%d",&n,&h,&w);
	for(int i=1;i<=n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		v+=h;
		G.push_back(make_tuple(u,v,w));
	}
	sort(G.begin(),G.end(),[=](const tuple<int,int,int>&x,const tuple<int,int,int>&y){return get<2>(x)>get<2>(y);});
	m=h+w;
	for(int i=1;i<=m;i++)
		fa[i]=i,isc[i]=false;
	long long ans=0;
	for(auto [u,v,w]:G)
		if(merge(u,v)!=-1) ans+=w;
	printf("%lld",ans);
	return 0;
}
```

------------

#### F - Candy Retribution
将问题差分一下，问题转化为了求 $\sum\limits_{i=1}^n a_i\leq x$ 的方案数。

如果枚举 $a_m=a_{m+1}=p$，分成排序后的两部分我们无法算出原序列的排列数。

考虑计算不合法的方案数。枚举 $a_m=p$，则 $\forall i\in [1,m],a_i \ge p$，$\forall i\in [m+1,n],a_i< p$。因为 $a_m=p$，需要保证至少有一个位置 $=p$，我们可以用 $\forall i\in [1,m],a_i \ge p$ 的方案数减去 $\forall i\in [1,m],a_i \ge p+1$ 的方案数。

考虑计算

$$\begin{cases}\forall i\in [1,m],a_i \ge p \\ \forall i\in [m+1,n],0\leq a_i< q \\ \sum\limits_{i=1}^n a_i\leq x\end{cases}$$

转化一下：

$$\begin{cases}\forall i\in [1,m],a_i \ge 0 \\ \forall i\in [m+1,n],0\leq a_i< q \\ t+\sum\limits_{i=1}^n a_i= x-p\cdot m\ (t\ge 0)\end{cases}$$

考虑容斥第二个条件，枚举 $[m+1,n]$ 中有多少个位置 $a_i\ge q$，现将这些位置填上 $p$，然后容斥一下就好了。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=600005;
const int MOD=1000000007;
int n,m,L,R;
long long fac[N],inv[N];
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
void init(int n=600000)
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
long long calc(long long x,int p,int q)
{
	x-=1LL*m*p;
	if(x<0) return 0;
	long long res=0;
	for(int i=0;i<=n-m&&x-1LL*i*q>=0;i++)
		if(i&1) res=(res-C(n-m,i)*C(x-1LL*i*q+n,n)%MOD+MOD)%MOD;
		else res=(res+C(n-m,i)*C(x-1LL*i*q+n,n)%MOD)%MOD;
	res*=C(n,m);
	return res;
}
long long solve(int x)
{
	long long res=0;
	for(int p=0;p<=x;p++)
		res=(res+(calc(x,p,p)-calc(x,p+1,p)+MOD)%MOD)%MOD;
	res=(C(x+n,n)-res+MOD)%MOD;
	return res;
}
int main()
{
	init();
	scanf("%d%d%d%d",&n,&m,&L,&R);
	printf("%lld",(solve(R)-solve(L-1)+MOD)%MOD);
	return 0;
}
```