// AC
#include <cstdio>

const int N = 100;
int a[N];

int main()
{
	int n, m, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	scanf("%d", &m);
	for (int i = 0; i < n; ++i) ans += m == a[i];
	printf("%d", ans);
	return 0;
}