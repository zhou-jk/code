#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1000005,M=5005;
const long long MAX=1e12;
int T;
bool isprime[N];
int prime[N],tot;
void init(int n=1000000)
{
	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(isprime[i]) prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0) break;
		}
	}
	return;
}
long long mul(long long a,long long b)
{
	__int128 c=(__int128)a*b;
	if(c>MAX) return MAX+1;
	else return c;
}
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=mul(res,a);
		a=mul(a,a),b>>=1;
	}
	return res;
}
vector<int>state[M];
int m;
map<vector<int>,int>pos;
int factor[M];
int b[M],num;
void dfs(vector<int>now,long long sum,int fac)
{
	if(sum>MAX) return;
	if(pos[now]) return;
	m++;
	state[m]=now;
	factor[m]=fac;
	b[++num]=fac;
	pos[now]=m;
	int lim=now.empty()?40:now.back();
	for(int i=1;i<=lim;i++)
	{
		vector<int>nxt=now;
		nxt.emplace_back(i);
		dfs(nxt,mul(sum,ksm(prime[nxt.size()],i)),fac*(i+1));
	}
	return;
}
vector<int>G[M];
void add(int s)
{
	vector<int>&val=state[s];
	for(size_t i=0;i<val.size();i++)
	{
		vector<int>nxt;
		for(size_t j=0;j<i;j++)
			nxt.emplace_back(val[j]);
		if(val[i]-1>0) nxt.emplace_back(val[i]-1);
		for(size_t j=i+1;j<val.size();j++)
			nxt.emplace_back(val[j]);
		sort(nxt.begin(),nxt.end(),greater<int>());
		if(pos[nxt]) G[s].emplace_back(pos[nxt]);
		nxt.clear();
		for(size_t j=0;j<i;j++)
			nxt.emplace_back(val[j]);
		nxt.emplace_back(val[i]+1);
		for(size_t j=i+1;j<val.size();j++)
			nxt.emplace_back(val[j]);
		sort(nxt.begin(),nxt.end(),greater<int>());
		if(pos[nxt]) G[s].emplace_back(pos[nxt]);
	}
	vector<int>nxt=val;
	nxt.push_back(1);
	if(pos[nxt]) G[s].emplace_back(pos[nxt]);
	return;
}
void bfs(int s,int *dis)
{
	static bool vis[M];
	for(int i=1;i<=m;i++)
		vis[i]=false,dis[i]=m+1;
	dis[s]=0;
	vis[s]=true;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:G[u])
		{
			if(vis[v]) continue;
			dis[v]=dis[u]+1;
			vis[v]=true;
			q.push(v);
		}
	}
	return;
}
vector<int>divide(int x)
{
	vector<int>res;
	for(int i=1;i<=tot&&prime[i]<=sqrt(x);i++)
		if(x%prime[i]==0)
		{
			int cnt=0;
			while(x%prime[i]==0) x/=prime[i],cnt++;
			res.emplace_back(cnt);
		}
	if(x!=1) res.emplace_back(1);
	sort(res.begin(),res.end(),greater<int>());
	return res;
}
int dis[M][M];
int f[M][M];
void solve()
{
	int a,b;
	scanf("%d%d",&a,&b);
	vector<int>p=divide(a),q=divide(b);
	int s=pos[p],t=pos[q];
	int ans=m;
	for(int u=1;u<=num;u++)
		ans=min(ans,f[s][u]+f[t][u]);
	printf("%d\n",ans);
	return;
}
int main()
{
	init();
	dfs({},1,1);
	for(int i=1;i<=m;i++)
		add(i);
	for(int i=1;i<=m;i++)
	{
		sort(G[i].begin(),G[i].end());
		G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
	}
	for(int i=1;i<=m;i++)
		bfs(i,dis[i]);
	sort(b+1,b+num+1);
	num=unique(b+1,b+num+1)-b-1;
	for(int i=1;i<=m;i++)
		factor[i]=lower_bound(b+1,b+num+1,factor[i])-b;
	memset(f,63,sizeof(f));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			f[i][factor[j]]=min(f[i][factor[j]],dis[i][j]);
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
