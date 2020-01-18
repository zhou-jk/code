#include <cstdio>

const int N=10;
int g[N][N],n,t,ans;

void dfs(int k,int s)
{
	if (s==t&&k==n-1)
	{
		++ans;
		return;
	}
	if (s>=t) return;
	for (int i=0; i<n; ++i)
		if (g[k][i]) dfs(i,s+g[k][i]);
}

int main()
{
	freopen("road.in","r",stdin); freopen("road.out","w",stdout);
	scanf("%d%d\n",&n,&t);
	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<n; ++j)
		{
			char tmp=getchar();
			g[i][j]=tmp^48;
		}
		getchar();
	}
	dfs(0,0);
	printf("%d",ans%2009);
	return 0;
}