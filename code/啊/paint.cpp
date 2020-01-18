#include <algorithm>
#include <cstdio>

using std::swap;

const int N = 1000000;
int fa[N + 1], c[N];

#define dd c = getchar()
int read()
{
	int s = 0, w = 1;
	char c;
	while (dd, c > '9' || c < '0')
		if (c == '-') w = -1;
	while (c >= '0' && c <= '9') s = s * 10 + c - '0', dd;
	return s * w;
}
#undef dd
void write(int x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x >= 10) write(x / 10);
	putchar(x % 10 | '0');
}
void wln(int x)
{
	write(x);
	putchar('\n');
}

int getFa(int k)
{
	int rt = k;
	while (rt != fa[rt]) rt = fa[rt];
	while (k != fa[k])
	{
		int tmp = k;
		k = fa[k];
		fa[tmp] = rt;
	}
	return rt;
}

int main()
{
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	int n = read(), m = read(), p = read(), q = read();
	for (int i = 0; i <= n; ++i) fa[i] = i;
	for (int i = m; i; --i)
	{
		int x = (i * p + q) % n, y = (i * q + p) % n;
		if (x > y) swap(x, y);
		for (int j = x; j <= y;)
		{
			int f = getFa(j);
			if (j == f)
			{
				c[j] = i;
				fa[j] = j + 1;
			}
			j = f;
		}
	}
	for (int i = 0; i < n; ++i) wln(c[i]);
	return 0;
}