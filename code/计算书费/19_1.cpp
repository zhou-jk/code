// AC
#include <cstdio>

const int N = 10;
double a[N] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};

int main()
{
	double ans = 0;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		ans += tmp * a[i];
	}
	printf("%.1lf", ans);
	return 0;
}