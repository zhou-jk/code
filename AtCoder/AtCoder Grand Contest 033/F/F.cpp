#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int N=2005;
int n,m;
vector<int>G[N];
int fa[N][N];
void dfs(int u,int father,int p)
{
	fa[p][u]=father;
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u,p);
	}
	return;
}
int top[N][N];
void add(int a,int b)
{
	if(top[a][b]==b||top[b][a]==a) return;
	if(top[a][b]!=a) return add(top[a][b],b);
	if(top[b][a]!=b) return add(a,top[b][a]);
	top[a][b]=b,top[b][a]=a;
	vector<pair<int,int> >edge;
	queue<int>q;
	q.push(b);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:G[u])
		{
			if(v==fa[a][u]) continue;
			if(top[a][v]==a)
			{
				top[a][v]=b;
				q.push(v);
			}
			else edge.push_back(make_pair(b,top[a][v]));
		}
	}
	swap(a,b);
	q.push(b);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:G[u])
		{
			if(v==fa[a][u]) continue;
			if(top[a][v]==a)
			{
				top[a][v]=b;
				q.push(v);
			}
			else edge.push_back(make_pair(b,top[a][v]));
		}
	}
	for(auto [u,v]:edge)
		add(u,v);
	return;
}
int ans;
void solve(int u,int father,int pre)
{
	if(u!=pre&&top[pre][u]!=pre) pre=u,ans++;
	for(int v:G[u])
	{
		if(v==father) continue;
		solve(v,u,pre);
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int u=1;u<=n;u++)
		dfs(u,0,u);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			top[i][j]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++)
		solve(i,0,i);
	printf("%d",ans/2);
	return 0;
}
