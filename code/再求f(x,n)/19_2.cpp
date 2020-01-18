// AC
#include <cstdio>

double f(int n, double x)
{
	if (!n) return x;
	return x / (n + f(n - 1, x));
}

int main()
{
	double x;
	int n;
	scanf("%lf%d", &x, &n);
	printf("%.2f", f(n, x));
	return 0;
}