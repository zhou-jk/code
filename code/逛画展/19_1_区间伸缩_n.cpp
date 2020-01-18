#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

const int N = 1000000, M = 2000;
int a[N], b[M], ans;

int main()
{
	int n, m, tmp = 0, ans = 1E8, l, r;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", a + i), --a[i];
	for (int i = 0, j = 0; i < n; ++i)
	{
		if (i)
		{
			--b[a[i - 1]];
			if (!b[a[i - 1]]) --tmp;
		}
		for (; tmp < m && j < n; ++j)
		{
			if (!b[a[j]]) ++tmp;
			++b[a[j]];
		}
		if (tmp == m && j - i < ans) ans = j - i, l = i, r = j - 1;
	}
	printf("%d %d", l + 1, r + 1);
	return 0;
}