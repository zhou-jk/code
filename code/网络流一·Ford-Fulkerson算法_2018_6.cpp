//HihoCoder - 1369
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int N=500,M=20000,INF=0x3f3f3f3f;
struct Edge
{
	int v,cf,next;
} edge[M<<1];
int head[N],n_edge,s,t;
bool vis[N];

void add_edge(int u,int v,int cf)
{
	edge[n_edge]= {v,cf,head[u]};
	head[u]=n_edge++;
}

int dfs(int k,int flow)
{
	int cf,v,tmp;
	vis[k]=true;
	if (k==t) return flow;
	for (int i=head[k]; i!=-1; i=edge[i].next)
	{
		cf=edge[i].cf;
		if (cf)
		{
			v=edge[i].v;
			if (!vis[v]&&(tmp=dfs(v,min(cf,flow))))
			{
				edge[i].cf-=tmp; edge[i^1].cf+=tmp;
				return tmp;
			}
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
	while ((tmp=dfs(s,INF)))
	{
		ans+=tmp;
		memset(vis,false,sizeof vis);
	}
	printf("%d",ans);
	return 0;
}