//POJ-2186
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int N=10000,M=50000;
struct Edge
{
	int v,next;
} edge[M];
int head[N],low[N],dfn[N],d[N+1],belong[N],sz[N+1],s[N],t,n_edge,n_scc,cnt;

void add_edge(int u,int v)
{
	edge[n_edge].v=v; edge[n_edge].next=head[u];
	head[u]=n_edge++;
}

void dfs(int k)
{
	low[k]=dfn[k]=++cnt;
	s[t++]=k;
	for (int i=head[k]; i!=-1; i=edge[i].next)
	{
		int v=edge[i].v;
		if (!dfn[v])
		{
			dfs(v);
			low[k]=min(low[k],low[v]);
		}
		else if (!belong[v]) low[k]=min(low[k],dfn[v]);
	}
	if (low[k]==dfn[k])
	{
		n_scc++;
		//puts("^");
		for (;;)
		{
			int tmp=s[--t];
			belong[tmp]=n_scc;
			sz[n_scc]++;
			//printf("%d\n",n_scc);
			if (tmp==k) break;
		}
	}
}

int main()
{
	int n,m,u,v,tmp1,tmp2=0;
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof head);
	for (int i=0; i<m; i++)
	{
		scanf("%d%d",&u,&v);
		u--; v--;
		add_edge(u,v);
	}
	for (int i=0; i<n; i++)
		if (!dfn[i]) dfs(i);
	for (int i=0; i<n; i++)
		for (int j=head[i]; j!=-1; j=edge[j].next)
		{
			int x=belong[i],y=belong[edge[j].v];
			if (x!=y) d[x]++;
		}
	for (int i=1; i<=n_scc; i++)
		if (!d[i]) tmp1=i,tmp2++;
	//printf("%d",tmp2);
	if (tmp2==1) printf("%d",sz[tmp1]);
	else puts("0");
	return 0;
}