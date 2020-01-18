// AC
#include <cstdio>

const int LIMIT = 70;

int main()
{
	int n;
	double ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		ans += a / LIMIT * 0.1;
		if (a % LIMIT) ans += 0.1;
	}
	printf("%.1f", ans);
	return 0;
}