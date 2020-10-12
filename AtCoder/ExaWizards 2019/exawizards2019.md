#### A - Regular Triangle
判断三个数是否相等。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int A,B,C;
int main()
{
	scanf("%d%d%d",&A,&B,&C);
	if(A==B&&B==C) printf("Yes");
	else printf("No");
	return 0;
}
```

------------

#### B - Red or Blue
模拟，记录 `R` 和 `B` 的个数判断。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
char s[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int R=0,B=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='R') R++;
		else if(s[i]=='B') B++;
	if(R>B) printf("Yes");
	else printf("No");
	return 0;
}
```

------------

#### C - Snuke the Wizard
可以发现，魔像的相对顺序是不变的，也就是说，最后剩下的魔像一定是原序列的一个区间，二分出左右端点，判断即为这个点最后会不会出去。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int n,Q;
char s[N];
char t[N],d[N];
bool checkl(int x)
{
	int p=x;
	for(int i=1;i<=Q;i++)
	{
		if(t[i]==s[p])
		{
			if(d[i]=='L') p--;
			else if(d[i]=='R') p++;
		}
		if(p<1) return false;
		if(p>n) return true;
	}
	return true;
}
bool checkr(int x)
{
	int p=x;
	for(int i=1;i<=Q;i++)
	{
		if(t[i]==s[p])
		{
			if(d[i]=='L') p--;
			else if(d[i]=='R') p++;
		}
		if(p<1) return true;
		if(p>n) return false;
	}
	return true;
}
int main()
{
	cin>>n>>Q;
	cin>>s+1;
	for(int i=1;i<=Q;i++)
		cin>>t[i]>>d[i];
	int L=n+1,R=0;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(checkl(mid)) L=mid,r=mid-1;
		else l=mid+1;
	}
	l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(checkr(mid)) R=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<max(R-L+1,0);
	return 0;
}
```

------------

#### D - Modulo Operations
可以发现，对于一个取模序列 $a_1,a_2,\cdots ,a_n$，一个 $a_i$ 对答案有影响当且仅当它为前缀最小值。将 $a_i$ 从大到小排序，然后就可以 DP 了。

令 $f_{i,j}$ 表示考虑前 $i$ 个模数，剩下 $j$ 的方案数。转移即为分成 $a_i$ 加入当前序列的后面成为前缀最小值或插入后面对最后的数没有影响的情况讨论即可。

$$f_{i-1,j}\to f_{i,j\bmod a_i}$$

$$f_{i-1,j}\cdot (n-i)\to f_{i,j}$$

直接转移即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=205,M=100005;
const int MOD=1000000007;
int n,X;
int a[N];
long long dp[N][M];
int main()
{
	scanf("%d%d",&n,&X);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	dp[0][X]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=X;j++)
		{
			dp[i][j%a[i]]=(dp[i][j%a[i]]+dp[i-1][j])%MOD;
			dp[i][j]=(dp[i][j]+dp[i-1][j]*(n-i)%MOD)%MOD;
		}
	long long ans=0;
	for(int j=0;j<=X;j++)
		ans=(ans+j*dp[n][j]%MOD)%MOD;
	printf("%lld",ans);
	return 0;
}
```

------------

#### E - Black or White
分成两种情况计算：

令 $f_i$ 表示吃了 $i$ 个巧克力且没有白色巧克力的概率，转移考虑吃完第 $i$ 个巧克力后没有白色巧克力的情况的概率：

$$f_i=f_{i-1}+C_{i-1}^{W-1}$$

令 $g_i$ 表示吃了 $i$ 个巧克力后两种都能吃的方案数，转移考虑减去吃完第 $i$ 个巧克力后没有白色巧克力的情况：

$$g_i=2g_{i-1}-(C_{i-1}^{B-1}+C_{i-1}^{W-1}))$$

