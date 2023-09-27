#### A - Subscribers

------------

最小值为 $\min(A,B)$，最大值为 $\max(A+B-n,0)$。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
int n,A,B;
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	printf("%d %d",min(A,B),max(A+B-n,0));
	return 0;
}
```

------------

#### B - Touitsu
对于每个位置 $i$，每次肯定将字符变成在 $a_i,b_i,c_i$ 出现次数最多的字符，然后模拟就完了。

------------

```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
int n;
char a[N],b[N],c[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	scanf("%s",c+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]!=b[i]&&b[i]!=c[i]&&a[i]!=c[i]) ans+=2;
		else if(a[i]==b[i]&&b[i]==c[i]);
		else if(a[i]==b[i]||b[i]==c[i]||a[i]==c[i]) ans++;
	printf("%d",ans);
	return 0;
}
```

------------

#### C - Different Strokes
可以转化一下，将答案先减去 $\sum\limits_{i=1}^n b_i$，问题变成了选 $i$ 会有 $a_i+b_i$ 的收益，不选会有 $0$ 的收益，将所有物品按照 $a_i+b_i$ 从大到小排序贪心选择即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n;
int a[N],b[N];
int id[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)
		id[i]=i;
	sort(id+1,id+n+1,[=](const int &x,const int &y){return a[x]+b[x]>a[y]+b[y];});
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans-=b[i];
	for(int i=1;i<=n;i+=2)
		ans+=a[id[i]]+b[id[i]];
	printf("%lld",ans);
	return 0;
}
```

------------

#### D - Restore the Tree
可以发现出度为 $0$ 的节点肯定为叶子，拓扑排序后从下往上搞就好了。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=100005;
int n,m;
vector<int>G[N],g[N];
int out[N];
int fa[N];
void topsort()
{
	queue<int>q;
	for(int i=1;i<=n-1+m;i++)
		if(!out[i]) q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:g[u])
			if(!fa[v]) fa[v]=u;
		for(int v:G[u])
		{
			out[v]--;
			if(out[v]==0) q.push(v);
		}
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1+m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		G[y].push_back(x);
		out[x]++;
	}
	topsort();
	for(int i=1;i<=n;i++)
		printf("%d\n",fa[i]);
	return 0;
}
```

------------

#### E - Weights on Vertices and Edges
考虑加边，将边按照边权从小到大排序，每次将两个连通块合并，如果合并后的联通块的权值和大于当前边的权值，将连通块内所有的边都加入答案中。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m;
int a[N];
struct Edge
{
	int u,v,w;
}e[N];
int fa[N],siz[N];
long long sum[N];
int getf(int v)
{
	if(v==fa[v]) return v;
	fa[v]=getf(fa[v]);
	return fa[v];
}
void merge(int u,int v)
{
	int f1=getf(u),f2=getf(v);
	if(f1!=f2) fa[f2]=f1,siz[f1]+=siz[f2],sum[f1]+=sum[f2];
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,[=](const Edge &a,const Edge &b){return a.w<b.w;});
	for(int i=1;i<=n;i++)
		fa[i]=i,sum[i]=a[i];
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		merge(e[i].u,e[i].v);
		int f=getf(e[i].u);
		siz[f]++;
		if(sum[f]>=e[i].w) ans+=siz[f],siz[f]=0;
	}
	printf("%d",m-ans);
	return 0;
}
```

------------

#### F - Jewels

将每种颜色的最大的两个视为一组，其他的看做单个。考虑容量 $x$ 多一的操作，可以分成四种情况：

- 加入一个已经加入组的单个。
- 将一个已经加入组的单个删除，加入新的一组。
- 将一组删除，加入一组加一个。
- 将一组加一个删除，加入新的两组。

模拟即可。具体实现可以用 $6$ 个 `std::multiset` 维护可以加入的单个，可以加入的两个，可以加入的一对加一个，当前已经有的单个，当前已经有的两个，当前已经有的一对加一个。注意细节即可。

------------

