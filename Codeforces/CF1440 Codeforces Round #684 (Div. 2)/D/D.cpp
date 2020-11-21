#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=100005;
int T;
int n,m,k;
int d[N];
vector<int>G[N];
bool check(int x,int y)
{
	vector<int>::iterator it=lower_bound(G[x].begin(),G[x].end(),y);
	if(it==G[x].end()) return false;
	else return *it==y;
}
bool book[N];
vector<int>check_clique(int u)
{
	vector<int>res;
	res.emplace_back(u);
	for(int v:G[u])
		if(!book[v]) res.emplace_back(v);
	for(int u:res)
		for(int v:res)
			if(u!=v)
			{
				if(!check(u,v)) return {};
			}
	return res;
}
bool vis[N];
void toposort()
{
	for(int i=1;i<=n;i++)
		vis[i]=book[i]=false;
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(d[i]<k)
		{
			vis[i]=true;
			q.emplace(i);
		}
	vector<int>clique;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		book[u]=true;
		if(d[u]==k-1)
		{
			vector<int>res=check_clique(u);
			if(!res.empty()) clique=res;
		}
		for(int v:G[u])
		{
			d[v]--;
			if(vis[v]) continue;
			if(d[v]<k)
			{
				vis[v]=true;
				q.emplace(v);
			}
		}
	}
	vector<int>subset;
	for(int i=1;i<=n;i++)
		if(!vis[i]) subset.emplace_back(i);
	if(!subset.empty())
	{
		int s=subset.size();
		printf("1 %d\n",s);
		for(int u:subset)
			printf("%d ",u);
		printf("\n");
	}
	else if(!clique.empty())
	{
		printf("2\n");
		for(int u:clique)
			printf("%d ",u);
		printf("\n");
	}
	else printf("-1\n");
	return;
}
void solve()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		G[i].clear(),d[i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].emplace_back(y);
		G[y].emplace_back(x);
		d[x]++,d[y]++;
	}
	if(1LL*k*(k-1)/2>m)
	{
		printf("-1\n");
		return;
	}
	for(int i=1;i<=n;i++)
		sort(G[i].begin(),G[i].end());
	toposort();
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
