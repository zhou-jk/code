// AC
#include <cstdio>

int main()
{
	int n, a;
	scanf("%d", &n);
	scanf("%d", &a);
	if (a)
	{
		if (a < 0) putchar('-');
		a = a < 0 ? -a : a;
		if (a != 1) printf("%d", a);
		printf("x^%d", n);
	}
	for (int i = 1; i < n - 1; ++i)
	{
		scanf("%d", &a);
		if (a)
		{
			putchar(a < 0 ? '-' : '+');
			a = a < 0 ? -a : a;
			if (a != 1) printf("%d", a);
			printf("x^%d", n - i);
		}
	}
	scanf("%d", &a);
	if (a)
	{
		putchar(a < 0 ? '-' : '+');
		a = a < 0 ? -a : a;
		if (a != 1) printf("%d", a);
		putchar('x');
	}
	scanf("%d", &a);
	if (a)
	{
		putchar(a < 0 ? '-' : '+');
		printf("%d", a < 0 ? -a : a);
	}
	return 0;
}