// AC
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 110, M = 510, dx[8] = {1, 1, 1, -1, -1, -1, 0, 0},
		  dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
const ll key[5] = {998244353, 1004535809, 1000000007, 1000000009, 123468723167};
char s[N][N], ans[M], c = 'a';
ll ht[M][8][5];
int vis[N][N], k1[M], k2[M], k3[M], k4[M], cnt, n, m;

void dfs(int x, int y)
{
	k1[cnt] = min(k1[cnt], x);
	k2[cnt] = max(k2[cnt], x);
	k3[cnt] = min(k3[cnt], y);
	k4[cnt] = max(k4[cnt], y);
	vis[x][y] = cnt;
	s[x][y] = '0';
	for (int i = 0; i < 8; ++i)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if (~tx && tx < n && ~ty && ty < m && s[tx][ty] == '1') dfs(tx, ty);
	}
}

void hash1(int k)
{
	for (int i = k1[k]; i <= k2[k]; ++i)
		for (int j = k3[k]; j <= k4[k]; ++j)
			for (int p = 0; p < 5; ++p)
				ht[k][0][p] = ((ht[k][0][p] << 1) + (vis[i][j] == k)) % key[p];
}

void hash2(int k)
{
	for (int i = k2[k]; i >= k1[k]; --i)
		for (int j = k3[k]; j <= k4[k]; ++j)
			for (int p = 0; p < 5; ++p)
				ht[k][1][p] = ((ht[k][1][p] << 1) + (vis[i][j] == k)) % key[p];
}

void hash3(int k)
{
	for (int i = k1[k]; i <= k2[k]; ++i)
		for (int j = k4[k]; j >= k3[k]; --j)
			for (int p = 0; p < 5; ++p)
				ht[k][2][p] = ((ht[k][2][p] << 1) + (vis[i][j] == k)) % key[p];
}

void hash4(int k)
{
	for (int i = k2[k]; i >= k1[k]; --i)
		for (int j = k4[k]; j >= k3[k]; --j)
			for (int p = 0; p < 5; ++p)
				ht[k][3][p] = ((ht[k][3][p] << 1) + (vis[i][j] == k)) % key[p];
}

void hash5(int k)
{
	for (int j = k3[k]; j <= k4[k]; ++j)
		for (int i = k1[k]; i <= k2[k]; ++i)
			for (int p = 0; p < 5; ++p)
				ht[k][4][p] = ((ht[k][4][p] << 1) + (vis[i][j] == k)) % key[p];
}

void hash6(int k)
{
	for (int j = k3[k]; j <= k4[k]; ++j)
		for (int i = k2[k]; i >= k1[k]; --i)
			for (int p = 0; p < 5; ++p)
				ht[k][5][p] = ((ht[k][5][p] << 1) + (vis[i][j] == k)) % key[p];
}

void hash7(int k)
{
	for (int j = k4[k]; j >= k3[k]; --j)
		for (int i = k1[k]; i <= k2[k]; ++i)
			for (int p = 0; p < 5; ++p)
				ht[k][6][p] = ((ht[k][6][p] << 1) + (vis[i][j] == k)) % key[p];
}

void hash8(int k)
{
	for (int j = k4[k]; j >= k3[k]; --j)
		for (int i = k2[k]; i >= k1[k]; --i)
			for (int p = 0; p < 5; ++p)
				ht[k][7][p] = ((ht[k][7][p] << 1) + (vis[i][j] == k)) % key[p];
}

int main()
{
	freopen("star.in", "r", stdin);
	freopen("star.out", "w", stdout);
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i) scanf("%s", s[i]);
	memset(k1, 127, sizeof k1);
	memset(k3, 127, sizeof k3);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '1') ++cnt, dfs(i, j);
	for (int i = 1; i <= cnt; ++i)
	{
		hash1(i);
		hash2(i);
		hash3(i);
		hash4(i);
		hash5(i);
		hash6(i);
		hash7(i);
		hash8(i);
	}
	for (int i = 1; i <= cnt; ++i)
		if (!ans[i])
		{
			ans[i] = c++;
			for (int j = i + 1; j <= cnt; ++j)
				if (k2[j] - k1[j] == k2[i] - k1[i]
					|| k2[j] - k1[j] == k4[i] - k3[i]
					|| k4[j] - k3[j] == k2[i] - k1[i]
					|| k4[j] - k3[j] == k4[i] - k3[i])
					for (int k = 0; k < 8; ++k)
					{
						bool flag = true;
						for (int p = 0; p < 5; ++p)
							if (ht[i][0][p] != ht[j][k][p])
							{
								flag = false;
								break;
							}
						if (flag)
						{
							ans[j] = ans[i];
							break;
						}
					}
		}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			putchar(ans[vis[i][j]] ? ans[vis[i][j]] : '0');
		putchar('\n');
	}
	return 0;
}
