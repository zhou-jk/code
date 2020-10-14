#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=100005;
int n,m;
vector<int>G[N];
int in[N];
bool vis[N];
int s,t;
int cnt;
void dfs(int u)
{
	vis[u]=true;
	for(int v:G[u])
	{
		if(v==t)
		{
			cnt++;
			continue;
		}
		if(vis[v]) continue;
		dfs(v);
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		in[x]++,in[y]++;
	}
	for(int i=1;i<=n;i++)
		if(in[i]&1)
		{
			printf("No");
			return 0;
		}
	for(int i=1;i<=n;i++)
		if(in[i]>4)
		{
			printf("Yes");
			return 0;
		}
	vector<int>pos;
	for(int i=1;i<=n;i++)
		if(in[i]==4) pos.push_back(i);
	if(pos.size()<2)
	{
		printf("No");
		return 0;
	}
	if(pos.size()>2)
	{
		printf("Yes");
		return 0;
	}
	s=pos.front(),t=pos.back();
	dfs(s);
	if(cnt>=4) printf("No");
	else printf("Yes");
	return 0;
}
