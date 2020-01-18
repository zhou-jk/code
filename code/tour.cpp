#define N 2000

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int g[N][N], d[N + 1], ans;
bool v[N];

int main()
{
	int n, m, s, t, a, b, c;
	freopen("tour.in", "r", stdin);
	freopen("tour.out", "w", stdout);
	memset(g, 127, sizeof g);
	memset(d, 127, sizeof d);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		g[a][b] = g[b][a] = min(c, g[a][b]);
	}
	scanf("%d%d", &s, &t);
	s--;
	t--;
	d[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int k = -1;
		for (int j = 0; j < n; j++)
			if (!v[j] && d[j] < d[n] && (k < 0 || d[j] < d[k]))
				k = j;
		if (k < 0)
		{
			printf("-1");
			return 0;
		}
		v[k] = true;
		for (int j = 0; j < n; j++)
			d[j] = min(d[j], d[k] + g[k][j]);
	}
	printf("%d", d[t]);
	return 0;
}
