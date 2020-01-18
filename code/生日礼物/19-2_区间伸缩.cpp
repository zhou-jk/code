// AC
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <utility>

using std::max;
using std::min;
using std::pair;
using std::sort;

typedef pair<int, int> pii;

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

int main()
{
	int n, m, k = 0, cnt = 0;
	long long ans = 1E11;
	n = get_int();
	m = get_int();
	int **s = new int *[m], *p = new int[m], *a = new int[m];
	pii *b = new pii[n];
	for (int i = 0; i < m; ++i)
	{
		a[i] = get_int();
		p[i] = 0;
		s[i] = new int[a[i]];
		for (int j = 0; j < a[i]; ++j)
		{
			s[i][j] = get_int() - 1;
			b[cnt++] = pii(s[i][j], i);
		}
		k = max(k, s[i][0]);
	}
	sort(b, b + n);
	for (int i = 0; i < n; ++i)
	{
		if (!i || b[i].first != b[i - 1].first)
			ans = min(ans, (long long)(k - b[i].first));
		int kk = b[i].second;
		while (p[kk] < a[kk] && s[kk][p[kk]] <= b[i].first) ++p[kk];
		if (p[kk] == a[kk]) break;
		k = max(k, s[kk][p[kk]]);
	}
	printf("%lld", ans);
	return 0;
}