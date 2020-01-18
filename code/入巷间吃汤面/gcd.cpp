// AC
#include <algorithm>
#include <cstdio>

using std::swap;

const int N = 1000;
int a[N], f[N][N], n, op, ans;

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

inline int get_int()
{
	int x = 0, f = 1;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar())
		if (c == '-') f = -1;
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 1) + (x << 3) + (c ^ 48);
	return x * f;
}

void put_int(int x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9) put_int(x / 10);
	putchar(x % 10 ^ 48);
}

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int get(int k)
{
	return op ? (k + ans - 1) % n + 1 : k;
}

int main()
{
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
	int m;
	n = get_int();
	m = get_int();
	op = get_int();
	for (int i = 0; i < n; ++i)
	{
		a[i] = get_int();
		int tmp = f[i][i] = a[i];
		for (int j = i - 1; ~j; --j) f[j][i] = tmp = gcd(a[j], tmp);
	}
	for (int i = 0; i < m; ++i)
	{
		int l, r;
		l = get(get_int()) - 1;
		r = get(get_int()) - 1;
		if (r < l) swap(l, r);
		put_int(ans = f[l][r]);
		puts("");
	}
	return 0;
}