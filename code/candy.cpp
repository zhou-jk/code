#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;

const int N=100,M=200;
int a[N],g[N][N],l[N][N-1],f[N][M+1],ans;
bool vis[N];

void add_edge(int u,int v,int len)
{
	g[u][++g[u][0]]=v; l[u][g[u][0]-1]=len;
}

void dp(int k,int m,int fa)
{
	//printf("%d %d\n",k,m);
	for (int i=1; i<=g[k][0]; i++)
		if (g[k][i]!=fa)
		{
			dp(g[k][i],m-(l[k][i-1]<<1),k);
			for (int j=m; j>=0; j--)
				for (int k1=0; k1<=j-(l[k][i-1]<<1); k1++)
					f[k][j]=max(f[k][j],f[k][j-(l[k][i-1]<<1)-k1]+f[g[k][i]][k1]);
		}
	for (int i=0; i<=m; i++) f[k][i]+=a[k];
}

int main()
{
	freopen("candy.in","r",stdin); freopen("candy.out","w",stdout);
	int n,m,k,u,v,len;
	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%d",&a[i]);
	for (int i=1; i<n; i++)
	{
		scanf("%d%d%d",&u,&v,&len);
		u--; v--;
		add_edge(u,v,len); add_edge(v,u,len);
	}
	//puts("*");
	scanf("%d%d",&k,&m);
	k--;
	dp(k,m,-1);
	printf("%d",f[k][m]);
	return 0;
}