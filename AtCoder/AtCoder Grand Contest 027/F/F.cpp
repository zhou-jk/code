#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=55;
const int INF=1061109567;
int T;
int n;
vector<pair<int,int>>edge;
vector<int>GA[N],GB[N];
vector<int>leaf;
void findleaf(int u,int father)
{
	int tot=(u!=1);
	for(int v:GA[u])
	{
		if(v==father) continue;
		findleaf(v,u);
		tot++;
	}
	if(tot==1) leaf.emplace_back(u);
	return;
}
vector<int>G[N];
int fab[N];
void dfsb(int u,int father)
{
	fab[u]=father;
	for(int v:GB[u])
	{
		if(v==father) continue;
		dfsb(v,u);
	}
	return;
}
bool flag;
int faa[N];
bool book[N];
int deg[N];
void dfsa(int u,int father)
{
	faa[u]=father;
	if(faa[u]!=fab[u]) book[u]=true;
	if(!book[u]&&book[father]) flag=false;
	for(int v:GA[u])
	{
		if(v==father) continue;
		dfsa(v,u);
	}
	return;
}
void dfs(int u,int father)
{
	if(book[u])
	{
		if(book[faa[u]]) G[faa[u]].emplace_back(u),deg[u]++;
		if(book[fab[u]]) G[u].emplace_back(fab[u]),deg[fab[u]]++;
	}
	for(int v:GA[u])
	{
		if(v==father) continue;
		dfs(v,u);
	}
	return;
}
int toposort()
{
	static bool vis[N];
	for(int i=1;i<=n;i++)
		vis[i]=false;
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(deg[i]==0) q.emplace(i);
	int tot=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		tot++;
		for(int v:G[u])
		{
			deg[v]--;
			if(deg[v]==0) q.emplace(v); 
		}
	}
	return tot;
}
void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		GA[i].clear(),GB[i].clear();
	edge.clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		GA[x].emplace_back(y);
		GA[y].emplace_back(x);
		edge.emplace_back(x,y);
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		GB[x].emplace_back(y);
		GB[y].emplace_back(x);
	}
	leaf.clear();
	findleaf(1,0);
	int ans=INF;
	for(int u:leaf)
	{
		dfsb(u,0);
		for(int v=1;v<=n;v++)
			if(u!=v)
			{ 
				for(int i=1;i<=n;i++)
					GA[i].clear(),book[i]=false,G[i].clear(),deg[i]=0;
				int fa=0;
				for(auto [uu,vv]:edge)
					if(uu==u) fa=vv;
					else if(vv==u) fa=uu;
				for(auto [uu,vv]:edge)
					{
						if(uu==u&&vv==fa) continue;
						if(uu==fa&&vv==u) continue;
						GA[uu].emplace_back(vv);
						GA[vv].emplace_back(uu);
					}
				GA[u].emplace_back(v);
				GA[v].emplace_back(u);
				flag=true;
				dfsa(u,0);
				dfs(u,0);
				if(!flag) continue;
				if(toposort()!=n) continue;
				int res=(v!=fa);
				for(int i=1;i<=n;i++)
					if(book[i]) res++;
				ans=min(ans,res);
			}
	}
	if(ans>=INF) printf("-1\n");
	else printf("%d\n",ans); 
	return;
}
int main()
{
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}