// AC
#include <cstdio>

int main()
{
	int n, b = 2E9, cnt, ans = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		if (a > b)
		{
			++cnt;
			if (cnt > ans) ans = cnt;
		}
		else
			cnt = 1;
		b = a;
	}
	printf("%d", ans);
	return 0;
}