#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=100,M=20;
int g[M][M],dist[M],n,m;
bool flag[N][M],vis[M],bo[M];
long long cost[N][N],f[N];

int short_path(int a,int b) {
	memset(vis,true,sizeof vis);
	for (int i=a;i<=b;i++)
		for (int j=0;j<m;j++)
			if (flag[i][j]) vis[j]=false;
	memset(dist,127,sizeof dist); dist[0]=0;
	for (int i=0;i<m;i++) {
		int k=-1;
		for (int j=0;j<m;j++)
			if (vis[j]&&(k<0||dist[j]<dist[k])) k=j;
		vis[k]=false;
		for (int j=0;j<m;j++) dist[j]=min(dist[j],dist[k]+g[k][j]);
	}
	return dist[m-1];
}

int main() {
	freopen("trans.in","r",stdin); freopen("trans.out","w",stdout);
	int k,e,x,y,len,d,p,a,b;
	scanf("%d%d%d",&n,&m,&k);
	memset(g,63,sizeof g);
	for (scanf("%d",&e);e;e--) {
		scanf("%d%d%d",&x,&y,&len);
		x--; y--;
		if (len<g[x][y]) g[x][y]=g[y][x]=len;
	}
	for (scanf("%d",&d);d;d--) {
		scanf("%d%d%d",&p,&a,&b);
		p--;
		for (int i=a-1;i<b;i++) flag[i][p]=true;
	}
	for (int i=0;i<n;i++)
		for (int j=i;j<n;j++) cost[i][j]=short_path(i,j);
	for (int i=0;i<n;i++) {
		f[i]=cost[0][i]*(i+1);
		for (int j=0;j<i;j++) f[i]=min(f[i],f[j]+k+cost[j+1][i]*(i-j));
	}
	printf("%lld",f[n-1]);
	return 0;
}
