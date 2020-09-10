#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n;
vector<int>G[N];
int dep[N];
vector<int>pos[2];
void dfs(int u,int father)
{
	dep[u]=dep[father]+1;
	pos[dep[u]&1].push_back(u);
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
	}
	return;
}
vector<int>col[3];
int ans[N];
int main()
{
	scanf("%d",&n);
	int num[3]={n/3,(n+2)/3,(n+1)/3};
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	int x=pos[0].size(),y=pos[1].size();
	if(x<=num[0])
	{
		for(int u:pos[0])
			col[0].push_back(u),num[0]--;
		for(int u:pos[1])
		{
			if(num[0]>0) col[0].push_back(u),num[0]--;
			else if(num[1]>0) col[1].push_back(u),num[1]--;
			else if(num[2]>0) col[2].push_back(u),num[2]--;
		}
	}
	else if(y<=num[0])
	{
		for(int u:pos[1])
			col[0].push_back(u),num[0]--;
		for(int u:pos[0])
		{
			if(num[0]>0) col[0].push_back(u),num[0]--;
			else if(num[1]>0) col[1].push_back(u),num[1]--;
			else if(num[2]>0) col[2].push_back(u),num[2]--;
		}
	}
	else
	{
		for(int u:pos[0])
		{
			if(num[1]>0) col[1].push_back(u),num[1]--;
			else if(num[0]>0) col[0].push_back(u),num[0]--;
		}
		for(int u:pos[1])
		{
			if(num[2]>0) col[2].push_back(u),num[2]--;
			else if(num[0]>0) col[0].push_back(u),num[0]--;
		}
	}
	int now=1;
	for(int u:col[1])
		ans[u]=now,now+=3;
	now=2;
	for(int u:col[2])
		ans[u]=now,now+=3;
	now=3;
	for(int u:col[0])
		ans[u]=now,now+=3;
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
