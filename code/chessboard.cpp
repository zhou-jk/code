#include <cstdio>

const int N=500,M=4,dx[M]={-1,1,0,0},dy[M]={0,0,-1,1};
int map[N][N],vis[N][N],h1[N],h2[N],t1,t2,n,cnt,ans1,ans2;

void hash1(int u) {
	for (int i=0;i<t1;i++)
		if (h1[i]==u) return;
	h1[t1++]=u;
}

void hash2(int u) {
	for (int i=0;i<t2;i++)
		if (h2[i]==u) return;
	h2[t2++]=u;
}

void dfs(int f,int x,int y) {
	vis[x][y]=f;
	for (int i=0;i<M;i++) {
		int tx=x+dx[i],ty=y+dy[i];
		if (tx>=0&&tx<n&&ty>=0&&ty<n&&map[tx][ty]==map[x][y]&&vis[tx][ty]<vis[x][y]) dfs(f,tx,ty);
	}
}

int main() {
	freopen("chessboard.in","r",stdin); freopen("chessboard.out","w",stdout);
	int x,y,m;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) scanf("%d",&map[i][j]);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (!vis[i][j]) {
				map[i][j]?ans1++:ans2++;
				dfs(++cnt,i,j);
			}
	//printf("%d %d\n",ans1,ans2);
	for (scanf("%d",&m);m;m--) {
		int tmp=cnt;
		scanf("%d%d",&x,&y);
		x--; y--;
		t1=t2=0;
		for (int i=0;i<M;i++) {
			int tx=x+dx[i],ty=y+dy[i];
			map[tx][ty]?hash1(vis[tx][ty]):hash2(vis[tx][ty]);
		}
		ans1-=t1; ans2-=t2;
		map[x][y]=!map[x][y];
		for (int i=0;i<M;i++) {
			int tx=x+dx[i],ty=y+dy[i];
			if (vis[tx][ty]<=tmp) dfs(++cnt,tx,ty),map[tx][ty]?ans1++:ans2++;
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}