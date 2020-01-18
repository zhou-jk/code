// AC
#include <cstdio>

double a, b, c, d;

double f(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
	int cnt = 0;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	for (int i = -100; i < 100; ++i)
	{
		double l = i, r = i + 1;
		double y1 = f(l), y2 = f(r);
		if (y1 == 0)
		{
			printf("%.2lf ", l);
			++cnt;
		}
		if (y1 * y2 < 0)
		{
			while (r - l >= 0.0001)
			{
				double mid = (l + r) / 2;
				if (f(l) * f(mid) < 0)
					r = mid;
				else
					l = mid;
			}
			printf("%.2lf ", l);
			++cnt;
		}
		if (cnt == 3) break;
	}
	return 0;
}