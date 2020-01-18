// AC
#include <cstdio>

int main()
{
	int n, sum = 0, max = 0, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		sum += a;
		if (a > max) max = a, cnt = 0;
		if (a == max) ++cnt;
	}
	printf("%d", sum - cnt * max);
	return 0;
}