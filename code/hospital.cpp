#define N 100 

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int g[N][N];

void add(int x,int y,int l) {
	if (x>=0&&y>=0) {
		g[x][y]=g[y][x]=l;
	}
}

int main() {
	int n,m[N],x,y,ans=100000000;
	freopen("hospital.in","r",stdin); freopen("hospital.out","w",stdout);
	memset(g,63,sizeof g);
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d%d",&m[i],&x,&y);
		add(i,x-1,1); add(i,y-1,1);
		g[i][i]=0;
	}
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for (int i=0;i<n;i++) {
		int sum=0;
		for (int j=0;j<n;j++) sum+=m[j]*g[i][j];
		ans=min(ans,sum);
	}
	printf("%d",ans);
	return 0;
}
