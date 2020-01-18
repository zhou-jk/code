// AC
#include <cmath>
#include <cstdio>

double arctan(double x)
{
	double ret = 0, tmp1 = x;
	int tmp2 = 1;
	while (fabs(tmp1 / tmp2) >= 1E-6)
	{
		ret += tmp1 / tmp2;
		tmp1 *= -x * x;
		tmp2 += 2;
	}
	return ret;
}

int main()
{
	printf("%.10f", 6 * arctan(1 / sqrt(3)));
	return 0;
}