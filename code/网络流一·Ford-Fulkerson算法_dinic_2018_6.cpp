//HihoCoder-1369
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int N=500,M=20000,INF=0x3f3f3f3f;
struct Edge
{
	int v,cf,next;
} edge[M<<1];
int head[N],work[N],q[N],dist[N],n_edge,s,t;

void add_edge(int u,int v,int cf)
{
	edge[n_edge]= {v,cf,head[u]};
	head[u]=n_edge++;
}

bool bfs()
{
	int l=0,r=0,v;
	memset(dist,-1,sizeof dist);
	dist[s]=0; q[r++]=s;
	for (; l<r; l++)
		for (int i=head[q[l]]; i!=-1; i=edge[i].next)
		{
			v=edge[i].v;
			if (edge[i].cf&&dist[v]==-1)
			{
				dist[v]=dist[q[l]]+1;
				q[r++]=v;
			}
		}
	return dist[t]!=-1;
}

int dfs(int k,int flow)
{
	int v,tmp;
	if (!flow||k==t) return flow;
	for (int &i=work[k]; i!=-1; i=edge[i].next)
	{
		v=edge[i].v;
		if (dist[v]==dist[k]+1&&(tmp=dfs(v,min(edge[i].cf,flow))))
		{
			edge[i].cf-=tmp; edge[i^1].cf+=tmp;
			return tmp;
		}
	}
	return 0;
}

int main()
{
	int n,m,tmp,u,v,c,ans=0;
	scanf("%d%d",&n,&m);
	s=0; t=n-1;
	memset(head,-1,sizeof head);
	for (int i=0; i<m; i++)
	{
		scanf("%d%d%d",&u,&v,&c);
		u--; v--;
		add_edge(u,v,c); add_edge(v,u,0);
	}
	while (bfs())
	{
		memcpy(work,head,sizeof head);
		while ((tmp=dfs(s,INF))) ans+=tmp;
	}
	printf("%d",ans);
	return 0;
}