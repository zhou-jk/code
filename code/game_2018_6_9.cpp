#include <cstdio>
#include <algorithm>

using std::max;
using std::sort;

const int N = 200, M = 40000;
struct Node
{
	int x, y, t, val;
} node[N];
int cnt, s[N + 1][N], t[N + 1], f[M + 1], belong[N - 1];

bool cmp(Node a, Node b)
{
	return a.x < b.y || (a.x == b.x && a.y < b.y);
}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m, tmp1, tmp2, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d%d", &node[i].x, &node[i].y, &node[i].t, &node[i].val);
	sort(node, node + n, cmp);
	for (int i = 0; i < n; i++)
		if (!belong[i])
		{
			//printf("%d\n",i);
			cnt++;
			tmp1 = tmp2 = 0;
			for (int j = i; j < n; j++)
				if (node[j].x % node[i].x == 0 && node[j].y % node[i].y == 0 &&
					node[j].x / node[i].x == node[j].y / node[i].y)
				{
					belong[j] = cnt;
					//printf("%d %d\n",j,cnt);
					s[cnt][t[cnt]++] = j;
					node[j].t = tmp1 = tmp1 + node[j].t;
					node[j].val = tmp2 = tmp2 + node[j].val;
				}
		}
	//puts("&");
	for (int i = 1; i <= cnt; i++)
		for (int j = m; j > 0; j--)
			for (int k = 0; k < t[i]; k++)
				if (j >= node[s[i][k]].t)
					f[j] = max(f[j], f[j - node[s[i][k]].t] + node[s[i][k]].val); //,
	//printf("%d %d %d\n",j,f[j],f[j-node[s[i][k]].t]+node[s[i][k]].val);
	for (int i = 1; i <= m; i++)
		ans = max(ans, f[i]);
	printf("%d", ans);
	return 0;
}