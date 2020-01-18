//Virtual Judge 2018年寒假网赛第三场 C
#define N 100
#define M 100

#include <cstdio>

const int dx[8]={-1,1,0,0,-1,-1,1,1},dy[8]={0,0,-1,1,-1,1,-1,1};
int m,n;
char matrix[N][M+1];

void dfs(int x,int y) {
	matrix[x][y]='*';
	for (int i=0;i<8;i++) {
		int tx=x+dx[i],ty=y+dy[i];
		if (tx>=0&&tx<n&&ty>=0&&ty<=m&&matrix[tx][ty]=='@') dfs(tx,ty);
	}
}

int main() {
	while (~scanf("%d%d",&n,&m)&&m>0) {
		int ans=0;
		for (int i=0;i<n;i++) scanf("%s",matrix[i]);
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				if (matrix[i][j]=='@') {
					ans++;
					dfs(i,j);
				}
		printf("%d\n",ans);
	}
	return 0;
}
