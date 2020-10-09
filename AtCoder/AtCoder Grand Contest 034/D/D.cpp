#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=2010;
const int INF=1061109567;
const long long LINF=4557430888798830399;
int n;
int rx[N],ry[N],rc[N];
int bx[N],by[N],bc[N];
struct Edge
{
	int to,next;
	long long flow,cost;
}edge[N*10];
int head[N],cur[N],cnt=1;
void add_edge(int u,int v,int c,int f)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].cost=c;
	edge[cnt].flow=f;
	edge[cnt].next=head[u];
	head[u]=cnt;
	return;
}
void add(int u,int v,int c,int f)
{
	add_edge(u,v,c,f);
	add_edge(v,u,-c,0);
	return;
}
int s,t;
long long dis[N];
bool spfa()
{
	static bool vis[N];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<=2*n+5;i++)
		dis[i]=-LINF;
	vis[s]=true;
	dis[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(edge[i].flow<=0) continue;
			if(dis[v]<dis[u]+edge[i].cost)
			{
				dis[v]=dis[u]+edge[i].cost;
				if(!vis[v])
				{
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	return dis[t]!=-LINF;
}
bool book[N];
pair<long long,long long> dfs(int u,long long flow)
{
	if(u==t||flow==0) return make_pair(flow,0);
	book[u]=true;
	long long used=0,res=0;
	for(int &i=cur[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(book[v]||dis[v]!=dis[u]+edge[i].cost||edge[i].flow<=0) continue;
		pair<long long,long long>t=dfs(v,min(flow,edge[i].flow));
		long long now=t.first;
		res+=t.second+now*edge[i].cost;
		flow-=now;
		edge[i].flow-=now;
		edge[i^1].flow+=now;
		used+=now;
		if(flow==0) break;
	}
	book[u]=false;
	return make_pair(used,res);
}
pair<long long,long long> dinic()
{
	long long ans=0,Min=0;
	while(spfa())
	{
		memcpy(cur,head,sizeof(head));
		pair<long long,long long> res=dfs(s,INF);
		ans+=res.first,Min+=res.second;
	}
	return make_pair(ans,Min);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&rx[i],&ry[i],&rc[i]);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&bx[i],&by[i],&bc[i]);
	s=0,t=2*n+1;
	int p1=2*n+2,p2=2*n+3,p3=2*n+4,p4=2*n+5;
	for(int i=1;i<=n;i++)
	{
		add(s,i,0,rc[i]);
		add(i,p1,rx[i]+ry[i],INF);
		add(i,p2,rx[i]-ry[i],INF);
		add(i,p3,-rx[i]+ry[i],INF);
		add(i,p4,-rx[i]-ry[i],INF);
	}
	for(int i=1;i<=n;i++)
	{
		add(i+n,t,0,bc[i]);
		add(p1,i+n,-bx[i]-by[i],INF);
		add(p2,i+n,-bx[i]+by[i],INF);
		add(p3,i+n,bx[i]-by[i],INF);
		add(p4,i+n,bx[i]+by[i],INF);
	}
	long long ans=dinic().second;
	printf("%lld",ans);
	return 0;
}
