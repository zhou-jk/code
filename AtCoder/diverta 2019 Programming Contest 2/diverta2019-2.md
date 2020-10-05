#### A - Ball Distribution
$k=1$ 时答案为 $0$，否则答案为 $n-k$。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1) printf("0");
	else printf("%d",n-k);
	return 0;
}
```

------------

#### B - Picking Up
$O(n^2)$ 枚举两个点之间的距离 $p,q$，$O(n)$ 判断即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N=55;
int n;
pair<int,int>a[N];
map<pair<int,int>,bool>book;
int calc(int p,int q)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=a[i].first,y=a[i].second;
		if(!book[make_pair(x-p,y-q)]) ans++;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i]=make_pair(x,y);
		book[a[i]]=true;
	}
	sort(a+1,a+n+1);
	int ans=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			int x=a[i].first-a[j].first,y=a[i].second-a[j].second;
			ans=min(ans,calc(x,y));
		}
	printf("%d",ans);
	return 0;
}
```

------------

#### C - Successive Subtraction
考虑贪心，用前面的数减去后面的除了最大的正数的正数，然后再用最大的正数依次减去所有的负数。注意特判一下全为负数和全为正数的方案。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
long long a[N];
vector<pair<long long,long long> >res;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int j=n;
	for(int i=1;i<=n-1;i++)
		if(a[i]>0)
		{
			j=i;
			break;
		}
	if(j==1)
	{
		for(int i=2;i<=n-1;i++)
			res.push_back(make_pair(a[1],a[i])),a[1]-=a[i];
		res.push_back(make_pair(a[n],a[1])),a[n]-=a[1];
		printf("%lld\n",a[n]);
		for(auto [x,y]:res)
			printf("%lld %lld\n",x,y);
		return 0;
	}
	for(int i=j;i<=n-1;i++)
		res.push_back(make_pair(a[1],a[i])),a[1]-=a[i];
	for(int i=1;i<=j-1;i++)
		res.push_back(make_pair(a[n],a[i])),a[n]-=a[i];
	printf("%lld\n",a[n]);
	for(auto [x,y]:res)
		printf("%lld %lld\n",x,y);
	return 0;
}
```

------------

#### D - Squirrel Merchant
可以发现，$A\to B$ 和 $B\to A$ 的决策是独立的，且我们肯定在第一次买入，第二次卖出。

考虑 $A\to B$ 的最大收益。如果 $B_i> A_i$，则不妨将 $A_i$ 看做重量，$B_i-A_i$ 看做收益，做一遍完全背包即可。$B\to A$ 同理。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=5005;
int n;
int a[4],b[4];
long long f[N*N];
int main()
{
	scanf("%d",&n);
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	scanf("%d%d%d",&b[1],&b[2],&b[3]);
	for(int i=1;i<=3;i++)
		if(b[i]>a[i])
		{
			for(int j=a[i];j<=n;j++)
				f[j]=max(f[j],f[j-a[i]]+b[i]);
		}
	long long ans=0;
	for(int j=0;j<=n;j++)
		ans=max(ans,f[j]+n-j);
	n=ans;
	memset(f,0,sizeof(f));
	for(int i=1;i<=3;i++)
		if(a[i]>b[i])
		{
			for(int j=b[i];j<=n;j++)
				f[j]=max(f[j],f[j-b[i]]+a[i]);
		}
	ans=0;
	for(int j=0;j<=n;j++)
		ans=max(ans,f[j]+n-j);
	printf("%lld",ans);
	return 0;
}
```

------------

#### E - Balanced Piles
令 $f_{i,j}$ 表示当前最大值为 $i$，有 $j$ 个最大值的方案数。但是好像没法得出最小值的数量，但是挑出一个最小值和将它变成最大值是一一对应的。那么就可以得出 $f_{i,j}\cdot j \to f_{i,j+1}$。

那么就可以得出转移：

是我们有

$$f_{i,j}= \begin{cases} f_{i,j-1}\cdot j & (j>1)  \\ \sum\limits_{k=1}^d\sum\limits_{l=1}^{n} f_{i-k,l}=\sum\limits_{k=1}^d f_{i-k,l} \sum\limits_{l=1}^n l! & (j=1) \end{cases}$$

只用记录 $f_{i,1}$，前缀和优化即可。

注意，$i=0$ 时只有 $f_{i,n}=n!$，其他位置都是 $0$，最后答案需要乘上 $\frac{n!}{\sum\limits_{i=1}^{n}i!}$。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000005;
const int MOD=1000000007;
int n,h,d;
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
long long fac,sum;
long long s[N],f[N];
int main()
{
	scanf("%d%d%d",&n,&h,&d);
	fac=1;
	for(int i=1;i<=n;i++)
		fac=fac*i%MOD,sum=(sum+fac)%MOD;
	s[0]=f[0]=1;
	for(int i=1;i<=h+1;i++)
	{
		long long p=(s[i-1]-(i-d-1>=0?s[i-d-1]:0)+MOD)%MOD;
		f[i]=p*sum%MOD;
		s[i]=(s[i-1]+f[i])%MOD;
	}
	printf("%lld",f[h]*fac%MOD*ksm(sum,MOD-2)%MOD);
	return 0;
}
```

------------

#### F - Diverta City
可以构造出一个序列 $a=\{1,2,4,7,12,20,29,38,52\}$。这个序列满足两两的和不相等，且两个数的和不等于另一个数。

考虑从小到大依次加入点 $i$，对于 $j< i$，将 $(i,j)$ 这条边的边权置为 $(M+1)a_j$，$M$ 表示前 $i-1$ 个点的哈密顿路权值的最大值。

这样构造显然是对的。因为考虑将当前这个位置加入到 $(u,v)$ 中，新的权值为 $d_1+(M+1)a_u+(M+1)a_v-\operatorname{dis}(u,v)$。对于另一条路径 $d_2+(M+1)a_{u'}+(M+1)a_{v'}-\operatorname{dis}(u',v')$。$(M+1)a_u+(M+1)a_v$ 显然是不等的，且 $d_1-\operatorname{dis}(u,v)\leq M$ 与 $d_2-\operatorname{dis}(u',v')\leq M$，则这个显然不等的。另一条路径为 $d_2+(M+1)a_{u'}$ 同理。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=15;
const int a[N]={0,1,2,4,7,12,20,29,38,52,73};
int n,p[N];
long long g[N][N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
			p[j]=j;
		long long M=0;
		do
		{
			long long s=0;
			for(int j=1;j<i;j++)
				s+=g[p[j]][p[j+1]];
			M=max(M,s);
		}
		while(next_permutation(p+1,p+i+1));
		for(int j=1;j<i;j++)
			g[i][j]=g[j][i]=(M+1)*a[j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%lld ",g[i][j]);
		printf("\n");
	}
	return 0;
}
```