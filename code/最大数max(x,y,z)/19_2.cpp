#include <cstdio>

double max(double a, double b, double c)
{
	if (a >= b && a >= c) return a;
	if (b >= c) return b;
	return c;
}

int main()
{
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	printf("%.3f", max(a, b, c) / (max(a + b, b, c) * max(a, b, b + c)));
	return 0;
}