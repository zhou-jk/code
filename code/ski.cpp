#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;

const int N=500,dx[4]= {-1,1,0,0},dy[4]= {0,0,-1,1};
int a[N][N],vis[N][N],ind[N*N],outd[N*N],n,m,cnt;

void dfs(int x,int y,int k)
{
	vis[x][y]=k;
	for (int i=0; i<4; ++i)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if (tx>=0&&ty>=0&&tx<n&&ty<m&&!(~vis[tx][ty])&&a[tx][ty]==a[x][y]) dfs(tx,ty,k);
	}
}

int main()
{
	freopen("ski.in","r",stdin); freopen("ski.out","w",stdout);
	int ans_ind=0,ans_outd=0;
	scanf("%d%d",&m,&n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			scanf("%d",&a[i][j]);
	memset(vis,-1,sizeof vis);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (!(~vis[i][j])) dfs(i,j,cnt++);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			for (int k=0; k<4; ++k)
			{
				int tx=i+dx[k],ty=j+dy[k];
				if (tx>=0&&ty>=0&&tx<n&&ty<m&&a[tx][ty]!=a[i][j])
				{
					if (a[tx][ty]<a[i][j]) outd[vis[i][j]]=true;
					else ind[vis[i][j]]=true;
				}
			}
	for (int i=0; i<cnt; ++i)
	{
		if (!ind[i]) ++ans_ind;
		if (!outd[i]) ++ans_outd;
	}
	if (cnt==1) puts("0");
	else printf("%d",max(ans_ind,ans_outd));
	return 0;
}