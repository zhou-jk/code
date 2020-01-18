// AC
#include <cstdio>
#include <cstring>

const int N = 1000000, M = 2000;
int a[N], b[M], n, m, ans;

bool check(int len)
{
	memset(b, 0, sizeof b);
	int tmp = 0;
	for (int i = 0; i < len; ++i)
	{
		if (!b[a[i]]) ++tmp;
		++b[a[i]];
	}
	if (tmp == m)
	{
		ans = 0;
		return true;
	}
	for (int i = len; i < n; ++i)
	{
		if (!b[a[i]]) ++tmp;
		++b[a[i]];
		--b[a[i - len]];
		if (!b[a[i - len]]) --tmp;
		if (tmp == m)
		{
			ans = i - len + 1;
			return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", a + i), --a[i];
	int l = 1, r = n;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d %d", ans + 1, ans + l);
	return 0;
}