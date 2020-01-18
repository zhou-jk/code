#include <algorithm>
#include <cstdio>

using std::sort;

const int N = 100;
int a[N], ans[N];

int main()
{
	int n, l, r, s = 1;
	scanf("%d", &n);
	l = (n >> 1) - 1;
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	if (n & 1)
	{
		ans[n >> 1] = a[n - 1];
		r = (n >> 1) + 1;
		s = 2;
	}
	else
		r = n >> 1;
	for (int i = n - s; ~i; i -= 2)
	{
		ans[l--] = a[i];
		ans[r++] = a[i - 1];
	}
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
	return 0;
}