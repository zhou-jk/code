// AC
#include <algorithm>
#include <cstdio>

using std::max;

typedef long long ll;

const int N = 1000;
ll a[N + 1][N + 1], b[N + 1][N + 1], f[N + 1][N + 1];

inline char get_char()
{
	static const int SIZE = 1 << 16;
	static char buffer[SIZE], *s, *t;
	if (s == t)
	{
		t = (s = buffer) + fread(buffer, sizeof buffer[0], SIZE, stdin);
		if (s == t) return EOF;
	}
	return *s++;
}

#define getchar get_char

inline ll get_ll()
{
	ll x = 0, f = 1;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar())
		if (c == '-') f = -1;
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 1) + (x << 3) + (c ^ 48);
	return x * f;
}

void put_ll(ll x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9) put_ll(x / 10);
	putchar(x % 10 ^ 48);
}

int main()
{
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int n = get_ll(), m = get_ll();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) a[i][j] = get_ll();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) b[i][j] = get_ll();
	for (int i = n - 1; ~i; --i)
		for (int j = m - 1; ~j; --j)
		{
			a[i][j] += a[i + 1][j];
			b[i][j] += b[i][j + 1];
			f[i][j] = max(f[i][j + 1] + a[i][j], f[i + 1][j] + b[i][j]);
		}
	put_ll(f[0][0]);
	return 0;
}