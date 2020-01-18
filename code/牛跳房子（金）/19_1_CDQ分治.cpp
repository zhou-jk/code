// AC
#include <cstdio>

const int N = 750, P = 1000000007;
int a[N][N], f[N][N], t[N * N], s[N * N], m, time;

void solve(int l, int r)
{
	if (l == r) return;
	int mid = (l + r) >> 1;
	solve(l, mid);
	++time;
	int sum = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = mid + 1; j <= r; ++j)
		{
			if (t[a[j][i]] < time) t[a[j][i]] = time, s[a[j][i]] = 0;
			f[j][i] = ((f[j][i] + sum - s[a[j][i]]) % P + P) % P;
		}
		for (int j = l; j <= mid; ++j)
		{
			if (t[a[j][i]] < time) t[a[j][i]] = time, s[a[j][i]] = 0;
			s[a[j][i]] = (s[a[j][i]] + f[j][i]) % P;
			sum = (sum + f[j][i]) % P;
		}
	}
	solve(mid + 1, r);
}

int main()
{
	int n, k;
	scanf("%d%d%d", &n, &m, &k);
	f[0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]), --a[i][j];
	solve(0, n - 1);
	printf("%d", f[n - 1][m - 1]);
	return 0;
}