// AC
#include <cstdio>

const int N = 1000;
int a[N];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	for (int i = 0; i < n; ++i)
	{
		int b;
		scanf("%d", &b);
		ans += a[i] * b;
	}
	printf("%d", ans);
	return 0;
}