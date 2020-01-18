// AC
#include <cstdio>

int main()
{
	double a, b, s = 0, ss = 7;
	int k1 = -1, k2;
	scanf("%lf%lf", &a, &b);
	for (k2 = 0; s <= a + b; ++k2)
	{
		if (k1 == -1 && s >= a - b) k1 = k2;
		s += ss * 0.98;
	}
	if (k1 == -1) k1 = k2;
	putchar(k2 - k1 <= 1 ? 'n' : 'y');
	return 0;
}