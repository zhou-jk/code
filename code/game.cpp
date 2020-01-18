#define N 10001
#define M 200000

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge{
	int p,next;
	long long len;
} edge[M+1];
int q[N],head[N],f[N],tot;
long long d[N+1];
bool vis[N];

void add_edge(int u,int v,long long len) {
	edge[++tot].next=head[u]; edge[tot].p=v; edge[tot].len=len;
	head[u]=tot;
}

void spfa(int s) {
	int l,r;
	d[s]=0;
	l=0; r=1; q[0]=s;
	memset(vis,false,sizeof vis); vis[s]=true;
	while (vis[q[l]]) {
		int p1=q[l],p2=head[q[l]];
		vis[p1]=false;
		f[p1]=s;
		while (p2) {
			int tmp=edge[p2].p;
			if (d[p1]+edge[p2].len<d[tmp]) {
			  	d[tmp]=d[p1]+edge[p2].len;
			  	if (!vis[tmp]) {
			  		if (l==r-1||d[tmp]>d[q[(l+1)%N]]) {
			  			q[r]=tmp;
			  			r=(r+1)%N;
					}
					else {
						q[l]=tmp;
						l=(l-1+N)%N;
					}
					vis[tmp]=true;
				}
			}
			p2=edge[p2].next;
		}
		l=(l+1)%N;
	}
}

int main() {
	int n,m,u,v,q;
	long long len; 
	freopen("game.in","r",stdin); freopen("game.out","w",stdout);
	for (scanf("%d%d",&n,&m);m;m--) {
		scanf("%d%d%lld",&u,&v,&len);
		u--;
		add_edge(u,v,len); add_edge(v,u,-len);
	}
	memset(f,-1,sizeof f); memset(d,127,sizeof d);
	for (int i=0;i<=n;i++)
		if (f[i]<0) spfa(i);
	for (scanf("%d",&q);q;q--) {
		scanf("%d%d",&u,&v);
		u--;
		if (f[u]==f[v]) printf("%lld\n",d[v]-d[u]);
		else printf("Too Hard\n");
	}
	return 0; 
}
