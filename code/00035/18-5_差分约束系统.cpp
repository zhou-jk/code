//AC
#include <cstdio>
#include <cstring>

const int K_MAX=50000,N_EDGE=50000;
int head[K_MAX],dist[K_MAX],q[K_MAX],n_edge,k_max;
bool vis[K_MAX];

class Edge
{
	friend int solve();
	friend inline void add_edge(const int u,const int v,const int dist);
	int v,dist,next;
} edge[N_EDGE+K_MAX*2];

int solve()
{
	memset(dist,-63,sizeof dist);
	memset(vis,false,sizeof vis);
	int r=1,k,v;
	q[0]=0;
	dist[0]=0;
	for (int l=0; l!=r; l=(l+1)%K_MAX)
	{
		k=q[l];
		vis[k]=false;
		for (int i=head[k]; i>-1; i=edge[i].next)
		{
			v=edge[i].v;
			if (dist[k]+edge[i].dist>dist[v])
			{
				dist[v]=dist[k]+edge[i].dist;
				if (!vis[v])
				{
					q[r]=v;
					r=(r+1)%K_MAX;
					vis[v]=true;
				}
			}
		}
	}
	return dist[k_max];
}

inline void add_edge(const int u,const int v,const int dist)
{
	edge[n_edge].v=v; edge[n_edge].dist=dist; edge[n_edge].next=head[u];
	head[u]=n_edge++;
}

int main()
{
	int n,u,v,dist;
	while (scanf("%d",&n)!=EOF)
	{
		memset(head,-1,sizeof head); n_edge=0;
		k_max=0;
		for (int i=0; i<n; i++)
		{
			scanf("%d%d%d",&u,&v,&dist);
			add_edge(u-1,v,dist);
			if (v>k_max) k_max=v;
		}
		for (int i=0; i<k_max; i++) add_edge(i,i+1,0),add_edge(i+1,i,-1);
		printf("%d\n",solve());
	}
	return 0;
}