//VOJ POJ 1144  POJ ZOJ 1311
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int N=100;
struct Edge
{
	int v,next;
} edge[N*N];
int head[N],n_edge,time_dfs[N],low[N],ans,cnt;
bool is_cut[N];

void add_edge(int u,int v)
{
	edge[n_edge]=Edge{v,head[u]};
	head[u]=n_edge++;
}

void dfs(int k)
{
	int n_son=0;
	time_dfs[k]=low[k]=++cnt;
	for (int i=head[k]; i>=0; i=edge[i].next)
		if (!time_dfs[edge[i].v])
		{
			n_son++;
			dfs(edge[i].v);
			low[k]=min(low[k],low[edge[i].v]);
			if ((!k&&n_son>1)||(k&&low[edge[i].v]>=time_dfs[k])) is_cut[k]=true;
		}
		else low[k]=min(low[k],time_dfs[edge[i].v]);
}

int main()
{
	int n,u,v;
	while (scanf("%d",&n)!=EOF&&n)
	{
		n_edge=0;
		memset(head,-1,sizeof head);
		while (scanf("%d",&u)!=EOF&&u--)
			while (getchar()!='\n')
			{
				scanf("%d",&v);
				v--;
				add_edge(u,v); add_edge(v,u);
			}
		memset(time_dfs,0,sizeof time_dfs);
		memset(is_cut,false,sizeof is_cut);
		ans=cnt=0;
		dfs(0);
		for (int i=0; i<n; i++) ans+=is_cut[i];
		printf("%d\n",ans);
	}
	return 0;
}