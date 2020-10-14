#### A - Anti-Adjacency
合法的条件即为 $k\leq \lceil \frac{n}{2} \rceil$。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	if((n+1)/2>=k) printf("YES");
	else printf("NO");
	return 0;
}
```

------------

#### B - Path
合法当且仅当只有两个点的度数为 $1$，其他点度数均为 $2$。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=5;
int n;
int deg[N];
int main()
{
	n=4;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		deg[x]++,deg[y]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(deg[i]>2||deg[i]==0)
		{
			printf("NO");
			return 0;
		}
		else if(deg[i]==1) cnt++;
	if(cnt==2) printf("YES");
	else printf("NO");
	return 0;
}
```

------------

#### C - When I hit my pocket...
如果 $B-A> 2$，贪心的将所有操作尽量多的分配给 $A\to B$。否则所有都分配给 $+1$。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int K,A,B;
int main()
{
	scanf("%d%d%d",&K,&A,&B);
	long long ans=0;
	if(B-A>2)
	{
		K-=A-1;
		ans+=A;
		if(K%2==1) ans++;
		K/=2;
		ans+=1LL*K*(B-A);
	}
	else ans+=1+K;
	printf("%lld",ans);
	return 0;
}
```

------------

#### D - Ears
可以发现，最后的序列肯定为：不走的边，走了偶数次的边，走了奇数次的边，走了偶数次的边，不走的边。我们可以从中间的走过奇数次的边开始走先向左走完在走右边的。那么就可以 DP 了。

令 $f_{i,1/2/3/4/5}$ 表示考虑前 $i$ 条点，第 $i$ 个点前面的边为第几种边的最小代价。枚举上一个点前面的边是哪一种边转移即可。注意 $a_i=0$ 的情况。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n;
int a[N];
int dp[N][6];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dp,63,sizeof(dp));
	dp[0][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			for(int k=1;k<=j;k++)
				if(j==1||j==5) dp[i][j]=min(dp[i][j],dp[i-1][k]+a[i]);
				else if(j==2||j==4) dp[i][j]=min(dp[i][j],dp[i-1][k]+(a[i]==0?2:(a[i]%2==1)));
				else if(j==3) dp[i][j]=min(dp[i][j],dp[i-1][k]+(a[i]%2==0));
	printf("%d",min({dp[n][1],dp[n][2],dp[n][3],dp[n][4],dp[n][5]}));
	return 0;
}
```

------------

#### E - Odd Subrectangles
考虑对于已经确定的一些行的集合，计算它选择列的方案数。

令 $a$ 为和为偶数的列的个数，$b$ 为和为奇数的列的个数，方案数即为：

$$2^a\cdot \sum_{i=1}^b C_b^i[i\bmod 2=1]=2^a\cdot 2^{b-1}=2^{m-1}$$

发现行列独立。只有 $b=0$ 的情况方案数为 $0$，即选出的行的每一列的异或和都为 $0$ 的方案，这个可以用线性基计算。如果线性基的大小为 $r$，选出的行的每一列的异或和为 $0$ 方案数即为 $2^{n-r}$。

答案即为 $(2^n-2^{n-r})\cdot 2^{m-1}$。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int N=300;
const int MOD=998244353;
int n,m;
bitset<N>a[N];
struct Basis
{
	bitset<N> d[N];
	int cnt;
	void clear()
	{
		cnt=0;
		return;
	}
	int size()
	{
		return cnt;
	}
	void insert(bitset<N> t)
	{
		for(int i=m-1;i>=0;i--)
			if(t[i])
			{
				if(d[i].count()) t^=d[i];
				else
				{
					for(int j=0;j<i;j++)
						if(t[j]) t^=d[j];
					for(int j=i+1;j<=m-1;j++)
						if(d[j][i]) d[j]^=t;
					d[i]=t;
					cnt++;
					return;
				}
			}
		return;
	}
}lb;
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
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			int x;
			scanf("%d",&x);
			a[i][j]=x;
		}
	for(int i=0;i<n;i++)
		lb.insert(a[i]);
	int r=lb.size();
	long long ans=(ksm(2,n)-ksm(2,n-r)+MOD)%MOD*ksm(2,m-1)%MOD;
	printf("%lld",ans);
	return 0;
}
```

------------

#### F - Pass
可以发现，最后的序列的前 $i$ 个球肯定是前 $i$ 个人的球，我们就可以求出序列中前 $i$ 个球中每种颜色的上界。令 $sumr_i$ 表示前 $i$ 个人中红球的数量，$sumb_i$ 表示前 $i$ 个人中蓝球的数量。

考虑 DP，令 $f_{i,j}$ 表示前 $i$ 个数，用了 $j$ 个蓝球的方案数。则 $j$ 需要满足的条件为 $i-j\leq sumr_i,j\leq sumb_i$。枚举当前位置为蓝球还是红球转移。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=4005;
const int MOD=998244353;
int n;
char s[N];
int sumr[N],sumb[N];
long long dp[N][N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		sumr[i]=sumr[i-1],sumb[i]=sumb[i-1];
		if(s[i]=='0') sumr[i]+=2;
		else if(s[i]=='1') sumr[i]++,sumb[i]++;
		else sumb[i]+=2;
	}
	for(int i=n+1;i<=n*2;i++)
		sumr[i]=sumr[i-1],sumb[i]=sumb[i-1];
	dp[0][0]=1;
	for(int i=1;i<=n*2;i++)
		for(int j=max(i-sumr[i],0);j<=min(sumb[i],i);j++)
		{
			dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
			if(j-1>=0) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;
		}
	printf("%lld",dp[n*2][sumb[n]]);
	return 0;
}
```