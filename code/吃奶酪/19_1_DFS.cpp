// AC
#include <cmath>
#include <cstdio>

const int N = 15 + 1;
double x[N] = {0}, y[N] = {0}, ans = 1e14;
int n;
bool vis[N];

void dfs(int k, int cnt, double s)
{
	if (s >= ans) return;
	if (cnt == n) ans = s;
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
		{
			vis[i] = true;
			dfs(i, cnt + 1,
				s
					+ sqrt((x[k] - x[i]) * (x[k] - x[i])
						   + (y[k] - y[i]) * (y[k] - y[i])));
			vis[i] = false;
		}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lf%lf", x + i, y + i);
	dfs(0, 0, 0);
	printf("%.2lf", ans);
	return 0;
}