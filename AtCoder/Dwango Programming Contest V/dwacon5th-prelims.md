#### A - Thumbnail
直接按照题意模拟。。。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=105;
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	double avg=(double)sum/n;
	double Min=1e9;
	int t=0;
	for(int i=1;i<=n;i++)
		if(abs(a[i]-avg)<Min) Min=abs(a[i]-avg),t=i;
	printf("%d",t-1);
	return 0;
}
```

------------

#### B - Sum AND Subarrays
把 $\frac{n(n-1)}{2}$ 个区间和分别找出来，按位确定即可，如果当前位可以为 $1$ 将所有的当前位为 $0$ 删除。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<bitset>
using namespace std;
const int N=1005;
int n;
long long k;
int a[N];
long long sum[N];
long long v[N*N];
int tot;
bool check(long long x)
{
	int cnt=0;
	for(int i=1;i<=tot;i++)
		if((v[i]&x)==x) cnt++;
	return cnt>=k;
}
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
			v[++tot]=sum[r]-sum[l-1];
	long long res=0;
	for(int i=60;i>=0;i--)
		if(check(res|(1LL<<i))) res|=1LL<<i;
	printf("%lld",res);
	return 0;
}
```

------------

#### C - k-DMC
从前往后维护一个类似单调队列的东西，队列里维护合法的 `D` 的位置。

如果遇到一个 `M`，我们需要将当前队列里所有的 `D` 加上 $1$；遇到一个 `D` 我们将它加入队列；遇到一个 `C` 计算一次所有队列里合法的数贡献之和。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1000005;
int n,Q;
char s[N];
void solve()
{
	int k;
	scanf("%d",&k);
	deque<pair<int,int>>q;
	int add=0;
	long long sum=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		while(!q.empty()&&i-q.front().first>=k) sum-=q.front().second,q.pop_front();
		if(s[i]=='D')
		{
			q.emplace_back(i,-add);
			sum+=-add;
		}
		else if(s[i]=='M') add++;
		else if(s[i]=='C') ans+=1LL*add*q.size()+sum;
	}
	printf("%lld\n",ans);
	return;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d",&Q);
	while(Q--)
		solve();
	return 0;
}
```

------------

#### D - Square Rotation
对于 $(x,y)$，它和 $(x\bmod D,y\bmod D)$ 是等价的，我们可以讨论对于模 $D$ 剩余系的所有点的情况，下文的 $A_{x,y}$ 表示模 $D$ 剩余系下 $(x,y)$ 的点的个数。

最终答案可以表示成 $aD+b$ 的形式，不妨令矩形左下角为 $(0,0)$，$cnt_{i,j}$ 表示模 $D$ 剩余系下 $(i,j)$ 在矩形中有几个，则：

- 对于 $0\leq i,j\leq b$ 的情况，$cnt_{i,j}=(a+1)^2$；
- 对于 $b< i,j< D$ 的情况，$cnt_{i,j}=a^2$；
- 对于剩下的情况，$cnt_{i,j}=a(a+1)$。

需要满足的条件为 $A_{i,j}\leq cnt_{i,j}$，我们需要找到一个最小的 $a$，使得 $(a+1)^2\ge \max\{A_{i,j}\}$，$a$ 的最小值为 $\sqrt{\max\{A_{i,j}\}}-1$，考虑计算 $b$。

显然可以二分 $b$，可以枚举矩形的左下角，判断合法。

对于 $a^2< A_{i,j}\leq a(a+1)$，判断一下 $A_{i,j}$ 有没有在 $a^2$ 的地方出现。

对于 $a(a+1)< A_{i,j} \leq (a+1)^2$ 的数，判断一下 $A_{i,j}$ 是否都在 $(a+1)^2$ 的地方。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100005,M=2005;
int n,D;
int x[N],y[N];
int cnt[M][M];
int s2[M][M],s3[M][M];
int getsum2(int x1,int y1,int x2,int y2)
{
	if(x1>x2) return 0;
	if(y1>y2) return 0;
	int res=s2[x2][y2];
	if(x1-1>=0) res-=s2[x1-1][y2];
	if(y1-1>=0) res-=s2[x2][y1-1];
	if(x1-1>=0&&y1-1>=0) res+=s2[x1-1][y1-1];
	return res;
}
int getsum3(int x1,int y1,int x2,int y2)
{
	if(x1>x2) return 0;
	if(y1>y2) return 0;
	int res=s3[x2][y2];
	if(x1-1>=0) res-=s3[x1-1][y2];
	if(y1-1>=0) res-=s3[x2][y1-1];
	if(x1-1>=0&&y1-1>=0) res+=s3[x1-1][y1-1];
	return res;
}
bool check2(int x,int y,int b)
{
	return getsum2(x+b+1,y+b+1,x+D-1,y+D-1)==0;
}
bool check3(int x,int y,int b)
{
	return getsum3(x,y,x+b,y+b)==getsum3(0,0,D-1,D-1);
}
int main()
{
	scanf("%d%d",&n,&D);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		cnt[x[i]%D][y[i]%D]++;
	int a=0;
	for(int i=0;i<D;i++)
		for(int j=0;j<D;j++)
			a=max(a,(int)ceil(sqrt(cnt[i][j])));
	a--;
	for(int i=0;i<D;i++)
		for(int j=0;j<D;j++)
		{
			if(cnt[i][j]>a*a&&cnt[i][j]<=a*(a+1)) s2[i][j]++;
			else if(cnt[i][j]>a*(a+1)) s3[i][j]++;
		}
	for(int i=0;i<D;i++)
		for(int j=0;j<D;j++)
			s2[i+D][j]=s2[i][j+D]=s2[i+D][j+D]=s2[i][j],s3[i+D][j]=s3[i][j+D]=s3[i+D][j+D]=s3[i][j];
	for(int i=0;i<D+D;i++)
		for(int j=0;j<D+D;j++)
		{
			if(i-1>=0) s2[i][j]+=s2[i-1][j];
			if(j-1>=0) s2[i][j]+=s2[i][j-1];
			if(i-1>=0&&j-1>=0) s2[i][j]-=s2[i-1][j-1];
			if(i-1>=0) s3[i][j]+=s3[i-1][j];
			if(j-1>=0) s3[i][j]+=s3[i][j-1];
			if(i-1>=0&&j-1>=0) s3[i][j]-=s3[i-1][j-1];
		}
	int res=D-1;
	for(int i=0;i<D;i++)
		for(int j=0;j<D;j++)
		{
			int l=0,r=D-1,ans=-1;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(check2(i,j,mid)&&check3(i,j,mid)) ans=mid,r=mid-1;
				else l=mid+1;
			}
			if(ans!=-1) res=min(res,ans);
		}
	printf("%d",a*D+res);
	return 0;
}
```

