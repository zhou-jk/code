// AC
#include <cstdio>

int f[4];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		if (a < 19)
			++f[0];
		else if (a < 36)
			++f[1];
		else if (a < 61)
			++f[2];
		else
			++f[3];
	}
	for (int i = 0; i < 4; ++i) printf("%.2lf%%\n", (double)f[i] / n * 100);
	return 0;
}