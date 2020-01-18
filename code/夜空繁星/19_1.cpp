// AC
#include <bits/stdc++.h>

using namespace std;

const int N = 100, M = 500, dx[8] = {1, 1, 1, -1, -1, -1, 0, 0},
		  dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
char s[N][N], ans[M + 1], c = 'a';
int vis[N][N], qx[N * N], qy[N * N], t, cnt, n, m;
double ss[M + 1];

void dfs(int x, int y)
{
	qx[t] = x;
	qy[t++] = y;
	vis[x][y] = cnt;
	s[x][y] = '0';
	for (int i = 0; i < 8; ++i)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if (~tx && tx < n && ~ty && ty < m && s[tx][ty] == '1') dfs(tx, ty);
	}
}

int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i) scanf("%s", s[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '1')
			{
				t = 0;
				++cnt;
				dfs(i, j);
				for (int i = 0; i < t; ++i)
					for (int j = 0; j < t; ++j)
						ss[cnt] += sqrt((qx[i] - qx[j]) * (qx[i] - qx[j])
										+ (qy[i] - qy[j]) * (qy[i] - qy[j]));
			}
	for (int i = 1; i <= cnt; ++i)
		if (!ans[i])
		{
			ans[i] = c++;
			for (int j = i + 1; j <= cnt; ++j)
				if (fabs(ss[i] - ss[j]) < 0.000001) ans[j] = ans[i];
		}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			putchar(ans[vis[i][j]] ? ans[vis[i][j]] : '0');
		putchar('\n');
	}
	return 0;
}
