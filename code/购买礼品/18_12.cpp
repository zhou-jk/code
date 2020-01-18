// AC
#include <cstdio>

const int N = 100000;
int f[N];

int main()
{
	int n, a, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		sum += a;
		int tmp = sum % n;
		if (f[tmp])
		{
			printf("%d\n", i - f[tmp] + 1);
			for (int j = f[tmp]; j <= i; ++j) printf("%d ", j + 1);
			return 0;
		}
		f[tmp] = i + 1;
	}
	puts("Sadly");
	return 0;
}