#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=200005;
const int INF=1061109567;
int n;
int p[N],q[N];
int ida[N],cnta;
int idb[N],cntb;
struct Edge
{
	int to,flow;
	int next;
}edge[N<<1];
int head[N],cnt=1;
void add_edge(int u,int v,int flow)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].flow=flow;
	edge[cnt].next=head[u];
	head[u]=cnt;
	return;
}
void add(int u,int v,int flow)
{
	add_edge(u,v,flow);
	add_edge(v,u,0);
	return;
}
int s,t;
int dep[N];
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
int cur[N];
int dfs(int u,int flow)
{
	if(u==t) return flow;
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
	if(used==0) dep[u]=-1;
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
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]),p[i]++;
	for(int i=1;i<=n;i++)
		scanf("%d",&q[i]),q[i]++;
	for(int i=1;i<=n;i++)
		if(!ida[i])
		{
			cnta++;
			ida[i]=cnta;
			int u=p[i];
			while(u!=i)
				ida[u]=cnta,u=p[u];
		}
	cntb=cnta;
	for(int i=1;i<=n;i++)
		if(!idb[i])
		{
			cntb++;
			idb[i]=cntb;
			int u=q[i];
			while(u!=i)
				idb[u]=cntb,u=q[u];
		}
	s=0,t=cntb+1;
	int ans=n;
	for(int i=1;i<=n;i++)
		if(p[i]==i&&q[i]==i) ans--;
		else if(p[i]==i&&q[i]!=i) add(s,idb[i],1);
		else if(p[i]!=i&&q[i]==i) add(ida[i],t,1);
		else if(p[i]==q[i]&&p[i]!=i) add(ida[i],idb[i],1),add(idb[i],ida[i],1);
		else add(ida[i],idb[i],1);
	ans-=dinic();
	printf("%d",ans);
	return 0;
}
