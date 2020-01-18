//VOJ HDU 4738
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int N=1000;
struct Edge
{
	int v,w,next;
} edge[N*N<<1];
int head[N],n_edge,time_dfs[N],low[N],cnt,ans;

void add_edge(int u,int v,int w)
{
	edge[n_edge]=Edge{v,w,head[u]};
	head[u]=n_edge++;
}

void dfs(int k,int fa)
{
	time_dfs[k]=low[k]=++cnt;
	for (int i=head[k]; i>=0; i=edge[i].next)
		if (!time_dfs[edge[i].v])
		{
			dfs(edge[i].v,i);
			low[k]=min(low[k],low[edge[i].v]);
			if (low[edge[i].v]>time_dfs[k]) ans=min(ans,edge[i].w);
		}
		else if (i!=(fa^1)) low[k]=min(low[k],time_dfs[edge[i].v]);
}

int main()
{
	int n,m,u,v,w;
	bool flag;
	while (scanf("%d%d",&n,&m)!=EOF&&n)
	{
		n_edge=cnt=0;
		flag=false;
		memset(head,-1,sizeof head);
		for (int i=0; i<m; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			u--; v--;
			add_edge(u,v,w); add_edge(v,u,w);
		}
		memset(time_dfs,0,sizeof time_dfs);
		ans=1<<30;
		dfs(0,-1);
		for (int i=0; i<n; i++)
			if (!time_dfs[i])
			{
				puts("0");
				flag=true;
				break;
			}
		if (flag) continue;
		if (ans==1<<30)
		{
			puts("-1");
			continue;
		}
		if (!ans) ans++;
		printf("%d\n",ans);
	}
	return 0;
}