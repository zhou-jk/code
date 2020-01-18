// AC
#include <cctype>
#include <cstdio>

const int N = 1000;
int g[N][N];

inline char get_char()
{
	static const int SIZE = 2 << 16;
	static char buf[SIZE], *s, *t;
	if (s == t)
	{
		t = (s = buf) + fread(buf, 1, SIZE, stdin);
		if (s == t) return EOF;
	}
	return *s++;
}

#define getchar get_char

inline int get_int()
{
	char c;
	int ret = 0;
	for (c = getchar(); !isdigit(c); c = getchar())
		;
	for (; isdigit(c); c = getchar()) ret = (ret << 1) + (ret << 3) + (c ^ 48);
	return ret;
}

void put_int(int num)
{
	if (num > 9) put_int(num / 10);
	putchar((num % 10) ^ 48);
}

int main()
{
	int n = get_int();
	int m = get_int();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) g[i][j] = get_int();
	for (int i = 0; i < m; ++i)
	{
		for (int j = n - 1; ~j; --j) put_int(g[j][i]), putchar(' ');
		puts("");
	}
	return 0;
}