//VOJ POJ 3169
#include <cstdio>
#include <cstring>

const int N=1000,M=10000;
struct Edge{
	int v,len,next;
} e[M+1];
int q[N],head[N],d[N+1],cnt[N],t;
bool vis[N];

void add_edge(int u,int v,int len) {
	e[++t]=Edge{v,len,head[u]};
	head[u]=t;
}

int main() {
	int n,ml,md,c,u,v,len,l,r;
	scanf("%d%d%d",&n,&ml,&md);
	for (int i=0;i<ml;i++) {
		scanf("%d%d%d",&u,&v,&len);
		add_edge(u-1,v-1,len);
	}
	for (int i=0;i<md;i++) {
		scanf("%d%d%d",&u,&v,&len);
		add_edge(v-1,u-1,-len);
	}
	memset(d,127,sizeof d); d[0]=0;
	l=0; r=1; q[0]=0;
	vis[0]=true;
	while (vis[q[l]]) {
		vis[q[l]]=false;
		for (int i=head[q[l]];i;i=e[i].next)
			if (d[q[l]]+e[i].len<d[e[i].v]) {
				d[e[i].v]=d[q[l]]+e[i].len;
				if (!vis[e[i].v]) {
					if (++cnt[e[i].v]>n) {
						puts("-1");
						return 0;
					}
					vis[e[i].v]=true;
					q[r]=e[i].v;
					r=(r+1)%N;
				}
			}
		l=(l+1)%N;
	}
	d[n-1]==d[n]?puts("-2"):printf("%d",d[n-1]);
	return 0;
}
