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
