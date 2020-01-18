// AC
#include <cstdio>

int main()
{
	int n, max = -10000, min = 10000;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		if (a > max) max = a;
		if (a < min) min = a;
	}
	printf("%d", max - min);
}