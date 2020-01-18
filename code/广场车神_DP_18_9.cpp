#include <cstdio>
#include <algorithm>

using std::max;

const int N=2000;
int f[N+1][N+1],sum[N+1][N+1];

int main()
{
	freopen("racing.in","r",stdin); freopen("racing.out","w",stdout);
	int n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	f[1][1]=sum[1][1]=1;
	for (int i=2; i<=n; ++i)
	{
		f[i][1]=sum[i-1][1]-sum[max(i-1-l,0)][1];
		sum[i][1]=sum[i-1][1]+f[i][1];
	}
	for (int i=2; i<=m; ++i)
	{
		f[1][i]=sum[1][i-1]-sum[1][max(i-1-l,0)];
		sum[1][i]=sum[1][i-1]+f[1][i];
	}
	for (int i=2; i<=n; ++i)
		for (int j=2; j<=m; ++j)
		{
			f[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]
			        -sum[i-1][max(j-1-l,0)]-sum[max(i-1-l,0)][j-1]+sum[max(i-1-l,0)][max(j-1-l,0)];
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+f[i][j];
		}
	printf("%d",f[n][m]);
	return 0;
}