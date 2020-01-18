// AC 摩尔投票法
#include <cstdio>

inline char get_char()
{
	static const int SIZE = 2 << 16;
	static char buffer[SIZE], *S, *T;
	if (S == T)
	{
		T = (S = buffer) + fread(buffer, 1, SIZE, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}

#define getchar get_char

inline int get_int()
{
	char c;
	int ret = 0;
	for (c = getchar(); c < '0' || c > '9'; c = getchar())
		;
	for (; c >= '0' && c <= '9'; c = getchar())
		ret = (ret << 1) + (ret << 3) + (c - '0');
	return ret;
}

int main()
{
	freopen("excellent.in", "r", stdin);
	freopen("excellent.out", "w", stdout);
	int n = get_int(), a = 0, k = 0;
	for (int i = 0; i < n; ++i)
	{
		int tmp = get_int();
		a = tmp == k ? a + 1 : a - 1;
		if (a < 0) k = tmp, a = 1;
	}
	printf("%d", k);
	return 0;
}