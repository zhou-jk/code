#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N=1000005,M=25;
int n,m;
int in[N],out[N];
int source[M],tot1;
int pos[N],tot2;
int state[M];
vector<int>G[N];
int bfs(int s)
{
	static bool vis[N];
	memset(vis,false,sizeof(vis));
	queue<int>q;
	vis[s]=true;
	q.emplace(s);
	int S=0;
	if(out[s]==0) S|=1<<pos[s];
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int v:G[u])
		{
			if(vis[v]) continue;
			if(out[v]==0) S|=1<<pos[v];
			vis[v]=true;
			q.emplace(v);
		}
	}
	return S;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		G[x].emplace_back(y);
		out[x]++,in[y]++;
	}
	for(int i=0;i<n;i++)
	{
		if(in[i]==0) source[tot1++]=i;
		if(out[i]==0) pos[i]=tot2++;
	}
	for(int i=0;i<tot1;i++)
		state[i]=bfs(source[i]);
	for(int S=1;S<(1<<tot1)-1;S++)
	{
		int to=0;
		for(int i=0;i<tot1;i++)
			if(S&(1<<i)) to|=state[i];
		if(__builtin_popcount(to)<=__builtin_popcount(S))
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