------------

#### E - Cyclic GCDs
首先有一个 DP，令 $f_{i,j}$ 表示前 $i$ 个数组成了 $j$ 个环的总和。转移为：

$$f_{i,j}=a_if_{i-1,j-1}+(i-1)f_{i-1,j}$$

答案为 $\gcd(f_{n,i})$。

考虑 $f_i$ 的生成函数 $P(n)$，则 $P(n)=P(n-1)(a_ix+(i-1))$，其中 $P(0)=1$。可以推出：

$$P(n)=\prod\limits_{i=1}^n (a_ix+(i-1))$$

然后就有一个结论：

令 $w(P)$ 表示 $P$ 的各项系数的 $\gcd$，则 $w(PQ)=w(P)\cdot w(Q)$。

首先 $w(P)\cdot w(Q)|w(PQ)$，我们需要证明的即为当 $w(P)=w(Q)=1$ 时，$w(PQ)=1$。

考虑反证，设 $P,Q$ 分别有 $n,m$ 项。如果 $w(PQ)$ 有一个质因子 $p$，则 $PQ$ 的最高次项为 $P_nQ_mx^{n+m}$，则 $P_n,Q_m$ 必然有一个是 $p$ 的倍数，我们可以将这个位置的数删去，然后继续考虑剩下的位置。这样做下去，必然有一个多项式 $P$ 或 $Q$ 被删到了空，则这个多项式系数会有一个公因数 $p$，矛盾，故假设不成立。

所以答案即为 $\prod\limits_{i=1}^n\gcd(a_i,i-1)$。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
const int MOD=998244353;
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*__gcd(a[i],i-1)%MOD;
	printf("%lld",ans);
	return 0;
}
```