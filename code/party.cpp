#define N 3000
#define M 400000

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge{
	int u,v,len,next;
} edge[M+1];
int n,head[N],d[3][N+1],ans[N],cnt,tot;
bool vis[N],f[N];

void dijkstra(int s) {
	memset(vis,false,sizeof vis);
	for (int i=0;i<n;i++) {
		int k=-1;
		for (int j=0;j<n;j++)
			if (!vis[j]&&(k<0||d[s][j]<d[s][k])) k=j;
		vis[k]=true;
		int p=head[k];
		while (p) {
			d[s][edge[p].v]=min(d[s][edge[p].v],d[s][k]+edge[p].len);
			p=edge[p].next;
		}
	}
}

void add_edge(int u,int v,int len) {
	edge[++tot].next=head[u]; edge[tot].u=u; edge[tot].v=v; edge[tot].len=len;
	head[u]=tot;
}

int main() {
	int m,u,v,len;
	freopen("party.in","r",stdin); freopen("party.out","w",stdout);
	for (scanf("%d%d",&n,&m);m;m--) {
		scanf("%d%d%d",&u,&v,&len);
		u--; v--; 
		add_edge(u,v,len); add_edge(v,u,len);
	}
	memset(d,127,sizeof d);
	for (int i=0;i<3;i++) {
		d[i][i]=0;
		dijkstra(i);
		for (int j=0;j<n;j++)
			if (d[i][j]==d[i][n]) f[j]=true;
	}
	for (int i=1;i<=tot;i++) {
		int tmp=0;
		for (int j=0;j<3;j++) tmp+=d[j][edge[i].u]+edge[i].len==d[j][edge[i].v];
		if (tmp>1) f[edge[i].v]=true;
	}
	for (int i=0;i<n;i++)
		if (!f[i]) ans[cnt++]=i+1;
	if (!cnt) printf("impossible");
	else {
		printf("%d\n",cnt);
		for (int i=0;i<cnt;i++) printf("%d ",ans[i]);
	}
	return 0;
}
