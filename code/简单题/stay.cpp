#include <cstdio>

const int N = 4, N_DIR = 4, M = 65536;
int q[M], ans[M];
bool vis[M];
char nu[4];

int read()
{
	int ret = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j) ret = (ret << 1) + (getchar() ^ 48);
		gets(nu);
	}
	return ret;
}

int up(int a, int k)
{
	if (k >= N * (N - 1)) return a;
	a -= a & (1 << k);
	a |= 1 << (k + N);
	return a;
}

int right(int a, int k)
{
	if (!(k % N)) return a;
	a -= a & (1 << k);
	a |= 1 << (k - 1);
	return a;
}

int down(int a, int k)
{
	if (k < N) return a;
	a -= a & (1 << k);
	a |= 1 << (k - N);
	return a;
}

int left(int a, int k)
{
	if (!((k + 1) % N)) return a;
	a -= a & (1 << k);
	a |= 1 << (k + 1);
	return a;
}

int change(int a, int k, int s)
{
	switch (s)
	{
		case 0: return up(a, k);
		case 1: return right(a, k);
		case 2: return down(a, k);
		case 3: return left(a, k);
		default: return a;
	}
}

int main()
{
	freopen("stay.in", "r", stdin);
	freopen("stay.out", "w", stdout);
	int a = 0, b = 0, l, r = 0;
	a = read();
	gets(nu);
	b = read();
	q[r++] = a;
	vis[a] = true;
	for (l = 0; l < r; ++l)
		for (int i = 0; i < N * N; ++i)
			if (q[l] & (1 << i))
				for (int j = 0; j < N_DIR; ++j)
				{
					int tmp = change(q[l], i, j);
					if (!vis[tmp])
					{
						vis[tmp] = true;
						q[r++] = tmp;
						ans[tmp] = ans[q[l]] + 1;
					}
				}
	printf("%d", ans[b]);
	return 0;
}