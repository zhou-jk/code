//HihoCoder-1393
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int N=100,M=100,INF=0x3f3f3f3f;
struct Edge
{
	int v,cf,next;
} edge[(N*M+N+M)<<1];
int head[N+M+2],work[N+M+2],dist[N+M+2],q[N+M+2],s,t,n_edge;

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
	if (!flow||k==t) return flow;
	int v,tmp;
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
	int tc,n,m,tmp1,tmp2,ans,sum;
	scanf("%d",&tc);
	while (tc--)
	{
		sum=ans=0;
		scanf("%d%d",&n,&m);
		s=0; t=n+m+1;
		memset(head,-1,sizeof head); n_edge=0;
		for (int i=1; i<=m; i++)
		{
			scanf("%d",&tmp1);
			tmp2=n+i;
			add_edge(tmp2,t,tmp1); add_edge(t,tmp2,0);
			sum+=tmp1;
		}
		for (int i=1; i<=n; i++)
		{
			scanf("%d%d",&tmp1,&tmp2);
			add_edge(s,i,tmp1); add_edge(i,s,0);
			for (int j=0; j<tmp2; j++)
			{
				scanf("%d",&tmp1);
				tmp1+=n;
				add_edge(i,tmp1,1); add_edge(tmp1,i,0);
			}
		}
		while (bfs())
		{
			memcpy(work,head,sizeof head);
			while ((tmp1=dfs(s,INF))) ans+=tmp1;
		}
		puts(sum==ans?"Yes":"No");
	}
	return 0;
}