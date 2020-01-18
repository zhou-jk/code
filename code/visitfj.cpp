#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int N=100;
struct Node
{
	int x,y;
	bool vis;
} g[N][N][12];
int a[N][N];
long long dist[N][N];
bool vis[N][N];

int main()
{
	//freopen("visitfj.in","r",stdin); freopen("visitfj.out","w",stdout);
	int n,t;
	scanf("%d%d",&n,&t);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j) scanf("%d",&a[i][j]);
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
		{
			if (i>2) g[i][j][0]= {i-3,j,true};
			if (j>2) g[i][j][1]= {i,j-3,true};
			if (i<n-3) g[i][j][2]= {i+3,j,true};
			if (i<n-3) g[i][j][3]= {i,j+3,true};
			if (i>1&&j>0) g[i][j][4]= {i-2,j-1,true};
			if (i>1&&j<n-1) g[i][j][5]= {i-2,j+1,true};
			if (i>0&&j>1) g[i][j][6]= {i-1,j-2,true};
			if (i<n-1&&j>1) g[i][j][7]= {i+1,j-2,true};
			if (i<n-2&&j>0) g[i][j][8]= {i+2,j-1,true};
			if (i<n-2&&j<n-1) g[i][j][9]= {i+2,j+1,true};
			if (i>0&&j<n-2) g[i][j][10]= {i-1,j+2,true};
			if (i<n-1&&j<n-2) g[i][j][11]= {i+1,j+2,true};
		}
	memset(dist,127,sizeof dist);
	dist[0][0]=0;
	for (int i=0; i<n*n; ++i)
	{
		int x=-1,y=-1;
		for (int j=0; j<n; ++j)
			for (int k=0; k<n; ++k)
				if (!vis[j][k]&&(x==-1||dist[j][k]<dist[x][y]))
					x=j,y=k;
		vis[x][y]=true;
		for (int j=0; j<12; ++j)
		{
			int tx=g[x][y][j].x,ty=g[x][y][j].y;
			if (g[x][y][j].vis&&dist[x][y]+t*3+a[tx][ty]<dist[tx][ty])
				dist[tx][ty]=dist[x][y]+t*3+a[tx][ty];
		}
	}
	long long ans=dist[n-1][n-1];
	ans=min(min(dist[n-2][n-1],dist[n-1][n-2])+t,
	        min(min(dist[n-3][n-1],dist[n-1][n-3]),dist[n-2][n-2])+t*2);
	printf("%lld",ans);
	return 0;
}