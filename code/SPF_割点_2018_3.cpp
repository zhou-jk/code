//VOJ POJ 1523
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;
using std::max;

const int N=1000;
struct Edge
{
	int v,next;
} edge[N*N];
int head[N],n_edge,time_dfs[N],low[N],cnt,cut[N],n;

void add_edge(int u,int v)
{
	edge[n_edge]=Edge{v,head[u]};
	head[u]=n_edge++;
}

void input_edge(int u)
{
	int v;
	n=max(n,u);
	scanf("%d",&v);
	n=max(n,v);
	u--; v--;
	add_edge(u,v); add_edge(v,u);
}

void dfs(int k)
{
	int n_son=0,n_son_cut=0;
	time_dfs[k]=low[k]=++cnt;
	for (int i=head[k]; i>=0; i=edge[i].next)
		if (!time_dfs[edge[i].v])
		{
			n_son++;
			dfs(edge[i].v);
			low[k]=min(low[k],low[edge[i].v]);
			if ((!k&&n_son>1)||(k&&low[edge[i].v]>=time_dfs[k]))
			{
				n_son_cut++;
				if (!k) cut[k]=n_son;
				else cut[k]=n_son_cut+1;
			}
		}
		else low[k]=min(low[k],time_dfs[edge[i].v]);
}

int main()
{
	int u,t=0;
	bool flag;
	while (scanf("%d",&u)!=EOF&&u)
	{
		n=n_edge=0;
		memset(head,-1,sizeof head);
		input_edge(u);
		while (scanf("%d",&u)!=EOF&&u) input_edge(u);
		memset(time_dfs,0,sizeof time_dfs);
		memset(cut,0,sizeof cut);
		cnt=0;
		dfs(0);
		printf("Network #%d\n",++t);
		flag=true;
		for (int i=0; i<n; i++)
			if (cut[i])
			{
				printf("  SPF node %d leaves %d subnets\n",i+1,cut[i]);
				flag=false;
			}
		if (flag) puts("  No SPF nodes");
		printf("\n");
	}
	return 0;
}