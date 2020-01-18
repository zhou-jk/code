#include <stdio.h>

int m,n,dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1},a;
char g[100][101];

void dfs(int x,int y) {
	g[x][y]='.';
	for (int i=0;i<8;i++) {
		int tx=x+dx[i],ty=y+dy[i];
		if (tx>=0&&tx<n&&ty>=0&&ty<m&&g[tx][ty]=='W') dfs(tx,ty);
	}
}

int main() {
	freopen("lkcount.in","r",stdin); freopen("lkcount.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++) scanf("%s",g[i]);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (g[i][j]=='W') {
				a++;
				dfs(i,j);
			}
	printf("%d",a);
	return 0;
}
