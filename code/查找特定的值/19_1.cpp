// AC
#include <cstdio>

const int N = 10000;
int a[N];

int main()
{
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	scanf("%d", &x);
	for (int i = 0; i < n; ++i)
		if (a[i] == x)
		{
			printf("%d", i + 1);
			return 0;
		}
	puts("-1");
	return 0;
}