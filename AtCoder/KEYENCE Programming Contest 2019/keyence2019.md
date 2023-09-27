#### A - Beginning
排序以后判断一下是否为 $1,4,7,9$ 即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10;
int a[N];
int main()
{
	for(int i=1;i<=4;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+4+1);
	if(a[1]==1&&a[2]==4&&a[3]==7&&a[4]==9) printf("YES");
	else printf("NO");
	return 0;
}
```

------------

#### B - KEYENCE String
求出最长匹配前缀和最长匹配后缀即可，判断一下是否可以接成 `keyence` 即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=105;
const char t[]=" keyence";
int n;
char s[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int i=1,a=1,j=n,b=7;
	while(s[i]==t[a]) i++,a++;
	while(s[j]==t[b]) j--,b--;
	if(a-1+1>=b+1) printf("YES");
	else printf("NO");
	return 0;
}
```

------------

#### C - Exam and Wizard
令 $x_i=B_i-A_i$，我们需要将所有的 $x_i$ 都调整为非负数，且改变的数最少。按照 $x_i$ 从大到小排序，每次贪心的填到所有负数上即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
long long a[N],b[N];
int id[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
		id[i]=i;
	sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]-b[x]>a[y]-b[y];});
	int ans=0;
	for(int i=1;i<=n;i++)
		if(a[id[i]]-b[id[i]]<0) ans++;
	int j=n;
	for(int i=1;i<j;i++)
	{
		if(a[id[j]]-b[id[j]]>=0) break;
		long long t=a[id[i]]-b[id[i]];
		ans++;
		while(j>i&&t>0)
		{
			long long tmp=min(t,b[id[j]]-a[id[j]]);
			a[id[j]]+=tmp;
			t-=tmp,a[id[i]]-=tmp;
			if(a[id[j]]-b[id[j]]<0) break;
			j--;
		}
	}
	if(a[id[j]]-b[id[j]]<0) printf("-1");
	else printf("%d",ans);
	return 0;
}
```

------------

#### D - Double Landscape

考虑从大到小填每个数。

对于一个数 $x$，如果某一行的最大值和某一列的最大值都为 $x$，则 $x$ 只有一种填法。如果某一行的最大值为 $x$，则 $x$ 可以填在那一行中比它大的列中。某一列的最大值为 $x$ 时同理。如果不存在某一行的最大值或某一列的最大值都为 $x$，$x$ 可以填在比它大的行列，注意要减去比它大的数字个数，因为比它的大的数也要填。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1005;
const int MOD=1000000007;
int n,m;
int a[N],b[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]==a[i-1])
		{
			printf("0");
			return 0;
		}
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)
		if(b[i]==b[i-1])
		{
			printf("0");
			return 0;
		}
	long long ans=1;
	int i=n,j=m;
	for(int k=n*m;k>=1;k--)
	{
		while(i>=1&&a[i]>=k) i--;
		while(j>=1&&b[j]>=k) j--;
		long long res=1;
		if(a[i+1]==k&&b[j+1]==k) res=1;
		else if(a[i+1]==k&&b[j+1]!=k) res=m-j;
		else if(a[i+1]!=k&&b[j+1]==k) res=n-i;
		else res=(1LL*(n-i)*(m-j)-(1LL*n*m-k))%MOD;
		ans=ans*res%MOD;
	}
	printf("%lld",ans);
	return 0;
}
```

------------