直接搞就是了。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
const int MOD=1000000007;
int n,m;
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
long long inv2[N];
void init(int n=200000)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n;i>=1;i--)
		inv[i-1]=inv[i]*i%MOD;
	inv2[n]=ksm(ksm(2,n),MOD-2);
	for(int i=n;i>=1;i--)
		inv2[i-1]=inv2[i]*2%MOD;
	return;
}
long long C(int n,int m)
{
	if(m>n) return 0;
	else return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
long long f[N],g[N];
int main()
{
	init();
	scanf("%d%d",&n,&m);
	f[0]=0;
	g[0]=1;
	for(int i=1;i<=n+m;i++)
	{
		f[i]=(f[i-1]+C(i-1,m-1)*inv2[i]%MOD)%MOD;
		g[i]=(2*g[i-1]%MOD-(C(i-1,n-1)+C(i-1,m-1))%MOD+MOD)%MOD;
		printf("%lld\n",(f[i-1]+g[i-1]*inv2[i]%MOD)%MOD);
	}
	return 0;
}
```

------------

#### F - More Realistic Manhattan Distance
可以发现，$(a,b)$ 右边如果有多条向下的边是有用的，只有第一条向下的边是有用的。其他情况同理。则对于 $(a,b),(c,d)$ 求出上下左右每个方向的东南西北的第一条边，然后跑最短路即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n,m,Q;
char s[N],t[N];
int pw[N],pe[N],nw[N],ne[N];
int pn[N],ps[N],nn[N],ns[N];
int a,b,c,d;
vector<pair<int,int> >G[N];
int dijkstra(int s,int t,int n)
{
	static int dis[N];
	static bool vis[N];
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	for(int i=0;i<n;i++)
		dis[i]=INF,vis[i]=false;
	dis[s]=0;
	q.push(make_pair(dis[s],s));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(auto [v,w]:G[u])
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
	}
	if(dis[t]>=INF) return -1;
	else return dis[t];
}
int id[N];
void solve()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	vector<int>posr={pw[a],pe[a],a,nw[a],ne[a],pw[c],pe[c],c,nw[c],ne[c]},posc={pn[b],ps[b],b,nn[b],ns[b],pn[d],ps[d],d,nn[d],ns[d]};
	sort(posr.begin(),posr.end());
	posr.erase(unique(posr.begin(),posr.end()),posr.end());
	sort(posc.begin(),posc.end());
	posc.erase(unique(posc.begin(),posc.end()),posc.end());
	vector<pair<int,int> >p;
	int S=0,T=0;
	for(int x:posr)
		for(int y:posc)
		{
			if(x==0||y==0) continue;
			p.push_back(make_pair(x,y));
			if(x==a&&y==b) S=p.size()-1;
			if(x==c&&y==d) T=p.size()-1;
		}
	int tot=p.size();
	for(int i=0;i<tot;i++)
		id[i]=i;
	sort(id,id+tot,[=](const int &i,const int &j){return p[i].first==p[j].first?p[i].second<p[j].second:p[i].first<p[j].first;});
	for(int i=0;i<tot-1;i++)
	{
		int j=i+1;
		int sx=p[id[i]].first,sy=p[id[i]].second;
		int tx=p[id[j]].first,ty=p[id[j]].second;
		if(sx==tx)
		{
			if(s[sx]=='E') G[id[i]].push_back(make_pair(id[j],ty-sy));
			else if(s[sx]=='W') G[id[j]].push_back(make_pair(id[i],ty-sy));
		}
	}
	sort(id,id+tot,[=](const int &i,const int &j){return p[i].second==p[j].second?p[i].first<p[j].first:p[i].second<p[j].second;});
	for(int i=0;i<tot-1;i++)
	{
		int j=i+1;
		int sx=p[id[i]].first,sy=p[id[i]].second;
		int tx=p[id[j]].first,ty=p[id[j]].second;
		if(sy==ty)
		{
			if(t[sy]=='S') G[id[i]].push_back(make_pair(id[j],tx-sx));
			else if(t[sy]=='N') G[id[j]].push_back(make_pair(id[i],tx-sx));
		}
	}
	int ans=dijkstra(S,T,tot);
	printf("%d\n",ans);
	for(int i=0;i<tot;i++)
		G[i].clear();
	return;
}
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		pw[i]=pw[i-1],pe[i]=pe[i-1];
		if(s[i]=='W') pw[i]=i;
		if(s[i]=='E') pe[i]=i;
	}
	for(int i=n;i>=1;i--)
	{
		nw[i]=nw[i+1],ne[i]=ne[i+1];
		if(s[i]=='W') nw[i]=i;
		if(s[i]=='E') ne[i]=i;
	}
	scanf("%s",t+1);
	for(int i=1;i<=m;i++)
	{
		pn[i]=pn[i-1],ps[i]=ps[i-1];
		if(t[i]=='N') pn[i]=i;
		if(t[i]=='S') ps[i]=i;
	}
	for(int i=m;i>=1;i--)
	{
		nn[i]=nn[i+1],ns[i]=ns[i+1];
		if(t[i]=='N') nn[i]=i;
		if(t[i]=='S') ns[i]=i;
	}
	while(Q--)
		solve();
	return 0;
}
```