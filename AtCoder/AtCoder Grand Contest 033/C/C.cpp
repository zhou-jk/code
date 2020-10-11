#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=200005;
int n;
vector<int>G[N];
int s,t,len;
int p;
int dis[N];
void dfs(int u,int father)
{
	dis[u]=dis[father]+1;
	if(dis[u]>dis[p]) p=u;
	for(int v:G[u])
	{
		if(v==father) continue;
		dfs(v,u);
	}
	return;
}
bool dp[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	p=0;
	dfs(1,0);
	s=p;
	p=0;
	dfs(s,0);
	t=p;
	len=dis[t];
	dp[0]=false,dp[1]=true,dp[2]=false;
	for(int i=3;i<=len;i++)
	{
		if(i-1>=0&&!dp[i-1]) dp[i]=true;
		if(i-2>=0&&!dp[i-2]) dp[i]=true;
	}
	if(dp[len]) printf("First");
	else printf("Second");
	return 0;
}
