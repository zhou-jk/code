// AC 错解
#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

const int N = 100;
int c[N], a[N][N], f[N][N];

void AddEdge(int u, int v, int dis)
{
	if (!a[c[v]][c[u]] && c[u] != c[v]) f[u][v] = min(f[u][v], dis);
}

int main()
{
	int n, k, m, s, t;
	scanf("%d%d%d%d%d", &n, &k, &m, &s, &t);
	--s;
	--t;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", c + i);
		--c[i];
	}
	if (c[s] == c[t])
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < k; ++j) scanf("%d", &a[i][j]);
	memset(f, 63, sizeof f);
	for (int i = 0; i < n; ++i) f[i][i] = 0;
	while (m--)
	{
		int u, v, dis;
		scanf("%d%d%d", &u, &v, &dis);
		--u;
		--v;
		AddEdge(u, v, dis);
		AddEdge(v, u, dis);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i != j)
				for (int k = 0; k < n; ++k)
					if (j != k && i != k)
						f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	printf("%d", f[s][t] > 100000000 ? -1 : f[s][t]);
}