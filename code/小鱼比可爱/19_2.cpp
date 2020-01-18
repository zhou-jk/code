// AC
#include <cstdio>

const int N = 100;
int a[N];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int ans = 0;
		scanf("%d", &a[i]);
		for (int j = 0; j < i; ++j) ans += a[j] < a[i];
		printf("%d ", ans);
	}
	return 0;
}