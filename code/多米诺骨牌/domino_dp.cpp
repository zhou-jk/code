// AC
#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
int f[N][2][2], e[2];

void solve(int k, int a, int b, int s)
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			f[k][i][j] = min(f[k][i][j], f[k - 1][i ^ a][j ^ b] + s);
}

int main()
{
	freopen("domino.in", "r", stdin);
	freopen("domino.out", "w", stdout);
	int n;
	scanf("%d", &n);
	memset(e, 127, sizeof e);
	memset(f, 127, sizeof f);
	f[0][0][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		solve(i, a & 1, b & 1, 0);
		solve(i, b & 1, a & 1, 1);
	}
	printf("%d", f[n][0][0] == e[0] ? -1 : f[n][0][0]);
	return 0;
}
