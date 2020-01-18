#include <cstdio>

typedef unsigned long long ull;
const int N = 100000;
int c[N];

int main()
{
	freopen("fight.in", "r", stdin);
	freopen("fight.out", "w", stdout);
	int n, m, p1, s1, s2;
	ull a = 0, b = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
	scanf("%d%d%d%d", &m, &p1, &s1, &s2);
	--m;
	c[p1 - 1] += s1;
	for (int i = 0; i < m; ++i) a += (ull)(m - i) * c[i];
	for (int i = m + 1; i < n; ++i) b += (ull)(i - m) * c[i];
	if (a > b)
	{
		ull tmp1 = (a - b) / s2, tmp2 = (a - b) % s2;
		if (s2 - tmp2 < tmp2) ++tmp1;
		if (m + tmp1 >= n)
			printf("%d", n);
		else
			printf("%llu", m + tmp1 + 1);
	}
	else if (a < b)
	{
		ull tmp1 = (b - a) / s2, tmp2 = (b - a) % s2;
		if (s2 - tmp2 < tmp2) ++tmp1;
		if (tmp1 > m)
			printf("%d", 1);
		else
			printf("%llu", m - tmp1 + 1);
	}
	else
		printf("%d", m + 1);
	return 0;
}