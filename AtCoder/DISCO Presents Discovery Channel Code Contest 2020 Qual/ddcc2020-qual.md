#### A - DDCC Finals
直接模拟即可。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int x,y;
int main()
{
	scanf("%d%d",&x,&y);
	int ans=0;
	if(x==1) ans+=30;
	else if(x==2) ans+=20;
	else if(x==3) ans+=10;
	if(y==1) ans+=30;
	else if(y==2) ans+=20;
	else if(y==3) ans+=10;
	if(x==1&&y==1) ans+=40;
	ans*=10000;
	printf("%d",ans);
	return 0;
}
```

------------

#### B - Iron Bar Cutting
直接枚举分界点，每次计算一下代价取个最小值即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200005;
int n;
int a[N];
long long sum[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	long long ans=1e18;
	for(int i=1;i<n;i++)
		ans=min(ans,abs(sum[i]-(sum[n]-sum[i])));
	printf("%lld",ans);
	return 0;
}
```

------------

#### C - Strawberry Cakes
考虑对于有草莓的行，直接将草莓看做分界点，把每个块分给靠近它的块就好了。没有草莓的行上下找一个有草莓的行复制一份就是了。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=305;
int h,w,k;
char s[N][N];
int ans[N][N];
bool book[N];
int main()
{
	scanf("%d%d%d",&h,&w,&k);
	for(int i=1;i<=h;i++)
		scanf("%s",s[i]+1);
	book[0]=book[h+1]=true;
	int tot=0;
	for(int i=1;i<=h;i++)
	{
		vector<int>pos;
		for(int j=1;j<=w;j++)
			if(s[i][j]=='#') pos.push_back(j);
		if(pos.empty())
		{
			book[i]=true;
			continue;
		}
		for(int l=1;l<pos.size();l++)
		{
			tot++;
			for(int j=pos[l-1];j<pos[l];j++)
				ans[i][j]=tot;
		}
		ans[i][pos.back()]=++tot;
		for(int j=pos.front()-1;j>=1;j--)
			if(!ans[i][j]) ans[i][j]=ans[i][j+1];
		for(int j=pos.front()+1;j<=w;j++)
			if(!ans[i][j]) ans[i][j]=ans[i][j-1];
	}
	for(int i=1;i<=h;i++)
		if(book[i]&&!book[i-1])
		{
			for(int j=1;j<=w;j++)
				ans[i][j]=ans[i-1][j];
			book[i]=false;
		}
	for(int i=h;i>=1;i--)
		if(book[i]&&!book[i+1])
		{
			for(int j=1;j<=w;j++)
				ans[i][j]=ans[i+1][j];
			book[i]=false;
		}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
```

------------

#### D - Digit Sum Replace
可以发现，无论怎么操作答案都是一样的，只需要计算出一种方案下的答案就是了。

具体证明的话可以考虑每次操作要不就是使得位数减一或者总和减九，这两个是独立的。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n;
int d[N];
long long c[N];
int main()
{
	scanf("%d",&n);
	long long sumc=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%lld",&d[i],&c[i]);
		sumc+=c[i],sum+=d[i]*c[i];
	}
	printf("%lld",(sum-1)/9+sumc-1);
	return 0;
}
```

------------

#### E - Majority of Balls
令 $f(i)$ 表示询问 $[l,l+n-1]$ 这个区间。可以发现对于一个 $i$，如果 $f(i)\neq f(i+1)$，则我们可以知道 $i$ 和 $i+n$ 的位置上的颜色，且 $[i+1,i+n-1]$ 这个区间一定是红蓝相等的，我们就可以拿这个区间去询问出剩下的位置的颜色。

考虑找出这个 $i$ 的位置，可以发现，对于 $f(1)\neq f(n+1)$，则在这个区间内必有一个位置 $i$ 使得 $f(i)\neq f(i+1)$，具体可以二分 $mid$，如果 $f(mid)=f(l)\neq f(r)$，则在 $[mid,r]$ 这段区间内一定有一个位置满足条件，继续在这个区间内找即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=205;
int n;
int query(const vector<int>&A)
{
	cout<<"? ";
	for(int u:A)
		cout<<u<<" ";
	cout<<endl;
	string s;
	cin>>s;
	if(s=="Red") return 1;
	else if(s=="Blue") return 0;
	else return -1;
}
vector<int> build(int l,int r)
{
	vector<int>res;
	for(int i=l;i<=r;i++)
		res.push_back(i);
	return res;
}
vector<int> operator+(const vector<int>&a,const vector<int>&b)
{
	vector<int>res;
	for(int u:a)
		res.push_back(u);
	for(int u:b)
		res.push_back(u);
	return res;
}
char ans[N];
int res[N];
int get(int u)
{
	if(res[u]!=-1) return res[u];
	else return res[u]=query(build(u,u+n-1));
}
int main()
{
	cin>>n;
	int l=1,r=n+1;
	memset(res,-1,sizeof(res));
	while(l<r-1)
	{
		int mid=(l+r)/2;
		auto check=[=](int x)->bool{return get(l)==get(x);};
		if(check(mid)) l=mid;
		else r=mid;
	}
	int L=l+1,R=l+n-1;
	vector<int>add=build(L,R);
	vector<int>posr,posb;
	for(int i=1;i<=L-1;i++)
		if(query((vector<int>){i}+add)) ans[i]='R',posr.push_back(i);
		else ans[i]='B',posb.push_back(i);
	for(int i=R+1;i<=n*2;i++)
		if(query(add+(vector<int>){i})) ans[i]='R',posr.push_back(i);
		else ans[i]='B',posb.push_back(i);
	vector<int>q;
	for(int i=0;i<n/2;i++)
		q.push_back(posr[i]),q.push_back(posb[i]);
	for(int i=L;i<=R;i++)
		if(query(q+(vector<int>){i})) ans[i]='R';
		else ans[i]='B';
	cout<<"! ";
	for(int i=1;i<=n*2;i++)
		cout<<ans[i];
	cout<<endl;
	return 0;
}
```

------------

#### F - DISCOSMOS
考虑找到移动的一个循环节，如果这个循环节内的合法那么整个就一定合法，否则一定不合法。循环节就是 $g=\frac{H}{\gcd(H,T)},h=\frac{W}{\gcd(W,T)}$，问题就变成了 $T=1$ 的情况，最后再乘上 $\frac{n\cdot m}{g\cdot h}$ 就是答案了。

合法的方案可以分成几种情况：

- 只往右移，一行要么不移，要么全移，方案数为 $2^g-1$；
- 只往下移，一列要么不移，要么全移，方案数为 $2^h-1$；
- 既往右移又下移，确定一个点以后可以确定 $\gcd(h,g)$ 个格子，每个格子可以往下或往右，方案数为 $2^{\gcd(h,g)}-2$。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000007;
int n,m,t;
int g,h;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
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
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	g=n/gcd(n,t),h=m/gcd(m,t);
	long long res=1;
	res=(res+ksm(2,g)-1)%MOD;
	res=(res+ksm(2,h)-1)%MOD;
	res=(res+ksm(2,gcd(g,h))-2)%MOD;
	res=ksm(res,1LL*(n/g)*(m/h))%MOD;
	printf("%lld",res);
	return 0;
}
```