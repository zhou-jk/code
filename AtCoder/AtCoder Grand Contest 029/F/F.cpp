#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n;
struct Edge
{
	int to,next,flow;
}edge[N*2+N*4];
int head[N<<1],cnt=1;
void add_edge(int u,int v,int f)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	edge[cnt].flow=f;
	head[u]=cnt;
	return;
}
void add(int u,int v,int f)
{
	add_edge(u,v,f);
	add_edge(v,u,0);
	return;
}
int s,t;
int dep[N<<1];
bool bfs()
{
	memset(dep,-1,sizeof(dep));
	queue<int>q;
	q.push(s);
	dep[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(dep[v]!=-1||edge[i].flow<=0) continue;
			dep[v]=dep[u]+1;
			q.push(v);
		}
	}
	return dep[t]!=-1;
}
int cur[N<<1];
int dfs(int u,int flow)
{
	if(u==t||flow==0) return flow;
	int used=0;
	for(int &i=cur[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(dep[v]!=dep[u]+1||edge[i].flow<=0) continue;
		int now=dfs(v,min(flow,edge[i].flow));
		flow-=now;
		edge[i].flow-=now;
		edge[i^1].flow+=now;
		used+=now;
		if(flow==0) break;
	}
	return used;
}
int dinic()
{
	int res=0;
	while(bfs())
	{
		memcpy(cur,head,sizeof(head));
		res+=dfs(s,INF);
	}
	return res;
}
vector<int>G[N];
int match[N];
bool vis[N];
pair<int,int>res[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=c;j++)
		{
			int x;
			scanf("%d",&x);
			if(x!=1) add(x,i+n,1);
			G[x].emplace_back(i);
		}
	}
	s=0,t=n+n-1+1;
	for(int i=2;i<=n;i++)
		add(s,i,1);
	for(int i=1;i<=n-1;i++)
		add(i+n,t,1);
	int ans=dinic();
	if(ans!=n-1)
	{
		printf("-1");
		return 0;
	}
	for(int u=2;u<=n;u++)
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(v==s) continue;
			if(edge[i].flow==0) match[v-n]=u;
		}
	queue<int>q;
	q.emplace(1);
	int tot=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int c:G[u])
			if(!vis[c])
			{
				int v=match[c];
				res[c]={u,v};
				tot++;
				q.emplace(v);
				vis[c]=true;
			}
	}
	if(tot!=n-1)
	{
		printf("-1");
		return 0; 
	}
	for(int i=1;i<=n-1;i++)
		printf("%d %d\n",res[i].first,res[i].second);
	return 0;
}