#### E - Connecting Cities
如果 $i> j$，将 $|i-j| \times D + A_{i} + A_{j}$，拆成 $i\times D+A_i-j\times D +A_j$，$i< j$ 时同理。然后用线段树维护一下最小值就好了。用 Boruvka 求最小生成树即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N=200005;
const long long INF=4557430888798830399;
int n,d;
long long a[N];
int fa[N];
int getf(int v)
{
	if(v==fa[v]) return v;
	fa[v]=getf(fa[v]);
	return fa[v];
}
bool merge(int u,int v)
{
	int f1=getf(u),f2=getf(v);
	if(f1!=f2)
	{
		fa[f2]=f1;
		return true;
	}
	else return false;
}
long long f(int j)
{
	return -1LL*j*d+a[j];
}
long long g(int j)
{
	return 1LL*j*d+a[j];
}
long long dis(int i,int j)
{
	return 1LL*abs(i-j)*d+a[i]+a[j];
}
struct Segment_Treef
{
	int Min(int x,int y)
	{
		return f(x)<f(y)?x:y;
	}
	struct Node
	{
		int l,r;
		int val;
	}tree[N<<2];
	void push_up(int i)
	{
		tree[i].val=Min(tree[i*2].val,tree[i*2+1].val);
		return;
	}
	void build(int i,int l,int r)
	{
		tree[i].l=l,tree[i].r=r;
		if(l==r)
		{
			tree[i].val=0;
			return;
		}
		int mid=(l+r)/2;
		build(i*2,l,mid);
		build(i*2+1,mid+1,r);
		push_up(i);
		return;
	}
	void modify(int i,int u,int v)
	{
		if(tree[i].l==tree[i].r)
		{
			tree[i].val=Min(tree[i].val,v);
			return;
		}
		if(u<=tree[i*2].r) modify(i*2,u,v);
		else modify(i*2+1,u,v);
		push_up(i);
		return;
	}
	int query(int i,int l,int r)
	{
		if(l>r) return 0;
		if(l<=tree[i].l&&tree[i].r<=r) return tree[i].val;
		int res=0;
		if(l<=tree[i*2].r) res=Min(res,query(i*2,l,r));
		if(r>=tree[i*2+1].l) res=Min(res,query(i*2+1,l,r));
		return res;
	}
}T1;
struct Segment_Treeg
{
	int Min(int x,int y)
	{
		return g(x)<g(y)?x:y;
	}
	struct Node
	{
		int l,r;
		int val;
	}tree[N<<2];
	void push_up(int i)
	{
		tree[i].val=Min(tree[i*2].val,tree[i*2+1].val);
		return;
	}
	void build(int i,int l,int r)
	{
		tree[i].l=l,tree[i].r=r;
		if(l==r)
		{
			tree[i].val=0;
			return;
		}
		int mid=(l+r)/2;
		build(i*2,l,mid);
		build(i*2+1,mid+1,r);
		push_up(i);
		return;
	}
	void modify(int i,int u,int v)
	{
		if(tree[i].l==tree[i].r)
		{
			tree[i].val=Min(tree[i].val,v);
			return;
		}
		if(u<=tree[i*2].r) modify(i*2,u,v);
		else modify(i*2+1,u,v);
		push_up(i);
		return;
	}
	int query(int i,int l,int r)
	{
		if(l>r) return 0;
		if(l<=tree[i].l&&tree[i].r<=r) return tree[i].val;
		int res=0;
		if(l<=tree[i*2].r) res=Min(res,query(i*2,l,r));
		if(r>=tree[i*2+1].l) res=Min(res,query(i*2+1,l,r));
		return res;
	}
}T2;
long long ans;
int to[N];
int x[N],y[N];
int solve()
{
	memset(to,0,sizeof(to));
	T1.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int u=getf(i);
		int x=T1.Min(T1.query(1,1,u-1),T1.query(1,u+1,n));
		if(!to[i]||dis(i,x)<dis(i,to[i])) to[i]=x;
		T1.modify(1,u,i);
	}
	T2.build(1,1,n);
	for(int i=n;i>=1;i--)
	{
		int u=getf(i);
		int x=T2.Min(T2.query(1,1,u-1),T2.query(1,u+1,n));
		if(!to[i]||dis(i,x)<dis(i,to[i])) to[i]=x;
		T2.modify(1,u,i);
	}
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	for(int i=1;i<=n;i++)
	{
		int u=getf(i);
		if(!x[u]||!y[u]||dis(i,to[i])<dis(x[u],y[u])) x[u]=i,y[u]=to[i];
	}
	int num=0;
	for(int u=1;u<=n;u++)
		if(getf(u)==u)
		{
			long long w=dis(x[u],y[u]);
			if(merge(x[u],y[u])) num++,ans+=w;
		}
	return num;
}
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	a[0]=INF;
	int tot=n;
	while(tot>1)
		tot-=solve();
	printf("%lld",ans);
	return 0;
}
```

------------

#### F - Paper Cutting
令 $f(k)$ 表示第 $k$ 次操作的贡献，答案即为 $\sum\limits_{k=1}^Kf(k)$。考虑计算 $f(k)$：

$$\begin{aligned}f(k)&=k!(K-k)!C_{H+W-k}^{K-k}\sum_{i=0}^{k}C_{H}^{i}C_{W}^{k-i}(i+1)(k-i+1) \\ &=k!(K-k)!C_{H+W-k}^{K-k}\sum_{i=0}^{k}C_{H}^{i}C_{W}^{k-i}(i(k-i)+i+(k-i)+1) \\ &=k!(K-k)!C_{H+W-k}^{K-k}\sum_{i=0}^{k}C_{H}^{i}C_{W}^{k-i}(i(k-i)+(k+1)) \\ &=k!(K-k)!C_{H+W-k}^{K-k}\left((k+1)\sum_{i=0}^{k}C_{H}^{i}C_{W}^{k-i}+\sum_{i=0}^{k}C_{H}^{i}C_{W}^{k-i}i(k-i)\right) \\ &=k!(K-k)!C_{H+W-k}^{K-k}\left((k+1)C_{H+W}^k+\sum_{i=0}^{k}HC_{H-1}^{i-1}WC_{W-1}^{k-i-1}\right) \\ &=k!(K-k)!C_{H+W-k}^{K-k}\left((k+1)C_{H+W}^k+HW\sum_{i=0}^{k}C_{H-1}^{i-1}C_{W-1}^{k-i-1}\right) \\ &= k!(K-k)!C_{H+W-k}^{K-k}\left((k+1)C_{H+W}^k+HWC_{H+W-2}^{k-2}\right) \end{aligned}$$

预处理组合数计算即可。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=20000005;
const int MOD=1000000007;
int h,w,K;
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
void init(int n=20000000)
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
	scanf("%d%d%d",&h,&w,&K);
	long long ans=0;
	for(int k=1;k<=K;k++)
	{
		long long res=((k+1)*C(h+w,k)%MOD+1LL*h*w%MOD*C(h+w-2,k-2)%MOD)%MOD;
		res=res*fac[k]%MOD*fac[K-k]%MOD*C(h+w-k,K-k)%MOD;
		ans=(ans+res)%MOD;
	}
	printf("%lld",ans);
	return 0;
}
```