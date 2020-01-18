// AC
#include <cstdio>

typedef long long LL;

const int MAX = 20;
int f[MAX + 1][MAX + 1][MAX + 1];
bool vis[MAX + 1][MAX + 1][MAX + 1];

int dfs(LL a, LL b, LL c)
{
	if (a > 0 && a <= MAX && b > 0 && b <= MAX && c > 0 && c <= MAX
		&& vis[a][b][c])
		return f[a][b][c];
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > MAX || b > MAX || c > MAX) return dfs(20, 20, 20);
	vis[a][b][c] = true;
	if (a < b && b < c)
		return f[a][b][c] =
				   dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
	return f[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c)
						+ dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
}

int main()
{
	LL a, b, c;
	while (scanf("%lld%lld%lld", &a, &b, &c) != EOF && (~a || ~b || ~c))
		printf("w(%lld, %lld, %lld) = %d\n", a, b, c, dfs(a, b, c));
	return 0;
}