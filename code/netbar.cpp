#define N 10000
#define M 100000

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Edge{
	int len,p,next;
} edge[M+1];
int q[N],head[N],d[N+1],tot;
bool vis[N];

void add_edge(int u,int v,int len) {
	edge[++tot].next=head[u]; edge[tot].p=v; edge[tot].len=len;
	head[u]=tot;
}

int main() {
	freopen("netbar.in","r",stdin); freopen("netbar.out","w",stdout);
	int n,m,u,v,len,s,t,l,r;
	memset(d,127,sizeof d);
	for (scanf("%d%d",&n,&m);m;m--) {
		scanf("%d%d%d",&u,&v,&len);
		u--; v--;
		add_edge(u,v,len);
	}
	scanf("%d%d",&s,&t);
	s--;  t--;
	d[s]=0;
	l=0; r=1; q[0]=s;
	vis[s]=true;
	while (vis[q[l]]) {
		int p=head[q[l]];
		vis[q[l]]=false;
		while (p) {
			int tmp=edge[p].p;
			if (d[q[l]]+edge[p].len<d[tmp]) {
			  	d[tmp]=d[q[l]]+edge[p].len;
			  	if (!vis[tmp]) {
			  		q[r]=tmp;
			  		r=(r+1)%N;
					vis[tmp]=true;
				}
			}
			p=edge[p].next;
		}
		l=(l+1)%N;
	}
	if (d[t]==d[n]) printf("No Solution!\n");
	else printf("%d\n",d[t]);
	return 0; 
}
