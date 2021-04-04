#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n;
vector<int>G[N];
int calc(int u,int father,int x)
{
	int res=0;
	for(int v:G[u])
	{
		if(v==father) continue;
		if(v<x) res+=calc(v,u,x)+1;
	}
	return res;
}
int mx[N];
int ans[N];
void dfs(int u,int father)
{
	mx[u]=max(mx[father],u);
	for(int v:G[u])
	{
		if(v==father) continue;
		ans[v]=ans[u];
		if(u>mx[father])
		{
			if(v>mx[father]) ans[v]+=calc(v,u,u)+1;
			else ans[v]+=calc(v,u,u)-calc(v,u,mx[father]);
		}
		else
		{
			if(v>mx[father]) ans[v]+=calc(v,u,mx[father])+1;
		}
		dfs(v,u);
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}
	dfs(1,0);
	for(int i=2;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}