```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int N=200005;
const long long INF=1e18;
int n,k;
vector<int>val[N];
multiset<pair<long long,int> >q1,q2,q3;
multiset<pair<long long,int> >n1,n2,n3;
int cnt[N];
long long res[N];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int c,v;
		scanf("%d%d",&c,&v);
		val[c].push_back(v);
	}
	for(int c=1;c<=k;c++)
		sort(val[c].begin(),val[c].end(),greater<int>());
	for(int c=1;c<=k;c++)
		if(val[c].size()>=2)
		{
			q2.insert(make_pair(val[c][0]+val[c][1],c));
			if(val[c].size()>=3) q3.insert(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c));
		}
	for(int t=1;t<=n;t++)
	{
		if(res[t-1]!=-1)
		{
			long long ans1=-INF,ans2=-INF,ans3=-INF,ans4=-INF;
			if(!q1.empty()) ans1=q1.rbegin()->first;
			if(!n1.empty()&&!q2.empty()) ans2=-n1.begin()->first+q2.rbegin()->first;
			if(!n2.empty()&&!q3.empty()) ans3=-n2.begin()->first+q3.rbegin()->first;
			if(!n3.empty()&&q2.size()>=2) ans4=-n3.begin()->first+(q2.rbegin()->first)+((++q2.rbegin())->first);
			long long ans=max({ans1,ans2,ans3,ans4});
			if(ans!=-INF)
			{
				if(ans==ans1)
				{
					n1.insert(*q1.rbegin());
					int c=q1.rbegin()->second;
					if(cnt[c]==1)
					{
						n2.insert(make_pair(val[c][0]+val[c][1],c));
						if(val[c].size()>=3) n3.erase(n3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
					}
					cnt[c]++;
					if(cnt[c]==1)
					{
						n2.erase(n2.find(make_pair(val[c][0]+val[c][1],c)));
						if(val[c].size()>=3) n3.insert(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c));
					}
					q1.erase(--q1.end());
				}
				else if(ans==ans2)
				{
					int c=n1.begin()->second;
					if(cnt[c]==1)
					{
						n2.insert(make_pair(val[c][0]+val[c][1],c));
						if(val[c].size()>=3) n3.erase(n3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
					}
					cnt[c]--;
					if(cnt[c]==1)
					{
						n2.erase(n2.find(make_pair(val[c][0]+val[c][1],c)));
						if(val[c].size()>=3) n3.insert(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c));
					}
					q1.insert(*n1.begin());
					n1.erase(n1.begin());
					c=q2.rbegin()->second;
					if(val[c].size()>=3) q3.erase(q3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
					for(size_t i=2;i<val[c].size();i++)
						q1.insert(make_pair(val[c][i],c));
					n2.insert(*q2.rbegin());
					q2.erase(--q2.end());
				}
				else if(ans==ans3)
				{
					int c=n2.begin()->second;
					q2.insert(*n2.begin());
					if(val[c].size()>=3) q3.insert(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c));
					for(size_t i=2;i<val[c].size();i++)
						q1.erase(q1.find(make_pair(val[c][i],c)));
					n2.erase(n2.begin());
					c=q3.rbegin()->second;
					cnt[c]++;
					n1.insert(make_pair(val[c][2],c));
					n3.insert(*q3.rbegin());
					for(size_t i=3;i<val[c].size();i++)
						q1.insert(make_pair(val[c][i],c));
					q2.erase(q2.find(make_pair(val[c][0]+val[c][1],c)));
					q3.erase(--q3.end());
				}
				else if(ans==ans4)
				{
					int c=n3.begin()->second;
					cnt[c]--;
					n1.erase(n1.find(make_pair(val[c][2],c)));
					q3.insert(*n3.begin());
					q2.insert(make_pair(val[c][0]+val[c][1],c));
					for(size_t i=3;i<val[c].size();i++)
						if(q1.find(make_pair(val[c][i],c))!=q1.end()) q1.erase(q1.find(make_pair(val[c][i],c)));
					n3.erase(n3.begin());
					c=q2.rbegin()->second;
					if(val[c].size()>=3) q3.erase(q3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
					for(size_t i=2;i<val[c].size();i++)
						q1.insert(make_pair(val[c][i],c));
					n2.insert(*q2.rbegin());
					c=(++q2.rbegin())->second;
					if(val[c].size()>=3) q3.erase(q3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
					for(size_t i=2;i<val[c].size();i++)
						q1.insert(make_pair(val[c][i],c));
					n2.insert(*(++q2.rbegin()));
					q2.erase(--(--q2.end()));
					q2.erase(--q2.end());
				}
				res[t]=res[t-1]+ans;
			}
			else res[t]=-1;
		}
		else if(res[t-2]==-1) res[t]=-1;
		else
		{
			long long ans=res[t-2];
			if(!q2.empty())
			{
				ans+=q2.rbegin()->first;
				int c=q2.rbegin()->second;
				if(val[c].size()>=3) q3.erase(q3.find(make_pair((long long)val[c][0]+val[c][1]+val[c][2],c)));
				for(size_t i=2;i<val[c].size();i++)
					q1.insert(make_pair(val[c][i],c));
				n2.insert(*q2.rbegin());
				q2.erase(--q2.end());
			}
			res[t]=ans;
		}
		printf("%lld\n",res[t]);
	}
	return 0;
}
```