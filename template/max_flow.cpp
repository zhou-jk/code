#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=205,M=10005;
const long long INF=4557430888798830399;
struct Edge
{
	int from,to,next;
	long long val;
}edge[M];
int cur[N],head[N],cnt=1;
int n,m,s,t;
void add_edge(int u,int v,int w)
{
	cnt++;
    edge[cnt].from=u;
	edge[cnt].to=v;
	edge[cnt].val=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
	return;
}
int dep[N];
bool bfs(int s,int t)
{
    for(int i=1;i<=n;i++)
        dep[i]=-1;
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
			if(dep[v]!=-1||edge[i].val<=0) continue;
			dep[v]=dep[u]+1;
			q.push(v);
		}
	}
	return dep[t]!=-1;
}
int pre[N];
long long dfs(int u,long long flow)
{
    if(u==t)
    {
        
    }
	if(u==t||flow==0) return flow;
	long long used=0;
	for(int &i=cur[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(dep[v]!=dep[u]+1||edge[i].val<=0) continue;
		long long now=dfs(v,min(flow,(long long)edge[i].val));
		flow-=now;
		edge[i].val-=now;
		edge[i^1].val+=now;
		used+=now;
		if(flow==0) break;
	}
	return used;
}
int gap[N];
long long isap()
{
    bfs(t,s);
    for(int i=1;i<=n;i++)
        gap[i]=0;
    for(int i=1;i<=n;i++)
        gap[dep[i]]++;
    int x=s;
    for(int i=1;i<=n;i++)
        cur[i]=head[i];
    while(dep[s]<n)
    {
        if(x==t)
        {

        }
    }
}
long long dinic()
{
	long long res=0;
	while(bfs(s,t))
	{
        for(int i=1;i<=n;i++)
            cur[i]=head[i];
		res+=dfs(s,INF);
	}
	return res;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
		add_edge(y,x,0);
	}
	printf("%lld",dinic());
	return 0;
}