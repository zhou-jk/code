#include <cstdio>
#include <cstring>

const int N_NODE=10000,N_EDGE=50000;
struct Edge
{
	int v,next;
} edge1[N_EDGE],edge2[N_EDGE];
int n_edge1,n_edge2,head1[N_NODE],head2[N_NODE],s[N_NODE],belong[N_NODE],
    sz[N_NODE],n_outdegree[N_NODE],n_vis,n_scc;
bool vis[N_NODE];

inline void add_edge1(const int u,const int v)
{
	edge1[n_edge1].v=v; edge1[n_edge1].next=head1[u];
	head1[u]=n_edge1++;
}

inline void add_edge2(const int u,const int v)
{
	edge2[n_edge2].v=v; edge2[n_edge2].next=head2[u];
	head2[u]=n_edge2++;
}

void dfs1(const int k)
{
	vis[k]=true;
	for (int i=head1[k]; i!=-1; i=edge1[i].next)
		if (!vis[edge1[i].v]) dfs1(edge1[i].v);
	s[n_vis++]=k;
}

void dfs2(const int k)
{
	belong[k]=n_scc; sz[n_scc]++;
	for (int i=head2[k]; i!=-1; i=edge2[i].next)
		if (belong[edge2[i].v]==-1) dfs2(edge2[i].v);
}


int main()
{
	freopen("popular.in","r",stdin); freopen("popular.out","w",stdout);
	int n_node,n_edge,u,v,k_ans=-1;
	scanf("%d%d",&n_node,&n_edge);
	memset(head1,-1,sizeof head1); memset(head2,-1,sizeof head2);
	for (int i=0; i<n_edge; i++)
	{
		scanf("%d%d",&u,&v);
		u--; v--;
		add_edge1(u,v); add_edge2(v,u);
	}
	for (int i=0; i<n_node; i++)
		if (!vis[i]) dfs1(i);
	//puts("^");
	memset(belong,-1,sizeof belong);
	for (int i=n_node-1; i>=0; i--)
		if (belong[s[i]]==-1) dfs2(s[i]),n_scc++;
	for (int i=0; i<n_node; i++)
		for (int j=head1[i]; j!=-1; j=edge1[j].next)
			if (belong[i]!=belong[edge1[j].v]) n_outdegree[belong[i]]++;
	for (int i=0; i<n_scc; i++)
		if (!n_outdegree[i])
		{
			if (k_ans!=-1)
			{
				puts("0");
				return 0;
			}
			k_ans=i;
		}
	if (k_ans!=-1) printf("%d",sz[k_ans]);
	else puts("0");
	return 0;
}