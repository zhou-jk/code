#### C - Product and GCD
令 $P=\prod p_i^{c_i}$。

对于某个 $p_i^{c_i}$，要使得 $\gcd(a_i)$ 尽可能大，肯定将每个 $p_i$ 平均分给 $n$ 个数最优，然后就没了。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,p;
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res*=a;
		a*=a,b>>=1;
	}
	return res;
}
int main()
{
	scanf("%lld%lld",&n,&p);
	long long ans=1;
	for(int i=2;i<=sqrt(p);i++)
		if(p%i==0)
		{
			int cnt=0;
			while(p%i==0) cnt++,p/=i;
			ans*=ksm(i,cnt/n);
		}
	if(p!=1) ans*=ksm(p,1/n);
	printf("%lld",ans);
	return 0;
}
```

------------

#### D - Harlequin
如果全为偶数的情况肯定后手赢。否则可以取奇数的位置转化成全为偶数的情况，先手赢。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]&1)
		{
			printf("first");
			return 0;
		}
	printf("second");
	return 0;
}
```

------------

#### E - Negative Doubling
一个简单的想法是枚举正数和负数的分界点，分别算出前面变成单调不减的负数的最少步数和后面变成单调不减的正数的最少步数。

考虑计算前面变成单调不减的负数的最少步数。

加入一个新的数 $a_i$，如果 $a_i< a_{i-1}$，我们需要调整 $1\sim i-1$ 的数使得 $a_{i-1}\le a_i$，直接做是 $O(n)$ 的。可以发现，我们肯定是每次将若干个连续的段，记录一下 $pre_i$ 表示 $i$ 前面第一个满足 $a_{l-1}\leq 4a_l$ 的 $l$，每次将 $l\sim i-1$ 的数都乘上 $4$ 就可以了，可以证明这样复杂度是对的。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const long long INF=4e18;
int n;
long long a[N],b[N];
int pre[N],nxt[N];
long long sp[N],sn[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		if(b[i]>0) b[i]*=-2,cnt++;
		if(i!=1&&b[i]<b[i-1])
		{
			while(b[i]<b[i-1])
			{
				int l=pre[i-1];
				while(l!=1&&b[l-1]>b[l]*4) pre[i-1]=pre[l-1],l=pre[i-1];
				cnt+=(i-1-l+1)*2;
				b[l]*=4;
				if(i-1!=l) b[i-1]*=4;
			}
		}
		if(i==1||b[i-1]<=b[i]*4) pre[i]=i;
		else pre[i]=pre[i-1];
		sp[i]=sp[i-1]+cnt;
	}
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	for(int i=n;i>=1;i--)
	{
		int cnt=0;
		if(b[i]<0) b[i]*=-2,cnt++;
		if(i!=n&&b[i]>b[i+1])
		{
			while(b[i]>b[i+1])
			{
				int r=nxt[i+1];
				while(r!=n&&b[r+1]<b[r]*4) nxt[i+1]=nxt[r+1],r=nxt[i+1];
				cnt+=(r-(i+1)+1)*2;
				b[r]*=4;
				if(i+1!=r) b[i+1]*=4;
			}
		}
		if(i==n||b[i+1]>=b[i]*4) nxt[i]=i;
		else nxt[i]=nxt[i+1];
		sn[i]=sn[i+1]+cnt;
	}
	long long ans=INF;
	for(int i=0;i<=n;i++)
		ans=min(ans,sp[i]+sn[i+1]);
	if(ans>=INF) printf("-1");
	else printf("%lld",ans);
	return 0;
}
```

------------

#### F - Square


不妨令 $s_{i,j}$ 表示 $(i,j)$ 的数，条件看做异或和为 $0$。

可以发现，对于 $|x-y|> 2$，$s_{x,y}=s_{y,x}$。

对于 $x$，$s_{x-1,x}\operatorname{xor}s_{x,x-1}=s_{x+1,x}\operatorname{xor}s_{x,x+1}$，$s_{x-1,x+1}\operatorname{xor}s_{x+1,x-1}=s_{x,x}$。

令 $f_{i,0/1}$ 表示填了 $i\times i$ 的方格，$s_{i,i}=0/1$ 的方案数，枚举 $s_{i-1,i-1},s_{i,i},s_{i-1,j},s_{i,j-1},s_{i,j-2},s_{i-2,j}$ 的值转移即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<tuple>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int N=100005,M=50005;
const int MOD=998244353;
int n,m;
map<int,int>book[N];
vector<pair<int,int>>pos[N];
int get(int x,int y)
{
	vector<pair<int,int>>::iterator t=lower_bound(pos[x].begin(),pos[x].end(),make_pair(y,-1));
	if(t==pos[x].end()) return -1;
	if(t->first==y) return t->second;
	else return -1;
}
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
long long dp[N][2];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(book[a].count(b))
		{
			if(book[a][b]==c) continue;
			else
			{
				printf("0");
				return 0;
			}
		}
		book[a][b]=c;
		pos[a].emplace_back(b,c);
		if(a!=b&&abs(b-a)>2)
		{
			book[b][a]=c;
			pos[b].emplace_back(a,c);
		}
	}
	for(int i=1;i<=n;i++)
		sort(pos[i].begin(),pos[i].end());
	int v=get(1,1);
	if(v==-1) dp[1][0]=dp[1][1]=1;
	else dp[1][v]=1;
	if(n==1)
	{
		printf("%lld",(dp[1][0]+dp[1][1])%MOD);
		return 0;
	}
	for(int j=0;j<=1;j++)
		for(int k=0;k<=1;k++)
			for(int p1=0;p1<=1;p1++)
				for(int p2=0;p2<=1;p2++)
				{
					if(j^k^p1^p2) continue;
					if(get(2,1)!=-1&&get(2,1)!=p1) continue;
					if(get(1,2)!=-1&&get(1,2)!=p2) continue;
					if(get(2,2)!=-1&&get(2,2)!=j) continue;
					dp[2][j]=(dp[2][j]+dp[1][k])%MOD;
				}
	for(int i=3;i<=n;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++)
				for(int p1=0;p1<=1;p1++)
					for(int p2=0;p2<=1;p2++)
						for(int p3=0;p3<=1;p3++)
							for(int p4=0;p4<=1;p4++)
							{
								if(j^k^p1^p2) continue;
								if(get(i,i-1)!=-1&&get(i,i-1)!=p1) continue;
								if(get(i-1,i)!=-1&&get(i-1,i)!=p2) continue;
								if(get(i,i)!=-1&&get(i,i)!=j) continue;
								if(get(i,i-2)!=-1&&get(i,i-2)!=p3) continue;
								if(get(i-2,i)!=-1&&get(i-2,i)!=p4) continue;
								if(p3^p4^k) continue;
								int num=(i-3)-(upper_bound(pos[i].begin(),pos[i].end(),make_pair(i-3,1))-pos[i].begin());
								dp[i][j]=(dp[i][j]+dp[i-1][k]*ksm(2,num)%MOD)%MOD;
							}
	printf("%lld",(dp[n][0]+dp[n][1])%MOD);
	return 0;
}
```