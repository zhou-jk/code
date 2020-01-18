#include <cmath>
#include <cstdio>

const int LEN_S = 1000000, LEN_P = 52;
char s[LEN_S], p[LEN_P];
int len_s, len_p;

char solve(int len)
{
	if (len < 26) return 'a' + len;
	return 'A' + len - 26;
}

int main()
{
	freopen("fake.in", "r", stdin);
	freopen("fake.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int m = sqrt(n);
	for (int i = 2; i <= m && n > 1; ++i)
		while (!(n % i))
		{
			n /= i;
			p[len_p] = solve(len_p);
			++len_p;
			for (int j = 0; j < i; ++j) s[len_s++] = p[len_p - 1];
		}
	if (n > 1)
	{
		p[len_p] = solve(len_p);
		++len_p;
		for (int i = 0; i < n; ++i) s[len_s++] = p[len_p - 1];
	}
	printf("%s %s", s, p);
	return 0;
}