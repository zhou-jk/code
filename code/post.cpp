#define N 10000
#define M 100000

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge{
	int len,p,next;
} edge1[M+1],edge2[M+1];
int head1[N],head2[N],d1[N],d2[N],tot1,tot2,ans;
bool vis[N];

void add_edge(Edge *edge,int *head,int &tot,int u,int v,int len) {
	edge[++tot].next=head[u]; edge[tot].p=v; edge[tot].len=len;
	head[u]=tot;
}

void dijkstra(Edge *edge,int *head,int *d,int size_d,int n) {
	memset(vis,false,sizeof vis);
	memset(d,127,size_d); d[0]=0;
	for (int i=0;i<n;i++) {
		int k=-1;
		for (int j=0;j<n;j++)
			if (!vis[j]&&(k<0||d[j]<d[k])) k=j;
		vis[k]=true;
		int p=head[k];
		while (p) {
			d[edge[p].p]=min(d[edge[p].p],d[k]+edge[p].len);
			p=edge[p].next;
		}
	}
}

int main() {
	int n,m,u,v,len;
	freopen("post.in","r",stdin); freopen("post.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		scanf("%d%d%d",&u,&v,&len);
		u--; v--;
		add_edge(edge1,head1,tot1,u,v,len); add_edge(edge2,head2,tot2,v,u,len);
	}
	dijkstra(edge1,head1,d1,sizeof d1,n); dijkstra(edge2,head2,d2,sizeof d2,n);
	for (int i=1;i<n;i++) ans+=d1[i]+d2[i];
	printf("%d",ans);
	return 0;
}
