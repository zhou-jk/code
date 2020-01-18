// AC
#include <cstdio>

const int N = 100000;
int a[N + 1];

int main()
{
	int n, s, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", a + i);
		if (a[i] != a[i - 1]) s = 0;
		++s;
		ans = s > ans ? s : ans;
	}
	printf("%d", ans);
	return 0;
}