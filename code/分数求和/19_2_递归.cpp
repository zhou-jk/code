// AC
#include <cstdio>

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int n, a1 = 0, b1 = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a, b, lcm;
		scanf("%d/%d", &a, &b);
		lcm = b1 * b / gcd(b1, b);
		a1 *= lcm / b1;
		a *= lcm / b;
		a1 += a;
		b1 = lcm;
	}
	int tmp = gcd(a1, b1);
	a1 /= tmp;
	b1 /= tmp;
	if (b1 == 1)
		printf("%d", a1);
	else
		printf("%d/%d", a1, b1);
	return 0;
}