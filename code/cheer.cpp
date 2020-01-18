#include <cstdio>
#include <algorithm>

using std::sort;
using std::min;

const int N_NODE=10000,N_EDGE=100000;
struct Edge
{
	int u,v,len;
} edge[N_EDGE];
int a[N_NODE],fa[N_NODE];

bool cmp(Edge a,Edge b)
{
	return a.len<b.len;
}

int get_fa(int k)
{
	return fa[k]==k?k:fa[k]=get_fa(fa[k]);
}

int main()
{
	freopen("cheer.in","r",stdin); freopen("cheer.out","w",stdout);
	int n_node,n_edge,ans=2000000000;
	scanf("%d %d",&n_node,&n_edge);
	for (int i=0; i<n_node; i++) scanf("%d",&a[i]),ans=min(ans,a[i]);
	for (int i=0; i<n_edge; i++)
	{
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].len);
		edge[i].u--; edge[i].v--;
		edge[i].len=(edge[i].len<<1)+a[edge[i].u]+a[edge[i].v];
	}
	sort(edge,edge+n_edge,cmp);
	for (int i=0; i<n_node; i++) fa[i]=i;
	for (int i=0,n_edge_used=0; n_edge_used<n_node-1; i++)
	{
		int x=get_fa(edge[i].u),y=get_fa(edge[i].v);
		if (x!=y) fa[x]=y,n_edge_used++,ans+=edge[i].len;
	}
	printf("%d",ans);
	return 0;
}