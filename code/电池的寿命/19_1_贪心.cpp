// AC
#include <cstdio>

const int N = 1000;
int a[N];

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int max = 0, sum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", a + i);
			if (a[i] > max) max = a[i];
			sum += a[i];
		}
		if (sum - max >= max)
			printf("%.1lf\n", (double)sum / 2);
		else
			printf("%d\n", sum - max);
	}
}