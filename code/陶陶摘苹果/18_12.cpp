// AC
#include <cstdio>

const int N = 10;
int h[N];

int main()
{
	int a, ans = 0;
	for (int i = 0; i < N; ++i) scanf("%d", h + i);
	scanf("%d", &a);
	for (int i = 0; i < N; ++i)
		if (h[i] <= a + 30) ++ans;
	printf("%d", ans);
	return 0;
}