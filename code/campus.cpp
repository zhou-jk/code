#define N 200 //E*2
#define LEN 106 //99+6+1

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int tot,q[20000],g[N][N];
char h[N][LEN];

int find(char *s) {
	for (int i=0;i<tot;i++)
		if (!strcmp(s,h[i])) return i;
	strcpy(h[tot++],s);
	return tot-1;
}

int main() {
	freopen("campus.in","r",stdin); freopen("campus.out","w",stdout);
	int c,e,d,l,r,dist[N+1];
	char s[LEN],t[LEN];
	bool v[N];
	for (scanf("%d",&c);c;c--) {
		tot=0; memset(dist,127,sizeof dist); memset(v,1,sizeof v); memset(g,127,sizeof g);
		for (scanf("%d",&e);e;e--) {
			scanf("%s%s%d",s,t,&d);
			int x=find(s),y=find(t);
			g[x][y]=g[y][x]=min(d,g[x][y]);
		}
		scanf("%s%s",s,t);
		int x=find(s),y=find(t);
		dist[x]=0; l=0; r=1; q[0]=x; v[x]=false;
		while (l<r) {
			for (int i=0;i<tot;i++)
				if (dist[q[l]]+g[q[l]][i]<dist[i]) {
			  		dist[i]=dist[q[l]]+g[q[l]][i];
			  		if (v[i]) {
			  			q[r++]=i; v[i]=false;
					}
			    }
			v[l++]=true;
		}
		if (dist[y]==dist[tot]) printf("-1\n");
		else printf("%d\n",dist[y]);
	} 
	return 0; 
}
