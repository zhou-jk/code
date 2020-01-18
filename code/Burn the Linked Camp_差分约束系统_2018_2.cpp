//VOJ ZOJ 2770
#define N 1001

#include <cstdio>
#include <cstring>

int g[N][N],q[N],d[N],cnt[N];
bool vis[N],b;

int main() {
	int n,m,u,v,len,l,r,t;
	while (~scanf("%d%d",&n,&m)) {
		n++;
		memset(g,128,sizeof g); memset(d,0,sizeof d); b=false;
		//printf("%d\n",g[0][0]);
		for (int i=1;i<n;i++) {
			scanf("%d",&g[i][i-1]);
			g[i][i-1]=-g[i][i-1];
			//printf("%d\n",g[i][i-1]);
		}
		for (;m;m--) {
			scanf("%d%d%d",&u,&v,&len);
			g[u-1][v]=len;
			//printf("%d %d %d\n",u-1,v,len);
		}
		for (int i=0;i<n;i++) {
			q[i]=i;
			vis[i]=true;
			cnt[i]=1;
		}
		l=t=0; r=n%N; 
		while (vis[t]) {
			vis[t]=false;
			//printf("%d\n",t);
			for (int i=0;i<n;i++)
				if (d[t]+g[t][i]>d[i]) {
					//printf("%d %d %d %d %d\n",t,i,d[t]+g[t][i],d[i],vis[i]);
					d[i]=d[t]+g[t][i];
					if (!vis[i]) {
						if (++cnt[i]>n) {
							puts("Bad Estimations");
							b=true;
							break;
						}
						//printf("$%d %d %d\n",i,l,r);
						vis[i]=true;
						q[r]=i;
						r=(r+1)%N;
					}
				}
			if (b) break; 
			l=(l+1)%N;
			t=q[l];
		}
		if (b) continue;
		printf("%d\n",d[n-1]);
	}
	return 0;
}
